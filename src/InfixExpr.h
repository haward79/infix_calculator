#ifndef InfixExpr_h
    
    #define InfixExpr_h
    
    #include <iostream>
    #include <string>
    #include "ExprTokens.h"
    #include "Stack.h"
    #include "InvalidCharInExprException.h"

    using std::cout;
    using std::cin;
    using std::string;
    using NutnDS_ExprTokens::ExprTokens;
    using NutnDS_Stack::Stack;

    namespace NutnDS_InfixExpr
    {
        class InfixExpr
        {
            public:
                // Constructor.
                InfixExpr();
                InfixExpr(string);
                InfixExpr(const ExprTokens&);

                // Destructor.
                ~InfixExpr();

                // Accessor.
                string getExpr() const { return expr->toString(); }
                string getSpacedExpr() const { return expr->toSpacedString(); }
                const ExprTokens& getTokens() const { return *expr; }

                // Mutator.
                bool setExpr(string expr);

                // Method.
                void input();
                static bool isInvalidChar(char);
                static string formatExpr(string expr);
                static ExprTokens& splitToTokens(string expr);
                ExprTokens& toPostfixTokens();

            private:
                // Variable.
                ExprTokens* expr;
        };
    }

#endif

