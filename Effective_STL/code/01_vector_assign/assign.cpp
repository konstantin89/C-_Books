#include <iostream>
#include <vector>

template <typename T>
void print_vector(const std::vector<T>& aVec)
{
    for(auto elem : aVec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec1 = {0,1,2,3,4,5};

    print_vector<int>(vec1); // 0,1,2,3,4,5

    /*
    * The best way to assign the second half of vec1 in to vec2
    * is the assign method.
    *
    * Range based methods are more effective than looping
    * over elements.
    */
    std::vector<int> vec2;
    vec2.assign(vec1.begin() + vec1.size()/2, vec1.end());

    print_vector<int>(vec2); // 3,4,5


}
