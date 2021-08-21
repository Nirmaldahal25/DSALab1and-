#include "LinkedList.hpp"

template <typename T>
class Queue: protected LinkedList<T>
{
    public:
        Queue():LinkedList<T>(),m_size(0){
        }
        int size() const
        {
            return m_size; 
        }

        bool isEmpty() const
        {
            return this->LinkedList<T>::isEmpty();
        }

        void display();
        void enqueue(T);
        T dequeue();
    private:
        int m_size;
};

template  <typename T>
void Queue<T>::enqueue(T __val)
{
    this->addToTail(__val);
    m_size++;
}

template <typename T>
T Queue<T>::dequeue()
{ 
    if(!this->isEmpty())
    {
        const T val = this->m_head->data;
        this->removeFromHead();
        m_size--;
        return val;
    }
    throw "Queue is empty";
}

template <typename T>
void Queue<T>::display()
{
    this->LinkedList<T>::traverse();
}