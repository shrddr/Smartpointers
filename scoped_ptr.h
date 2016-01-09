#pragma once
#include "Complex.h"

// disabled copy constructor
// disabled operator=
// two scoped_ptrs to the same object -> unsafe
// can be set to null safely
// simple access syntax

class scoped_ptr
{
private:
	Complex* pObj;
	scoped_ptr(const scoped_ptr& p);
	scoped_ptr& operator= (const scoped_ptr& p);
public:
	scoped_ptr(Complex* pObject);
	~scoped_ptr();
	Complex* operator->();
	Complex& operator*();	// by reference is faster
};