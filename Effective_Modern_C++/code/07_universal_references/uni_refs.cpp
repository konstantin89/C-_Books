#include "uni_refs.h"

int main()
{
	MyClass mc;
	
	/**
	* The following example demonstrates how function
	* whos parameter is universal reference can accept 
	* both rvalue and lvalue references.
	*/
	tFunc<MyClass>(mc);             // parameter type is &MyClass.
	tFunc<MyClass>(std::move(mc));  // patameter type is &&MyClass.

	return 0;
}
