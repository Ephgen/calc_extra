// calc_extra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

using namespace std;

int deistvie(char* arr, int a, int b, int ot, int ido)
{
	for (int i = ot; i < ido; i++) {
		switch (*(arr + i))
		{
		case '*':
		{
			return a * b;
			break;
		}
		case '/':
		{
			if (b == 0)
			{
				cout << " На ноль делить нельзя";
				return 0;
			}
			else
				return a / b;
			break;
		}
		case '+':
		{
			return a + b;
			break;
		}
		case '-':
		{
			return a - b;
			break;
		}
		default:
			break;
		}
	}
}

void schitaemUbiraem(char* arr, int ot, int ido)
{
	int a = 0, b = 0; int c = 0; int index = 0;
	for (int i = ot; i < ido; i++) {
		if (*(arr + i) == 42 || *(arr + i) == 43 || *(arr + i) == 45 || *(arr + i) == 47)
		{
			index = i;
			break;
		}
		if (*(arr + i) > 47 && *(arr + i) < 58 && b == 0)
			a = a * 10 + (*(arr + i) - '0');
	}
	for (int i = index; i < ido; i++) {
		if (*(arr + i) > 47 && *(arr + i) < 58)
			b = b * 10 + (*(arr + i) - '0');
	}
	c = deistvie(arr, a, b, ot, ido);
	while ((ido - 1) != (ot - 1))
	{
		int i = ido - 1;
		if (c == 0)
			*(arr + i) = '\0';
		int d = c % 10;
		switch (d)
		{
		case 0:
		{
			*(arr + i) = 48;
			break;
		}
		case 1:
		{
			*(arr + i) = 49;
			break;
		}
		case 2:
		{
			*(arr + i) = 50;
			break;
		}
		case 3:
		{
			*(arr + i) = 51;
			break;
		}
		case 4:
		{
			*(arr + i) = 52;
			break;
		}
		case 5:
		{
			*(arr + i) = 53;
			break;
		}
		case 6:
		{
			*(arr + i) = 54;
			break;
		}
		case 7:
		{
			*(arr + i) = 55;
			break;
		}
		case 8:
		{
			*(arr + i) = 56;
			break;
		}
		case 9:
		{
			*(arr + i) = 57;
			break;
		}
		default:
			break;
		}	
		c /= 10;
		ido--;
	}	
}

int main()
{
	setlocale(0, "");
	char virazhenie[20];
	cout << " Вас приветствует калькулятор. Вы можете ввести с клавиатуры некоторое арифметическое выражение. Выражение может содержать : (), +, -, *, / ." << endl;
	cin.getline(virazhenie, 20);
	int k = 0;
	while (*(virazhenie + k) != '\0')
		k++;
	int skob1 = 55, skob2 = 55; float a;
	for (int i = 0; i < k; i++) {   // Находим скобки если они есть
		if (*(virazhenie + i) == '(')
			skob1 = i;
		if (*(virazhenie + i) == ')')
		{
			skob2 = i;
			schitaemUbiraem(virazhenie, skob1, skob2 + 1);
		}
	}
	int index = 0, left = 55, right = 55;
	int kolvo = 0;
	for (int i = 0; i < k; i++) {                    // Ищем сперва деление или умножение
		if (*(virazhenie + i) == 42 || *(virazhenie + i) == 47)
		{
			index = i;
			kolvo++;
			while (kolvo != 0)
			{
				for (int j = index - 1; j >= 0; j--)   // Находим границы что на что надо умножить
				{
					if (*(virazhenie + j) == 42 || *(virazhenie + j) == 43 || *(virazhenie + j) == 45 || *(virazhenie + j) == 47 || j == 0) {
						left = j;
						break;
					}
				}
				for (int r = index + 1; r < k; r++) {
					if (*(virazhenie + r) == 42 || *(virazhenie + r) == 43 || *(virazhenie + r) == 45 || *(virazhenie + r) == 47 || r == k - 1) {
						right = r;
						break;
					}
				}
				if (right == k - 1)
					schitaemUbiraem(virazhenie, left + 1, right + 1);
				else if (left == 0)
					schitaemUbiraem(virazhenie, left, right);
				else
					schitaemUbiraem(virazhenie, left + 1, right);
				kolvo--;
			}
		}
	}
	for (int i = 0; i < k; i++) {                    //  плюс или минус
		if (*(virazhenie + i) == 45 || *(virazhenie + i) == 43)
		{
			index = i;
			kolvo++;
			while (kolvo != 0)
			{
				for (int j = index - 1; j >= 0; j--)
				{
					if (*(virazhenie + j) == 42 || *(virazhenie + j) == 43 || *(virazhenie + j) == 45 || *(virazhenie + j) == 47 || j == 0) {
						left = j;
						break;
					}
				}
				for (int r = index + 1; r < k; r++) {
					if (*(virazhenie + r) == 42 || *(virazhenie + r) == 43 || *(virazhenie + r) == 45 || *(virazhenie + r) == 47 || r == k - 1) {
						right = r;
						break;
					}
				}
				if (right == k - 1)
					schitaemUbiraem(virazhenie, left + 1, right + 1);
				else if (left == 0)
					schitaemUbiraem(virazhenie, left, right);
				else
					schitaemUbiraem(virazhenie, left + 1, right);
				kolvo--;
			}
		}
	}
	cout << " Ответ - ";
	for (int i = 0; i < k; i++) {
		if (*(virazhenie + i) == '0')
			*(virazhenie + i) = *(virazhenie + i + 1);
		else
			cout << *(virazhenie + i);
	}


}

