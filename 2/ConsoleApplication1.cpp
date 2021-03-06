// Атапина Александра 91 гр.
//№1
/*Создать класс vector3D, задаваемый тройкой координат. Обязательно должны быть
реализованы: сложение и вычитание векторов, скалярное произведение, умножение на
скаляр, сравнение векторов, вычисление длины вектора, сравнение длины векторов.*/

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;

class Vector
{
private:
	double x;
	double y;
	double z;
public:
	// конструктор по умолчанию
	Vector() : x(), y(), z()
	{}

	// конструктор с заданными значениями
	Vector(double vx, double vy, double vz) : x(vx), y(vy), z(vz)
	{}
	//сеттеры
	//изменение первой координаты
	void setx(double vx)
	{
		x = vx;
	}
	//второй
	void sety(double vy)
	{
		y = vy;
	}
	//третьей
	void setz(double vz)
	{
		z = vz;
	}
	//геттеры
	//получение первой координаты
	double getx()
	{
		return x;
	}
	//второй
	double gety()
	{
		return y;
	}
	//третьей
	double getz()
	{
		return z;
	}
	// инициализация нулями
	void Init() 
	{ 
		x = 0; y = 0; z = 0; 
	}
	//ввод с клавиатуры
	void Read() 
	{ 
		double vx, vy, vz;
		cout << "Введите координаты вектора: " << endl;
		cin >> vx >>vy >> vz;
		x = vx;
		y = vy;
		z = vz;
	}
	//ввывод на экран
	void Display()
	{
		cout << "{" << x << ";" << y << ";" << z << "}";
	}
	//скалярное произведение
	double Scalar(Vector v)
	{
		double vx = x * v.x;
		double vy = y * v.y;
		double vz = z * v.z;
		return(vx + vy + vz);
	}

	//вычисление длины вектора
	double Dist() const
	{
		return sqrt(x*x + y * y + z * z);
	}


	//-------------ПЕРЕГРУЗКИ ОПЕРАЦИЙ-------------

	//сравнение векторов
	bool  operator== (Vector v)const
	{
		
		return ((x==v.x)&&(y==v.y)&&(z==v.z));
	} 

	//сложение
	Vector  operator+ (Vector v)const
	{
		double vx = x + v.x;
		double vy = y + v.y;
		double vz = z + v.z;
		return Vector(vx, vy, vz);
	} 

	//вычитание
	Vector  operator- (Vector v)const
	{
		double vx = x - v.x;
		double vy = y - v.y;
		double vz = z - v.z;
		return Vector(vx, vy, vz);
	}

	//произведение вектора на число
	Vector operator* (int a)const 
	{
		double vx = x*a;
		double vy = y*a;
		double vz = z*a;
		return Vector(vx, vy, vz);
	}

	//сравнение длин векторов(больше)
	bool  operator> (Vector v)const
	{
		return ((this->Dist())>v.Dist());
	}

	//больше либо равно
	bool  operator>= (Vector v)const
	{
		
		return ((this->Dist()) >= v.Dist());
	}

	//меньше
	bool  operator< (Vector v)const
	{
		
		return ((this->Dist()) < v.Dist());
	}

	//меньше либо равно
	bool  operator<= (Vector v)const
	{
		Vector a(x, y, z);
		return ((this->Dist()) <= v.Dist());
	}
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
}
//выбор пункта меню ввода
int SelectInputMenuItem(void)
{
	cout << "1 - Ввод координат вектора с каливатуры" << endl;
	cout << "2 - Инициализация вектора нулями" << endl;
	return InputNum("0-выхдод", 0, 2);
}
//выбор пункта меню обработки
int SelectDoMenuItem(void)
{
	cout << "1 - Сложение двух векторов" << endl;
	cout << "2 - Разность двух векторов" << endl;
	cout << "3 - Скалярное произведение двух векторов" << endl;
	cout << "4 - Вычисление длины вектора" << endl;
	cout << "5 - Сравнение двух векторов" << endl;
	cout << "6 - Сравнение длин двух векторов(a>b)" << endl;
	cout << "7 - Сравнение длин двух векторов(>=)" << endl;
	cout << "8 - Сравнение длин двух векторов(<)" << endl;
	cout << "9 - Сравнение длин двух векторов(<=)" << endl;
	cout << "10-Умножение вектора на число" << endl;
	cout << "11-Изменение координат вектора" << endl;
	cout << "12-Получение координат вектора" << endl;
	return InputNum("0 - выход", 0, 12);
}

