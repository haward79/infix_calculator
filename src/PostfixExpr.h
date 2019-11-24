#ifndef PostfixExpr_h

    #define PostfixExpr_h

    #include <math.h>
    #include <string>
    #include "ExprTokens.h"
    #include "Stack.h"

    using std::string;
    using NutnDS::ExprTokens;
    using NutnDS::Stack;

    namespace NutnDS
    {
        class PostfixExpr
        {
            public:
                // Constructor.
                PostfixExpr();
                PostfixExpr(const ExprTokens&);

                // Destructor.
                ~PostfixExpr();

                // Accessor.
                string getExpr() const { return expr->toString(); }
                string getSpacedExpr() const { return expr->toSpacedString(); }
                const ExprTokens& getTokens() const { return *expr; }

                // Mutator.
                bool setExpr(const ExprTokens&);

                // Method.
                double evaluate() const;

            private:
                // Variable.
                ExprTokens* expr;
        };
    }

#endif

