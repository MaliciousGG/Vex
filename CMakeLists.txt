cmake_minimum_required(VERSION 3.10)
project(VexCompiler VERSION 1.0.0 LANGUAGES CXX)

# ==================== Project Configuration ====================

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Binaries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Library)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Library)

# ==================== Compiler Options ====================

# Enable warnings
if(MSVC)
    add_compile_options(/W4)
    # Optionally treat warnings as errors: /WX
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    # Optionally treat warnings as errors: -Werror
endif()

# ==================== Build Configuration ====================

# Default to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# ==================== Subdirectories ====================

# Add subdirectories in dependency order
add_subdirectory(Source/Lexer)

# Future subdirectories:
# add_subdirectory(Source/AST)
# add_subdirectory(Source/Parser)
# add_subdirectory(Source/SemanticAnalyzer)
# add_subdirectory(Source/CodeGen)
# add_subdirectory(Source/Compiler)

# ==================== Testing ====================

# Enable testing
enable_testing()

# Tests are added by subdirectories via add_test()
# Run with: ctest or make test

# ==================== Documentation ====================

# Find Doxygen (optional)
find_package(Doxygen QUIET)

if(DOXYGEN_FOUND)
    message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE}")
    
    # Configure Doxygen
    set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Docs)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_GENERATE_MAN NO)
    
    # Add documentation target
    doxygen_add_docs(docs
        ${CMAKE_SOURCE_DIR}/Source/Lexer
        ${CMAKE_SOURCE_DIR}/Source/AST
        ${CMAKE_SOURCE_DIR}/Source/Parser
        COMMENT "Generating API documentation with Doxygen"
    )
else()
    message(STATUS "Doxygen not found - documentation target unavailable")
endif()

# ==================== Project Summary ====================

message(STATUS "")
message(STATUS "========================================")
message(STATUS "Vex Compiler Configuration Summary")
message(STATUS "========================================")
message(STATUS "")
message(STATUS "Project:")
message(STATUS "  Name: ${PROJECT_NAME}")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "")
message(STATUS "Compiler:")
message(STATUS "  ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Version: ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "")
message(STATUS "Components:")
message(STATUS "  ✓ Lexer     (Tokenization)")
message(STATUS "  - AST       (Abstract Syntax Tree)")
message(STATUS "  - Parser    (Syntax Analysis)")
message(STATUS "  - Semantic  (Not yet implemented)")
message(STATUS "  - CodeGen   (Not yet implemented)")
message(STATUS "")
message(STATUS "Output Directories:")
message(STATUS "  Binaries: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "  Libraries: ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(STATUS "")
message(STATUS "Installation Prefix:")
message(STATUS "  ${CMAKE_INSTALL_PREFIX}")
message(STATUS "")
message(STATUS "Testing:")
message(STATUS "  Enabled: Yes")
message(STATUS "  Run with: ctest or make test")
message(STATUS "")

if(DOXYGEN_FOUND)
    message(STATUS "Documentation:")
    message(STATUS "  Generate with: make docs")
    message(STATUS "  Output: ${DOXYGEN_OUTPUT_DIRECTORY}")
    message(STATUS "")
endif()

message(STATUS "========================================")
message(STATUS "")
message(STATUS "To build:")
message(STATUS "  make")
message(STATUS "")
message(STATUS "To test:")
message(STATUS "  ctest")
message(STATUS "  or")
message(STATUS "  ./Binaries/Test.Lexer")
message(STATUS "")
message(STATUS "To install:")
message(STATUS "  make install")
message(STATUS "")
message(STATUS "========================================")
message(STATUS "")