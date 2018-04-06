#include <iostream>


class MyClass
{


};


/**
* In the following example function,
* T is universe reference and can bind 
* to both rvalue and lvalue.
*
*/
template <typename T>
void tFunc(T&& arg)
{
	/* EMPTY */
}
