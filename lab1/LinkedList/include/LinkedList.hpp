#include <iostream>

template <typename T>
struct Node
{   
    Node():node(nullptr){

    }
    Node(T _val)noexcept
    {
        this->data = _val;
        this->node = nullptr;
    }
    Node* node;
    T data;

    ~Node(){
        delete node;
    }
};

template <typename T>
class LinkedList
{
    public:
        LinkedList(){
            m_head = nullptr;
        }

        bool isEmpty() const
        {
            return m_head == nullptr;
        }

        void addToHead(T _val);
        void addToTail(T _val);
        bool removeFromHead();
        bool remove(T _val);
        bool add(T _val, T _pred);
        bool search(T _val);
        void traverse();
        void retrieve(T _val, Node<T>* nodePointer);
        bool removeFromTail();
        ~LinkedList(){
            delete m_head;
        }
    protected:
        Node<T>* m_head;
    
};

template <typename T>
void LinkedList<T>::retrieve(T _val, Node<T>* nodePointer)
{
    auto nodes = m_head;
    while(nodes!=nullptr)
    {
        if(nodes->data == _val)
        {
            nodePointer->data = nodes->data;
            return;
        }
        nodes = nodes->node;
    }
}

template <typename T>
void LinkedList<T>::traverse()
{
    auto nextnode = m_head;
    while(nextnode != nullptr){
        std::cout<<nextnode->data<<" ";
        nextnode = nextnode->node;
    }
    std::cout<<std::endl;
}

template <typename T>
bool LinkedList<T>::search(T _val)
{
    auto nextnode = m_head;
    while( nextnode != nullptr){
        if(nextnode->data == _val) return true;
        nextnode = nextnode->node;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::add(T _val, T _pred)
{
    if(m_head == nullptr) return false;
    auto nextnode = m_head;
    while(nextnode != nullptr)
    {
        if(nextnode->data == _pred){
            auto temp = new Node<T>(_val); 
            temp->node = nextnode->node;
            nextnode->node = temp;
            return true;
        }
        nextnode = nextnode->node;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::remove(T _val)
{
    if(m_head == nullptr) return false;
    if(m_head->data == _val) return removeFromHead();
    auto nextnode = m_head;
    while(nextnode->node != nullptr)
    {
        if(nextnode->node->data == _val){
            auto temp = nextnode->node;
            nextnode->node = nextnode->node->node;
            temp->node = nullptr;
            delete temp;
            return true;
        }    
        nextnode = nextnode->node;
    }
    return false;
}

template <typename T>
void LinkedList<T>::addToHead(T _val)
{
    if(m_head != nullptr){
        auto temp= new Node<T>(_val);
        temp->node = m_head;
        m_head = temp;
        return;
    }
    m_head = new Node<T>(_val);
}

template <typename T>
void LinkedList<T>::addToTail(T _val)
{
    if(m_head == nullptr){ 
        addToHead(_val);
        return;
    }
    auto nextnode = m_head;
    while(nextnode->node != nullptr){
        nextnode = nextnode->node;
    }
    nextnode->node = new Node<T>(_val);
}

template <typename T>
bool LinkedList<T>::removeFromHead()
{   
    if( m_head == nullptr) return false;
    auto temp = m_head;
    m_head = m_head->node;
    temp->node = nullptr;
    delete temp;
    return true;
}

template <typename T>
bool LinkedList<T>::removeFromTail()
{   
    if( m_head == nullptr) return false;
    if(m_head->node == nullptr)
    {
        delete m_head;
        m_head = nullptr;
    }
    else
    {
        auto nextnode = m_head;
        while(nextnode != nullptr)
        {
            if(nextnode->node->node == nullptr)
            {
                auto temp = nextnode->node;
                nextnode->node = nullptr;
                delete temp;
                break;
            }
            nextnode = nextnode->node;
        }
    }
    return true;
}
