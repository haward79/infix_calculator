#include "StringManip.h"

namespace NutnDS_StringManip
{
    bool isDigit(char ch)
    {
        /*
         *  Check if parameter is a digit.
         */

        if(ch>='0' && ch<='9')
            return true;
        else
            return false;
    }

    bool isAlpha(char ch)
    {
        /*
         *  Check if parameter is an alpha.
         */

        if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z'))
            return true;
        else
            return false;
    }

    bool isCapital(char ch)
    {
        /*
         *  Check if parameter is a capital alpha.
         *  If parameter is not an alpha, false is returned.
         */

        if(isAlpha(ch) && ch<='Z')
            return true;
        else
            return false;
    }

    bool isOperator(char ch)
    {
        /*
         *  Check if parameter is an operator.
         */

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
            return true;
        else
            return false;
    }

    bool isParentheses(char ch)
    {
        /*
         *  Check if parameter is a parentheses.
         */

        if(ch=='(' || ch==')')
            return true;
        else
            return false;
    }

    bool isNumber(string str)
    {
        /*
         *  Check if parameter is a number string.
         */

        for(int i=0, len=str.length(); i<len; ++i)
        {
            if(!isDigit(str.at(i)))
                return false;
        }

        return true;
    }

    bool isAlpha(string str)
    {
        /*
         *  Check if parameter is a string which contains alphas only.
         */

        for(int i=0, len=str.length(); i<len; ++i)
        {
            if(!isAlpha(str.at(i)))
                return false;
        }

        return true;
    }

    bool isOperator(string str)
    {
        /*
         *  Check if parameter is a string which contains operators only.
         */

        for(int i=0, len=str.length(); i<len; ++i)
        {
            if(!isOperator(str.at(i)))
                return false;
        }

        return true;
    }

    bool isParentheses(string str)
    {
        /*
         *  Check ifparameter is a string which contains parentheses only.
         */

        for(int i=0, len=str.length(); i<len; ++i)
        {
            if(!isParentheses(str.at(i)))
                return false;
        }

        return true;
    }
    
    string charToString(char ch)
    {
        return string(1, ch);
    }

    string removeChar(string str, char dechar)
    {
        /*
         *  Remove all dechar from str.
         */

        int index = 0;

        while((index=str.find(dechar)) != string::npos)
        {
            if(index == str.length()-1)
                str = str.substr(0, index);
            else
                str = str.substr(0, index) + str.substr(index+1);
        }
        
        return str;
    }
}

