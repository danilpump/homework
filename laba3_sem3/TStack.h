#pragma once
#include <iostream>
#include <string>
const int MaxMemSize = 25; // ������������ ������ ������ ��� �����
typedef double TELEM; // ��� �������� ��
typedef TELEM* PTElem; // ��� ��������� �� ��
using namespace std;
class TStack {
protected: // ����
	PTElem pMem; // ��������� �� ������ ���������
	int MemSize; // ������ ������ ��� ��
	int DataCount; // ���������� ��������� � ��
	int Hi; // ������ ������� �����
	virtual int GetNextIndex(int index); // �������� ��������� ������
public:
	void Print();
	TStack(int Size = MaxMemSize);//�����������
	~TStack(); //����������
	bool IsEmpty(void) const; // �������� �������
	bool IsFull(void) const; // �������� ������������
	void Put(const TELEM& Val);// �������� ��������
	virtual TELEM Get(void); // ������� ��������
	TELEM End(void);
};