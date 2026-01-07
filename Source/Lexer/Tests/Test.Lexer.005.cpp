#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_005_Operators() {
    std::cout << "--- Lexer Test 005: Operators ---" << '\n';

    const std::string Code = "+ - * / % ** "
                         R"(= += -= *= /= %= )"
                         R"(== === != !== < > <= >= )"
                         R"(&& || ! )"
                         R"(& | ^ ~ << >> )"
                         R"(-> . .. ..= ? ?. ?? : :: ; , # @ )";
    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    for (const auto & Token : Tokens) {
        std::cout << Token.ToString() << "\n";
    }

    assert(Tokens.size() == 43);

    assert(Tokens[0].Type == ETokenType::PLUS);
    assert(Tokens[1].Type == ETokenType::MINUS);
    assert(Tokens[2].Type == ETokenType::STAR);
    assert(Tokens[3].Type == ETokenType::SLASH);
    assert(Tokens[4].Type == ETokenType::PERCENT);
    assert(Tokens[5].Type == ETokenType::POWER);

    assert(Tokens[6].Type == ETokenType::ASSIGN);
    assert(Tokens[7].Type == ETokenType::PLUS_ASSIGN);
    assert(Tokens[8].Type == ETokenType::MINUS_ASSIGN);
    assert(Tokens[9].Type == ETokenType::STAR_ASSIGN);
    assert(Tokens[10].Type == ETokenType::SLASH_ASSIGN);
    assert(Tokens[11].Type == ETokenType::PERCENT_ASSIGN);

    assert(Tokens[12].Type == ETokenType::EQUAL);
    assert(Tokens[13].Type == ETokenType::TYPE_VAL_EQ);
    assert(Tokens[14].Type == ETokenType::NOT_EQUAL);
    assert(Tokens[15].Type == ETokenType::TYPE_VAL_NEQ);
    assert(Tokens[16].Type == ETokenType::LESS);
    assert(Tokens[17].Type == ETokenType::GREATER);
    assert(Tokens[18].Type == ETokenType::LESS_EQUAL);
    assert(Tokens[19].Type == ETokenType::GREATER_EQUAL);

    assert(Tokens[20].Type == ETokenType::AND);
    assert(Tokens[21].Type == ETokenType::OR);
    assert(Tokens[22].Type == ETokenType::NOT);

    assert(Tokens[23].Type == ETokenType::BITWISE_AND);
    assert(Tokens[24].Type == ETokenType::BITWISE_OR);
    assert(Tokens[25].Type == ETokenType::BITWISE_XOR);
    assert(Tokens[26].Type == ETokenType::BITWISE_NOT);
    assert(Tokens[27].Type == ETokenType::LEFT_SHIFT);
    assert(Tokens[28].Type == ETokenType::RIGHT_SHIFT);

    assert(Tokens[29].Type == ETokenType::ARROW);
    assert(Tokens[30].Type == ETokenType::DOT);
    assert(Tokens[31].Type == ETokenType::DOUBLE_DOT);
    assert(Tokens[32].Type == ETokenType::DOT_DOT_EQUAL);
    assert(Tokens[33].Type == ETokenType::QUESTION);
    assert(Tokens[34].Type == ETokenType::QUESTION_DOT);
    assert(Tokens[35].Type == ETokenType::DOUBLE_QUESTION);
    assert(Tokens[36].Type == ETokenType::COLON);
    assert(Tokens[37].Type == ETokenType::DOUBLE_COLON);
    assert(Tokens[38].Type == ETokenType::SEMICOLON);
    assert(Tokens[39].Type == ETokenType::COMMA);
    assert(Tokens[40].Type == ETokenType::HASH);
    assert(Tokens[41].Type == ETokenType::AT);

    std::cout << "Lexer Test 005: Passed\n\n";
}