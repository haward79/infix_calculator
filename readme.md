# What's this ?
This is an infix expression calculator.

# How does it work ?
The program reads an infix expression which contains addition, subtraction, multiplication, division, remainder, power, parentheses and space as input.

Then, the infix expression is converted to postfix expression.

Finally, the postfix expression converted by infix is interpreted and evaluated.

# In details
Following function or syntax are able to print details during program executing.

    /*
     *  'infix' is a object name of InfixExpr type.
     */

    // Get formatted expression string (without space).
    infix.getExpr();

    // Get formatted expression string (with spaces).
    infix.getSpacedExpr();

    // Print infix expression tokens.
    infix.getTokens().print();

    // Print postfix expression converted from infix tokens.
    infix.toPostfixTokens().print();

# Requirements
To compile and run this program, please install the following softwares:
1. C++98, C++11 compiler
2. C++ runtime environment

# Installation and Run
Compile this program by using the following command in cmd, powershell, or terminal.

## Windows
    # Change work directory to the root of this repository.
    > cd [Root of this repo]

    # Compile codes in src folder. (Using g++ for example.)
    # Replace [program_name] with any filename you want.
    > g++ src/*.cpp -o [program_name].exe

    # Run program.
    > [program_name]

## Linux / Unix
    # Change work directory to the root of this repository.
    $ cd [Root of this repo]

    # Compile codes in src folder. (Using g++ for example.)
    # Replace [program_name] with any filename you want.
    $ g++ src/*.cpp -o [program_name]

    # Run program.
    $ ./[program_name]

# Copyright
This program is developed by haward79:  
[haward79's personal website](https://www.haward79.tw/)

Feel free to use or modify this program.  
2019/11/23

