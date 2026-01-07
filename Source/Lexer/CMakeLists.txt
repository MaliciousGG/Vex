cmake_minimum_required(VERSION 3.10)

# Lexer library
add_library(Vex.Lexer STATIC
        Token.cpp
        Token.h
        Lexer.cpp
        Lexer.h
        TokenEnums.h
)

# Make headers available to other targets
target_include_directories(Vex.Lexer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Lexer test executable - combines all test files
add_executable(Test.Lexer
        Test.Lexer.cpp
        Tests/Test.Lexer.001.cpp
        Tests/Test.Lexer.002.cpp
        Tests/Test.Lexer.003.cpp
        Tests/Test.Lexer.004.cpp
        Tests/Test.Lexer.005.cpp
)

target_link_libraries(Test.Lexer PRIVATE
        Vex.Lexer
)

# Add test
add_test(NAME LexerTest COMMAND Test.Lexer)

# Installation
install(TARGETS Vex.Lexer
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

install(FILES Token.h Lexer.h TokenEnums.h
        DESTINATION include/vex/lexer
)

install(TARGETS Test.Lexer
        RUNTIME DESTINATION bin
)