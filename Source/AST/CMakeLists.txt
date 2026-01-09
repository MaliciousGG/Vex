cmake_minimum_required(VERSION 3.10)

# Lexer library
add_library(Vex.AST STATIC
    ASTNode.h
)

# Make headers available to other targets
target_include_directories(Vex.AST PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Lexer test executable - combines test runner and all test files
#add_executable(Test.AST
#
#)

target_link_libraries(Test.AST PRIVATE
        Vex.AST
)

# Add test
add_test(NAME ASTTest COMMAND Test.AST)

# Installation
install(TARGETS Vex.AST
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
)

install(FILES ASTNode.h
        DESTINATION include/vex/ast
)

install(TARGETS Test.AST
        RUNTIME DESTINATION bin
)