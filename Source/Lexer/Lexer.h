#pragma once

#include <vector>
#include <string>

#include "Token.h"
#include "TokenEnums.h"  // FIXED: Added .h

namespace Vex {
    class Lexer {
    public:
        explicit Lexer(std::string  Source);

        std::vector<Token> Tokenize();
        Token NextToken();
        [[nodiscard]] bool IsAtEnd() const;

    private:
        std::string Source;
        size_t      Start   = 0;
        size_t      Current = 0;
        int         Line    = 1;
        int         Column  = 1;

        // Helpers
        char Advance();
        [[nodiscard]] char Peek() const;
        [[nodiscard]] char PeekNext() const;
        bool Match(char Expected);

        void SkipWhitespace();
        void SkipLineComment();
        void SkipBlockComment();

        [[nodiscard]] Token MakeToken(ETokenType Type) const;
        [[nodiscard]] Token MakeToken(ETokenType Type, const std::string& Lexeme) const;
        [[nodiscard]] Token ErrorToken(const std::string& Message) const;

        // Scanners
        [[nodiscard]] Token ScanToken();
        [[nodiscard]] Token Identifier();
        [[nodiscard]] Token Number();
        [[nodiscard]] Token String();
        [[nodiscard]] Token Character();

        static bool IsDigit(char C);

        static bool IsAlpha(char C);

        static bool IsAlphaNumeric(char C);

        [[nodiscard]] ETokenType IdentifierType() const;
        [[nodiscard]] ETokenType CheckKeyword(int Start, const std::string& Rest, ETokenType Type) const;
    };
}