#pragma once
#include "Complex.h"

class Storage
{
public:
	Storage(Complex* pObject);
	~Storage();
	void addRef() { count++; }
	void remRef() { count--; }
	bool noRefs() { return (count == 0); }
	Complex* pObj;
private:
	int count;
};

class shared_ptr
{
private:
	Storage* storage;
public:
	shared_ptr(Complex* pObject);
	~shared_ptr();
	shared_ptr(const shared_ptr& p);
	shared_ptr& operator= (const shared_ptr& p);
	Complex* operator->();
	Complex& operator*();
};

