
#include <stdlib.h>
#include <stddef.h>
#include <new>

#include <iostream>

#define DEBUG(msg) do{std::cout << msg << std::endl;}while(0)

#define ALLOCATOR_TRAITS(T)                \
typedef T                 type;            \
typedef type              value_type;      \
typedef value_type*       pointer;         \
typedef value_type const* const_pointer;   \
typedef value_type&       reference;       \
typedef value_type const& const_reference; \
typedef size_t            size_type;       \
typedef std::ptrdiff_t    difference_type; \


template<typename T>
struct max_allocations
{
  enum{value = static_cast<size_t>(-1) / sizeof(T)};
};

template<typename T>
class heap
{
public:

  ALLOCATOR_TRAITS(T)

  template<typename U>
  struct rebind
  {
      typedef heap<U> other;
  };

  // Default Constructor
  heap(void){}

  // Copy Constructor
  template<typename U>
  heap(heap<U> const& other){}

  // Allocate memory
  pointer allocate(size_type count, const_pointer /* hint */ = 0)
  {
      DEBUG("allocate");
      if(count > max_size()){throw std::bad_alloc();}
      return static_cast<pointer>(::operator new(count * sizeof(type), ::std::nothrow));
  }

  // Delete memory
  void deallocate(pointer ptr, size_type /* count */)
  {
      DEBUG("deallocate");
      ::operator delete(ptr);
  }

  // Max number of objects that can be allocated in one call
  size_type max_size(void) const {return max_allocations<T>::value;}
};
