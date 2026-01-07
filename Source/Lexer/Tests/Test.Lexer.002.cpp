#include <iostream>
#include <cassert>

#include "../Lexer.h"
using namespace Vex;

void Test_Lexer_002_AccessModifiers() {
    std::cout << "--- Lexer Test 002: Access Modifiers ---" << '\n';

    const std::string Code = "Public Private Protected View";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    assert(Tokens.size() == 5);
    assert(Tokens[0].Type == ETokenType::PUBLIC);
    assert(Tokens[1].Type == ETokenType::PRIVATE);
    assert(Tokens[2].Type == ETokenType::PROTECTED);
    assert(Tokens[3].Type == ETokenType::VIEW);

    std::cout << "Lexer Test 002: Passed\n\n";
}