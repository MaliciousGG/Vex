#include <sstream>

#include "Token.h"

namespace Vex {
    std::string Token::ToString() const {
        std::stringstream Stream;
        Stream << "Token(Type: ";

        // Convert TokenType to string
        switch (Type) {
            // Identifiers and literals
            case ETokenType::IDENTIFIER:        Stream << "IDENTIFIER"; break;
            case ETokenType::INTEGER_LITERAL:   Stream << "INTEGER_LITERAL"; break;
            case ETokenType::FLOAT_LITERAL:     Stream << "FLOAT_LITERAL"; break;
            case ETokenType::STRING_LITERAL:    Stream << "STRING_LITERAL"; break;
            case ETokenType::CHAR_LITERAL:      Stream << "CHAR_LITERAL"; break;

            // Keywords
            case ETokenType::DEFINE:            Stream << "DEFINE"; break;
            case ETokenType::FETCH:             Stream << "FETCH"; break;
            case ETokenType::SET:               Stream << "SET"; break;
            case ETokenType::INTERFACE:         Stream << "INTERFACE"; break;
            case ETokenType::NAMESPACE:         Stream << "NAMESPACE"; break;
            case ETokenType::USING:             Stream << "USING"; break;

            // Access modifiers
            case ETokenType::PUBLIC:            Stream << "PUBLIC"; break;
            case ETokenType::PRIVATE:           Stream << "PRIVATE"; break;
            case ETokenType::PROTECTED:         Stream << "PROTECTED"; break;
            case ETokenType::VIEW:              Stream << "VIEW"; break;

            // Type keywords
            case ETokenType::STRUCT:            Stream << "STRUCT"; break;
            case ETokenType::CLASS:             Stream << "CLASS"; break;
            case ETokenType::REF:               Stream << "REF"; break;
            case ETokenType::ENUM:              Stream << "ENUM"; break;

            // Control flow
            case ETokenType::IF:                Stream << "IF"; break;
            case ETokenType::ELSE:              Stream << "ELSE"; break;
            case ETokenType::FOR:               Stream << "FOR"; break;
            case ETokenType::WHILE:             Stream << "WHILE"; break;
            case ETokenType::DO:                Stream << "DO"; break;
            case ETokenType::MATCH:             Stream << "MATCH"; break;
            case ETokenType::BREAK:             Stream << "BREAK"; break;
            case ETokenType::CONTINUE:          Stream << "CONTINUE"; break;
            case ETokenType::RETURN:            Stream << "RETURN"; break;

            // Memory keywords
            case ETokenType::UNIQUE:            Stream << "UNIQUE"; break;
            case ETokenType::SHARED:            Stream << "SHARED"; break;
            case ETokenType::BORROW:            Stream << "BORROW"; break;
            case ETokenType::RAW:               Stream << "RAW"; break;
            case ETokenType::UNSAFE:            Stream << "UNSAFE"; break;

            // Variable keywords
            case ETokenType::VAR:               Stream << "VAR"; break;
            case ETokenType::LET:               Stream << "LET"; break;
            case ETokenType::CONST:             Stream << "CONST"; break;
            case ETokenType::STATIC:            Stream << "STATIC"; break;

            // Function keywords
            case ETokenType::OVERRIDE:          Stream << "OVERRIDE"; break;
            case ETokenType::VIRTUAL:           Stream << "VIRTUAL"; break;
            case ETokenType::IMPLEMENT:         Stream << "IMPLEMENT"; break;
            case ETokenType::OPERATOR:          Stream << "OPERATOR"; break;

            // Boolean literals
            case ETokenType::TRUE:              Stream << "TRUE"; break;
            case ETokenType::FALSE:             Stream << "FALSE"; break;

            // Other keywords
            case ETokenType::NEW:               Stream << "NEW"; break;
            case ETokenType::AS:                Stream << "AS"; break;
            case ETokenType::IS:                Stream << "IS"; break;
            case ETokenType::IN:                Stream << "IN"; break;
            case ETokenType::STEP:              Stream << "STEP"; break;
            case ETokenType::SUPER:             Stream << "SUPER"; break;
            case ETokenType::THIS:              Stream << "THIS"; break;
            case ETokenType::GLOBAL:            Stream << "GLOBAL"; break;
            case ETokenType::NULL_KEY:          Stream << "NULL"; break;

            // Primitive types
            case ETokenType::INT8:              Stream << "INT8"; break;
            case ETokenType::INT16:             Stream << "INT16"; break;
            case ETokenType::INT32:             Stream << "INT32"; break;
            case ETokenType::INT64:             Stream << "INT64"; break;
            case ETokenType::UINT8:             Stream << "UINT8"; break;
            case ETokenType::UINT16:            Stream << "UINT16"; break;
            case ETokenType::UINT32:            Stream << "UINT32"; break;
            case ETokenType::UINT64:            Stream << "UINT64"; break;
            case ETokenType::FLOAT32:           Stream << "FLOAT32"; break;
            case ETokenType::FLOAT64:           Stream << "FLOAT64"; break;
            case ETokenType::INT:               Stream << "INT"; break;
            case ETokenType::UINT:              Stream << "UINT"; break;
            case ETokenType::FLOAT:             Stream << "FLOAT"; break;
            case ETokenType::DOUBLE:            Stream << "DOUBLE"; break;
            case ETokenType::BOOL:              Stream << "BOOL"; break;
            case ETokenType::CHAR:              Stream << "CHAR"; break;
            case ETokenType::STRING:            Stream << "STRING"; break;
            case ETokenType::VOID:              Stream << "VOID"; break;

            // Game types
            case ETokenType::VECTOR2:           Stream << "VECTOR2"; break;
            case ETokenType::VECTOR3:           Stream << "VECTOR3"; break;
            case ETokenType::VECTOR4:           Stream << "VECTOR4"; break;
            case ETokenType::QUATERNION:        Stream << "QUATERNION"; break;
            case ETokenType::COLOR:             Stream << "COLOR"; break;
            case ETokenType::TRANSFORM:         Stream << "TRANSFORM"; break;

            // Operators
            case ETokenType::PLUS:              Stream << "PLUS"; break;
            case ETokenType::MINUS:             Stream << "MINUS"; break;
            case ETokenType::STAR:              Stream << "STAR"; break;
            case ETokenType::SLASH:             Stream << "SLASH"; break;
            case ETokenType::PERCENT:           Stream << "PERCENT"; break;
            case ETokenType::POWER:             Stream << "POWER"; break;

            case ETokenType::ASSIGN:            Stream << "ASSIGN"; break;
            case ETokenType::PLUS_ASSIGN:       Stream << "PLUS_ASSIGN"; break;
            case ETokenType::MINUS_ASSIGN:      Stream << "MINUS_ASSIGN"; break;
            case ETokenType::STAR_ASSIGN:       Stream << "STAR_ASSIGN"; break;
            case ETokenType::SLASH_ASSIGN:      Stream << "SLASH_ASSIGN"; break;
            case ETokenType::PERCENT_ASSIGN:    Stream << "PERCENT_ASSIGN"; break;

            case ETokenType::EQUAL:             Stream << "EQUAL"; break;
            case ETokenType::TYPE_VAL_EQ:       Stream << "TYPE_VAL_EQ"; break;
            case ETokenType::NOT_EQUAL:         Stream << "NOT_EQUAL"; break;
            case ETokenType::TYPE_VAL_NEQ:      Stream << "TYPE_VAL_NEQ"; break;
            case ETokenType::LESS:              Stream << "LESS"; break;
            case ETokenType::GREATER:           Stream << "GREATER"; break;
            case ETokenType::LESS_EQUAL:        Stream << "LESS_EQUAL"; break;
            case ETokenType::GREATER_EQUAL:     Stream << "GREATER_EQUAL"; break;

            case ETokenType::AND:               Stream << "AND"; break;
            case ETokenType::OR:                Stream << "OR"; break;
            case ETokenType::NOT:               Stream << "NOT"; break;

            case ETokenType::BITWISE_AND:       Stream << "BITWISE_AND"; break;
            case ETokenType::BITWISE_OR:        Stream << "BITWISE_OR"; break;
            case ETokenType::BITWISE_XOR:       Stream << "BITWISE_XOR"; break;
            case ETokenType::BITWISE_NOT:       Stream << "BITWISE_NOT"; break;
            case ETokenType::LEFT_SHIFT:        Stream << "LEFT_SHIFT"; break;
            case ETokenType::RIGHT_SHIFT:       Stream << "RIGHT_SHIFT"; break;

            // Special operators
            case ETokenType::ARROW:             Stream << "ARROW"; break;
            case ETokenType::DOT:               Stream << "DOT"; break;
            case ETokenType::DOUBLE_DOT:        Stream << "DOUBLE_DOT"; break;
            case ETokenType::DOT_DOT_EQUAL:     Stream << "DOT_DOT_EQUAL"; break;
            case ETokenType::QUESTION:          Stream << "QUESTION"; break;
            case ETokenType::QUESTION_DOT:      Stream << "QUESTION_DOT"; break;
            case ETokenType::DOUBLE_QUESTION:   Stream << "DOUBLE_QUESTION"; break;
            case ETokenType::EXCLAIM:           Stream << "EXCLAIM"; break;
            case ETokenType::COLON:             Stream << "COLON"; break;
            case ETokenType::DOUBLE_COLON:      Stream << "DOUBLE_COLON"; break;
            case ETokenType::SEMICOLON:         Stream << "SEMICOLON"; break;
            case ETokenType::COMMA:             Stream << "COMMA"; break;
            case ETokenType::HASH:              Stream << "HASH"; break;
            case ETokenType::AT:                Stream << "AT"; break;
            case ETokenType::UNDERSCORE:        Stream << "UNDERSCORE"; break;

            // Delimiters
            case ETokenType::LEFT_PAREN:        Stream << "LEFT_PAREN"; break;
            case ETokenType::RIGHT_PAREN:       Stream << "RIGHT_PAREN"; break;
            case ETokenType::LEFT_BRACE:        Stream << "LEFT_BRACE"; break;
            case ETokenType::RIGHT_BRACE:       Stream << "RIGHT_BRACE"; break;
            case ETokenType::LEFT_BRACKET:      Stream << "LEFT_BRACKET"; break;
            case ETokenType::RIGHT_BRACKET:     Stream << "RIGHT_BRACKET"; break;

            // Special
            case ETokenType::END_OF_FILE:       Stream << "END_OF_FILE"; break;
            case ETokenType::UNKNOWN:           Stream << "UNKNOWN"; break;

            default:                            Stream << "OTHER"; break;
        }
        
        Stream << ", Lexeme: '" << Lexeme << "'";
        Stream << ", Line: "    << Line;
        Stream << ", Column: "  << Column;
        Stream << ")";
        
        return Stream.str();
    }
}