#include "TFormula.h"

TFormula::TFormula(char form[])
{
    SIZEF = strlen(form);
    SIZEP = SIZEF;
    Formula = new char[SIZEF];
    PostfixForm = new char[255];

    for (int i = 0; i < strlen(form); i++) {
        Formula[i] = form[i];
        PostfixForm[i] = 0;
    }
}

TFormula::~TFormula()
{
    delete[]Formula;
    delete[]PostfixForm;
    SIZEF = 0;
    SIZEP = 0;
}

int TFormula::proverka(char i) {
    int s = -1;
    switch (i)
    {
    case '(': s = 0; break;
    case ')': s = 1; break;
    case '+': s = 2; break;
    case '-': s = 2; break;
    case '*': s = 3; break;
    case '/': s = 3; break;
    case ' ': s = -2; break;
    }
    return s;
}

void TFormula::PostfixFormPrint(void)
{
    for (int i = 0; i < SIZEP; i++)
        cout << PostfixForm[i];
}

void TFormula::FormulaConverter(void)
{
    TStack INTSTACK;
    TStack CHARSTACK;
    int flag = 0;
    int s;
    int j = 0;
    for (int i = 0; i < SIZEF; i++) {
        s = proverka(Formula[i]);
        if (s != -2) {   // если символ не €вл€етс€ пробелом
            if (s == -1) {// если символ не знак, не скобка и не пробел (т.е. €вл€етс€ числом или его частью)
                PostfixForm[j] = Formula[i];
                j++;
                flag = 1;
                PostfixForm[j] = ' ';
            }
            else {
                if ((s == 2 && i == 0) || (flag == 0 && s == 2)) { // если перед числом стоит знак (например -3)
                    PostfixForm[j] = Formula[i];
                    j++;
                    PostfixForm[j] = ' ';
                }
                else {
                    PostfixForm[j] = ' ';
                    j++;
                    PostfixForm[j] = ' ';
                    if ((s == 0) || (s > INTSTACK.End()) || (INTSTACK.IsEmpty() != 0)) { // если это открывающа€ скобка или действие с бќльшим приоритетом
                        if (s == 0)  //если открывающа€ скобка
                            j--;
                        flag = 0;
                        INTSTACK.Put(s);
                        CHARSTACK.Put(i);
                    }
                    else {
                        if (s == 1) { // если закрывающа€ скобка
                            while (INTSTACK.End() != 0) { // пока не попадетс€ открывающа€ скобка выписывание операций из стека
                                PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
                                INTSTACK.Get();
                                j++;
                                PostfixForm[j] = ' ';
                                j++;
                                PostfixForm[j] = ' ';
                            }
                            j--;
                            INTSTACK.Get();
                            CHARSTACK.Get();
                        }
                        else {
                            while (s <= INTSTACK.End()) { // если действие с меньшим приоритетом
                                PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
                                INTSTACK.Get();
                                j++;
                                PostfixForm[j] = ' ';
                                j++;
                                PostfixForm[j] = ' ';
                            }
                            INTSTACK.Put(s);
                            CHARSTACK.Put(i);
                        }
                    }
                }
            }
        }
    }

    if (INTSTACK.End() == 1) { //если в конце закрывающа€ скобка, то убирает скобки в записи
        j--;
        INTSTACK.Get();
        INTSTACK.Get();
        CHARSTACK.Get();
        CHARSTACK.Get();
    }

    while (CHARSTACK.IsEmpty() == 0) {       //переписывание в постфиксную форму
        j++;
        PostfixForm[j] = Formula[(int)CHARSTACK.Get()];
        j++;
        PostfixForm[j] = ' ';
    }
    SIZEP = j;
}

double TFormula::alg(double p2, double p1, char s) {
    double res = -1;
    switch (s)
    {
    case '+': res = p1 + p2; break;
    case '-': res = p1 - p2; break;
    case '*': res = p1 * p2; break;
    case '/':
        if (p2 != 0)  res = p1 / p2;
        else res = 999999999;
        break;
    }
    return res;
}
double TFormula::FormulaCalculator(void)
{
    int min = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp = 0;
    double p1 = 0, p2 = 0;
    double res = 0;
    TStack INTSTACK;
    for (int i = 0; i < SIZEP; i++) {
        if ((PostfixForm[i] == '-') && (PostfixForm[i + 1] != ' ') && (i != SIZEP - 1)) {
            INTSTACK.Put(-1);
            temp = 0;
            min = 1;
        }
        else {
            if ((PostfixForm[i] == '+') || (PostfixForm[i] == '-') || (PostfixForm[i] == '*') || (PostfixForm[i] == '/')) {
                p2 = INTSTACK.Get();
                p1 = INTSTACK.Get();
                res = alg(p2, p1, PostfixForm[i]);
                if (res == 999999999) {
                    cout << "вычисление невозможно" << endl;
                    return 1;
                }
                INTSTACK.Put(res);
            }
            else {
                if (PostfixForm[i] == ' ') {
                    temp = 1;
                }
                else {
                    if (PostfixForm[i] == '.') {
                        p1 = 0;
                        temp2 = INTSTACK.Get();
                        for (int j = i + 1; PostfixForm[j] != ' '; j++) {
                            temp3 = temp3 * 10 + (PostfixForm[j] - '0');
                            p1++;
                            i = j;
                        }
                        if (temp2 < 0)
                            INTSTACK.Put(temp2 - (static_cast<double>(temp3) / pow(10, p1)));
                        else
                            INTSTACK.Put(temp2 + (static_cast<double>(temp3) / pow(10, p1)));
                        temp3 = 0;
                    }
                    else {
                        if (temp == 0 && i > 0) {
                            temp2 = INTSTACK.Get();
                            if (min == 1)
                            { INTSTACK.Put(temp2 * (PostfixForm[i] - '0')); min = 0; }
                            else
                                INTSTACK.Put((temp2 * 10) + PostfixForm[i] - '0');
                        }
                        else { INTSTACK.Put(PostfixForm[i] - '0'); temp = 0; }
                    }
                }
            }
        }
    }
    double r = INTSTACK.End();
    return r;
}