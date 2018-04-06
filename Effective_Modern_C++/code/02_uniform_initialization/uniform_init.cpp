#include <iostream>
#include <vector>

class MyClass
{
public:

    MyClass(std::initializer_list<int> il)
    {
        std::cout << "MyClass(std::initializer_list<int> il)" << std::endl;
    }
    MyClass(int arg)
    {
        std::cout << "MyClass(int arg)" << std::endl;
    }

    //Init non static member fields.
    int field {0};
};

int main()
{
    //C++ has three ways to init variables.
    int var1 = 0;
    int var2(0);
    int var3{0}; //Uniform initialization


    //Init vector with initial elements.
    std::vector<int> vec{1,2,3,4,5};

    /**
    * Note that uniform init in constructor call can
    * prefer constructors using initializer_list.
    *
    * initializer_list is proxy class that used to
    * pass init lists to class constructors.
    *
    * The following example demostrates this behaviour.
    */
    MyClass instance1(1); // MyClass(int arg)
    MyClass instance2{1}; // MyClass(std::initializer_list<int> il)

    return 0;
}

/***************************** End Of File *********************************/
