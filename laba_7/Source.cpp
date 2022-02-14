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

//������� ����� � ������ ������

char* f_input_str(int& in_len)
{

	cout << "������� ������: " << endl;

	char ch = '\n';
	int count = 0;

	char* str_1 = new char[in_len]; //�������� ������� ��������

	//������������ ������ ������

	while (cin.get(ch) && ch != '\n')
	{

		if (count >= in_len)
		{

			in_len = in_len * 2;

			char* strNew = new char[in_len]; //�������� ������� ��� �������� �������� ������

			//������� ������ �� ������� ������ � ������

			for (int i = 0; i < count; i++)
			{

				strNew[i] = str_1[i];

			}

			delete[] str_1; 				//������������ ������, ���������� ��� ������ ������

			str_1 = new char[in_len]; 		//������������� ������ ��� ������

			//������� ������ �� ������� � ����� ������ 

			for (int i = 0; i < count; i++)
			{

				str_1[i] = strNew[i];

			}

			delete[] strNew; 				//������������ ������ �������

		}

		str_1[count] = ch; 					//������ ������� � ������

		count++;

	}

	str_1[count] = '\0'; 					//����� ������

	//�������� ����, ��� ������ �� �������

	if (f_my_str_len(str_1) == 0)
	{

		cerr << "������ �� ����� ���� �������!!!" << endl;
		exit(0);

	}

	return str_1;

}
// my_len - �������� ���� �������
//������� ����� ���������� ����� ���������

void f_input_params(int& start, int& length, int &str_len)
{

	cout << "������� ����� �������, � �������� ����� ���������� ��������� ���������." << endl;
	cout << "�� ������ ������ � �������� �� 0 �� " << str_len - 1 << endl;
	cin >> start;

	while (!cin.good() || start < 0 || start > str_len)
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "������������ ���� ������ �������!!! ����� ������� �� ����� ���� �������� ��� ������!!!" << endl;
		cout << "����� ������� ������ ������ � �������� �� 0 �� " << str_len-1 << endl;
		cout << "������� ����� �������, � �������� ����� ���������� ��������� ��������� ������: ";

		cin >> start;
		cout << endl;

	}

	cout << "������� ����� ���������� ���������. ��� ������ ���� �� 1 �� " << str_len - start << endl;
	cin >> length;

	while (!cin.good() || length < 1 || str_len-start < length)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "������������ ���� ����� ���������!!! ����� ��������� �� ����� ���� ������������� ������, ����� ��� ������!!!" << endl;
		cout << "������� ����� ���������� ��������� ������. "<< "��� ������ ���� �� 1 �� " << str_len - start << endl;

		cin >> length;
		cout << endl;

	}


}

//������� ��������� ����� ��������� �� ��������� ����������

char* f_cut(int& start, int& length, const char* str_ch_1)
{

	int count = 0;

	char* str_2 = new char[length + 1]; 		//�������� ������� ��������

	//������ ����� ���������

	for (int i = start; i < start + length; i++)
	{

		str_2[count] = str_ch_1[i];

		count++;

	}

	str_2[count] = '\0'; 					//����� ������

	return str_2;

}

//������� ������ ���������

void f_output(const char* str_ch_2)
{

	cout << "���������� ������: " << str_ch_2 << endl;

}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������������� ����������

	int start;
	int length;
	int str_len = 4;

	char* str_ch_1 = f_input_str(str_len); 		//���� � style ������

	str_len = f_my_str_len(str_ch_1);

	f_input_params(start, length, str_len); //����� ������� ����� ����������

	char* str_ch_2 = f_cut(start, length, str_ch_1); //����� ������� ��������� ���������

	f_output(str_ch_2); 							//����� ������� ������ ���������

	//������� ������ � �������� �� ������

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