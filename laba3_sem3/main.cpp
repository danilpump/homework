#include <iostream>
#include "TFormula.h"
#include "TStack.h"

void main() {
    setlocale(LC_ALL, "Russian");

    double r;
    
    {
        char d1[] = "(1+2)/(3+4*6.7)-5.3*(4.4)";
        cout << "Формула : " << d1 << endl;
        TFormula a1(d1);
        a1.FormulaConverter();
        cout << "Expected pizExpr: 1 2 + 3 4 6.7 * + / 5.3 4.4 * -" << endl;
        cout << "Actual pizExpr:   ";
        a1.PostfixFormPrint();
        cout << endl;
        r = a1.FormulaCalculator();
        cout << "Expected res: -23,2193" << endl;
        cout << "Actual res:   " << r << endl;
        cout << endl;
    }
    
    {
        char d1[] = "(((1 + 23) * 1 - 22) + 5) * 2 - 7";
        cout << "Формула : " << d1 << endl;
        TFormula a1(d1);
        a1.FormulaConverter();
        cout << "Expected pizExpr: 1 23 + 1 * 22 - 5 + 2 * 7 -" << endl;
        cout << "Actual pizExpr:   ";
        a1.PostfixFormPrint();
        cout << endl;
        r = a1.FormulaCalculator();
        cout << "Expected res: 7" << endl;
        cout << "Actual res:   " << r << endl;
        cout << endl;
    }
    cout << endl;

    system("pause");
}