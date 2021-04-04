#include "ClassVector.h"
#include <iostream>

using namespace std;

void main()
{
    ClassVector vec1, vec2(4), vec3, vec4(vec2);
    int temp = 0;
    double temp2 = 0;

    for (int i = 1; i < 5; i++)
        vec1.setElem(i, i);

    cout << "ClassVector vec1 = " << vec1 << endl;
    cout << "ClassVector vec2(4) = " << vec2 << endl;
    cout << "ClassVector vec3 = " << vec3 << endl;
    cout << "ClassVector vec4(vec2) = " << vec4 << endl;
    cout << "int temp = " << temp << endl;
    cout << "double temp2 = " << temp2 << endl << endl;

    vec3 = vec1 + vec2;
    cout << "vec3 = vec1 + vec2; = " << vec3 << endl << endl;

    temp = vec1 * vec2;
    cout << "temp = vec1 * vec2; = " << temp << endl << endl;

    temp2 = vec1.length();
    cout << "temp2 = vec1.length(); = " << temp2 << endl << endl;

    vec2.setElem(4, 10);
    cout << "vec2.setElem(4, 10);" << endl;
    cout << "vec2 = " << vec2 << endl << endl;

    temp = vec2.getElem(4);
    cout << "temp = vec2.getElem(4); = " << temp << endl << endl;

    vec2.setsize(6);
    cout << "vec2.setsize(6);" << endl;
    cout << "vec2 = " << vec2 << endl << endl;

    temp = vec2.getsize();
    cout << "temp = vec2.getsize(); = " << temp << endl << endl;

    vec2.setsize(3);
    cout << "vec2.setsize(3);" << endl;
    cout << "vec2 = " << vec2 << endl << endl;

    system("pause");
}