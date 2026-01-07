#include "Lexer.h"

#include <utility>

namespace Vex {
    Lexer::Lexer(std::string  Source) : Source(std::move(Source)) {}

    std::vector<Token> Lexer::Tokenize() {
        std::vector<Token> Tokens;

        while (true) {
            Token T = NextToken();
            Tokens.push_back(T);

            if (T.Type == ETokenType::END_OF_FILE) {
                break;
            }
        }

        return Tokens;
    }

    Token Lexer::NextToken() {
        SkipWhitespace();

        if (IsAtEnd()) {
            return MakeToken(ETokenType::END_OF_FILE);
        }

        Start = Current;

        return ScanToken();
    }

    bool Lexer::IsAtEnd() const {
        return Current >= Source.length();
    }

    char Lexer::Advance() {
        Column++;

        return Source[Current++];
    }

    char Lexer::Peek() const {
        if (IsAtEnd()) {
            return '\0';
        }

        return Source[Current];
    }

    char Lexer::PeekNext() const {
        if (Current + 1 >= Source.length()) {
            return '\0';
        }

        return Source[Current + 1];
    }

    bool Lexer::Match(const char Expected) {
        if (IsAtEnd()) {
            return false;
        }

        if (Source[Current] != Expected) {
            return false;
        }

        Current++;
        Column++;
        return true;
    }

    void Lexer::SkipWhitespace() {
        while (!IsAtEnd()) {  // FIXED: Added parentheses

            switch (Peek()) {
                case ' ':
                case '\r':
                case '\t':
                    Advance();
                    break;
                case '\n':
                    Line++;
                    Column = 0;
                    Advance();
                    break;
                case '/':
                    if (PeekNext() == '/') {
                        SkipLineComment();
                    } else if (PeekNext() == '*') {
                        SkipBlockComment();
                    } else {
                        return;
                    }
                    break;
                default:
                    return;
            }
        }
    }

    void Lexer::SkipLineComment() {
        Advance();
        Advance();

        while (Peek() != '\n' && !IsAtEnd()) {
            Advance();
        }
    }

    void Lexer::SkipBlockComment() {
        Advance();
        Advance();

        while (!IsAtEnd()) {
            if (Peek() == '*' && PeekNext() == '/') {
                Advance();
                Advance();
                break;
            }

            if (Peek() == '\n') {
                Line++;
                Column = 0;
            }

            Advance();
        }
    }

    Token Lexer::MakeToken(const ETokenType Type) const {
        const std::string Lexeme = Source.substr(Start, Current - Start);
        return Token(Type, Lexeme, Line, Column - Lexeme.length());
    }

    Token Lexer::MakeToken(ETokenType Type, const std::string& Lexeme) const {
        return Token(Type, Lexeme, Line, Column - Lexeme.length());
    }

    Token Lexer::ErrorToken(const std::string& Message) const {
        return Token(ETokenType::UNKNOWN, Message, Line, Column);
    }

    Token Lexer::ScanToken() {
        const char C = Advance();

        if (IsAlpha(C)) {
            return Identifier();
        }

        // Numbers
        if (IsDigit(C)) {
            return Number();
        }

        switch(C) {
            case '(': return MakeToken(ETokenType::LEFT_PAREN);
            case ')': return MakeToken(ETokenType::RIGHT_PAREN);
            case '{': return MakeToken(ETokenType::LEFT_BRACE);
            case '}': return MakeToken(ETokenType::RIGHT_BRACE);
            case '[': return MakeToken(ETokenType::LEFT_BRACKET);
            case ']': return MakeToken(ETokenType::RIGHT_BRACKET);
            case ',': return MakeToken(ETokenType::COMMA);
            case ';': return MakeToken(ETokenType::SEMICOLON);
            case '~': return MakeToken(ETokenType::BITWISE_NOT);
            case '@': return MakeToken(ETokenType::AT);
            case '#': return MakeToken(ETokenType::HASH);
            case '_': return MakeToken(ETokenType::UNDERSCORE);
            case '^': return MakeToken(ETokenType::BITWISE_XOR);
            case '/':
                return MakeToken(Match('=') ? ETokenType::SLASH_ASSIGN : ETokenType::SLASH);
            case ':':
                return MakeToken(Match(':') ? ETokenType::DOUBLE_COLON : ETokenType::COLON);
            case '+':
                return MakeToken(Match('=') ? ETokenType::PLUS_ASSIGN : ETokenType::PLUS);
            case '%':
                return MakeToken(Match('=') ? ETokenType::PERCENT_ASSIGN : ETokenType::PERCENT);
            case '&':
                return MakeToken(Match('&') ? ETokenType::AND : ETokenType::BITWISE_AND);
            case '|':
                return MakeToken(Match('|') ? ETokenType::OR : ETokenType::BITWISE_OR);
            case '=':
                if (Match('=')) {
                    if (Match('=')) {
                        return MakeToken(ETokenType::TYPE_VAL_EQ);
                    }
                    return MakeToken(ETokenType::EQUAL);
                }
                return MakeToken(ETokenType::ASSIGN);
            case '!':
                if (Match('=')) {
                    if (Match('=')) {
                        return MakeToken(ETokenType::TYPE_VAL_NEQ);
                    }
                    return MakeToken(ETokenType::NOT_EQUAL);
                }
                return MakeToken(ETokenType::NOT);
            case '<':
                if (Match('=')) {
                    return MakeToken(ETokenType::LESS_EQUAL);
                } else if (Match('<')) {
                    return MakeToken(ETokenType::LEFT_SHIFT);
                }
                return MakeToken(ETokenType::LESS);
            case '>':
                if (Match('=')) {
                    return MakeToken(ETokenType::GREATER_EQUAL);
                } else if (Match('>')) {
                    return MakeToken(ETokenType::RIGHT_SHIFT);
                }
                return MakeToken(ETokenType::GREATER);
            case '-':
                if (Match('=')) {
                    return MakeToken(ETokenType::MINUS_ASSIGN);
                } else if (Match('>')) {
                    return MakeToken(ETokenType::ARROW);
                }
                return MakeToken(ETokenType::MINUS);
            case '*':
                if (Match('=')) {
                    return MakeToken(ETokenType::STAR_ASSIGN);
                } else if (Match('*')) {
                    return MakeToken(ETokenType::POWER);
                }
                return MakeToken(ETokenType::STAR);
            case '.':
                if (Match('.')) {
                    if (Match('=')) {
                        return MakeToken(ETokenType::DOT_DOT_EQUAL);
                    }
                    return MakeToken(ETokenType::DOUBLE_DOT);
                }
                return MakeToken(ETokenType::DOT);
            case '?':
                if (Match('.')) {
                    return MakeToken(ETokenType::QUESTION_DOT);
                } else if (Match('?')) {
                    return MakeToken(ETokenType::DOUBLE_QUESTION);
                }
                return MakeToken(ETokenType::QUESTION);
            case '"':
                return String();
            case '\'':
                return Character();
            default:
                return ErrorToken("Unexpected character");
        }
    }

