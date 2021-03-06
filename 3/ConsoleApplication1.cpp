/* 2к. 91 гр. Атапина Александра
№6
Реализовать шаблон класса множество. Класс должен одержать методы:
-добавление эл-та
-удаление эл-та
-проверка существования эл-та
-объединение двух мн-в(+)
-пересечение двух мн-в(*)
-разность двух мн-в(-)
-печать мн-ва
*/

#include "pch.h"
#include <iostream>
#include "string"

using namespace std;

struct Person {
	string name;
	string surname;
	string patronymic;
	bool operator == (const Person & p) const {
		return this->name == p.name && this->surname == p.surname && this->patronymic == p.patronymic;
	}
	friend ostream& operator<<(ostream& s, Person& my)
	{
		return cout <<" "<< my.name << " " << my.surname << " " << my.patronymic;
	}
	friend istream& operator>>(istream& s, Person& my)
	{
		cout << "Имя: ";
		cin>> my.name;
		cout << "Фамилия:";
		cin >> my.surname;
		cout << "Отчество:";
		cin >> my.patronymic;
		return s;
	}
};
template <class T>
class set
{
private:
	T *a;
	int size = 3;
	int count;
public:
	//по умолчанию
	set() {
		a = new T[size];
		count = 0;
	};


	//проверка вхождения эл-та в множество
	bool check_in(T x)const
	{
		for (int i = 0; i < count; i++)
			if (a[i] == x)
				return true;
		return false;
	};
	//увеличение размера массива на заданную величину n
	T *incSize(T *arr, int sz, int n)
	{
		T *b = new T[sz+n];
		for (int i = 0; i < sz; i++)
			b[i] = arr[i];
		delete[] arr;
		return b;
	}
	//добавление эл-та в множество
	void add(T x)
	{
		if (count == size) 
		{ 
			a = incSize(a,size,10);
			size += 10;
		}
			if (!check_in(x))
			{
				a[count] = x;
				count += 1;
			}
			else
				cout << ("Добавление невозможно, элемент уже существует!");
	};

	//удаление эл-та из множества
	void del(T x)
	{
		if ((count != 0) && this->check_in(x))
		{
			for (int i = 0; i < count; i++)
			{
				if (a[i] == x)
				{
					for (int j = i; j < count - 1; j++)
					{
						a[j] = a[j + 1];
					}
					count -= 1;
				}
			}
		}
		else
			cout << ("Удаление невозможно!");
	};

	//Вывод множества на экран
	void output() {
		if (count == 0)
		{
			cout << "{ }";
			return;
		}
		cout << "{" << a[0];
		for (int i = 1; i < count; i++)
			cout << ", " << a[i];
		cout << "}";

	};
	//присваивание одного множества другому
	set<T> operator= (const set <T> &s)
	{
		if (size < s.size)//если меньшему=большее
		{
			a = incSize(a, size, s.size-size);
			size += s.size;
		}
		for (int i = 0; i < s.count; i++)
		{
			a[i] = s.a[i];
		}
		count = s.count;
		return *this;
	};

	// пересечение
	set<T> operator* (const set <T> &s2)
	{
		set <T> s3;
		for (int i = 0; i < count; i++)
			if (s2.check_in(a[i]))
				s3.add(a[i]);
		return s3;
	};

	//объединение
	set<T> operator+ (const set <T> &s2)
	{
		set <T> s3;
		s3 = *this;
		for (int i = 0; i < s2.count; i++)
			if (!s3.check_in(s2.a[i]))
				s3.add(s2.a[i]);
		return s3;
	};

	//разность
	set<T> operator- (const set <T> &s2)
	{
		set <T> s3;
		s3 = *this;
		for (int i = 0; i < count; i++)
			if (s2.check_in(a[i]))
				s3.del(a[i]);
		return s3;
	};

	//ввод множества с клавиатуры с проверкой существования
	void Input_set(int n)
	{
		T x;
		count = n;
		if (count>size)//если кол-во элементов больше размера
		{
			a = incSize(a, size, count-size);
			size = count;
		}
		cout << "Заполните множество:" << endl;
		for (int i = 0; i < count; i++)
		{
			do
			{
				cin >> x;
				if (this->check_in(x))
					cout << "Данный элемент уже существует!Повторите ввод!" << endl;
			} while (this->check_in(x));
			a[i] = x;
		}
	};

};

//ввод размера множества
int Inputcount()
{
	cout << "Введите размер (положительное целое число) множества: ";
	int n; cin >> n;
	return n;
};
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
};

