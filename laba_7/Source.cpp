#define NOMINMAX
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <climits>
#include <iomanip>
#include <crtdbg.h>
#include <cstdlib>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif

using namespace std;

int f_my_str_len(char *str_ch_1)
{

	int count = 0;

	while (str_ch_1[count])
		count++;


	return count;

}

//Функция ввода и записи строки

char* f_input_str(int& in_len)
{

	cout << "Введите строку: " << endl;

	char ch = '\n';
	int count = 0;

	char* str_1 = new char[in_len]; //Создание массива символов

	//Посимвольное чтение строки

	while (cin.get(ch) && ch != '\n')
	{

		if (count >= in_len)
		{

			in_len = in_len * 2;

			char* strNew = new char[in_len]; //Создание буффера для хранения считаной строки

			//Перенос данных из сходной строки в буффер

			for (int i = 0; i < count; i++)
			{

				strNew[i] = str_1[i];

			}

			delete[] str_1; 				//Освобождение памяти, выделенной под первую строку

			str_1 = new char[in_len]; 		//Перевыделение памяти под массив

			//Перенос данных из буффера в новый массив 

			for (int i = 0; i < count; i++)
			{

				str_1[i] = strNew[i];

			}

			delete[] strNew; 				//Освобождение памяти буффера

		}

		str_1[count] = ch; 					//Запись символа в массив

		count++;

	}

	str_1[count] = '\0'; 					//Конец строки

	//Проверка того, что строка не нулевая

	if (f_my_str_len(str_1) == 0)
	{

		cerr << "Строка не может быть нулевой!!!" << endl;
		exit(0);

	}

	return str_1;

}
// my_len - написать свою функцию
//Функция ввода параметров новой подстроки

void f_input_params(int& start, int& length, int &str_len)
{

	cout << "Введите номер символа, с которого будет начинаться выделение подстроки." << endl;
	cout << "Он должен лежать в пределах от 0 до " << str_len - 1 << endl;
	cin >> start;

	while (!cin.good() || start < 0 || start > str_len)
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "Неккоректный ввод номера символа!!! Номер символа не может быть символом или буквой!!!" << endl;
		cout << "Номер символа должен лежать в пределах от 0 до " << str_len-1 << endl;
		cout << "Введите номер символа, с которого будет начинаться выделение подстроки заново: ";

		cin >> start;
		cout << endl;

	}

	cout << "Введите длину выделяемой подстроки. Она должна быть от 1 до " << str_len - start << endl;
	cin >> length;

	while (!cin.good() || length < 1 || str_len-start < length)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "Неккоректный ввод длины подстроки!!! Длина подстроки не может быть отрицательным числом, нулем или буквой!!!" << endl;
		cout << "Введите длину выделяемой подстроки заново. "<< "Она должна быть от 1 до " << str_len - start << endl;

		cin >> length;
		cout << endl;

	}


}

//Функция выделения новой подстроки по введенным параметрам

char* f_cut(int& start, int& length, const char* str_ch_1)
{

	int count = 0;

	char* str_2 = new char[length + 1]; 		//Создание массива символов

	//Запись новой подстроки

	for (int i = start; i < start + length; i++)
	{

		str_2[count] = str_ch_1[i];

		count++;

	}

	str_2[count] = '\0'; 					//Конец строки

	return str_2;

}

//Функция вывода подстроки

void f_output(const char* str_ch_2)
{

	cout << "Полученная строка: " << str_ch_2 << endl;

}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Инициализация переменных

	int start;
	int length;
	int str_len = 4;

	char* str_ch_1 = f_input_str(str_len); 		//Ввод С style строки

	str_len = f_my_str_len(str_ch_1);

	f_input_params(start, length, str_len); //Вызов функции ввода параметров

	char* str_ch_2 = f_cut(start, length, str_ch_1); //Вызов функции выделения подстроки

	f_output(str_ch_2); 							//Вызов функции вывода подстроки

	//Очистка памяти и проверка на утечки

	delete[] str_ch_1;
	str_ch_1 = 0;
	delete[] str_ch_2;
	str_ch_2 = 0;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	system("pause");

}