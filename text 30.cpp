/*Дан текстовый файл. Вывести последнее слово текста наименьшей

длины. Словом считать набор символов, не содержащий пробелов и огра-
ниченный пробелами или началом/концом строки.*/

#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	fstream fs;
	string path = "File_3.txt";
	fs.open(path, fstream::in);
	if (!fs.is_open())
	{
		cout << "file open error";
	}
	else
	{
		cout << "file was opened succesfully" << "\n";
		int count = 0; // счетчик количества

		char s[300];// сюда считываем весь текст
		fs.getline(s, sizeof(s));// пока не достигнут конец файла класть очередную строку в переменную(s)
		int words = 0;
		for (int i = 0; i < sizeof(s); i++)
		{
			if ((s[i] == ' ') || (s[i] == '\0'))
			{
				words++;
			}
		}
		int size = 200;




		char **str = new char*[size];
		for (int i = 0; i < words; i++)
		{
			str[i] = new char[size];
		}
		/*int i = 0;// массив с текстом
		int j = 0;
		int k = 0;// rows
		*/

		int k = 0;
		for (int i = 0; ; i++)
		{
			if (s[k] != '\0')
			{
				int stop = 0;
				for (int j = 0; stop == 0; j++)
				{
					if (s[k] != ' ')
					{
						str[i][j] = s[k];
						k++;
					}
					else if (s[k] == ' ')
					{
						str[i][j] = ' ';
						str[i][j+1] = '\0';
						stop = 1;
						k++;
						count++;
					}
				}
			}
			else
			{
				count++; break;// учитываем последнее слово
			}

		}


		/*while (true)
		{

		  str[k][j] = s[i];
		  if (s[i] == '\0')
		  {
			count++;// учитываем последнее слово
			break;
		  }
		  if (s[i] == ' ')
		  {
			str[k][j] = '\0';
			k++;
			count++;
		  }
		  i++;
		  j++;
		}
		*/
		int min = strlen(str[1]);//слово с минимальным количеством букв
		int count2 = 1;//номер наименьшего слова
		for (int i = 0; i < count; i++)
		{

			for (int j = 0; str[i][j] != '\0'; j++)
			{
				cout << str[i][j];
			}
			if (min >= strlen(str[i]))
			{
				min = strlen(str[i]);
				count2 = i+1;
			}
		}
		cout << " our word :" << str[count2];


		for (int i = 0; i < words; i++)
		{
			delete[]str[i];
		}
		delete[]str;
	}
	fs.close();
}