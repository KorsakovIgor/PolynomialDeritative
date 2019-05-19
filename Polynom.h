#include <string>
#include "BynaryTree.h"

class Polynom
{
	public:
		//������� ��������
		int degree;

		Polynom(string);
		void DeletePolynom();

		//���������� ������ ����������� ����������
		string Deritative();

	private:
		//������ ������������� ��������
		int *coefficients;

		//������������� ������
		string NewStr(string);
		
		//����� ������� ��������
		void CalculateDegree(Tree*);

		//����� ������������� ��������
		void CalculateCoefficients(Tree*);

};