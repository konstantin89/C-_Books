template<typename T>
class object_traits
{
public:

   typedef T type;

   template<typename U>
   struct rebind
   {
      typedef object_traits<U> other;
   };

   // Constructor
   object_traits(void){}

   // Copy Constructor
   template<typename U>
   object_traits(object_traits<U> const& other){}

   // Address of object
   type*       address(type&       obj) const {return &obj;}
   type const* address(type const& obj) const {return &obj;}

   // Construct object
   void construct(type* ptr, type const& ref) const
   {
      // In-place copy construct
      new(ptr) type(ref);
   }

   // Destroy object
   void destroy(type* ptr) const
   {
      // Call destructor
      ptr->~type();
   }
};
