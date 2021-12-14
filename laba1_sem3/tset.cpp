#include "tset.h"

// Fake variables used as placeholders in tests



TSet::TSet(int mp)
{
	BitField = mp;
	MaxPower = BitField.GetLength();
}

// êîíñòðóêòîð êîïèðîâàíèÿ
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

TSet& TSet::operator=(const TSet& s) // ïðèñâàèâàíèå
{
	this->BitField = s.BitField;
	this->MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::GetMaxPower(void) const// ïîëó÷èòü ìàêñ. ê-âî ýë-òîâ
{
	return this->MaxPower;
}

TSet::operator TBitField()
{
	std::printf("\noperator TBitField()");
	return BitField;
}

TSet TSet::operator<<(int k) //ñäâèã áèòîâ âëåâî
{
	this->BitField = BitField << k;
	return *this;
}

TSet TSet::operator>>(int k) //ñäâèã áèòîâ âëåâî
{
	this->BitField = BitField >> k;
	return *this;
}

bool TSet::operator==(const TSet& s) // ñðàâíåíèå
{
	return  (BitField == s.BitField);
}

int TSet::IsMember(const int Elem) const // ýëåìåíò ìíîæåñòâà?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // âêëþ÷åíèå ýëåìåíòà ìíîæåñòâà
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // èñêëþ÷åíèå ýëåìåíòà ìíîæåñòâà
{
	BitField.ClrBit(Elem);
}

// òåîðåòèêî-ìíîæåñòâåííûå îïåðàöèè

bool TSet::operator!=(const TSet& s) // ñðàâíåíèå
{
	return  (BitField != s.BitField);
}

TSet TSet::operator+(const TSet& s) // îáúåäèíåíèå 
{
	/*int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField | s.BitField;
	return temp;*/
	BitField = BitField << s.MaxPower;
	BitField = BitField | s.BitField;
	return *this;
}

TSet TSet::operator+(const int Elem) // îáúåäèíåíèå ñ ýëåìåíòîì 
{
	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // ðàçíîñòü ñ ýëåìåíòîì
{
	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet& s) // ïåðåñå÷åíèå
{
	int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField & s.BitField;
	return temp;
}

TSet TSet::operator~(void) // äîïîëíåíèå
{
	TSet temp(~BitField);
	return temp;
}

// ïåðåãðóçêà ââîäà/âûâîäà

istream& operator>>(istream& istr, TSet& s) // ââîä
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
