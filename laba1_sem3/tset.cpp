#include "tset.h"

// Fake variables used as placeholders in tests



TSet::TSet(int mp) :BitField(mp)
{}

// ����������� �����������
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField)
{}

void  TSet::print_array()
{
	BitField.print_array();
}

TSet::TSet(const TBitField& bf) : BitField(bf)
{
	this->MaxPower = bf.GetLength();
}

TSet& TSet::operator=(const TSet& s) // ������������
{
	this->BitField = s.BitField;
	this->MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::GetMaxPower(void) const// �������� ����. �-�� ��-���
{
	return this->MaxPower;
}

TSet::operator TBitField()
{
	std::printf("\noperator TBitField()");
	return BitField;
}

TSet TSet::operator<<(int k) //����� ����� �����
{
	this->BitField = BitField << k;
	return *this;

}

bool TSet::operator==(const TSet& s) // ���������
{
	return  (BitField == s.BitField);
}

int TSet::IsMember(const int Elem) const // ������� ���������?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // ��������� �������� ���������
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // ���������� �������� ���������
{
	BitField.ClrBit(Elem);
}

// ���������-������������� ��������

bool TSet::operator!=(const TSet& s) // ���������
{
	return  (BitField != s.BitField);
}

TSet TSet::operator+(const TSet& s) // ����������� 
{
	int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField | s.BitField;
	return temp;
}

TSet TSet::operator+(const int Elem) // ����������� � ��������� 
{
	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // �������� � ���������
{
	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet& s) // �����������
{
	int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField & s.BitField;
	return temp;
}

TSet TSet::operator~(void) // ����������
{
	TSet temp(~BitField);
	return temp;
}

// ���������� �����/������

istream& operator>>(istream& istr, TSet& s) // ����
{
	int temp;
	char ch;
	do {
		istr >> ch;
	} while (ch != '{');
	do {
		istr >> temp; s.InsElem(temp);
		do {
			istr >> ch;
		} while ((ch != ',') && (ch != '}'));
	} while (ch != '}');
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) {
	int i, n; char ch = ' ';
	ostr << '{';
	n = s.GetMaxPower();
	for (i = 0; i < n; i++) {
		if (s.IsMember(i)) {
			ostr << ch << ' ' << i; ch = ',';
		}
	}
	ostr << " }";
	return ostr;
}