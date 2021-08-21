#include "LinkedList.hpp"
int main()
{
    LinkedList<int> list;
    
    std::cout<<"Adding 12 to head.\n";
    list.addToHead(12);
    std::cout<<"Adding 14 after 12.\n";
    list.add(14, 12);
    std::cout<<"Adding 400 to tail.\n";
    list.addToTail(400);

    std::cout<<"list.traverse()->"<<'\n';
    list.traverse();

    std::cout<<"popping everything from list...\n";
    while(list.removeFromHead());
    
    std::cout<<"Listtraversal->"<<'\n';
    list.traverse();

    list.addToHead(14);
    Node<int> ptr;
    std::cout<<"Retriving Node with 14 from list\n";
    list.retrieve(14, &ptr);
    std::cout<<"Retrived data "<<ptr.data<<'\n';
    list.traverse();
    
    list.removeFromTail();
    list.traverse();
    return 0;
}