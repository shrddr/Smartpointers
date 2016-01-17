#pragma once
#include "Complex.h"

template <class T>
class Storage
{
private:
	int count;
public:
	T* pObj;

	Storage(T* pObject)
	{
		pObj = pObject;
		count = 1;
	}

	~Storage()
	{
		if (pObj) delete pObj;
	}

	void addRef()
	{
		count++;
	}

	void remRef()
	{
		count--;
	}

	bool noRefs() 
	{
		return (count == 0);
	}
};

template <class T>
class shared_ptr
{
private:
	Storage<T>* storage;
public:
	shared_ptr(T* pObject)
	{
		storage = new Storage<T>(pObject);
	}

	~shared_ptr()
	{
		storage->remRef();
		if (storage->noRefs()) delete storage;
	}

	shared_ptr(const shared_ptr& p)
	{
		storage = p.storage;
		storage->addRef();
	}

	shared_ptr& operator= (const shared_ptr& p)
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

	T* operator->()
	{
		return storage->pObj;
	}

	T& operator*()
	{
		return *(storage->pObj);
	}
};

