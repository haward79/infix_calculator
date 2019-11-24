#include "ExprTokens.h"

namespace NutnDS
{
    // Constructor.
    ExprTokens::ExprTokens() : tokens(*(new LinkedList<string>)), types(*(new LinkedList<ExprTokenType>))
    {
        // Empty.
    }

    ExprTokens::ExprTokens(const ExprTokens& obj) : tokens(*(new LinkedList<string>(&obj.tokens))), types(*(new LinkedList<ExprTokenType>(&obj.types)))
    {
        // Empty.
    }

    // Destructor.
    ExprTokens::~ExprTokens()
    {
        delete &tokens;
        delete &types;
    }

    // Accessor.
    string ExprTokens::getToken() const
    {
        return getToken(tokens.getSize()-1);
    }

    string ExprTokens::getToken(int index) const
    {
        if(index>=0 && index<tokens.getSize())
            return tokens.getData(index);
        else
        {
            throw OutOfIndexException(index);
            return "";
        }
    }

    ExprTokenType ExprTokens::getType() const
    {
        return getType(tokens.getSize()-1);
    }

    ExprTokenType ExprTokens::getType(int index) const
    {
        if(index>=0 && index<tokens.getSize())
            return types.getData(index);
        else
        {
            throw OutOfIndexException(index);
            return unknown;
        }
    }

    // Mutator.
    bool ExprTokens::addToken(string token)
    {
        return addToken(tokens.getSize(), token);
    }

    bool ExprTokens::addToken(int index, string token)
    {
        if(index>=0 && index<=tokens.getSize())
        {
            bool status = false;
            
            status = tokens.addData(index, token);
            
            if(status)
            {
                status = types.addData(index, whichType(token));

                if(!status)
                    tokens.removeData(index);
            }

            return status;
        }
        else
            return false;
    }

    bool ExprTokens::removeToken()
    {
        return removeToken(tokens.getSize()-1);
    }

    bool ExprTokens::removeToken(int index)
    {
        if(index>=0 && index<tokens.getSize())
        {
            tokens.removeData(index);
            types.removeData(index);

            return true;
        }
        else
            return false;
    }

    // Method.
    void ExprTokens::clear()
    {
        tokens.clear();
        types.clear();
    }

    void ExprTokens::print() const
    {
        cout << "\n>> " << std::to_string(tokens.getSize()) << " tokens in total\n";

        for(int i=0; i<tokens.getSize(); ++i)
            cout << std::setw(10) << std::left << tokens.getData(i) << " | " << ExprTokens::getTypeName(types.getData(i)) << "\n";

        cout << "\n";
    }

    string ExprTokens::toString() const
    {
        string expr = "";

        // Generate expression by tokens.
        for(int i=0; i<tokens.getSize(); ++i)
            expr += tokens.getData(i);

        return expr;
    }

    string ExprTokens::toSpacedString() const
    {
        string expr = "";

        // Generate expression by tokens.
        for(int i=0; i<tokens.getSize(); ++i)
            expr += " " + tokens.getData(i);

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

