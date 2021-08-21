template <class T, int sizeT>
class StackArray
{
    public:
        StackArray():m_index(-1)
        {
        }

        void push(T _val)
        {
            if(!isFull())
            {
                m_arr[++m_index] = _val;
            }
        }

        T pop()
        {
            if(!isEmpty())
            {
                return m_arr[m_index--];
            }
            throw "array is empty";
        }

        T top()
        {
            return m_arr[m_index];
        }

        bool isFull() const
        {
            return m_index+1 == sizeT;
        }

        bool isEmpty() const
        {
            return m_index < 0;
        }


    private:
        T m_arr[sizeT];
        int m_index;
};

