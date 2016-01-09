#include "scoped_ptr.h"


scoped_ptr::scoped_ptr(Complex *pObject)
{
	pObj = pObject;
}

scoped_ptr::~scoped_ptr()
{
	if (pObj) delete pObj;
}

Complex* scoped_ptr::operator->()
{
	return pObj;
}

Complex& scoped_ptr::operator*()
{
	return *pObj;
}