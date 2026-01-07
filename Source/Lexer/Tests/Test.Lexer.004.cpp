#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_004_GameTypes() {
    std::cout << "--- Lexer Test 004: Game Type Keywords ---" << '\n';

    const std::string Code = "Vector2 Vector3 Vector4 Quat Color Transform";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto& Token : Tokens) {
        std::cout << Token.ToString() << '\n';
    }

    assert(Tokens.size() == 7);

    assert(Tokens[0].Type == ETokenType::VECTOR2);
    assert(Tokens[1].Type == ETokenType::VECTOR3);
    assert(Tokens[2].Type == ETokenType::VECTOR4);
    assert(Tokens[3].Type == ETokenType::QUATERNION);
    assert(Tokens[4].Type == ETokenType::COLOR);
    assert(Tokens[5].Type == ETokenType::TRANSFORM);

    std::cout << "Lexer Test 004: Passed\n\n";
}