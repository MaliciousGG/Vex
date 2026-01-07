#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_001_BasicKeywords() {
    std::cout << "--- Lexer Test 001: Basic Keywords ---" << "\n";

    const std::string Code = "Define Fetch Set Interface Namespace Using";
    Lexer Lexer(Code);

    const auto Tokens = Lexer.Tokenize();

    for (int i = 0; i < Tokens.size(); ++i) {
        std::cout << Tokens[i].ToString() << "\n";
    }

    assert(Tokens.size() == 7);
    assert(Tokens[0].Type == ETokenType::DEFINE);
    assert(Tokens[1].Type == ETokenType::FETCH);
    assert(Tokens[2].Type == ETokenType::SET);
    assert(Tokens[3].Type == ETokenType::INTERFACE);
    assert(Tokens[4].Type == ETokenType::NAMESPACE);
    assert(Tokens[5].Type == ETokenType::USING);
    assert(Tokens[6].Type == ETokenType::END_OF_FILE);

    std::cout << "Lexer Test 001: Passed\n\n";
}