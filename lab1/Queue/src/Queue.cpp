#include "Queue.hpp"

int main()
{
    Queue<int> queue;
    std::cout<<"Enqueue queue values(0-9)"<<'\n';
    for(int i=0; i<10; i++)
    {
        queue.enqueue(i);
    }
    std::cout<<"Printing Queue"<<'\n';
    queue.display();
    std::cout<<"Dequeue Queue"<<'\n';
    try
    {
        for(int i= 11; i>0;i--)
        {
            std::cout<<" Data-> "<< queue.dequeue() << " Rem Size-> "<< queue.size()<<'\n';
        }
    }
    catch (const char *err)
    {
        std::cout<<'\n'<<"Error: "<<err<<std::endl;
    }
    
}