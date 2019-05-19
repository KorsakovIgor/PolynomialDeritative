#include <string>
#include <cstdlib>

using namespace std;

class Tree
{
	public:
		//Атрибуты
		//Левый потомок
		Tree *left;
		//Правый потомок
		Tree *right;


		//Методы
		//Конструктор(создание дерева по строке)
		Tree(string);

		//Получение значения
		string GetValue();

		//Получение значения 
		int GetIntValue();
		
		//Удалить всё дерево
		void DeleteTree(Tree*);
		
		//Корректировка дерева
		void CorrectTree(Tree*);

	private:
		//Атрибуты
		//Значение
		string value;

		

		
};
