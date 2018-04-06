#include <iostream>
#include <vector>
#include <list>
#include <memory>

/**
* aliases can be used to define function pointers
* in a more intuitive way that typedefs.
*/
using FP_alias = void (*)(int arg);
typedef void (*FP_typedef)(int arg);


/**
* aliases support templates, while typedefs not.
*
* The following example demonstrates alias to
* list (Linked List) with custor memory allocator.
*/
template<typename S>
class MyAlloc
{
    /* Custom allocator implementation.*/
};

template<typename T>
using MyAllocLinkedList = std::list<T, MyAlloc<T>>;



int main()
{
    
    return 0;
}


/***************************** End Of File *********************************/
