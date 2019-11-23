#ifndef Stack_h

    #define Stack_h

    #include <iostream>
    #include "LinkedList.h"

    using std::cout;
    using NutnDS_LinkedList::LinkedList;

    namespace NutnDS_Stack
    {
        template <typename T>
        class Stack
        {
            public:
                // Constructor.
                Stack();

                // Destructor.
                ~Stack();

                // Accessor.
                int getSize() const { return data.getSize(); }
                const T& peek() const;

                // Mutator.
                const T& pop();
                const bool push(T&);

                // Method.
                void clear();
                void print() const;

            private:
                // Variable.
                LinkedList<T>& data;
        };
    }

    #include "Stack.tpp"

#endif