//выбор пункта меню обработки для одного множества
int SelectDoMenuItem(void)
{
	cout << "1 - Проверка принадлежность элемента множеству" << endl;
	cout << "2 - Добавление элемента" << endl;
	cout << "3 - Удаление элемента" << endl;
	cout << "4 - Печать множества" << endl;
	cout << "5 - Операции с двумя множествами" << endl;
	return InputNum("0 - Выход", 0, 5);
};
//для двух мн-в
int SelectOperationMenuItem(void)
{
	cout << "1 - Объединение" << endl;
	cout << "2 - Пересечение" << endl;
	cout << "3 - Разность" << endl;
	return InputNum("0 - Вернуться", 0, 3);
};
int SelectTypeMenuItem(void)
{
	cout << "1 - Целочисленный" << endl;
	cout << "2 - Строковый" << endl;
	cout << "3 - Структура" << endl;
	return InputNum("0 - Выход", 0, 3);
};

int main()
{
	setlocale(0, "RUS");
	int k = 1;
	int x;
	string strx;
	Person px;
	set<Person>  pa, pb, pc;
	set<int>  a, b, c;
	set<string> stra, strb, strc;
	int q;
	int n,m;
	
	cout << "ТИП ДАННЫХ:"<<endl;
	int p = SelectTypeMenuItem();
	switch (p)
	{
	case 1://int
		n = Inputcount();
		a.Input_set(n);
		do 
		{
			cout << endl;
			k = SelectDoMenuItem();
			switch (k)
			{
			case 1:
				cout << "Введите элемент:";
				cin >> x;
				a.check_in(x) ? cout << "Принадлежит" : cout << "Не принадлежит";
				break;
			case 2:
				cout << "Введите элемент:";
				cin >> x;
				a.add(x);
				break;
			case 3:
				cout << "Введите элемент:";
				cin >> x;
				a.del(x);
				break;
			case 4:
				a.output();
				break;
			case 5:
				m = Inputcount();
				b.Input_set(m);
				do {
					cout << endl;
					q = SelectOperationMenuItem();
					switch (q)
					{
					case 1:
						c = a + b;
						c.output();
						break;
					case 2:
						c = a * b;
						c.output();
						break;
					case 3:
						c = a - b;
						c.output();
						break;
					}
				} while (q != 0);
			}
			if (k == 0) return 0;
		} while (k != 0);
		break;
	case 2://string
		n = Inputcount();
		stra.Input_set(n);
		do
		{
			cout << endl;
			k = SelectDoMenuItem();
			switch (k)
			{
			case 1:
				cout << "Введите элемент:";
				cin >> strx;
				stra.check_in(strx) ? cout << "Принадлежит" : cout << "Не принадлежит";
				break;
			case 2:
				cout << "Введите элемент:";
				cin >> strx;
				stra.add(strx);
				break;
			case 3:
				cout << "Введите элемент:";
				cin >> strx;
				stra.del(strx);
				break;
			case 4:
				stra.output();
				break;
			case 5:
				m = Inputcount();
				strb.Input_set(m);
				do {
					cout << endl;
					q = SelectOperationMenuItem();
					switch (q)
					{
					case 1:
						strc = stra + strb;
						strc.output();
						break;
					case 2:
						strc = stra * strb;
						strc.output();
						break;
					case 3:
						strc = stra - strb;
						strc.output();
						break;
					}
				} while (q != 0);
			}
			if (k == 0) return 0;
		} while (k != 0);
		break;
	case 3://person
		n = Inputcount();
		pa.Input_set(n);
		do
		{
			cout << endl;
			k = SelectDoMenuItem();
			switch (k)
			{
			case 1:
				cout << "Введите элемент:" << endl;
				cin >> px;
				pa.check_in(px) ? cout << "Принадлежит" : cout << "Не принадлежит";
				break;
			case 2:
				cout << "Введите элемент:" << endl;
				cin >> px;
				pa.add(px);
				break;
			case 3:
				cout << "Введите элемент:" << endl;
				cin >> px;
				pa.del(px);
				break;
			case 4:
				pa.output();
				break;
			case 5:
				m = Inputcount();
				pb.Input_set(m);
				do {
					cout << endl;
					q = SelectOperationMenuItem();
					switch (q)
					{
					case 1:
						pc = pa + pb;
						pc.output();
						break;
					case 2:
						pc = pa *pb;
						pc.output();
						break;
					case 3:
						pc = pa - pb;
						pc.output();
						break;
					}
				} while (q != 0);
			}
			if (k == 0) return 0;
		} while (k != 0);
		break;
	default: return 0;
	}
	return 0;
}
