#ifndef ExprTokens_h

    #define ExprTokens_h

    #include <iostream>
    #include <iomanip>
    #include <string>
    #include "StringManip.h"
    #include "OutOfIndexException.h"

    using std::cout;
    using std::string;
    using namespace NutnDS_StringManip;

    namespace NutnDS_ExprTokens
    {
        // Data type.
        typedef enum {unknown, posInteger, float_, operator_, parentheses} ExprTokenType;

        class ExprTokens
        {
            public:
                // Constant.
                static const int kMaxToken = 100;

                // Constructor.
                ExprTokens();
                ExprTokens(const ExprTokens&);

                // Accessor.
                int getSize() const { return size; }
                string getToken(int) const;
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
                int size;
                string tokens[kMaxToken];
                ExprTokenType types[kMaxToken];
        };
    }

#endif

