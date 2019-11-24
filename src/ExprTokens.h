#ifndef ExprTokens_h

    #define ExprTokens_h

    #include <iostream>
    #include <iomanip>
    #include <string>
    #include "LinkedList.h"
    #include "StringManip.h"
    #include "OutOfIndexException.h"

    using std::cout;
    using std::string;

    namespace NutnDS
    {
        // Data type.
        typedef enum {unknown, posInteger, float_, operator_, parentheses} ExprTokenType;

        class ExprTokens
        {
            public:
                // Constructor.
                ExprTokens();
                ExprTokens(const ExprTokens&);

                // Destructor.
                ~ExprTokens();

                // Accessor.
                int getSize() const { return tokens.getSize(); }
                string getToken() const;
                string getToken(int) const;
                ExprTokenType getType() const;
                ExprTokenType getType(int) const;

                // Mutator.
                bool addToken(string);
                bool addToken(int, string);
                bool removeToken();
                bool removeToken(int);

                // Method.
                void clear();
                void print() const;
                string toString() const;
                string toSpacedString() const;
                static string getTypeName(ExprTokenType);
                static ExprTokenType whichType(string);
                static int getOperatorOrder(string);

            private:
                // Variable.
                LinkedList<string>& tokens;
                LinkedList<ExprTokenType>& types;
        };
    }

#endif

