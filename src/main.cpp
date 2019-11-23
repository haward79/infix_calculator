#include <iostream>
#include "InfixExpr.h"
#include "PostfixExpr.h"
#include "Stack.h"

using NutnDS_InfixExpr::InfixExpr;
using NutnDS_PostfixExpr::PostfixExpr;
using NutnDS_Stack::Stack;

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

