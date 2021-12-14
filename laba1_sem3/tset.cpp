#include "tset.h"

// Fake variables used as placeholders in tests



TSet::TSet(int mp) :BitField(mp)
{}

// конструктор копирования
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

TSet& TSet::operator=(const TSet& s) // присваивание
{
	this->BitField = s.BitField;
	this->MaxPower = s.GetMaxPower();
	return *this;
}

int TSet::GetMaxPower(void) const// получить макс. к-во эл-тов
{
	return this->MaxPower;
}

TSet::operator TBitField()
{
	std::printf("\noperator TBitField()");
	return BitField;
}

TSet TSet::operator<<(int k) //сдвиг битов влево
{
	this->BitField = BitField << k;
	return *this;

}

bool TSet::operator==(const TSet& s) // сравнение
{
	return  (BitField == s.BitField);
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

bool TSet::operator!=(const TSet& s) // сравнение
{
	return  (BitField != s.BitField);
}

TSet TSet::operator+(const TSet& s) // объединение 
{
	int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField | s.BitField;
	return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом 
{
	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet& s) // пересечение
{
	int size = MaxPower;
	if (s.MaxPower > MaxPower)
		size = s.MaxPower;
	TSet temp(size);
	temp.BitField = BitField & s.BitField;
	return temp;
}

TSet TSet::operator~(void) // дополнение
{
	TSet temp(~BitField);
	return temp;
}

// перегрузка ввода/вывода

istream& operator>>(istream& istr, TSet& s) // ввод
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