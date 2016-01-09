#pragma once
#include "Complex.h"

class auto_ptr
{
private:
	Complex* pObj;
public:
	auto_ptr(Complex* pObject);
	~auto_ptr();
	auto_ptr(auto_ptr& p);
	auto_ptr& operator= (auto_ptr& p);
	Complex* operator->();
	Complex& operator*();
};

