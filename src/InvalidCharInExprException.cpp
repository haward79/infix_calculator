#include "InvalidCharInExprException.h"

// Constructor.
InvalidCharInExprException::InvalidCharInExprException() : isCharProvided(false), ch(0)
{
    // Empty.
}

InvalidCharInExprException::InvalidCharInExprException(char ch) : isCharProvided(true), ch(ch)
{
    // Empty.
}

// Method.
string InvalidCharInExprException::toString() const
{
    if(isCharProvided)
        return "Exception: Invalid character '" + std::to_string(ch) + "' found in expression.";
    else
        return "Exception: Invalid character found in expression.";
}

