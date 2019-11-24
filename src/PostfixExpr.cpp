#include "PostfixExpr.h"

namespace NutnDS
{
    // Constructor.
    PostfixExpr::PostfixExpr() : expr(new ExprTokens)
    {
        // Empty.
    }

    PostfixExpr::PostfixExpr(const ExprTokens& expr) : expr(new ExprTokens(expr))
    {
        // Empty.
    }

    // Destructor.
    PostfixExpr::~PostfixExpr()
    {
        delete expr;
    }

    // Mutator.
    bool PostfixExpr::setExpr(const ExprTokens& expr)
    {
        return this->expr = new ExprTokens(expr);
    }

    // Method.
    double PostfixExpr::evaluate() const
    {
        /*
         *  Evaluate value of this expression.
         */

        Stack<string>& st = *(new Stack<string>);
        double num1=0, num2=0, result=0;

        while(expr->getSize() != 0)
        {
            switch(expr->getType(0))
            {
                case ExprTokenType::operator_:  // Operator.
                    num1 = std::stod(st.pop());
                    num2 = std::stod(st.pop());
                    
                    if(expr->getToken(0) == "+")
                        result = num2 + num1;
                    else if(expr->getToken(0) == "-")
                        result = num2 - num1;
                    else if(expr->getToken(0) == "*")
                        result = num2 * num1;
                    else if(expr->getToken(0) == "/")
                        result = num2 / num1;
                    else if(expr->getToken(0) == "%")
                        result = (int)num2 % (int)num1;
                    else if(expr->getToken(0) == "^")
                        result = pow(num2, num1);
                    else  // Invalid operator.
                        result = 0;
                    
                    st.push(*(new string(std::to_string(result))));

                    break;

                default:  // Number.
                    st.push(*(new string(expr->getToken(0))));
            }

            expr->removeToken(0);
        }

        return std::stod(st.pop());
    }
}

