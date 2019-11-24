#include "StringManip.h"

namespace NutnDS
{
    bool isDigit(char ch)
    {
        /*
         *  Check if ch is a digit.
         */

        if(ch>='0' && ch<='9')
            return true;
        else
            return false;
    }

    bool isAlpha(char ch)
    {
        /*
         *  Check if ch is an alpha.
         */

        if((ch>='A'&&ch<='Z') || (ch>='a'&&ch<='z'))
            return true;
        else
            return false;
    }

    bool isCapital(char ch)
    {
        /*
         *  Check if ch is a capital alpha.
         *  If ch is not an alpha, false is returned.
         */

        if(isAlpha(ch) && ch<='Z')
            return true;
        else
            return false;
    }

    bool isOperator(char ch)
    {
        /*
         *  Check if ch is an operator.
         */

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
            return true;
        else
            return false;
    }

    bool isParentheses(char ch)
    {
        /*
         *  Check if ch is a parentheses.
         */

        if(ch=='(' || ch==')')
            return true;
        else
            return false;
    }

    bool isNumber(string str)
    {
        /*
         *  Check if ch is a number string.
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
         *  Check if ch is a string which contains alphas only.
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
         *  Check if ch is a string which contains operators only.
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
         *  Check ifch is a string which contains parentheses only.
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
        /*
         *  Convert char to string.
         */

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
            if(index == str.length()-1)  // dechar is at the end.
                str = str.substr(0, index);
            else  // dechar is NOT at the end.
                str = str.substr(0, index) + str.substr(index+1);
        }
        
        return str;
    }
}

