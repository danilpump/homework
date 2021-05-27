#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class longnum
{
private:
	uint32_t numleft, numright;
	bool sign;
public:
	longnum();
	longnum(int input);
	longnum(uint64_t input);
	~longnum();

	longnum& operator=(const longnum& q);

	longnum& operator=(uint64_t input);

	longnum& operator=(int input);

	longnum operator+(const longnum& q);

	longnum operator-(const longnum& q);

	longnum operator*(const longnum& q);

	longnum operator/(const longnum& q);

	longnum operator%(const longnum& q);

	friend ostream& operator<<(ostream& os, longnum& q)
	{
		uint64_t temp;
		temp = q.numleft;
		temp <<= 32;
		temp += q.numright;
		if (q.sign)
			os << "-";
		os << temp;
		
		return os;
	}
};