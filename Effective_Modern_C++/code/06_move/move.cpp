#include <iostream>
#include <string>

class MyClass
{
public:
    MyClass(std::string aStr)
    {
        std::cout << "Constructor" << std::endl;
        mStr = aStr;
    }
        MyClass(const MyClass& other)
    {
        std::cout << "Copy constructor." << std::endl;
        mStr = other.mStr;
    }
        MyClass(MyClass&& other)
    {
        std::cout << "Move constructor." << std::endl;
        mStr = other.mStr;
        other.mStr = "";
    }

private:
    std::string mStr;

};


class MySuperClass
{
public:
    MySuperClass(MyClass& aMyClass) : mMyClass(std::move(aMyClass))
    {

    }

private:
    MyClass mMyClass;
};


/**
* Note that since func accepts rvalue reference to 
* MyClass instance, its argument is candidate of
* move operation.
*/
void func(MyClass&& arg)
{
	std::cout << "In func()." << std::endl;
}

int main()
{
	std::cout << "------------------------------------" << std::endl;

    MyClass m1("Test");
    MySuperClass m2(m1);

	std::cout << "------------------------------------" << std::endl;
	
	/*
	* Note that we pass rvalue to func. 
	* Passing lvalue will fail.
	*/
	func(MyClass("Test2"));

	std::cout << "------------------------------------" << std::endl;
    
	return 0;
}

