#include "Vector.h"

template <class T>
TVector<T>::TVector(int s, int si) {
    Size = s;
    StartIndex = si;
    pVector = new T[Size];
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = 0;
    }
}

template <class T>
TVector<T>::TVector(const TVector& v) {
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new T[v.Size];
    for (int i = 0; i < Size; i++) {
        pVector[i] = v.pVector[i];
    }
}

template <class T>
TVector<T>::~TVector() {
    delete[] pVector;
    pVector = nullptr;
}

template <class T>
T& TVector<T>::operator[](int pos) {
    return pVector[pos - StartIndex];
}

template<class T>
bool TVector<T>::operator==(const TVector& v)
{
    bool flag = 0;
    if ((Size == v.Size) & (StartIndex == v.StartIndex))
    {
        int n = 0;
        for (int i = 0; i < Size; i++)
        {
            if ((pVector[i] == v.pVector[i]))
                n++;
        }
        if (n == Size)
        {
            flag = 1;
        }
    }
    return flag;
}

template <class T>
TVector<T>& TVector<T>::operator=(const TVector& v) {
    if (this != &v) {
        if (Size != v.Size) {
            delete[] pVector;
            pVector = new T[v.Size];
        }
        Size = v.Size;
        StartIndex = v.StartIndex;
        for (int i = 0; i < Size; i++) {
            pVector[i] = v.pVector[i];
        }
    }
    return *this;
}

template <class T>
TVector<T> TVector<T>::operator+(const TVector<T>& v) {
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] + v.pVector[i];
    return temp;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T>& v) {
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] - v.pVector[i];
    return temp;
}

template<class T>
TVector<T> TVector<T>::operator*(const TVector<T>& v) {
    TVector temp(1);
    for (int i = 0; i < Size; i++) temp.pVector[0] = (pVector[i] * v.pVector[i]) + temp.pVector[0];
    return temp;
}

template<class T>
T& TVector<T>::GetValue(int pos)
{
    if ((pos < StartIndex) || (pos >= (Size + StartIndex)))
    {
        throw 1;
    }
    return pVector[pos];
}

template<class T>
TVector<T> TVector<T>::operator+(const T& val)
{
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] + val;
    return temp;
}

template<class T>
TVector<T> TVector<T>::operator-(const T& val)
{
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] - val;
    return temp;
}

template<class T>
TVector<T> TVector<T>::operator*(const T& val)
{
    TVector temp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        temp.pVector[i] = pVector[i] * val;
    return temp;
}

template class TVector<int>;
template class TVector<TVector<int>>;