#include "auto_ptr.h"

auto_ptr::auto_ptr(Complex *pObject)
{
	pObj = pObject;
}

auto_ptr::~auto_ptr()
{
	if (pObj) delete pObj;
}

auto_ptr::auto_ptr(auto_ptr& p)
{
	pObj = p.pObj;
	p.pObj = 0;
}

auto_ptr& auto_ptr::operator= (auto_ptr& p)
{
	if (this != &p)
	{
		delete pObj;
		pObj = p.pObj;
		p.pObj = 0;
	}
	return *this;
}

Complex* auto_ptr::operator->()
{
	return pObj;
}

Complex& auto_ptr::operator*()
{
	return *pObj;
}