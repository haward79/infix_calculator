#include <iostream>
#include "InfixExpr.h"
#include "PostfixExpr.h"
#include "OutOfIndexException.h"

using NutnDS::InfixExpr;
using NutnDS::PostfixExpr;

int main()
{
    InfixExpr& infix = *(new InfixExpr);
    PostfixExpr& postfix = *(new PostfixExpr);

    // Read an infix expression (and split to tokens).
    infix.input();

    // Infix to postfix.
    postfix.setExpr(infix.toPostfixTokens());
    cout << "Answer: " << postfix.evaluate() << "\n";

    // Clear heap.
    delete &infix;
    delete &postfix;

    return 0;
}

