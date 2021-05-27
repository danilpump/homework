#include "Task1Head.h"

longnum::longnum()
{
	sign = false;
	numleft = 0;
	numright = 0;
}

longnum::longnum(int input)
{
	if (input < 0)
	{
		sign = true;
		input = input * (-1);
	}
	else
		sign = false;
	uint64_t tmp = input;
	numleft = tmp >> 32;
	tmp <<= 32;
	numright = tmp >> 32;
}

longnum::longnum(uint64_t input)
{
	sign = false;
	numleft = input >> 32;
	input <<= 32;
	numright = input >> 32;
}

longnum::~longnum()
{
	numleft = NULL;
	numright = NULL;
	sign = NULL;
}

longnum& longnum::operator=(const longnum& q)
{
	sign = q.sign;
	numleft = q.numleft;
	numright = q.numright;
	return *this;
}

longnum& longnum::operator=(int input)
{
	if (input < 0)
	{
		sign = true;
		input = input * (-1);
	}
	else
		sign = false;

	uint64_t tmp = input;
	numleft = tmp >> 32;
	tmp <<= 32;
	numright = tmp >> 32;
	return *this;
}

longnum& longnum::operator=(uint64_t input)
{
	sign = false;
	numleft = input >> 32;
	input <<= 32;
	numright = input >> 32;
	return *this;
}

longnum longnum::operator+(const longnum& q)
{
	uint64_t temp, temp2;
	temp = numleft;
	temp <<= 32;
	temp += numright;

	temp2 = q.numleft;
	temp2 <<= 32;
	temp2 += q.numright;

	longnum temp3;

	if (!sign)
		if (!q.sign)                     // If both of numbers are positive.
			temp3 = temp2 + temp;
		else if (q.sign)                // If second number is negative.
			if (temp >= temp2)
				temp3 = temp + temp2;
			else
			{
				temp3 = temp2 - temp;
				temp3.sign = true;
			}
	else if (sign)
		if (!q.sign)                    // If first number is negative.
			if (temp < temp2)
				temp3 = temp2 - temp;
			else
			{
				temp3 = temp - temp2;
				temp3.sign = true;
			}
		else if (q.sign)               // If both of numbers are negative.
		{
			temp3 = temp + temp2;
			temp3.sign = true;
		}
	return temp3;
}

longnum longnum::operator-(const longnum& q)
{
	uint64_t temp, temp2;
	temp = numleft;
	temp <<= 32;
	temp += numright;

	temp2 = q.numleft;
	temp2 <<= 32;
	temp2 += q.numright;

	longnum temp3;

	if (!sign)
		if (!q.sign)                    // If both of numbers are positive.
			if (temp < temp2)
			{
				temp3 = temp2 - temp;
				temp3.sign = true;
			}
			else
				temp3 = temp - temp2;
		else if (q.sign)                // If second number is negative.
			temp3 = temp + temp2;
	else if (sign)
		if (!q.sign)                    // If first number is negative.
		{
			temp3 = temp + temp2;
			temp3.sign = true;
		}
		else if (q.sign)                // If both of numbers are negative.
			if (temp < temp2)
				temp3 = temp2 - temp;
			else
			{
				temp3 = temp - temp2;
				temp3.sign = true;
			}
	return temp3;
}

longnum longnum::operator*(const longnum& q)
{
	uint64_t temp, temp2;
	temp = numleft;
	temp <<= 32;
	temp += numright;

	temp2 = q.numleft;
	temp2 <<= 32;
	temp2 += q.numright;

	longnum temp3(temp * temp2);

	if (sign != q.sign)
		temp3.sign = true;

	return temp3;
}

longnum longnum::operator/(const longnum& q)
{
	uint64_t temp, temp2;
	temp = numleft;
	temp <<= 32;
	temp += numright;

	temp2 = q.numleft;
	temp2 <<= 32;
	temp2 += q.numright;

	longnum temp3(temp / temp2);

	if (sign != q.sign)
		temp3.sign = true;

	return temp3;
}

longnum longnum::operator%(const longnum& q)
{
	uint64_t temp, temp2;
	temp = numleft;
	temp <<= 32;
	temp += numright;

	temp2 = q.numleft;
	temp2 <<= 32;
	temp2 += q.numright;

	longnum temp3(temp % temp2);

	if (sign != q.sign)
		temp3.sign = true;

	return temp3;
}
