#pragma once
#include <iostream>
using namespace std;
template <class T>
class TVector
{
protected:
    T* pVector;
    int Size; // размер вектора
    int StartIndex; // индекс первого элемента вектора
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v); // конструктор копирования
    ~TVector();
    int GetSize() { return Size; } // размер вектора
    int GetStartIndex() { return StartIndex; } // индекс первого элемента
    T& GetValue(int pos); // доступ с контролем индекса
    T& operator[](int pos); // доступ
    bool operator==(const TVector& v); // сравнение
    TVector& operator= (const TVector& v); // присванивание
    // скалярные операции
    TVector operator+ (const T& val); // прибавить скаляр
    TVector operator- (const T& val); // вычесть скаляр
    TVector operator* (const T& val); // умножить на скаляр
    // векторные операции
    TVector operator+ (const TVector& v); // сложение
    TVector operator- (const TVector& v); // вычитание
    TVector operator* (const TVector& v); // произведение
    // ввод-вывод 
    friend istream& operator>>(istream& in, TVector& v) {
        for (int i = 0; i < v.Size; i++) in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v) {
        for (int i = 0; i < v.Size; i++) out << v.pVector[i] << ' ';
        return out;
    }
};