#include "Stack.hpp"

int main()
{
    Stack<int> stack;
    std::cout<<"Push into stack: values(0-9)"<<'\n';
    for(int i=0; i<10; i++)
    {
        stack.push(i);
    }
    std::cout<<"Printing stack"<<'\n';
    stack.display();
    std::cout<<"Pop out stack"<<'\n';
    try
    {
        for(int i= 11; i>0;i--)
        {
            std::cout<<"  Data-> "<<stack.pop()<<"  Rem Size-> "<< stack.size()<<'\n';
        }
    }
    catch (const char *err)
    {
        std::cout<<'\n'<<"Error: "<<err<<std::endl;
    }
}