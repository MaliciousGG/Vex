#include <sstream>

#include "Token.h"

namespace Vex {
    std::string Token::ToString() const {
        std::stringstream Stream;
        Stream << "Token(Type: ";

        // Convert TokenType to string
        switch (Type) {
            case ETokenType::IDENTIFIER:        Stream << "IDENTIFIER";
                break;
            case ETokenType::INTEGER_LITERAL:   Stream << "INTEGER_LITERAL";
                break;
            case ETokenType::FLOAT_LITERAL:     Stream << "FLOAT_LITERAL";
                break;
            case ETokenType::STRING_LITERAL:    Stream << "STRING_LITERAL";
                break;
            case ETokenType::DEFINE:            Stream << "DEFINE";
                break;
            case ETokenType::FETCH:             Stream << "FETCH";
                break;
            case ETokenType::SET:               Stream << "SET";
                break;
            case ETokenType::INTERFACE:         Stream << "INTERFACE";
                break;
            case ETokenType::NAMESPACE:         Stream << "NAMESPACE";
                break;
            case ETokenType::USING:             Stream << "USING";
                break;
            case ETokenType::ARROW:             Stream << "ARROW";
                break;
            case ETokenType::LEFT_BRACE:        Stream << "LEFT_BRACE";
                break;
            case ETokenType::RIGHT_BRACE:       Stream << "RIGHT_BRACE";
                break;
            case ETokenType::SEMICOLON:         Stream << "SEMICOLON";
                break;
            case ETokenType::END_OF_FILE:       Stream << "END_OF_FILE";
                break;
            default:                            Stream << "OTHER";
                break;
        }
        
        Stream << ", Lexeme: '" << Lexeme << "'";
        Stream << ", Line: "    << Line;
        Stream << ", Column: "  << Column;
        Stream << ")";
        
        return Stream.str();
    }
}