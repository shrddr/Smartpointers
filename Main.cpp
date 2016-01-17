#include <stdio.h>
#include "Complex.h"
#include "scoped_ptr.h"
#include "auto_ptr.h"
#include "shared_ptr.h"

int main()
{
	// scoped_ptr deletes its payload upon reaching the end of scope
	// useful for RAII (before delete, destructor is called, freeing the resource)
	// it can't be passed to/from functions

	scoped_ptr<Complex> sp = new Complex(0, 1);	
	sp->print();

	// auto_ptr improves that by allowing copy constructor and assignment;
	// however, the right side argument is lost in order to keep a single reference

	auto_ptr<Complex> ap1 = new Complex(1, 1);
	auto_ptr<Complex> ap2 = ap1;					// ap2 -> (1, 1); ap1 -> null
	ap2->print();

	auto_ptr<Complex> ap3 = new Complex(1, 3);
	auto_ptr<Complex> ap4 = new Complex(1, 4);
	ap4 = ap3;										// ap4 -> (1, 3); ap3 -> null
	ap4->print();
	
	// shared_ptr keeps count of references. this way several shared_ptrs can
	// own the same object, but only delete it once

	shared_ptr<Complex> sp1 = new Complex(2, 1);
	shared_ptr<Complex> sp2 = sp1;					// same object referenced twice
	sp1->print();
	sp2->print();

	shared_ptr<Complex> sp3 = new Complex(2, 3);
	shared_ptr<Complex> sp4 = new Complex(2, 4);
	sp4 = sp3;										// sp4 -> (2, 3); sp3 -> (2, 3);
	sp3->print();									// (2, 4) is already deleted
	sp4->print();

	return 0;
}