    Token Lexer::Identifier() {
        while(IsAlphaNumeric(Peek())) {
            Advance();
        }

        return MakeToken(IdentifierType());
    }

    Token Lexer::Number() {
        while (IsDigit(Peek())) {
            Advance();
        }

        if (Peek() == '.' && IsDigit(PeekNext())) {
            Advance();

            while (IsDigit(Peek())) {
                Advance();
            }

            Token T = MakeToken(ETokenType::FLOAT_LITERAL);
            T.FloatValue = std::stod(T.Lexeme);
            return T;
        }

        Token T = MakeToken(ETokenType::INTEGER_LITERAL);
        T.IntValue = std::stoll(T.Lexeme);
        return T;
    }

    Token Lexer::String() {
        std::string Value;

        while (Peek() != '"' && !IsAtEnd()) {
            if (Peek() == '\n') {
                Line++;
                Column = 0;
            }

            if (Peek() == '\\') {
                Advance();
                if (!IsAtEnd()) {
                    switch(const char Escaped = Advance()) {
                        case 'n': Value += '\n';
                            break;
                        case 't': Value += '\t';
                            break;
                        case 'r': Value += '\r';
                            break;
                        case '\\': Value += '\\';
                            break;
                        case '"': Value += '"';
                            break;
                        case '0': Value += '\0';
                            break;
                        default: Value += Escaped;
                            break;
                    }
                }
            } else {
                Value += Advance();
            }
        }

        if (IsAtEnd()) {
            return ErrorToken("Unterminated String");
        }

        Advance();

        return MakeToken(ETokenType::STRING_LITERAL, Value);
    }

    Token Lexer::Character() {
        if (IsAtEnd()) {
            return ErrorToken("Unterminated Character Literal");
        }

        char Value;

        if (Peek() == '\\') {
            Advance();
            if (IsAtEnd()) {
                return ErrorToken("Unterminated Character Literal");
            }

            switch (const char Escaped = Advance()) {
                case 'n':   Value = '\n';
                    break;
                case 't':   Value = '\t';
                    break;
                case 'r':   Value = '\r';
                    break;
                case '\\':  Value = '\\';
                    break;
                case '\'':  Value = '\'';
                    break;
                case '0':   Value = '\0';
                    break;
                default:    Value = Escaped;
                    break;
            }
        } else {
            Value = Advance();
        }

        if (Peek() != '\'') {
            return ErrorToken("Unterminated Character Literal");
        }

        Advance();

        return MakeToken(ETokenType::CHAR_LITERAL, std::string(1, Value));
    }

    bool Lexer::IsDigit(const char C) {
        return C >= '0' && C <= '9';
    }

    bool Lexer::IsAlpha(const char C) {
        return (C >= 'a' && C <= 'z') ||
               (C >= 'A' && C <= 'Z') ||
               C == '_';
    }

    bool Lexer::IsAlphaNumeric(char C) {  // FIXED: Added const
        return IsAlpha(C) || IsDigit(C);
    }

    ETokenType Lexer::IdentifierType() const {
        const std::string Text = Source.substr(Start, Current - Start);

        if (const auto IT = Keywords.find(Text); IT != Keywords.end()) {
            return IT->second;
        }

        return ETokenType::IDENTIFIER;
    }

    ETokenType Lexer::CheckKeyword(const int Start, const std::string& Rest, const ETokenType Type) const {
        if (const size_t IdentLen = Current - this->Start; IdentLen == static_cast<size_t>(Start) + Rest.size()) {
            if (Source.compare(this->Start + Start, Rest.size(), Rest) == 0) {
                return Type;
            }
        }
        return ETokenType::IDENTIFIER;
    }
}