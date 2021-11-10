// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len)
{
    BitLen = len;
    MemLen = (len + 31) / 32;
    pMem = new TELEM[MemLen];
    if (pMem != NULL)
        for (int i = 0; i < MemLen; i++)
            pMem[i] = 0;
}

TBitField::TBitField(const TBitField& bf) // конструктор копирования
{
    BitLen = bf.BitLen;
    MemLen = bf.MemLen;
    pMem = new TELEM[MemLen];
    if (pMem != NULL)
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return (n/32);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    TELEM mask = n - GetMemIndex(n) * 32;
    mask = pow(2, mask);
    return mask;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if ((n > -1) && (n < BitLen))
        pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if ((n > -1) && (n < BitLen))
        pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if ((pMem[GetMemIndex(n)] & GetMemMask(n)) != NULL)
        return 1;
    else
        return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField& bf) // присваивание
{
    BitLen = bf.BitLen;
    if (MemLen != bf.MemLen)
    {
        MemLen = bf.MemLen;
        if (pMem != NULL)
            delete[] pMem;
        pMem = new TELEM[MemLen];
    }
    if (pMem != NULL)
    {
        for (int i = 0; i < MemLen; i++)
            pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField& bf) const // сравнение
{
    if (BitLen == bf.BitLen)
    {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return 0;
        return 1;
    }
    return 0;
}

int TBitField::operator!=(const TBitField& bf) const // сравнение
{
    if (BitLen == bf.BitLen)
    {
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i])
                return 1;
        return 0;
    }
    return 1;
}

TBitField TBitField::operator|(const TBitField& bf) // операция "или"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;

    TBitField tmp(len);

    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < bf.MemLen; i++)
        tmp.pMem[i] |= bf.pMem[i];

    return tmp;
}

TBitField TBitField::operator&(const TBitField& bf) // операция "и"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;

    TBitField tmp(len);

    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < bf.MemLen; i++)
        tmp.pMem[i] &= bf.pMem[i];

    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(BitLen);

    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = ~pMem[i];

    return tmp;
}

// ввод/вывод

istream& operator>>(istream& istr, TBitField& bf) // ввод
{
    char ch;
    for (int i = 0; i < bf.GetLength(); i++)
    {
        cin >> ch;
        if (ch == '0')
            bf.ClrBit(i);
        else if (ch == '1')
            bf.SetBit(i);
        else i--;
    }
    return istr;
}

ostream& operator<<(ostream& ostr, const TBitField& bf) // вывод
{
    for (int i = 0; i < bf.GetLength(); i++)
        if (bf.GetBit(i))
            ostr << '1';
        else
            ostr << '0';
    return ostr;
}