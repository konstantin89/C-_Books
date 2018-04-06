#include <iostream>
#include <vector>
#include <typeinfo>


template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i)
{
    return c[i];
}


int main()
{
    const int var1 = 0;
    decltype(var1) var2 = 5; //decltype(var1) is const int.
    std::cout << "var2 type is: " << typeid(var2).name() << std::endl; // "i"

    std::vector<int> vec(1,0);
    auto var3 = authAndAccess(vec, 0);

    /*
    * decltype of (x) returns reference to x.
    * The following example demostrates this behaviour.
    */
    int var4 = 0;
    decltype((var4)) var5 = var4;   // decltype((var4)) is &int.
    std::cout << "var4 = " << var4 << std::endl; //var4=0.
    var5++;
    std::cout << "var4 = " << var4 << std::endl; //var4=1.
    std::cout << "var5 type is: " << typeid(var5).name() << std::endl; // "i"

    // PKi is Pointer Konst Integer.
    const int* var6;
    std::cout << "var6 type is: " << typeid(var6).name() << std::endl; // "PKi"

    return 0;
}


/***************************** End Of File *******************************/
