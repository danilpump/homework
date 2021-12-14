#pragma once
#include <iostream>
using namespace std;
template <class T>
class TVector
{
protected:
    T* pVector;
    int Size; // ������ �������
    int StartIndex; // ������ ������� �������� �������
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v); // ����������� �����������
    ~TVector();
    int GetSize() { return Size; } // ������ �������
    int GetStartIndex() { return StartIndex; } // ������ ������� ��������
    T& GetValue(int pos); // ������ � ��������� �������
    T& operator[](int pos); // ������
    bool operator==(const TVector& v); // ���������
    TVector& operator= (const TVector& v); // �������������
    // ��������� ��������
    TVector operator+ (const T& val); // ��������� ������
    TVector operator- (const T& val); // ������� ������
    TVector operator* (const T& val); // �������� �� ������
    // ��������� ��������
    TVector operator+ (const TVector& v); // ��������
    TVector operator- (const TVector& v); // ���������
    TVector operator* (const TVector& v); // ������������
    // ����-����� 
    friend istream& operator>>(istream& in, TVector& v) {
        for (int i = 0; i < v.Size; i++) in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v) {
        for (int i = 0; i < v.Size; i++) out << v.pVector[i] << ' ';
        return out;
    }
};