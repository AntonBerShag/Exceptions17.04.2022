#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double division(double num1, double num2) {
	if (num2 == 0)
		throw invalid_argument("обнаружено деление на ноль");
	return num1 / num2;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	/*try { // блок, в который необходимо поместить часть программы, в которой может возникнуть исключительная ситуация
		cout << "Введите число от 1 до 10: ";
		int x;
		cin >> x;
		// если введённое число ниже указанного диапазона, то "брасается" исключение со значением 0
		if (x < 1)
			throw 0;
		// если введённое число выше указанного диапазона, то "брасается" исключение со строковым значеним
		if (x > 10)
			throw "Введенное число больше указанного диапазона!\n";
		// команда throw останавливает дальнейшее выполнеие блока throw
		cout << "Введено правильное число\n";
	}
	catch (const int ex) { // блок catch который "ловит" исключение со значением int и выполняется, если такое исключение было "брошено"
		if (ex == 0)
			cerr << "Ошибка!\nВведеное число меньше указанного диапазона\n";
		if (ex == 11)
			cerr << "Ошибка!\nВведеное число больше указанного диапазона\n";
	}
	catch (const char ex[]) { // блок catch который "ловит" исключение со строковым значением и выполняется, если такое исключение было "брошено"
		cerr << "Ошибка!\n" << ex << endl;
	}*/
	
	
	/*bool fer = true;
	do {
		try {
			string nStr;
			cout << "Введите число: ";
			getline(cin, nStr);
			int num = stoi(nStr);
			cout << "Введено: " << num << endl;
		}
		catch (const exception& ex) {
			string err = ex.what();
			if (err == "invalid stoi argument")
				cerr << "Ошибка: " << err << endl;
		}
	} while (fer);*/

	/*try {
		cout << "Введите два числа: ";
		cin >> n >> m;
		cout << n << " / " << m << " = " << division(n, m) << endl;
	}
	catch (const invalid_argument& ex) {
		cerr << "Ошибка: " << ex.what() << endl;
	}*/



	string path = "file.tx";
	ifstream in;
	in.exceptions(ios::badbit | ios::eofbit | ios::failbit);
	try {
		cout << "Попытка открытия файла...\n";
		in.open(path);
		cout << "Файл открыт для чтения.\n";
		cout << "Содержимое файла:\n";
		string str;
		getline(in, str);
		cout << str << endl;
		in.close();
	}
	catch (const ifstream::failure &ex) {
		cout << "Ошибка: " << ex.what() << endl;
		cout << "Код ошибки: " << ex.code() << endl;
	}

	return 0;
}