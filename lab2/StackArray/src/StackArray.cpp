#include "StackArray.hpp"
#include <iostream>
int main()
{
    StackArray<int, 10> stack;
    std::cout<<"Push into stack: values(1000-1009)\n";
    for(int i=0 ; i<11;i++)
    {
        stack.push(i+1000);
    }

    std::cout<<stack.top()<<"    Top\n";
    std::cout<<"printing Stack\n";
    try
    {
        for(int i=0;i<15;i++)
        {
            std::cout<<"index= "<<i<<" data=  "<<stack.pop()<<'\n';
        }
        std::cout<<std::endl;
    }
    catch (const char* msg)
    {
            std::cout<<"Error: "<<msg<<std::endl;
    }
    std::cout<<std::endl;
}