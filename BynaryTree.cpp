#include "BynaryTree.h"


string Tree::GetValue()
{
	return this->value;
}

int Tree::GetIntValue()
{
	return atoi(this->GetValue().c_str());
}

Tree::Tree(string polynomStr)
{
	this->left = nullptr;
	this->right = nullptr;

	//Позиция определенного знака в строке
	int pos;

	//Поиск + в строке и деление строки на 2 части: до + и после + 
	if (polynomStr.find('+') != -1)
	{
		pos = polynomStr.find('+');
		this->value = '+';
		string leftStr;
		string rightStr;

		//Строка до +
		leftStr.assign(polynomStr, 0, pos);

		//Строка после +
		rightStr.assign(polynomStr, pos + 1, polynomStr.length() - pos - 1);

		//В левого ребенка - левую строку, в правого - правую
		if(leftStr.length()!=0) this->left = new Tree(leftStr);
		if (rightStr.length() != 0) this->right = new Tree(rightStr);

	}

	//Поиск * в строке и деление строки на 2
	else if (polynomStr.find('*') != -1)
	{
		pos = polynomStr.find('*');
		this->value = '*';
		string leftStr = "";
		string rightStr= "";

		//Строка до *
		leftStr.assign(polynomStr, 0, pos);

		//Строка после *
		rightStr.assign(polynomStr, pos + 1, polynomStr.length() - pos - 1);

		//В левого ребенка - левую строку, в правого - правую
		if (leftStr.length() != 0) this->left = new Tree(leftStr);
		if (rightStr.length() != 0) this->right = new Tree(rightStr);
	}

	//Поиск ^ в строке и деление ее на 2 части
	else if (polynomStr.find('^') != -1)
	{
		pos = polynomStr.find('^');
		this->value = '^';
		string leftStr = "";
		string rightStr = "";

		//Строка до ^
		leftStr.assign(polynomStr, 0, pos);

		//Строка после ^
		rightStr.assign(polynomStr, pos + 1, polynomStr.length() - pos - 1);

		//В левого ребенка - левую строку, в правого - правую
		if (leftStr.length() != 0) this->left = new Tree(leftStr);
		if (rightStr.length() != 0) this->right = new Tree(rightStr);
	}

	//Если знаков не нашли, то это число или х
	else 
	{
		this->value = polynomStr;
	}
}

void Tree::CorrectTree(Tree *head)
{
	if (head->GetValue() == "*"&&head->right->GetValue() != "^")
	{
		DeleteTree(head->right);
		head->right = new Tree("^");
		head->right->left = new Tree("x");
		head->right->right = new Tree("1");
	}
	if (head->GetValue() == "+"&&head->left->GetValue() != "+"&&head->left->GetValue() != "*")
	{
		if (head->left->GetValue() == "^")
		{
			Tree *tree = head->left;
			head->left = new Tree("*");
			if (tree->left->GetValue()[0]!='-') head->left->left = new Tree("1");
			else head->left->left = new Tree("-1");
			head->left->right = tree;
		}
		else if (head->left->GetValue() != "x"&&head->left->GetValue() != "-x")
		{
			string tree = head->left->GetValue();
			DeleteTree(head->left);
			head->left = new Tree("*");
			head->left->left = new Tree (tree);
			head->left->right = new Tree("^");
			head->left->right->left = new Tree("x");
			head->left->right->right = new Tree("0");

		}
		else if (head->left->GetValue() != "-x")
		{
			DeleteTree(head->left);
			head->left = new Tree("*");
			head->left->left = new Tree("1");
			head->left->right = new Tree("^");
			head->left->right->left = new Tree("x");
			head->left->right->right = new Tree("1");

		}
		else
		{
			DeleteTree(head->left);
			head->left = new Tree("*");
			head->left->left = new Tree("-1");
			head->left->right = new Tree("^");
			head->left->right->left = new Tree("x");
			head->left->right->right = new Tree("1");
		}
	}

	if (head->GetValue() == "+"&&head->right->GetValue() != "+"&&head->right->GetValue() != "*")
	{
		if (head->right->GetValue() == "^")
		{
			Tree *tree = head->right;
			head->right = new Tree("*");
			if(tree->left->GetValue()[0]!='-') head->right->left = new Tree("1");
			else head->right->left = new Tree("-1");
			head->right->right = tree;
		}
		else if (head->right->GetValue() != "x"&&head->right->GetValue() != "-x")
		{
			string tree = head->right->GetValue();
			DeleteTree(head->right);
			head->right = new Tree("*");
			head->right->left = new Tree(tree);
			head->right->right = new Tree("^");
			head->right->right->left = new Tree("x");
			head->right->right->right = new Tree("0");
		}
		else if (head->right->GetValue()!="-x")
		{
			DeleteTree(head->right);
			head->right = new Tree("*");
			head->right->left = new Tree("1");
			head->right->right = new Tree("^");
			head->right->right->left = new Tree("x");
			head->right->right->right = new Tree("1");
		}
		else
		{
			DeleteTree(head->right);
			head->right = new Tree("*");
			head->right->left = new Tree("-1");
			head->right->right = new Tree("^");
			head->right->right->left = new Tree("x");
			head->right->right->right = new Tree("1");
		}
	}

	if (head->left != nullptr) CorrectTree(head->left);
	if (head->right != nullptr) CorrectTree(head->right);
}

void Tree::DeleteTree(Tree *head)
{
	if (head->left != nullptr) DeleteTree(head->left);
	if (head->right != nullptr) DeleteTree(head->right);
	delete head;
	head = nullptr;
}