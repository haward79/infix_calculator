#include "ExprTokens.h"

namespace NutnDS_ExprTokens
{
    // Constructor.
    ExprTokens::ExprTokens() : size(0)
    {
        // Empty.
    }

    ExprTokens::ExprTokens(const ExprTokens& obj)
    {
        size = obj.size;

        for(int i=0; i<size; ++i)
        {
            tokens[i] = obj.tokens[i];
            types[i] = obj.types[i];
        }
    }

    // Accessor.
    string ExprTokens::getToken(int index) const
    {
        if(index>=0 && index<size)
            return tokens[index];
        else
        {
            throw OutOfIndexException(index);
            return "";
        }
    }

    ExprTokenType ExprTokens::getType(int index) const
    {
        if(index>=0 && index<size)
            return types[index];
        else
        {
            throw OutOfIndexException(index);
            return unknown;
        }
    }

    // Mutator.
    bool ExprTokens::addToken(string token)
    {
        if(size < kMaxToken)
        {
            tokens[size] = token;
            types[size] = whichType(token);
            ++size;

            return true;
        }
        else
            return false;
    }

    bool ExprTokens::addToken(int index, string token)
    {
        if(index>=0 && index<=size && size<kMaxToken)
        {
            if(index == size)
                return addToken(token);
            else
            {
                for(int i=size; i>index; ++i)
                {
                    token[i] = token[i-1];
                    types[i] = types[i-1];
                }

                tokens[index] = token;
                types[index] = whichType(token);

                return true;
            }
        }
        else
            return false;
    }

    bool ExprTokens::removeToken()
    {
        /*
         *  Remove last token from token array.
         */

        if(size > 0)
        {
            --size;
            return true;
        }
        else
            return false;
    }

    bool ExprTokens::removeToken(int index)
    {
        if(index>=0 && index<size)
        {
            // Move data forward after deleted data.
            for(int i=index+1; i<size; ++i)
            {
                tokens[i-1] = tokens[i];
                types[i-1] = types[i];
            }
            --size;

            return true;
        }
        else
            return false;
    }

    // Method.
    void ExprTokens::clear()
    {
        size = 0;
    }

    void ExprTokens::print() const
    {
        cout << "\n>> " << std::to_string(size) << " tokens in total\n";

        for(int i=0; i<size; ++i)
            cout << std::setw(10) << std::left << tokens[i] << " | " << NutnDS_ExprTokens::ExprTokens::getTypeName(types[i]) << "\n";

        cout << "\n";
    }

    string ExprTokens::toString() const
    {
        string expr = "";

        // Generate expression by tokens.
        for(int i=0; i<size; ++i)
            expr += tokens[i];

        return expr;
    }

    string ExprTokens::toSpacedString() const
    {
        string expr = "";

        // Generate expression by tokens.
        for(int i=0; i<size; ++i)
            expr += " " + tokens[i];

        // Remove first space char.
        if(expr != "")
            expr = expr.substr(1);

        return expr;
    }

    string ExprTokens::getTypeName(ExprTokenType type)
    {
        switch(type)
        {
            case posInteger:
                return "Positive integer";

            case float_:
                return "Float";

            case operator_:
                return "Operator";

            case parentheses:
                return "Parentheses";

            default:
                return "Unknown";
        }
    }
    
    ExprTokenType ExprTokens::whichType(string token)
    {
        /*
         *  Determine which type token is.
         */

        if(isOperator(token))  // Operator.
            return operator_;
        else if(isParentheses(token))  // Parentheses.
            return parentheses;
        else  // Number.
        {
            if(isNumber(token))  // Positive integer.
                return posInteger;
            else
            {
                int pos = 0;  // Store position of float point.
                
                if(pos=token.find('.') != string::npos)
                {
                    if(isNumber(token.erase(pos)) && token.at(token.length()-1)!='.')  // Float.
                        return float_;
                    else  // Invalid token.
                        return unknown;
                }
                else  // Invalid token.
                    return unknown;
            }
        }
    }

    int ExprTokens::getOperatorOrder(string op)
    {
        /*
         *  Return operator precedence number.
         */

        if(op=="+" || op=="-")
            return 0;
        else if(op=="*" || op=="/" || op=="%")
            return 1;
        else if(op == "^")
            return 2;
        else  // Invalid operator.
            return -1;
    }
}

