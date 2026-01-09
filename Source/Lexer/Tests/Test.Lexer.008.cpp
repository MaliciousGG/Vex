#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_008_Comments() {
    std::cout << "--- Lexer Test 008: Comments ---" << "\n";

    const std::string Code = R"(
        // This is a line comment
        Define Player
        /* This is a
           block comment */
        Fetch Health
        )";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    // COMMENTS SHOULD BE SKIPPED HERE

    assert(Tokens.size() == 5);

    assert(Tokens[0].Type == ETokenType::DEFINE);
    assert(Tokens[1].Type == ETokenType::IDENTIFIER);
    assert(Tokens[1].Lexeme == "Player");

    assert(Tokens[2].Type == ETokenType::FETCH);
    assert(Tokens[3].Type == ETokenType::IDENTIFIER);
    assert(Tokens[3].Lexeme == "Health");


    std::cout << "Lexer Test 008: Passed\n\n";
}