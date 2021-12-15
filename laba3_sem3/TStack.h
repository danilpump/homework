#pragma once
#include <iostream>
#include <string>
const int MaxMemSize = 25; // максимальный размер памяти для стека
typedef double TELEM; // тип элемента СД
typedef TELEM* PTElem; // тип указателя на СД
using namespace std;
class TStack {
protected: // поля
	PTElem pMem; // указатель на массив элементов
	int MemSize; // размер памяти для СД
	int DataCount; // количество элементов в СД
	int Hi; // индекс вершины стека
	virtual int GetNextIndex(int index); // получить следующий индекс
public:
	void Print();
	TStack(int Size = MaxMemSize);//конструктор
	~TStack(); //деструктор
	bool IsEmpty(void) const; // контроль пустоты
	bool IsFull(void) const; // контроль переполнения
	void Put(const TELEM& Val);// добавить значение
	virtual TELEM Get(void); // извлечь значение
	TELEM End(void);
};