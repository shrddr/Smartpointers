#include "shared_ptr.h"

Storage::Storage(Complex* pObject)
{
	pObj = pObject;
	count = 1;
}

Storage::~Storage()
{
	if (pObj) delete pObj;
}

shared_ptr::shared_ptr(Complex* pObject)
{
	storage = new Storage(pObject);
}

shared_ptr::~shared_ptr()
{
	storage->remRef();
	if (storage->noRefs()) delete storage;
}

shared_ptr::shared_ptr(const shared_ptr& p)
{
	storage = p.storage;
	storage->addRef();
}

shared_ptr& shared_ptr::operator= (const shared_ptr& p)
{
	if (this != &p)
	{
		storage->remRef();
		if (storage->noRefs()) delete storage;

		storage = p.storage;
		storage->addRef();
	}
	return *this;
}

Complex* shared_ptr::operator->()
{
	return storage->pObj;
}

Complex& shared_ptr::operator*()
{
	return *(storage->pObj);
}