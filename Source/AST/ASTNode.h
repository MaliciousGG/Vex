#pragma once

#include <string>
#include <vector>
#include <memory>

namespace Vex {
    class ASTVisitor;

    /**
     * Base class for all AST nodes
     * Every node can accept a visitor for traversal
     */
    class ASTNode {
    public:
        virtual ~ASTNode() = default;
        virtual void Accept(ASTVisitor& Visitor) = 0;
        virtual std::string ToString() const = 0;
    };

    enum class EAccessModifier {
        NONE,
        PUBLIC,
        PRIVATE,
        PROTECTED, 
        VIEW
    };

    std::string AccessModifierToString(EAccessModifier Modifier);

    /**
     * Represents a type reference in the AST
     * Can be simple (Int_32) or complex (Player.Health)
     * 
     * Examples:
     *   Int_32              -> Name: "Int_32", IsPointer: false
     *   Vector3             -> Name: "Vector3"
     *   Entity.Health       -> Name: "Entity", MemberPath: ["Health"]
     *   Float{Entity.Health}-> Name: "Float", AllowedFields: ["Entity.Health"]
     */
    struct TypeRef {
        std::string Name;                           // Base type name
        bool IsPointer = false;                     // Is this a pointer?
        bool IsUnique = false;                      // Unique ownership?
        bool IsShared = false;                      // Shared ownership?
        bool IsBorrow = false;                      // Borrowed reference?
        std::vector<std::string> MemberPath;        // For Entity.Health
        std::vector<std::string> AllowedFields;     // For Float{Entity.Health}
        
        TypeRef() = default;
        explicit TypeRef(const std::string& Name) : Name(Name) {}
        
        std::string ToString() const;
    };

    /**
     * Function parameter
     * Example: Amount: Int_32
     */
    struct Parameter {
        std::string Name;                           // Parameter name
        std::unique_ptr<TypeRef> Type;              // Parameter type
        std::unique_ptr<class Expression> DefaultValue; // Optional default
        
        Parameter(const std::string& Name, std::unique_ptr<TypeRef> Type)
            : Name(Name), Type(std::move(Type)) {}
        
        std::string ToString() const;
    };

    /**
     * Base class for all expressions.
     * Expressions evaluate to a value.
     */
    class Expression : public ASTNode {
    public:
        void Accept(ASTVisitor& Visitor) override = 0;
        std::string ToString() const override = 0;
    };

    /**
     * Base class for all top-level declarations.
     * (Define, Fetch, Set, Interface, Namespace, Function)
     */
    class Declaration : public ASTNode {
    public:
        void Accept(ASTVisitor& Visitor) override = 0;
        std::string ToString() const override = 0;
    };
}