#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_007_StringLiterals() {
    std::cout << "--- Lexer Test 006: String Literals ---" << "\n";

    const std::string Code = R"("Hello World" "Hello Vex" "Player Name" "Escape: \n \t \\")";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    assert(Tokens.size() == 5);

    assert(Tokens[0].Type == ETokenType::STRING_LITERAL);
    assert(Tokens[0].Lexeme == "Hello World");

    assert(Tokens[1].Type == ETokenType::STRING_LITERAL);
    assert(Tokens[1].Lexeme == "Hello Vex");

    assert(Tokens[2].Type == ETokenType::STRING_LITERAL);
    assert(Tokens[2].Lexeme == "Player Name");

    assert(Tokens[3].Type == ETokenType::STRING_LITERAL);
    assert(Tokens[3].Lexeme == "Escape: \n \t \\");

    std::cout << "Lexer Test 007: Passed\n\n";
}