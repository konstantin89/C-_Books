#include "object_traits.h"
#include "heap.h"

#define FORWARD_ALLOCATOR_TRAITS(C)                  \
typedef typename C::value_type      value_type;      \
typedef typename C::pointer         pointer;         \
typedef typename C::const_pointer   const_pointer;   \
typedef typename C::reference       reference;       \
typedef typename C::const_reference const_reference; \
typedef typename C::size_type       size_type;       \
typedef typename C::difference_type difference_type; \

template<typename T,
         typename PolicyT = heap<T>,
         typename TraitsT = object_traits<T> >
class allocator : public PolicyT,
                  public TraitsT
{
public:

    // Template parameters
    typedef PolicyT Policy;
    typedef TraitsT Traits;

    FORWARD_ALLOCATOR_TRAITS(Policy)

    template<typename U>
    struct rebind
    {
       typedef allocator<U,
                         typename Policy::template rebind<U>::other,
                         typename Traits::template rebind<U>::other
                        > other;
    };

    // Constructor
    allocator(void){}

    // Copy Constructor
    template<typename U,
             typename PolicyU,
             typename TraitsU>
    allocator(allocator<U,
                        PolicyU,
                        TraitsU> const& other) :
       Policy(other),
       Traits(other)
    {}
};

/****************************************************************************/

// Two allocators are not equal unless a specialization says so
template<typename T, typename PolicyT, typename TraitsT,
         typename U, typename PolicyU, typename TraitsU>
bool operator==(allocator<T, PolicyT, TraitsT> const& left,
                allocator<U, PolicyU, TraitsU> const& right)
{
   return false;
}

// Also implement inequality
template<typename T, typename PolicyT, typename TraitsT,
         typename U, typename PolicyU, typename TraitsU>
bool operator!=(allocator<T, PolicyT, TraitsT> const& left,
                allocator<U, PolicyU, TraitsU> const& right)
{
   return !(left == right);
}

// Comparing an allocator to anything else should not show equality
template<typename T, typename PolicyT, typename TraitsT,
         typename OtherAllocator>
bool operator==(allocator<T, PolicyT, TraitsT> const& left,
                OtherAllocator const& right)
{
   return false;
}

// Also implement inequality
template<typename T, typename PolicyT, typename TraitsT,
         typename OtherAllocator>
bool operator!=(allocator<T, PolicyT, TraitsT> const& left,
                OtherAllocator const& right)
{
  return !(left == right);
}

// Specialize for the heap policy
template<typename T, typename TraitsT,
         typename U, typename TraitsU>
bool operator==(allocator<T, heap<T>, TraitsT> const& left,
                allocator<U, heap<U>, TraitsU> const& right)
{
   return true;
}

// Also implement inequality
template<typename T, typename TraitsT,
         typename U, typename TraitsU>
bool operator!=(allocator<T, heap<T>, TraitsT> const& left,
                allocator<U, heap<U>, TraitsU> const& right)
{
   return !(left == right);
}







/************************* End Of File **********************************/
