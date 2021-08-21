#include "LinkedList.hpp"

template <typename T>
class Stack: protected LinkedList<T>
{
    public:
        Stack():LinkedList<T>(),m_size(0)
        {

        }
        int size()const
        {
            return m_size;
        }
        
        bool isEmpty() const
        {
            return this->LinkedList<T>::isEmpty();
        }

        T peek();
        T pop();
        void display();
        void push(T);
    private:
        int m_size;
};

template <typename T>
T Stack<T>::peek()
{
    if(!this->isEmpty())
    {
        return this->m_head->data;
    }
    throw "Stack is Empty";
}

template <typename T>
void Stack<T>::push(T __val)
{
    this->addToHead(__val);
    m_size++;
}

template <class T>
T Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        const T value = this->m_head->data;
        this->removeFromHead();
        m_size--;
        return value;
    }
    throw "Stack is empty";
}

template <typename T>
void Stack<T>::display()
{
    this->LinkedList<T>::traverse();
}