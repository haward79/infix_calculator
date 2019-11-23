#ifndef StringManip_h

    #define StringManip_h

    #include <string>

    using std::string;

    namespace NutnDS_StringManip
    {
        bool isDigit(char);
        bool isAlpha(char);
        bool isCapital(char);
        bool isOperator(char);
        bool isParentheses(char);
        bool isNumber(string);
        bool isAlpha(string);
        bool isOperator(string);
        bool isParentheses(string);
        string charToString(char);
        string removeChar(string, char);
    }

#endif

