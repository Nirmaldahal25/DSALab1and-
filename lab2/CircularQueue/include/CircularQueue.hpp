#include <utility>
#include <iostream>

template <typename T, int sizeT>
class CircularQueue
{
    public:
        CircularQueue():m_rear(-1),m_front(-1)
        {
            m_size = sizeT;
        }

        bool isEmpty()const
        {
            return m_front==-1;
        }

        bool isFull() const
        {
            return (m_front==0 && m_rear == m_size-1) || (m_rear + 1 == m_front);
        }

        bool enqueue(T value)
        {
            if( !isFull())
            {
                if(m_front == -1) m_front = 0;
                m_rear = (m_rear + 1) % m_size;
                m_arr[m_rear] = value;
                return true;
            }
            return false;
        }

        decltype(auto) dequeue()
        {
            if(!isEmpty())
            {
                const int temp = m_front;
                if(m_front == m_rear)
                {
                    m_front=m_rear=-1;
                } 
                else
                {
                    m_front = (m_front+1) % m_size;
                }

                return std::move(m_arr[temp]);
            }
            throw "Queue is Full";
        }

	T front()
	{
		if(!isEmpty())
		{
			return m_arr[m_front];
		}
        throw "Queue is empty";
	}
	
	T back()
	{
		if(!isEmpty())
		{
			return m_arr[m_rear];
		}
        throw "Queue is empty";
	}

    private:
        T m_arr[sizeT];
        int m_rear;
        int m_front;
        int m_size;
};