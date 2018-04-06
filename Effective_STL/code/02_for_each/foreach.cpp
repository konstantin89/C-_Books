#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    /*
    * Use lambda function to print vector elements.
    */
    std::vector<int> vec = {0,1,2,3,4,5};
    for_each(vec.begin(), vec.end(), [](int var){std::cout<<var<<" ";});
    std::cout << std::endl;

    /*
    * Multiply all vector elements by 2.
    */
    for_each(vec.begin(), vec.end(), [](int& var){var*=2;});
    for_each(vec.begin(), vec.end(), [](int var){std::cout<<var<<" ";});
    std::cout << std::endl;

    /*
    * Count vars that hold the following condition: var%4 is 0.
    */
    int counter = 0;
    auto countDevidedLambda = [&counter](int var){if(var%4 == 0) counter++;};
    for_each(vec.begin(), vec.end(), countDevidedLambda);
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}