void InputVector(Vector& v) 
{
	int k;
	k = SelectInputMenuItem();
	switch (k)
	{
	case 1: v.Read();
		break;
	case 2: v.Init();
		break;
	}
}

int main()
{
		setlocale(0, "Rus");
		Vector a,b,c;
		int k=1;
		InputVector(a);
		do {
		cout << "===============================" << endl;
		k = SelectDoMenuItem();
		switch (k)
		{
		case 1: InputVector(b);
			c = a + b;
			cout << "a";
			a.Display();
			cout << "+b";
			b.Display();
			cout << "=c";
			c.Display();
			break;
		case 2: InputVector(b);
			c = a - b;
			cout << "a";
			a.Display();
			cout << "-b";
			b.Display();
			cout << "=c";
			c.Display();
			break;
		case 3:InputVector(b);
			double d;
			d = a.Scalar(b);
			cout << "a";
			a.Display();
			cout << "*b";
			b.Display();
			cout << "=";
			cout << d; break;
		case 4: double len;
			len = a.Dist();
			cout << len; break;
		case 5: InputVector(b);
			cout << "a";
			a.Display();
			cout << "==b";
			b.Display();
			cout << "=" << (a == b); break;
		case 6:InputVector(b);
			cout << "|a";
			a.Display();
			cout << "|>|b";
			b.Display();
			cout << "|=" << (a > b); break;
		case 7:InputVector(b);
			cout << "|a";
			a.Display();
			cout << "|>=|b";
			b.Display();
			cout << "|=" << (a >= b); break;
		case 8:InputVector(b);
			cout << "|a";
			a.Display();
			cout << "|<|b";
			b.Display();
			cout << "|=" << (a < b); break;
		case 9:InputVector(b);
			cout << "|a";
			a.Display();
			cout << "|<=|b";
			b.Display();
			cout << "|=" << (a <= b); break;
		case 10:
			cout << "Введите целое число:";
			int num;
			cin >> num;
			c = a * (num);
			cout << num;
			cout << "*a";
			a.Display();
			cout << "=";
			c.Display();
			break;
		case 11:
			cout << "Какую координату требуется изменить?" << endl;
			int n;
			cout << "1-х;" << endl;
			cout << "2-y;" << endl;
			cout << "3-z;" << endl;
			n = InputNum("0 - выход", 0, 3);
			switch (n)
			{
			case 1:
				cout << "Введите новую координату х:";
				int vx;
				cin >> vx;
				a.setx(vx);
				break;
			case 2:
				cout << "Введите новую координату y:";
				int vy;
				cin >> vy;
				a.sety(vy);
				break;
			case 3:
				cout << "Введите новую координату z:";
				int vz;
				cin >> vz;
				a.setz(vz);
				break;
			default: return 0;
			}
			cout << "Измененный вектор: " << endl;
			a.Display();
			break;
		case 12:
			cout << "Какую координату требуется вывести?" << endl;
			int m;
			cout << "1-х;" << endl;
			cout << "2-y;" << endl;
			cout << "3-z;" << endl;
			m = InputNum("0 - выход", 0, 3);
			switch (m)
			{
			case 1:
				cout << a.getx();
				break;
			case 2:
				cout << a.gety();
				break;
			case 3:
				cout << a.getz();
				break;
			default: return 0;
			}
			break;
		}
		cout << endl;	
	} while (k != 0);
	return 0;
}