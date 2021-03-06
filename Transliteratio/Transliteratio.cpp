#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

using namespace std;

class Transliteratio
{
public:
	Transliteratio(string tmp);
	string TransliteToEng();//from eng to rus
	string TransliteToRus();//from rus to eng
private:
	string str;
	char rus[33][10] = { "А","Б","В","Г","Д","Е","Ё","Ж", "З","И","Й","К","Л","М", "Н",
		  "О","П","Р","С","Т","У","Ф","Х", "Ц", "Ч", "Ш", "Щ",   "Ъ", "Ы","Ь",
		  "Э","Ю", "Я" };

	char eng[33][10] = { "A","B","V","G","D","E","E","ZH","Z","I","Y","K","L","M","N",
		  "O","P","R","S","T","U","F","KH","TS","CH","SH","SHCH"," ", "Y", " ",
		  "E","YU","YA" };

	char rus2[23][10] = { "А","Б","В","Г","Д","Е","Ё", "З","И","Й","К","Л","М", "Н",
		  "О","П","Р","С","Т","У","Ф","Ы",
		  "Э" };

	char eng2[23][10] = { "A","B","V","G","D","E","E","Z","I","Y","K","L","M","N",
		  "O","P","R","S","T","U","F","Y" };

};

Transliteratio::Transliteratio(string tmp)
{
	str = tmp;//set the string
}
string Transliteratio::TransliteToEng() {
	for (int j = 0; j < 33; j++)
	{
		int it = str.find(rus[j], 0);
		while (it != string::npos)//looking for the first letter of the array of Russian letters
		{
			str.replace(it, 1, eng[j]);//change the location in the array to eng
			it = str.find(rus[j], it);
		}
	}
	return str;// return string
}

string Transliteratio::TransliteToRus() {
	//it was necessary to make many such constructions, because in transliteration from English into Russian there are many exceptions, and they had to be handled all
	int it = str.find("ZH", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Ж");
		it = str.find("ZH", it);
	}

	it = str.find("KH", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Х");
		it = str.find("KH", it);
	}

	it = str.find("TS", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Ц");
		it = str.find("TS", it);
	}
	it = str.find("CH", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Ч");
		it = str.find("CH", it);
	}

	it = str.find("SH", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Ш");
		it = str.find("SH", it);
	}

	it = str.find("SCH", 0);
	while (it != string::npos)
	{
		str.replace(it, 3, "Щ");
		it = str.find("SCH", it);
	}

	it = str.find("YU", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Ю");
		it = str.find("YU", it);
	}

	it = str.find("YA", 0);
	while (it != string::npos)
	{
		str.replace(it, 2, "Я");
		it = str.find("YA", it);
	}
	//When all exceptions have been processed, we are already looking for all letters.
	for (int j = 0; j < 22; j++)
	{
		it = str.find(eng2[j], 0);
		while (it != string::npos)
		{
			str.replace(it, 1, rus2[j]);
			it = str.find(eng2[j], it);
		}
	}
	return str;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);//Russian language in the console for visual studio and Windows
	SetConsoleOutputCP(1251);

	if (!(argc == 2))//If the file name did not come with the command line.
	{
		cout << "You must specify the name of the task file in the command line parameters. \nThe format of the configuration file is as follows : \n[code][Name of the input file][Name of the output file]\n";
		return 1;
	}
	if (strcmp("/?", argv[1]) == 0)
	{
		cout << "You must specify the name of the task file in the command line parameters. \ nThe format of the configuration file is as follows: \ n [code] [Name of the input file] [Name of the output file].\n";
		return -1;
	}

	ifstream in, conf(argv[1]);
	ofstream out;
	string file_in, file_out, operation, str;

	while (!(conf.eof()))
	{
		conf >> operation;
		conf >> file_in;//read from file
		conf >> file_out;

		in.open(file_in);

		if (!(in)) { cout << "error\n"; return -1; }

		string tmp;
		str = "";
		while (!in.eof())
		{
			getline(in, tmp);
			str += tmp + '\n';
		}

		Transliteratio obj(str);
		in.close();

		if (operation == "code")//If you need to do transliteration from Russian into English
		{
			out.open(file_out);
			str = obj.TransliteToEng();
			out << "Transliteration from Russian into English : \n" << str << endl;
			cout << "Transliteration from Russian into English : \n" << str << endl;
			out.close();
		}
		else
		{
			if (operation == "decode")//If you need to do transliteration from English into Russian
			{
				out.open(file_out);
				str = obj.TransliteToRus();
				out << "Transliteration from English into Russian : \n" << str << endl;
				cout << "Transliteration from English into Russian : \n" << str << endl;
				out.close();
			}
		}
		out << endl << endl;
	}

	return 0;
}

