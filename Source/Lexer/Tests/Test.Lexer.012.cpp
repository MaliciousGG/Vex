#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_012_Delimiters() {
    std::cout << "--- Lexer Test 012: Delimiters ---" << "\n";

    const std::string Code = "( ) { } [ ] , ; : ::";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    assert(Tokens.size() == 11);

    assert(Tokens[0].Type == ETokenType::LEFT_PAREN);
    assert(Tokens[1].Type == ETokenType::RIGHT_PAREN);
    assert(Tokens[2].Type == ETokenType::LEFT_BRACE);
    assert(Tokens[3].Type == ETokenType::RIGHT_BRACE);
    assert(Tokens[4].Type == ETokenType::LEFT_BRACKET);
    assert(Tokens[5].Type == ETokenType::RIGHT_BRACKET);
    assert(Tokens[6].Type == ETokenType::COMMA);
    assert(Tokens[7].Type == ETokenType::SEMICOLON);
    assert(Tokens[8].Type == ETokenType::COLON);
    assert(Tokens[9].Type == ETokenType::DOUBLE_COLON);

    std::cout << "Lexer Test 012: Passed\n\n";
}