#include "LinkedList.h"

namespace NutnDS_LinkedList
{
    // Construtor.
    template <typename T>
    Node<T>::Node() : data(nullptr), next(nullptr)
    {
        // Empty.
    }

    template <typename T>
    Node<T>::Node(const T* data, Node<T>* next)
    {
        this->data = new T(*data);
        this->next = next;
    }

    // Destructor.
    template <typename T>
    Node<T>::~Node()
    {
        delete data;
    }
    
    // Constructor.
    template <typename T>
    LinkedList<T>::LinkedList() : size(0), firstNode(new Node<T>)
    {
        // Empty.
    }

    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList* obj) : size(obj->size), firstNode(*(new Node<T>))
    {
        /*
         *  Copy constructor.
         */

        if(obj->firstNode->getNext() != nullptr)
        {
            Node<T>* self = firstNode;
            Node<T>* tmp = obj->firstNode->getNext();

            do
            {
                self->setNext(new Node<T>(tmp->getData(), nullptr));
                
                self = self->getNext();
                tmp = tmp->getNext();
            }
            while(self != nullptr);
        }
    }

    // Destructor.
    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        clear();
        delete firstNode;
    }

    // Accessor.
    template <typename T>
    const T& LinkedList<T>::getData() const
    {
        return getData(size);
    }

    template <typename T>
    const T& LinkedList<T>::getData(int index) const
    {
        if(index>=1 && index<=size)
        {
            Node<T>* tmp = firstNode;
            
            for(int i=0; i<index; ++i)
                tmp = tmp->getNext();

            return tmp->getData();
        }
        else
            return *(new T);
    }

    // Mutator.
    template <typename T>
    bool LinkedList<T>::setData(int index, const T& data)
    {
        if(index>=1 && index<=size)
        {
            Node<T>* tmp = firstNode->getNext();
            
            for(int i=0; i<index; ++i)
                tmp = tmp->getNext();

            tmp->setData(&data);

            return true;
        }
        else
            return false;
    }

    template <typename T>
    bool LinkedList<T>::addData(const T& data)
    {
        Node<T>* tmp = firstNode;
        Node<T>* newNode = nullptr;
        
        for(int i=0; i<size; ++i)
            tmp = tmp->getNext();

        newNode = new Node<T>(&data, nullptr);

        if(newNode != nullptr)
        {
            tmp->setNext(newNode);
            ++size;

            return true;
        }
        else
            return false;
    }

    template <typename T>
    bool LinkedList<T>::addData(int index, const T& data)
    {
        if(index == size+1)
            return addData(data);
        if(index>=1 && index<=size)
        {
            Node<T>* tmp = firstNode;
            Node<T>* newNode = nullptr;
            
            for(int i=0; i<index-1; ++i)
                tmp = tmp->getNext();

            newNode = new Node<T>(&data, tmp->getNext());

            if(newNode != nullptr)
            {
                tmp->setNext(newNode);
                ++size;

                return true;
            }
            else
                return false;
        }
        else
            return false;
    }

    template <typename T>
    bool LinkedList<T>::removeData()
    {
        if(size != 0)
        {
            Node<T>* tmp = firstNode;
            Node<T>* deletedNode = nullptr;
            
            for(int i=0; i<size-1; ++i)
                tmp = tmp->getNext();

            deletedNode = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            delete deletedNode;

            --size;

            return true;
        }
        else
            return false;
    }

    template <typename T>
    bool LinkedList<T>::removeData(int index)
    {
        if(index == size)
            return removeData();
        else if(index>=1 && index<size)
        {
            Node<T>* tmp = firstNode;
            Node<T>* deletedNode = nullptr;
            
            for(int i=0; i<index-1; ++i)
                tmp = tmp->getNext();

            deletedNode = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            delete deletedNode;

            --size;

            return true;
        }
        else
            return false;
    }

    // Method.
    template <typename T>
    void LinkedList<T>::clear()
    {
        Node<T>* tmp = firstNode->getNext();
        Node<T>* tmpNext;

        while(tmp != nullptr)
        {
            tmpNext = tmp->getNext();
            delete tmp;
            tmp = tmpNext;
        }

        size = 0;
    }

    template <typename T>
    void LinkedList<T>::print()
    {
        Node<T>* tmp = firstNode->getNext();

        cout << "Size: " << size << " node(s).\n";

        for(int i=0; i<size; ++i, tmp=tmp->getNext())
            cout << "[" << i+1 << "] " << tmp->getData() << "\n";

        cout << "\n";
    }
}

