#include <string>
#include <cstdlib>

using namespace std;

class Tree
{
	public:
		//��������
		//����� �������
		Tree *left;
		//������ �������
		Tree *right;


		//������
		//�����������(�������� ������ �� ������)
		Tree(string);

		//��������� ��������
		string GetValue();

		//��������� �������� 
		int GetIntValue();
		
		//������� �� ������
		void DeleteTree(Tree*);
		
		//������������� ������
		void CorrectTree(Tree*);

	private:
		//��������
		//��������
		string value;

		

		
};
