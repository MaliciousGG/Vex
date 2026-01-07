#include <iostream>

// Forward declarations of all test functions
void Test_Lexer_001_BasicKeywords();
void Test_Lexer_002_AccessModifiers();
void Test_Lexer_003_Types();
void Test_Lexer_004_GameTypes();

int main() {
    std::cout << "========================================" << "\n";
    std::cout << " VEX LEXER TEST SUITE" << "\n";
    std::cout << "========================================" << "\n\n";

    try {
        Test_Lexer_001_BasicKeywords();
        Test_Lexer_002_AccessModifiers();
        Test_Lexer_003_Types();
        Test_Lexer_004_GameTypes();
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