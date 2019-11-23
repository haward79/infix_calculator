#ifndef InvalidCharInExprException_h

    #define InvalidCharInExprException_h

    #include "Exception.h"

    class InvalidCharInExprException : public Exception
    {
        public:
            // Constructor.
            InvalidCharInExprException();
            InvalidCharInExprException(char);

            // Accessor.
            char getCh() const { return ch; }

            // Mutator.
            void setCh(char ch) { this->ch = ch; }

            // Method.
            string toString() const;

        private:
            // Variable.
            bool isCharProvided;
            char ch;
    };

#endif

