#include <iostream>

// Forward declarations of all test functions
void Test_Lexer_001_BasicKeywords();
void Test_Lexer_002_AccessModifiers();
void Test_Lexer_003_Types();
void Test_Lexer_004_GameTypes();
void Test_Lexer_005_Operators();

int main() {
    std::cout << "========================================" << "\n";
    std::cout << " VEX LEXER TEST SUITE" << "\n";
    std::cout << "========================================" << "\n\n";

    try {
        Test_Lexer_001_BasicKeywords();      // STATUS::PASSED
        Test_Lexer_002_AccessModifiers();    // STATUS::PASSED
        Test_Lexer_003_Types();              // STATUS::PASSED
        Test_Lexer_004_GameTypes();          // STATUS::PASSED
        Test_Lexer_005_Operators();             // STATUS::IN PROGRESS
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