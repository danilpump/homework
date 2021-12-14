#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

using namespace std;

typedef int TELEM;

class TBitField
{
private:
	int _razmer;// длина битового поля - макс. к-во битов
	TELEM* pMem; // память для представления битового поля
	int  MemLen, Elem; // к-во эл-тов Мем для представления бит.поля
	int   GetMemIndex(const int n) const; // indx pmem for bit n      (#Î2)
	TELEM GetMemMask(const int n) const; // bit mask for bit n

	// методы реализации

public:
	//                                   (#О1)
	TBitField(const TBitField& bf);  // копирующий конструктор              (#П1)
	TBitField(int Elem);
	TBitField();

	TBitField& resize(int size);  //используем resize каждый раз когда новый массив не равен старому

	~TBitField();
	// доступ к битам
	int GetLength(void) const;      // получить длину (к-во битов)           (#О)
	void SetBit(const int i);       // установить бит                       (#О4)
	void ClrBit(const int i);       // очистить бит                         (#П2)
	int  GetBit(const int i) const; // получить значение бита               (#Л1)
	TBitField& operator=(const TBitField& bf); // присваивание              (#П3)

	TBitField operator>>(int k); //сдвиг битов в право
	TBitField operator<<(int k); //сдвиг битов в лево
	bool operator==(const TBitField& bf); // сравнение 
	bool operator!=(const TBitField& bf); // сравнение
	TBitField operator|(const TBitField& bf); // операция "или" 
	TBitField operator~(void); //операция отрицания

	TBitField  operator&(const TBitField& bf); // операция "и"  
	void print_array();
	bool test();
};
#endif