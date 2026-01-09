#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_011_ControlFlow() {
    std::cout << "--- Lexer Test 011: Control Flow ---" << "\n";

    const std::string Code = "if else for while do match break continue return";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    assert(Tokens.size() == 10);

    assert(Tokens[0].Type == ETokenType::IF);
    assert(Tokens[1].Type == ETokenType::ELSE);
    assert(Tokens[2].Type == ETokenType::FOR);
    assert(Tokens[3].Type == ETokenType::WHILE);
    assert(Tokens[4].Type == ETokenType::DO);
    assert(Tokens[5].Type == ETokenType::MATCH);
    assert(Tokens[6].Type == ETokenType::BREAK);
    assert(Tokens[7].Type == ETokenType::CONTINUE);
    assert(Tokens[8].Type == ETokenType::RETURN);

    std::cout << "Lexer Test 011: Passed\n\n";
}