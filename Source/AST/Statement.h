#pragma once

#include "ASTNode.h"
#include "Expression.h"
#include <vector>
#include <memory>

namespace Vex {

    // ============================================================================
    // VARIABLE DECLARATION
    // ============================================================================

    /**
     * Variable declaration
     * Examples:
     *   Var X = 10;
     *   Let Name: String = "Player";
     *   Const MaxHealth: Int_32 = 100;
     */
    class VariableDeclaration : public Statement {
    public:
        bool IsConst;                               // Const vs Var/Let
        bool IsLet;                                 // Let vs Var
        std::string Name;                           // Variable name
        std::unique_ptr<TypeRef> Type;              // Optional type annotation
        std::unique_ptr<Expression> Initializer;    // Optional initializer

        VariableDeclaration(
            bool IsConst,
            bool IsLet,
            const std::string& Name,
            std::unique_ptr<TypeRef> Type = nullptr,
            std::unique_ptr<Expression> Initializer = nullptr
        ) : IsConst(IsConst),
            IsLet(IsLet),
            Name(Name),
            Type(std::move(Type)),
            Initializer(std::move(Initializer)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // EXPRESSION STATEMENT
    // ============================================================================

    /**
     * Expression as statement
     * Examples:
     *   TakeDamage(10);
     *   X = 5;
     *   Print("Hello");
     */
    class ExpressionStatement : public Statement {
    public:
        std::unique_ptr<Expression> Expr;

        explicit ExpressionStatement(std::unique_ptr<Expression> Expr)
            : Expr(std::move(Expr)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // BLOCK STATEMENT
    // ============================================================================

    /**
     * Block of statements: { Statement1; Statement2; ... }
     */
    class BlockStatement : public Statement {
    public:
        std::vector<std::unique_ptr<Statement>> Statements;

        BlockStatement() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // IF STATEMENT
    // ============================================================================

    /**
     * If statement with optional else
     * Examples:
     *   if X > 0 { DoSomething(); }
     *   if Health <= 0 { Die(); } else { Live(); }
     *   if X { A(); } else if Y { B(); } else { C(); }
     */
    class IfStatement : public Statement {
    public:
        std::unique_ptr<Expression> Condition;
        std::unique_ptr<Statement> ThenBranch;
        std::unique_ptr<Statement> ElseBranch;      // Optional

        IfStatement(
            std::unique_ptr<Expression> Condition,
            std::unique_ptr<Statement> ThenBranch,
            std::unique_ptr<Statement> ElseBranch = nullptr
        ) : Condition(std::move(Condition)),
            ThenBranch(std::move(ThenBranch)),
            ElseBranch(std::move(ElseBranch)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // WHILE STATEMENT
    // ============================================================================

    /**
     * While loop
     * Example: while IsRunning { Update(); }
     */
    class WhileStatement : public Statement {
    public:
        std::unique_ptr<Expression> Condition;
        std::unique_ptr<Statement> Body;

        WhileStatement(
            std::unique_ptr<Expression> Condition,
            std::unique_ptr<Statement> Body
        ) : Condition(std::move(Condition)), Body(std::move(Body)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // DO-WHILE STATEMENT
    // ============================================================================

    /**
     * Do-while loop
     * Example: do { Update(); } while IsRunning;
     */
    class DoWhileStatement : public Statement {
    public:
        std::unique_ptr<Statement> Body;
        std::unique_ptr<Expression> Condition;

        DoWhileStatement(
            std::unique_ptr<Statement> Body,
            std::unique_ptr<Expression> Condition
        ) : Body(std::move(Body)), Condition(std::move(Condition)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // FOR STATEMENT
    // ============================================================================

    /**
     * For loop with range
     * Examples:
     *   for I in 0..10 { Print(I); }
     *   for I in 0..=100 step 10 { SpawnEnemy(I); }
     */
    class ForStatement : public Statement {
    public:
        std::string Iterator;                       // Loop variable
        std::unique_ptr<Expression> RangeStart;     // Start of range
        std::unique_ptr<Expression> RangeEnd;       // End of range
        bool IsInclusive;                           // .. vs ..=
        std::unique_ptr<Expression> Step;           // Optional step
        std::unique_ptr<Statement> Body;

        ForStatement(
            const std::string& Iterator,
            std::unique_ptr<Expression> RangeStart,
            std::unique_ptr<Expression> RangeEnd,
            bool IsInclusive,
            std::unique_ptr<Statement> Body,
            std::unique_ptr<Expression> Step = nullptr
        ) : Iterator(Iterator),
            RangeStart(std::move(RangeStart)),
            RangeEnd(std::move(RangeEnd)),
            IsInclusive(IsInclusive),
            Step(std::move(Step)),
            Body(std::move(Body)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // RETURN STATEMENT
    // ============================================================================

    /**
     * Return statement
     * Examples:
     *   return;
     *   return 42;
     *   return Health * 2;
     */
    class ReturnStatement : public Statement {
    public:
        std::unique_ptr<Expression> Value;          // Optional return value

        explicit ReturnStatement(std::unique_ptr<Expression> Value = nullptr)
            : Value(std::move(Value)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // BREAK STATEMENT
    // ============================================================================

    /**
     * Break statement: break;
     */
    class BreakStatement : public Statement {
    public:
        BreakStatement() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // CONTINUE STATEMENT
    // ============================================================================

    /**
     * Continue statement: continue;
     */
    class ContinueStatement : public Statement {
    public:
        ContinueStatement() = default;

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

    // ============================================================================
    // MATCH STATEMENT
    // ============================================================================

    /**
     * Match case in match statement
     * Example: WeaponType.Sword -> Damage = 50.0
     */
    struct MatchCase {
        std::unique_ptr<Expression> Pattern;        // Pattern to match
        std::unique_ptr<Statement> Body;            // Code to execute

        MatchCase(
            std::unique_ptr<Expression> Pattern,
            std::unique_ptr<Statement> Body
        ) : Pattern(std::move(Pattern)), Body(std::move(Body)) {}
    };

    /**
     * Match statement (pattern matching)
     * Example:
     *   match WeaponType {
     *       WeaponType.Sword -> Damage = 50.0
     *       WeaponType.Bow -> Damage = 35.0
     *       _ -> Damage = 10.0
     *   }
     */
    class MatchStatement : public Statement {
    public:
        std::unique_ptr<Expression> Value;          // Value to match against
        std::vector<MatchCase> Cases;               // Match cases

        explicit MatchStatement(std::unique_ptr<Expression> Value)
            : Value(std::move(Value)) {}

        void Accept(ASTVisitor& Visitor) override;
        std::string ToString() const override;
    };

} // namespace Vex