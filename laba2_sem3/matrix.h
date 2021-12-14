#pragma once
#include "Vector.h"
template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
    TMatrix(int s = 10);
    TMatrix(const TMatrix& mt); // �����������
    TMatrix(const TVector<TVector<T> >& mt); // �������������� ����
    bool operator==(const TMatrix& mt); // ���������
    TMatrix& operator= (const TMatrix& mt); // ������������
    TMatrix operator+ (const TMatrix& mt); // ��������
    TMatrix operator- (const TMatrix& mt); // ���������
    TMatrix operator* (const TMatrix& mt); // ���������
    // ���� / �����
    friend istream& operator>>(istream& in, TMatrix& mt) {
        for (int i = 0; i < mt.Size; i++) in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt) {
        for (int i = 0; i < mt.Size; i++) out << mt.pVector[i] << endl;
        return out;
    }
};