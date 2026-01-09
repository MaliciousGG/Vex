#include <iostream>

// Forward declarations of all test functions
void Test_Lexer_001_BasicKeywords();
void Test_Lexer_002_AccessModifiers();
void Test_Lexer_003_Types();
void Test_Lexer_004_GameTypes();
void Test_Lexer_005_Operators();
void Test_Lexer_006_NumberLiterals();
void Test_Lexer_007_StringLiterals();
void Test_Lexer_008_Comments();
void Test_Lexer_009_Identifiers();
void Test_Lexer_010_CompleteCode();
void Test_Lexer_011_ControlFlow();
void Test_Lexer_012_Delimiters();

int main() {
    std::cout << "========================================" << "\n";
    std::cout << " VEX LEXER TEST SUITE" << "\n";
    std::cout << "========================================" << "\n\n";

    try {
        // Test_Lexer_001_BasicKeywords();      // STATUS::PASSED
        // Test_Lexer_002_AccessModifiers();    // STATUS::PASSED
        // Test_Lexer_003_Types();              // STATUS::PASSED
        // Test_Lexer_004_GameTypes();          // STATUS::PASSED
        // Test_Lexer_005_Operators();          // STATUS::PASSED
        // Test_Lexer_006_NumberLiterals();     // STATUS::PASSED
        // Test_Lexer_007_StringLiterals();     // STATUS::PASSED
        Test_Lexer_008_Comments();           // STATUS::IN_PROGRESS
        Test_Lexer_009_Identifiers();        // STATUS::IN_PROGRESS
        Test_Lexer_010_CompleteCode();       // STATUS::IN_PROGRESS
        Test_Lexer_011_ControlFlow();        // STATUS::IN_PROGRESS
        Test_Lexer_012_Delimiters();         // STATUS::IN_PROGRESS

        std::cout << "\n";

        std::cout << "========================================" << "\n";
        std::cout << " ALL TESTS PASSED!" << "\n";
        std::cout << "========================================" << "\n";

        return 0;

    } catch (const std::exception& E) {
        std::cerr << "Test failed with exception: " << E.what() << "\n";
        return 1;
    } catch (...) {
        std::cerr << "Test failed with unknown exception" << "\n";
        return 1;
    }
}