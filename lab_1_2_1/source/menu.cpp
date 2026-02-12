#include <iostream>
#include <format>
#include <conio.h>

#include "functions.h"
#include "fixes.h"

using namespace std;

//
int menu_f1() {
	double a, b;
	cout << "Число A: "; cin >> a;
	cout << "Число B: "; cin >> b;

	double result;

	try {
		result = f1(a, b);
	}
	catch (const invalid_argument& e) {
		cout << "Ошибка вычисления функции: " << e.what() << endl;
		return -1;
	}

	cout << format("Результат вычисления функции со значениями A ({:.4f}) и B ({:.4f}) равен : {:.4f}", a, b, result) << endl;
	return 0;
}

int menu_f2() {
	double x;
	cout << "Число x: "; cin >> x;

	double result;

	try {
		result = f2(x);
	}
	catch (const invalid_argument& e) {
		cout << "Ошибка вычисления функции: " << e.what() << endl;
		return -1;
	}

	cout << format("Результат вычислений с x ({:.4f}) равен : {:.4f}", x, result) << endl;
	return 0;
}

int menu_f3() {
	int function_number;
	void (*f)();

	cout <<
		"1. f1" << endl <<
		"2. f2" << endl <<
		"Выберите функцию для проверки: "
		;
	cin >> function_number;

	switch (function_number) {
	case 1:
		f = fix1;
		break;
	case 2:
		f = fix2;
		break;
	default:
		cout << "Выбран неизвестный номер функции" << endl;
		return 0;
	}

	f();

	return 0;
}

int menu_f4() {
	double x;
	cout << "Число x: "; cin >> x;

	cout << format("Результат попадания x ({:.4f}) в диапазон (от -2 до 2): {}", x, f4(x) ? "Попал" : "Не попал") << endl;
	return 0;
}

//
int menu_start() {
	int action;
	int result;

	do
	{
		action = 0;
		result = 0;

		cout <<
			"Лабораторная работа 1" << endl <<
			"Выполнили: Горяйнов Павел Андеевич и Рычжков Сергей Максимович" << endl <<
			"Группа: бИЦ-252" << endl << endl <<

			"1. Вычислить значение алгебраического выражения" << endl <<
			"2. Вычислить значение функции, разложенной в ряд" << endl <<
			"3. Проверить работу сломанных функций" << endl <<
			"4. Проверить попадание числа в диапазон" << endl <<
			"0. Выход" << endl <<
			"Выберите действие: "
		;

		cin >> action;

		switch (action) {
		case 0: // skip
			break;
		case 1:
			result = menu_f1();
			break;
		case 2:
			result = menu_f2();
			break;
		case 3:
			result = menu_f3();
			break;
		case 4:
			result = menu_f4();
			break;
		default:
			cout << "Выбран неизвестный номер действия" << endl;
			break;
		}

		if (result < 0) {
			cout << "Произошла ошибка при выполнении действия" << endl;
		}

		if (action == 0) {
			cout << "Выход из программы..." << endl;
			break;
		}

		//
		printf("\nНажмите любую клавишу для продолжения\n");
		(void)_getch();

		system("cls");
	} while (true);
	return 0;
}