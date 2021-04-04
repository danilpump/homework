#include "ClassVector.h"
#include <cstdlib>
#include <ctime>

ClassVector::ClassVector()
{
    size = 4;
    vec = new int[size];

    for (int i = 0; i < size; i++)
        vec[i] = 0;
}

ClassVector::ClassVector(ClassVector& q)
{
    size = q.size;
    vec = new int[size];
    for (int i = 0; i < size; i++)
        vec[i] = q.vec[i];
}

ClassVector::ClassVector(int s)
{
    srand(time(NULL));
    int temp;

    size = s;
    vec = new int[size];

    for (int i = 0; i < size; i++)
    {
        temp = rand() % 20 + 1;
        vec[i] = temp;
    }
}

ClassVector::~ClassVector()
{
    delete[] vec;
}

int ClassVector::getElem(int i)
{
    return vec[i-1];
}

void ClassVector::setElem(int i, int el)
{
    if (0 < i || i <= size)
        vec[i-1] = el;
    else
        cout << "Invalid" << endl;
}

int ClassVector::getsize()
{
    return size;
}

void ClassVector::setsize(int s)
{
    int* temp = new int[s];

    if (s <= size)
    {
        for (int i = 0; i < s; i++)
            temp[i] = vec[i];
    }
    else
    {
        for (int i = 0; i < size; i++)
            temp[i] = vec[i];
        for (int i = size; i < s; i++)
            temp[i] = 0;
    }
    size = s;
    delete[] vec;
    vec = new int[size];

    for (int i = 0; i < size; i++)
        vec[i] = temp[i];
}

double ClassVector::length()
{
    double temp = 0;
    for (int i = 0; i < size; i++)
        temp += pow(vec[i], 2);
    temp = sqrt(temp);
    return temp;
}

int ClassVector::operator*(const ClassVector& q)
{
    int temp = 0;
    if (size == q.size)
        for (int i = 0; i < size; i++)
            temp += vec[i] * q.vec[i];
    else
        cout << "Size of vectors is different" << endl;
    return temp;
}

ClassVector ClassVector::operator+(const ClassVector& q)
{
    ClassVector temp(q.size);
    if (size == q.size)
        for (int i = 0; i < size; i++)
            temp.vec[i] = vec[i] + q.vec[i];
    else
        cout << "Size of vectors is different" << endl;
    return temp;
}

ClassVector& ClassVector::operator=(const ClassVector& q)
{
    if (size == q.size)
        for (int i = 0; i < size; i++)
            vec[i] = q.vec[i];
    else
        cout << "Size of vectors is different" << endl;
    return *this;
}