#pragma once
#include "Complex.h"

// disabled copy constructor
// disabled operator=
// two scoped_ptrs to the same object -> unsafe
// can be set to null safely
// simple access syntax

template <class T>
class scoped_ptr
{
private:
	T* pObj;
	scoped_ptr(const scoped_ptr& p);
	scoped_ptr& operator= (const scoped_ptr& p);
public:
	scoped_ptr(T* pObject) 
	{
		pObj = pObject; 
	}

	~scoped_ptr()
	{
		if (pObj) delete pObj;
	}

	T* operator->()
	{
		return pObj;
	}

	T& operator*()
	{
		return *pObj;
	}
};