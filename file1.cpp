/*Дано имя файла и целые положительные числа N и K. Создать тексто-
вый файл с указанным именем и записать в него N строк, каждая из кото-
рых состоит из K символов «*» (звездочка).*/

#include "pch.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	int N,K;
	N = 5; //rand() % 10;
	K = 3; //rand() % 10;
	string path = " file1.txt";
	ofstream fout;
	fout.open(path);
	char str[200];
	if (K <= 0)
	{
		exit(1);
	}
	else
	{
		string star = "*";
		
		for (int i = 0; i < N; i++)
		{
			for (int i = 1; i <= K; i++)
			{
				fout << star;
			}
			fout << "\n";
		}

		fout.close();

	}
}

