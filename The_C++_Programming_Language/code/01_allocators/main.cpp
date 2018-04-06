// Reference:  http://jrruethe.github.io/blog/2015/11/22/allocators/

#include "allocator.h"
#include <set>

struct Example
{
  int value;

  Example(int v) :
      value(v)
  {/* EMPTY */}

  bool operator<(Example const& other) const
  {
      return value < other.value;
  }
};

int main(int argc, char* argv[])
{
    /*
    template<
        class Key,
        class Compare = std::less<Key>,
        class Allocator = std::allocator<Key>>
    class set;
    */
     std::set<Example,
              std::less<Example>,
              allocator<Example, heap<Example>>> foo;

     foo.insert(Example(3));
     foo.insert(Example(1));
     foo.insert(Example(4));
     foo.insert(Example(2));

}
