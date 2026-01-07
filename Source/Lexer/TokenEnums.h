#pragma once

namespace Vex {
    enum class ETokenType {
        // Keywords
        DEFINE,             // Class & Struct variable declaration
        FETCH,              // Class & Struct getter declaration
        SET,                // Class & Struct setter declaration
        INTERFACE,
        NAMESPACE,          // Namespace declaration
        USING,              // Include and forward declaration 
        
        // Access modifiers
        PUBLIC,
        PRIVATE,
        PROTECTED,
        VIEW,
        
        // Type keywords
        STRUCT,
        CLASS,
        REF,
        ENUM,
        
        // Control flow
        IF,
        ELSE,
        FOR,
        WHILE,
        DO,
        MATCH,
        BREAK,
        CONTINUE,
        RETURN,
        
        // Memory keywords
        UNIQUE,
        SHARED,
        BORROW,
        RAW,
        UNSAFE,
        
        // Variable keywords
        VAR,
        LET,
        CONST,
        STATIC,
        
        // Function keywords
        OVERRIDE,
        VIRTUAL,
        IMPLEMENT,
        OPERATOR,
        
        // Boolean literals
        TRUE,
        FALSE,
        
        // Other keywords
        NEW,
        AS,
        IS,
        IN,
        STEP,
        SUPER,
        THIS,
        GLOBAL,
        NULL_KEY, // Can't use NULL as it's a keyword
        
        // Primitive types
        INT8, 
        INT16, 
        INT32, 
        INT64,
        UINT8, 
        UINT16, 
        UINT32, 
        UINT64,
        FLOAT32, 
        FLOAT64,
        INT, 
        UINT, 
        FLOAT, 
        DOUBLE,
        BOOL, 
        CHAR, 
        STRING,
        VOID,
        
        // Game types
        VECTOR2, 
        VECTOR3, 
        VECTOR4,
        QUATERNION, 
        COLOR, 
        TRANSFORM,
        
        // Identifiers and literals
        IDENTIFIER,
        INTEGER_LITERAL,
        FLOAT_LITERAL,
        STRING_LITERAL,
        CHAR_LITERAL,
        
        // Operators
        PLUS,           // +
        MINUS,          // -
        STAR,           // *
        SLASH,          // /
        PERCENT,        // %
        POWER,          // **
        
        ASSIGN,         // =
        PLUS_ASSIGN,    // +=
        MINUS_ASSIGN,   // -=
        STAR_ASSIGN,    // *=
        SLASH_ASSIGN,   // /=
        PERCENT_ASSIGN, // %=
        
        EQUAL,          // ==
        TYPE_VAL_EQ,    // ===  // FIXED: Added comma
        NOT_EQUAL,      // !=
        TYPE_VAL_NEQ,   // !==  // FIXED: Added comma
        LESS,           // <
        GREATER,        // >
        LESS_EQUAL,     // <=
        GREATER_EQUAL,  // >=
        
        AND,            // &&
        OR,             // ||
        NOT,            // !
        
        BITWISE_AND,    // &
        BITWISE_OR,     // |
        BITWISE_XOR,    // ^
        BITWISE_NOT,    // ~
        LEFT_SHIFT,     // <<
        RIGHT_SHIFT,    // >>
        
        ARROW,          // ->
        DOT,            // .
        DOUBLE_DOT,     // ..
        DOT_DOT_EQUAL,  // ..=
        QUESTION,       // ?
        QUESTION_DOT,   // ?.
        DOUBLE_QUESTION,// ??
        COLON,          // :
        DOUBLE_COLON,   // ::
        SEMICOLON,      // ;
        COMMA,          // ,
        HASH,           // #
        AT,             // @
        UNDERSCORE,     // _
        
        // Delimiters
        LEFT_PAREN,     // (
        RIGHT_PAREN,    // )
        LEFT_BRACE,     // {
        RIGHT_BRACE,    // }
        LEFT_BRACKET,   // [
        RIGHT_BRACKET,  // ]
        
        // Special
        END_OF_FILE,
        UNKNOWN
    };
}