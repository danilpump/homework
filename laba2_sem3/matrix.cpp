#include "matrix.h"
template <class T>
TMatrix<T>::TMatrix(int s) :TVector<TVector<T>>(s) {
    for (int i = 0; i < s; i++) this->pVector[i] = TVector<T>(s - i, i);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& mt) : TVector<TVector<T>>(mt) {}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>>& mt) : TVector<TVector<T>>(mt) {}

template<class T>
bool TMatrix<T>::operator==(const TMatrix& mt) { return  TVector<TVector<T>>::operator==(mt); }

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt) { return  TVector<TVector<T>>::operator+(mt); }

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt) { return  TVector<TVector<T>>::operator-(mt); }

template <class T>
TMatrix<T> TMatrix<T>::operator* (const TMatrix& mt) {
    TMatrix<T> temp(this->GetSize());
    int i, j, k;
    for (i = 0; i < temp.Size; ++i)
        for (j = i; j < temp.Size; ++j)
            for (k = i; k < j + 1; ++k)
                temp[i][j] += this->pVector[i][k] * mt.pVector[k][j];
    return temp;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& mt)
{
    if (this != &mt)
    {
        if (this->Size != mt.Size)
        {
            delete[] this->pVector;
            this->pVector = new TVector<T>[mt.Size];
        }
        this->Size = mt.Size;
        this->StartIndex = mt.StartIndex;
        for (int i = 0; i < this->Size; i++)
            this->pVector[i] = mt.pVector[i];
    }
    return *this;
}
template class TMatrix<int>;