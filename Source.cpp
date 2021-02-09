#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct List
{
	string data;
	List* next_block;
	List* prev_block;
};
int GetSize()
{
	int size;
	while (!(cin >> size) || (cin.peek() != '\n') || (size < 1))
	{
		cin.clear();
		while (cin.get() != '\n')
		{
			cout << "Введите корректное число!\t";
		}
	}
	return size;
}
List* Create_list(int size)
{
	List* first_element = nullptr;
	List* current_element;
	if (size == 1)
	{
		cout << "Введите 0-й элемент списка:\t";
		current_element = new List;
		cin >> current_element->data;
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->prev_block = nullptr;
	}
	else
	{
		cout << "Введите 0-й элемент списка:\t";
		current_element = new List;
		cin >> current_element->data;
		first_element = current_element;
		current_element->next_block = nullptr;
		current_element->prev_block = nullptr;
		for (int i = 1; i < size; i++)
		{
			cout << "Введите " << i << "-й элемент списка:\t";
			List* new_element = new List;
			current_element->next_block = new_element;
			new_element->prev_block = current_element;
			current_element = new_element;
			cin >> current_element->data;
			current_element->next_block = nullptr;
		}
	}
	return first_element;
}
List* Pop(List*& first_element)
{
	List* tmp = first_element->next_block;
	delete first_element;
	first_element = tmp;
	return first_element;
}
List* Push_list(List* first_element, string value)
{
	List* current_element = first_element;
	if (first_element == nullptr)
	{
		first_element = new List;
		first_element->data = value;
		first_element->next_block = nullptr;
		first_element->prev_block = nullptr;
	}
	else
	{
		{
			while (current_element->next_block != nullptr)

				current_element = current_element->next_block;
		}
		List* new_element = new List;
		new_element->data = value;
		new_element->next_block = nullptr;
		new_element->prev_block = current_element;
		current_element->next_block = new_element;
	}
	return first_element;
}
List* Print_list(List*& first_element)
{
	vector <string> tmp;
	int i = 0;
	while (first_element != nullptr)
	{
		cout << i << "-й элемент очереди:\t" << first_element->data << endl;
		i++;
		tmp.push_back(first_element->data);
		first_element = Pop(first_element);
	}
	int j = 0;
	while (j < tmp.size())
	{
		first_element = Push_list(first_element, tmp[j]);
		j++;
	}
	return first_element;
}
bool Add_element(List*& first_element)
{
	string value;
	vector <string> tmp;
	bool check = false;
	cout << "Введите значение, после которого нужно добавить элемент:\t";
	cin >> value;
	while (first_element != nullptr)
	{

		tmp.push_back(first_element->data);
		first_element = Pop(first_element);

	}
	vector <string> temper2;
	for (int i = 0; i < tmp.size(); i++) 
	{
		if (tmp[i] == value) 
		{
			check = true;
			string temp;
			cout << "Введите значение нового элемента в очереди:\t";
			cin >> temp;
			temper2.push_back(tmp[i]);
			temper2.push_back(temp);
		}
		else 
		{
			temper2.push_back(tmp[i]);
		}
	}
	for (int j = 0; j < temper2.size(); j++)
	{	
		first_element = Push_list(first_element, temper2[j]);
	}
	return check;
}
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите размер очереди:\t";
	int size = GetSize();
	List* que = Create_list(size);
	que = Print_list(que);
	cout << "============================\n";
	if (Add_element(que))
	{
		cout << "============================\n";
		Print_list(que);
		cout << "============================\n";
	}
	else
	{
		cout << "============================\n";
		cout << "Такого элемента в очереди нет!\n";
		cout << "============================\n";
	}
}