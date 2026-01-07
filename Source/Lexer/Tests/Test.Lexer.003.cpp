#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_003_Types() {
    std::cout << "--- Lexer Test 003: Type Keywords ---" << '\n';

    const std::string Code = "Int_8 Int_16 Int_32 Int_64 Uint_8 Float_32 Bool String";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    assert(Tokens.size() == 9);

    assert(Tokens[0].Type == ETokenType::INT8);
    assert(Tokens[1].Type == ETokenType::INT16);
    assert(Tokens[2].Type == ETokenType::INT32);
    assert(Tokens[3].Type == ETokenType::INT64);
    assert(Tokens[4].Type == ETokenType::UINT8);
    assert(Tokens[5].Type == ETokenType::FLOAT32);
    assert(Tokens[6].Type == ETokenType::BOOL);
    assert(Tokens[7].Type == ETokenType::STRING);

    std::cout << "Lexer Test 003: Passed\n\n";
}