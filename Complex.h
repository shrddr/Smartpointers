#pragma once

class Complex
{
public:
	Complex() : re(0), im(0) {}
	Complex(float re, float im) : re(re), im(im) {}
	void print();
private:
	float re, im;
};

