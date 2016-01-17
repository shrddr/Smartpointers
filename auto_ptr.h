#pragma once
#include "Complex.h"

template <class T>
class auto_ptr
{
private:
	T* pObj;
public:
	auto_ptr(T* pObject) 
	{
		pObj = pObject;
	}

	~auto_ptr()
	{
		if (pObj) delete pObj;
	}

	auto_ptr(auto_ptr& p)
	{
		pObj = p.pObj;
		p.pObj = 0;
	}

	auto_ptr& operator= (auto_ptr& p)
	{
		if (this != &p)
		{
			delete pObj;
			pObj = p.pObj;
			p.pObj = 0;
		}
		return *this;
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

