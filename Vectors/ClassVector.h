#include <iostream>


using namespace std;

class ClassVector
{
private:
    int size;
    int* vec;
public:
    ClassVector();
    ClassVector(ClassVector& q);
    ClassVector(int s);
    ~ClassVector();

    int getElem(int i);

    void setElem(int i, int el);

    int getsize();

    void setsize(int s);

    double length();

    int operator*(const ClassVector& q);

    ClassVector operator+(const ClassVector& q);

    ClassVector& operator=(const ClassVector& q);

    friend ostream& operator<<(ostream& os, const ClassVector& q)
    {
        for (int i = 0; i < q.size; i++)
            os << q.vec[i] << ' ';
        return os;
    }
};
