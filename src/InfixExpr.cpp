#include "InfixExpr.h"

namespace NutnDS
{
    // Constructor.
    InfixExpr::InfixExpr() : expr(new ExprTokens)
    {
        // Empty.
    }

    InfixExpr::InfixExpr(string expr) : expr(&splitToTokens(expr))
    {
        // Empty.
    }

    InfixExpr::InfixExpr(const ExprTokens& expr) : expr(new ExprTokens(expr))
    {
        // Empty.
    }

    // Destructor.
    InfixExpr::~InfixExpr()
    {
        delete expr;
    }

    // Mutator.
    bool InfixExpr::setExpr(string expr)
    {
        string formatted = formatExpr(expr);

        if(formatted != "")
        {
            this->expr = &splitToTokens(formatted);
            
            return true;
        }
        else
            return false;
    }

    // Method.
    void InfixExpr::input()
    {
        /*
         *  Read an infix expression from keyboard
         *  and store it in class variable.
         */

        string inputExpr = "";
        bool isError = false;
        
        do
        {
            if(isError)
                cout << "Invalid characters in infix expression.\n\n";

            cout << "Please input an infix expression: ";
            getline(cin, inputExpr);

            inputExpr = formatExpr(inputExpr);

            if(inputExpr == "")
                isError = true;
            else
                isError = false;
        }
        while(isError);

        expr = &splitToTokens(inputExpr);
    }

    bool InfixExpr::isInvalidChar(char ch)
    {
        /*
         *  Check if parameter is an invalid infix expression char.
         */

        if(isDigit(ch) || isOperator(ch) || isParentheses(ch) || ch=='.')
            return false;
        else
            return true;
    }

    string InfixExpr::formatExpr(string expr)
    {
        /*
         *  Format infix expression by removing spaces.
         *  
         *  If any invalid character contains in expression,
         *  empty string is returned.
         */

        // Remove spaces.
        expr = removeChar(expr, ' ');

        // Check invalid character.
        for(int i=0, len=expr.length(); i<len; ++i)
        {
            if(isInvalidChar(expr.at(i)))
                return "";
        }

        return expr;
    }

    ExprTokens& InfixExpr::splitToTokens(string expr)
    {
        /*
         *  Split expression to tokens.
         */

        ExprTokens& tokens = *(new ExprTokens);

        // Format expression.
        expr = formatExpr(expr);

        // Split expression into tokens.
        for(int i=0, len=expr.length(); i<len; )
        {
            if(isOperator(expr.at(i)))  // Operator.
            {
                tokens.addToken(charToString(expr.at(i)));
                ++i;
            }
            else if(isParentheses(expr.at(i)))  // Parentheses.
            {
                tokens.addToken(charToString(expr.at(i)));
                ++i;
            }
            else if(isDigit(expr.at(i)))  // Number.
            {
                string extracted = charToString(expr.at(i));
                bool isFloat = false;

                for(int j=1; i+j<len; ++j)
                {
                    if(isDigit(expr.at(i+j)))
                        extracted += expr.at(i+j);
                    else if(expr.at(i+j) == '.')  // Float point.
                    {
                        if(!isFloat)  // First float point found.
                        {
                            isFloat = true;
                            extracted += expr.at(i+j);
                        }
                        else  // More than one float point in a float.
                        {
                            throw InvalidCharInExprException(expr.at(i+j));
                            return tokens;
                        }
                    }
                    else  // End of this number.
                    {
                        tokens.addToken(extracted);
                        extracted = "";
                        i += j;
                        break;
                    }
                }

                // This number is the end of expression.
                if(extracted != "")
                {
                    tokens.addToken(extracted);
                    break;
                }
            }
            else
            {
                throw InvalidCharInExprException(expr.at(i));
                return tokens;
            }
        }

        return tokens;
    }

    ExprTokens& InfixExpr::toPostfixTokens()
    {
        Stack<string>& st = *(new Stack<string>);
        ExprTokens& postfix = *(new ExprTokens);
        string tmp, token;

        for(int i=0, len=expr->getSize(); i<len; ++i)
        {
            token = expr->getToken(i);
            
            if(token == ")")
            {
                while((tmp=st.pop()) != "(")
                    postfix.addToken(tmp);
            }
            else if(token == "(")
                st.push(token);
            else if(ExprTokens::getOperatorOrder(token) < 0)  // Number.
                postfix.addToken(token);
            else if(ExprTokens::getOperatorOrder(token) >= 0)  // Operator.
            {
                // Pop low precedence operators.
                while(st.getSize()>0 && ExprTokens::getOperatorOrder(st.peek())>=ExprTokens::getOperatorOrder(token))
                    postfix.addToken(st.pop());

                st.push(token);
            }
            else  // Invalid token.
                throw InvalidCharInExprException();
        }

        while(st.getSize() != 0)
            postfix.addToken(st.pop());

        return postfix;
    }
}

