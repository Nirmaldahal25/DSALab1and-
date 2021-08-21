#include "CircularQueue.hpp"

int main(){
    CircularQueue<int,4> Qu;
    std::cout<<"Enqueue values(100-103)\n";
    for(int i=0; i<7; i++)
    {
        Qu.enqueue(i+100);
    }
    std::cout<<Qu.front()<<"  Front\n";
    std::cout<<Qu.dequeue()<<"   Removing an item\n";
    std::cout<<Qu.front()<<"  Front\n";
    std::cout<<Qu.back()<<"   Back\n";

    std::cout<<"Removing Data from queue\n";
    try{
        for(int i=0; i<10; i++)
        {
            std::cout<<"data-> "<<Qu.dequeue()<<'\n';
        }
    }
    catch(const char *msg)
    {
        std::cout<<"Error: "<<msg<<'\n';
    }
    std::cout<<std::endl;
    return 0;
}