#include "Polynom.h"

Polynom::Polynom(string polymonStr)
{
	string poly = NewStr(polymonStr);
	if (poly != "")
	{
		Tree *tree = new Tree(poly);
		tree->CorrectTree(tree);
		CalculateDegree(tree);
		this->coefficients = new int[this->degree + 1]();
		CalculateCoefficients(tree);
		tree->DeleteTree(tree);
	}
}

string Polynom::NewStr(string polynomStr)
{
	//Удаление всего лишнего
	for (int i = 0; i < polynomStr.length(); i++)
	{
		if (polynomStr[i]!='+'&&polynomStr[i] != '-'&&polynomStr[i] != '*'&&!isdigit(polynomStr[i])&& polynomStr[i] != '^'&&polynomStr[i] != 'x')
		{
			polynomStr.erase(i, 1);
			i--;
		}
	}

	//Для считывания отлицательных коэффициентов
	for (int i = 0; i < polynomStr.length(); i++)
	{
		if (polynomStr[i] == '-' && i!=0)
		{
			polynomStr.insert(i, "+");
			i++;
		}

	}
	if (polynomStr != "")
	{
		return polynomStr + "+0*x^0"; //чтобы в корне дерева точно был +
	}
	else
	{
		return "";
	}
}

void Polynom::CalculateDegree(Tree *head)
{
	
	if (head->GetValue() == "^")
	{
		if (degree < head->right->GetIntValue())
		{
			degree = head->right->GetIntValue();
		}
	}
	if (head->left != nullptr) CalculateDegree(head->left);
	if (head->right != nullptr) CalculateDegree(head->right);
}

void Polynom::CalculateCoefficients(Tree *head)
{
	if (head->GetValue() == "*")
	{
		this->coefficients[head->right->right->GetIntValue()] += head->left->GetIntValue();
		
	}

	if (head->left != nullptr) CalculateCoefficients(head->left);
	if (head->right != nullptr) CalculateCoefficients(head->right);
}

string Polynom::Deritative()
{
	string result = "";
	if (degree != 0)
	{
		int *deritativeCoefficients = new int[degree]();

		for (int i = 0; i < degree; i++)
		{
			deritativeCoefficients[i] = coefficients[i + 1] * (i + 1);
		}

		for (int i = degree - 1; i > 1; i--)
		{
			if (deritativeCoefficients[i] > 0)
			{
				if (deritativeCoefficients[i] != 1)
				{
					result += "+" + to_string(deritativeCoefficients[i]) + "*x^" + to_string(i);
				}
				else
				{
					result += "+x^" + to_string(i);
				}
			}

			if (deritativeCoefficients[i] < 0)
			{
				if (deritativeCoefficients[i] != -1)
				{
					result += to_string(deritativeCoefficients[i]) + "*x^" + to_string(i);
				}
				else
				{
					result += "-x^" + to_string(i);
				}
			}
		}

		if (degree > 1)
		{
			if (deritativeCoefficients[1] > 0)
			{
				if (deritativeCoefficients[1] != 1)
				{
					result += "+" + to_string(deritativeCoefficients[1]) + "*x";
				}
				else
				{
					result += "+x";
				}
			}

			if (deritativeCoefficients[1] < 0)
			{
				if (deritativeCoefficients[1] != -1)
				{
					result += to_string(deritativeCoefficients[1]) + "*x";
				}
				else
				{
					result += "-x";
				}
			}
		}

		if (deritativeCoefficients[0] > 0)
		{
			result += "+" + to_string(deritativeCoefficients[0]);
		}

		if (deritativeCoefficients[0] < 0)
		{
			result += to_string(deritativeCoefficients[0]);
		}

		if (result[0] == '+') result.erase(0, 1);

		delete deritativeCoefficients;
	}
	else
	{
		result += "0";
	}
	return result;
}

void Polynom::DeletePolynom()
{
	if (coefficients != nullptr)
	{
		delete coefficients;
		coefficients = nullptr;
	}
	delete this;
}

