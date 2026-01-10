#pragma once

#include "ASTNode.h"
#include <vector>
#include <memory>

namespace Vex {

    // ============================================================================
    // BINARY OPERATORS
    // ============================================================================

    enum class EBinaryOp {
        // Arithmetic
        Add,            // +
        Subtract,       // -
        Multiply,       // *
        Divide,         // /
        Modulo,         // %
        Power,          // **

        // Comparison
        Equal,          // ==
        NotEqual,       // !=
        TypeValueEq,    // ===
        TypeValueNeq,   // !==
        Less,           // <
        Greater,        // >
        LessEqual,      // <=
        GreaterEqual,   // >=

        // Logical
        LogicalAnd,     // &&
        LogicalOr,      // ||

        // Bitwise
        BitwiseAnd,     // &
        BitwiseOr,      // |
        BitwiseXor,     // ^
        LeftShift,      // <<
        RightShift,     // >>

        // Range
        Range,          // ..
        RangeInclusive, // ..=

        // Null coalescing
        NullCoalesce,   // ??
    };

    std::string BinaryOpToString(EBinaryOp Op);

    // ============================================================================
    // UNARY OPERATORS
    // ============================================================================

    enum class EUnaryOp {
        Plus,           // +x
        Minus,          // -x
        LogicalNot,     // !x
        BitwiseNot,     // ~x
    };

    std::string UnaryOpToString(EUnaryOp Op);

    // ============================================================================
    // LITERAL EXPRESSIONS
    // ============================================================================

    /**
     * Integer literal: 42, 1000
     */
    class IntegerLiteral : public Expression {
    public:
        long long Value;

        explicit IntegerLiteral(long long Value) : Value(Value) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    /**
     * Float literal: 3.14, 100.0
     */
    class FloatLiteral : public Expression {
    public:
        double Value;

        explicit FloatLiteral(double Value) : Value(Value) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    /**
     * String literal: "Hello World"
     */
    class StringLiteral : public Expression {
    public:
        std::string Value;

        explicit StringLiteral(const std::string& Value) : Value(Value) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    /**
     * Character literal: 'A'
     */
    class CharLiteral : public Expression {
    public:
        char Value;

        explicit CharLiteral(char Value) : Value(Value) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    /**
     * Boolean literal: true, false
     */
    class BoolLiteral : public Expression {
    public:
        bool Value;

        explicit BoolLiteral(bool Value) : Value(Value) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    /**
     * Null literal: null
     */
    class NullLiteral : public Expression {
    public:
        NullLiteral() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // IDENTIFIER
    // ============================================================================

    /**
     * Identifier: Health, Player, X
     */
    class Identifier : public Expression {
    public:
        std::string Name;

        explicit Identifier(const std::string& Name) : Name(Name) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // BINARY EXPRESSION
    // ============================================================================

    /**
     * Binary operation: Left Op Right
     * Examples: X + Y, Health == 0, A && B
     */
    class BinaryExpression : public Expression {
    public:
        std::unique_ptr<Expression> Left;
        EBinaryOp Op;
        std::unique_ptr<Expression> Right;

        BinaryExpression(
            std::unique_ptr<Expression> Left,
            EBinaryOp Op,
            std::unique_ptr<Expression> Right
        ) : Left(std::move(Left)), Op(Op), Right(std::move(Right)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // UNARY EXPRESSION
    // ============================================================================

    /**
     * Unary operation: Op Operand
     * Examples: -X, !IsAlive, ~Flags
     */
    class UnaryExpression : public Expression {
    public:
        EUnaryOp Op;
        std::unique_ptr<Expression> Operand;

        UnaryExpression(EUnaryOp Op, std::unique_ptr<Expression> Operand)
            : Op(Op), Operand(std::move(Operand)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // FUNCTION CALL
    // ============================================================================

    /**
     * Function call: Function(Arg1, Arg2, ...)
     * Examples: TakeDamage(10), Print("Hello")
     */
    class FunctionCall : public Expression {
    public:
        std::unique_ptr<Expression> Callee;                     // Function being called
        std::vector<std::unique_ptr<Expression>> Arguments;     // Arguments

        explicit FunctionCall(std::unique_ptr<Expression> Callee)
            : Callee(std::move(Callee)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // MEMBER ACCESS
    // ============================================================================

    /**
     * Member access: Object.Member
     * Examples: Player.Health, Entity.Position.X
     */
    class MemberAccess : public Expression {
    public:
        std::unique_ptr<Expression> Object;
        std::string Member;

        MemberAccess(std::unique_ptr<Expression> Object, const std::string& Member)
            : Object(std::move(Object)), Member(Member) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // INDEX ACCESS
    // ============================================================================

    /**
     * Array/index access: Object[Index]
     * Examples: Array[0], Map["Key"]
     */
    class IndexAccess : public Expression {
    public:
        std::unique_ptr<Expression> Object;
        std::unique_ptr<Expression> Index;

        IndexAccess(
            std::unique_ptr<Expression> Object,
            std::unique_ptr<Expression> Index
        ) : Object(std::move(Object)), Index(std::move(Index)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // TERNARY EXPRESSION
    // ============================================================================

    /**
     * Ternary/conditional: Condition ? TrueExpr : FalseExpr
     * Example: X > 0 ? X : -X
     */
    class TernaryExpression : public Expression {
    public:
        std::unique_ptr<Expression> Condition;
        std::unique_ptr<Expression> TrueExpr;
        std::unique_ptr<Expression> FalseExpr;

        TernaryExpression(
            std::unique_ptr<Expression> Condition,
            std::unique_ptr<Expression> TrueExpr,
            std::unique_ptr<Expression> FalseExpr
        ) : Condition(std::move(Condition)),
            TrueExpr(std::move(TrueExpr)),
            FalseExpr(std::move(FalseExpr)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // CAST EXPRESSION
    // ============================================================================

    /**
     * Type cast: Expression as Type
     * Example: Value as Int_32
     */
    class CastExpression : public Expression {
    public:
        std::unique_ptr<Expression> Expr;
        std::unique_ptr<TypeRef> Type;

        CastExpression(
            std::unique_ptr<Expression> Expr,
            std::unique_ptr<TypeRef> Type
        ) : Expr(std::move(Expr)), Type(std::move(Type)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // NEW EXPRESSION
    // ============================================================================

    /**
     * Object creation: new Type()
     * Examples: new Player(), new Vector3(1, 2, 3)
     */
    class NewExpression : public Expression {
    public:
        std::unique_ptr<TypeRef> Type;
        std::vector<std::unique_ptr<Expression>> Arguments;

        explicit NewExpression(std::unique_ptr<TypeRef> Type)
            : Type(std::move(Type)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // THIS EXPRESSION
    // ============================================================================

    /**
     * This keyword: this
     */
    class ThisExpression : public Expression {
    public:
        ThisExpression() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // SUPER EXPRESSION
    // ============================================================================

    /**
     * Super keyword: super
     */
    class SuperExpression : public Expression {
    public:
        SuperExpression() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // GROUPING EXPRESSION
    // ============================================================================

    /**
     * Parenthesized expression: (Expression)
     * Example: (X + Y) * Z
     */
    class GroupingExpression : public Expression {
    public:
        std::unique_ptr<Expression> Expr;

        explicit GroupingExpression(std::unique_ptr<Expression> Expr)
            : Expr(std::move(Expr)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

} // namespace Vex