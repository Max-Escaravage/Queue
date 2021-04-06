#include <iostream>
#include "myQueue.h"

int main()
{
    myQueue<int> intQueue(5);
    intQueue.addQueue(1);
    intQueue.addQueue(2);
    intQueue.addQueue(3);
    intQueue.addQueue(4);
    intQueue.addQueue(5);
    //std::cout << intQueue.frontQueue() << std::endl;
    //std::cout << intQueue.backQueue() << std::endl;
    //intQueue.deleteQueue();
    //std::cout << intQueue.frontQueue() << std::endl;
    //std::cout << intQueue.backQueue() << std::endl;
    //std::cout << intQueue.isEmptyQueue() << std::endl;
    //std::cout << intQueue.isFullQueue() << std::endl;
    intQueue.printQueue();

    myQueue<int> intQueue2(intQueue);
    intQueue2.printQueue();
    //std::cout << intQueue.frontQueue() << std::endl;
    //std::cout << intQueue.backQueue() << std::endl;

    system("PAUSE");
    return 0;
}