#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_009_Identifiers() {
    std::cout << "--- Lexer Test 009: Identifiers ---" << "\n";

    const std::string Code = "Player_Health bIsMoving SERVER_TIME";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    std::cout << "TOKEN SIZE: " << Tokens.size() << "\n";

    assert(Tokens.size() == 4);

    assert(Tokens[0].Type == ETokenType::IDENTIFIER);
    assert(Tokens[0].Lexeme == "Player_Health");

    assert(Tokens[1].Type == ETokenType::IDENTIFIER);
    assert(Tokens[1].Lexeme == "bIsMoving");
    
    assert(Tokens[2].Type == ETokenType::IDENTIFIER);
    assert(Tokens[2].Lexeme == "SERVER_TIME");

    std::cout << "Lexer Test 009: Passed\n\n";
}