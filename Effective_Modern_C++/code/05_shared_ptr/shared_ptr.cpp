#include <memory>
#include <iostream>


/**
* Example class.
*/
class MyClass
{
public:
    MyClass()
    {
        std::cout << "[ ] MyClass::MyClass()" << std::endl;
    }
};

/**
* Custor delete operator.
*/
auto customDeleteOperator = [](MyClass* ptr)
{
    std::cout << "[ ] Custorm delete operator" << std::endl;
    delete ptr;
};


int main()
{
    //Creating shared_ptr with custor delete operator.
    std::shared_ptr<MyClass> sPtr1(new MyClass(), customDeleteOperator);

    //Output: 1.
    std::cout << "[ ] sPtr1.use_count(): "<< sPtr1.use_count() << std::endl;

    //Create shared_ptr from shared_ptr.
    std::shared_ptr<MyClass> sPtr2(sPtr1);

    //Output: 2.
    std::cout << "[ ] sPtr1.use_count(): "<< sPtr1.use_count() << std::endl;

    sPtr2 = nullptr;

    //Output: 1.
    std::cout << "[ ] sPtr1.use_count(): "<< sPtr1.use_count() << std::endl;

    std::weak_ptr<MyClass> wPtr(sPtr1);

    //Output: 1.
    std::cout << "[ ] sPtr1.use_count(): "<< sPtr1.use_count() << std::endl;

    std::shared_ptr<MyClass> sPtr3 = wPtr.lock();
    if(sPtr3 == nullptr)
    {
        std::cout << "[ ] sPtr3 is null" << std::endl;

    }



    return 0;
}






/******************************* End Of File *********************************/
