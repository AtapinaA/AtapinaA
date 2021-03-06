/* 29.В заданной матрице вывести р-ю строку и q-й столбец.
Атапина Александра 91гр.*/


#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

//ввод размерности из файла
void InputMatrSizeFile(ifstream &in, int* n, int* m)
{
	if (in.is_open())
	{
		in >> *n;
		in >> *m;
	}
}
int** CreateMatr(int n, int m)
{
	int **A; //создаём матрицу введённой размерности
	A = new int *[n]; //через массив указателей
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	return A;
}

//ввод матрицы из файла
void InputMatrFile(int** mas, ifstream &FileIn, int n, int m)
{
	if (FileIn.is_open())
	{
		cout << "Введенная матрица:\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				FileIn >> mas[i][j];
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
	}
}
//ввод числа с заданными границами
int InputNum(const char *txt, int min, int max)
{
	int num;
	cout << txt << endl; //вывод вопроса на экран
	cin >> num;
	while ((num < min) || (num > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> num;
	}
	return num;
}
//ввод матрицы с клавиатуры
void InputMatrKey(int** mas, int* n, int* m)
{
	*n = InputNum("Введите количество строк", 0, 50);
	*m = InputNum("Введите количество столбцов", 0, 50);
	for (int i = 0; i < *n; ++i)
		mas[i] = new int[*m];
	cout << " Заполните массив: ""\n";
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> mas[i][j];
		}
	}
	cout << "Введенная матрица:\n";
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < *m; ++j)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}
//вывод результата в файл(p строка, q столбец)
void OutputResFile(int **mas, int n, int m, int p, int q)
{
	ofstream FileOut("output.txt");
	if (FileOut.is_open())
	{
		FileOut << p << "-я cтрока:" << endl;
		for (int j = 0; j < m; ++j)
			FileOut << mas[p - 1][j] << " ";
		FileOut << endl;
		FileOut << q << "-й cтолбец:" << endl;
		for (int i = 0; i < n; ++i)
			FileOut << mas[i][q - 1] << endl;
	}

	FileOut.close();
}
//вывод результата в консоль
void OutputResKey(int **mas, int n, int m, int p, int q)
{
	cout << p << "-я cтрока:" << endl;
	for (int j = 0; j < m; ++j)
		cout << mas[p - 1][j] << " ";
	cout << endl;
	cout << q << "-й cтолбец:" << endl;
	for (int i = 0; i < n; ++i)
		cout << mas[i][q - 1] << endl;
}
//выбор пункта меню ввода
int SelectInputMenuItem(void)
{
	cout << "1 - Ввод массива из консоли" << endl;
	cout << "2 - Ввод массива из файла" << endl;
	return InputNum("0 - выход", 0, 2);
}
//выбор пункта меню вывода результата
int SelectResultMenuItem(void)
{
	cout << "1 - Вывести результат в консоль" << endl;
	cout << "2 - Вывести результат в файл" << endl;
	return InputNum("0 - выход", 0, 2);
}
//главная программа
int main()
{
	setlocale(LC_ALL, "Russian");//русский язык	
	ifstream FileIn("input.txt");
	int n, m, p, q;
	int** arr = new int*[0];
	int MenuItem = -1;
	int SubMenuItem = -1;
	MenuItem = SelectInputMenuItem();
	switch (MenuItem)
	{
	case 1:
		InputMatrKey(arr, &n, &m);
		break;
	case 2:
		InputMatrSizeFile(FileIn, &n, &m);
		arr = CreateMatr(n, m);
		InputMatrFile(arr, FileIn, n, m);
		break;
	default:
		return 0;
	}
	p = InputNum("Введите номер строки (p):", 1, n);
	q = InputNum("Введите номер столбца (q):", 1, m);
	SubMenuItem = SelectResultMenuItem();
	switch (SubMenuItem)
	{
	case 1:
		OutputResKey(arr, n, m, p, q);
		break;
	case 2:
		OutputResFile(arr, n, m, p, q);
		break;
	default:
		return 0;
	}
	FileIn.close();   
	return 0;
}


