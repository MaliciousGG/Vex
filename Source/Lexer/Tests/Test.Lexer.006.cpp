#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_006_NumberLiterals() {
    std::cout << "--- Lexer Test 006: Number Literals ---" << "\n";

    const std::string Code = "45 1000 3.14 69 540";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    assert(Tokens.size() == 6);

    assert(Tokens[0].Type == ETokenType::INTEGER_LITERAL);
    assert(Tokens[0].IntValue == 45);

    assert(Tokens[1].Type == ETokenType::INTEGER_LITERAL);
    assert(Tokens[1].IntValue == 1000);

    assert(Tokens[2].Type == ETokenType::FLOAT_LITERAL);
    assert(Tokens[2].FloatValue == 3.14);

    assert(Tokens[3].Type == ETokenType::INTEGER_LITERAL);
    assert(Tokens[3].IntValue == 69);

    assert(Tokens[4].Type == ETokenType::INTEGER_LITERAL);
    assert(Tokens[4].IntValue == 540);

    std::cout << "Lexer Test 006: Passed\n\n";
}