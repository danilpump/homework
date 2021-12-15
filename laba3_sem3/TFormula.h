#pragma once
#include "TStack.h"
#include <cstring>
const int MaxLength = 255; // максимальный размер входной строки
class TFormula {
private:
	char* Formula; // входная строка
	char* PostfixForm; // постфиксная запись
	int SIZEF;
	int SIZEP;
public:
	TFormula(char form[]);
	~TFormula();
	int proverka(char i);      // проверка для конвертации
	void PostfixFormPrint(void);
	void FormulaConverter(void); // перевод в постфиксную форму
	double alg(double p2, double p1, char s);
	double FormulaCalculator(void); // вычисление результата
};