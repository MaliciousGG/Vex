#include <iostream>
#include <cassert>

#include "../Lexer.h"

using namespace Vex;

void Test_Lexer_010_CompleteCode() {
    std::cout << "--- Lexer Test 010: Complete Code ---" << "\n";

    const std::string Code = R"(
        Define Entity {
        Public:
            Health -> Int_32;
            Name -> String;
        Private:
            bIsAlive -> Bool;
        }
        
        Fetch Entity {
            Fetch_Health() -> Entity.Health {
                return Entity.Health;
            }
        }
        
        Set Entity {
            Set_Health(Value: Int_32) -> Void {
                Health = Value;
            }
        }
    )";

    Lexer Lexer(Code);
    const auto Tokens = Lexer.Tokenize();

    assert(Tokens.size() > 0);


    bool bHasDefine = false;
    bool bHasFetch = false;
    bool bHasSet = false;
    bool bHasArrow = false;

    for (const auto& Token : Tokens) {
        if (Token.Type == ETokenType::DEFINE) { bHasDefine = true; }
        if (Token.Type == ETokenType::FETCH)  { bHasFetch = true;  }
        if (Token.Type == ETokenType::SET)    { bHasSet = true;    }
        if (Token.Type == ETokenType::ARROW)  { bHasArrow = true;  }
    }

    assert(bHasDefine == true);
    assert(bHasFetch == true);
    assert(bHasSet == true);
    assert(bHasArrow == true);

    std::cout << "Lexer Test 010: Passed\n\n";
}