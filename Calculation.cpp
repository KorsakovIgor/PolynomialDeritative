#include "Calculation.h"
#include "iostream"

string Deritative(string polynom)
{
	Polynom *poly = new Polynom(polynom);
	string result = poly->Deritative();
	poly->DeletePolynom();
	return result;
}

void Menu()
{
	setlocale(LC_ALL, "Russian");
	int isContinue;
	do
	{
		system("cls");
		cout << "������� ������� (������:x^2; 2*x^100; -x^3-x^2)" << endl;
		string polynom;
		//getline(cin, polynom);
		cin >> polynom;
		cout << endl;
		cout << "����������� ��������:" << endl;
		cout << Deritative(polynom) << endl << endl;
		cout << "����������?(1/0)"<<endl;
		cin >> isContinue;
		cout << endl;
	} while (isContinue);

}