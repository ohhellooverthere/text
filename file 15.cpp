/*Дано целое число K и текстовый файл. Удалить из файла строку с но-
мером K. Если строки с таким номером нет, то оставить файл без измене-
ний.*/

#include "pch.h"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	
		int K=7;
	string path = "File 2.txt";
	fstream fs;
	fs.open(path,fstream::in | fstream::out); // out-работать на запись /in на считывание
	int count = 0; // счетчик строк
	if (!fs.is_open())
	{
		cout << "file open error";
	}
	else
	{
	cout << "file was opened succesfully" << "\n";
	string arr[200];
		string msg;
		msg = "";
		string s;// сюда будем класть считанные строки
		
		int i=0;
		while (getline(fs, s))// пока не достигнут конец файла класть очередную строку в переменную(s)
		{	
			count++;
			msg = s;
			//cout <<"s: "<< s << endl;
		
			if (count == K)
			{
			//cout << "stop"<< endl;
				msg.erase(msg.begin(), msg.end());
			}
		cout <<"msg: "<< msg<<endl;
		arr[i] = msg;
		i++;
		}
		fs.close();
		/////////////// удаление содержимого файла
		fs.open(path, fstream::trunc);
		fs.close();
		///////////////////////////// запись новых данных в файл 
		fs.open(path, fstream::out);
		for (int i = 0; i < count; i++)
		{
			fs << arr[i];
			if ((arr[i]) != "\0")
			{
					fs << "\n";
			}
		
		}
		fs.close();
	}
}
