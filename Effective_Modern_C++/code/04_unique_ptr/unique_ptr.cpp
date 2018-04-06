#include <iostream>
#include <memory>

/**
* unique_ptr implements "exclusive ownership".
* unique_ptr is "move only" type, thus you cant copy it.
*/


/**
* Example class.
*/
class MyClass
{
public:
        MyClass()
        {
            std::cout << "MyClass::MyClass()" << std::endl;
        }

        void sayHi()
        {
            std::cout << "MyClass::sayHi()" << std::endl;
        }
};

/**
* Custom delete operator for MyClass.
*/
auto deleteMyClass = [](MyClass* ptrMyClass)
{
    std::cout << "custom delete operator" << std::endl;
    delete ptrMyClass;
};

/**
* Class factory.
*/
std::unique_ptr<MyClass, decltype(deleteMyClass)> makeClass()
{
    //Creating unique_ptr with nullptr as its content.
    std::unique_ptr<MyClass, decltype(deleteMyClass)>
        ptr(nullptr, deleteMyClass);

    //Set new MyClass instance as content for unique_ptr.
    ptr.reset(new MyClass());

    return ptr;
}

int main()
{
    auto uniquePtr = makeClass();
    uniquePtr->sayHi();

    //Converting unique_ptr to shared_ptr.
    std::shared_ptr<MyClass> sharedPtr = makeClass();

    return 0;
}




/***************************** End Of File ***********************************/
