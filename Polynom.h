#include <string>
#include "BynaryTree.h"

class Polynom
{
	public:
		//Степень полинома
		int degree;

		Polynom(string);
		void DeletePolynom();

		//Возвращает строку производной многочлена
		string Deritative();

	private:
		//Массив коэффициентов полинома
		int *coefficients;

		//Преобазование строки
		string NewStr(string);
		
		//Поиск степени полинома
		void CalculateDegree(Tree*);

		//Поиск коэффициентов полинома
		void CalculateCoefficients(Tree*);

};