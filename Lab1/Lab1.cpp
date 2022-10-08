#include <iostream>
#include <string>
#include <math.h>

//глобальные переменные
int tap = -5, main_key = -5;
const int const_float_bit = 32;//кол-во бит во float 
const int const_unsigned_char_bit = 8;//кол-во бит в беззнаковом символе
int binary_float[const_float_bit];//массив float
int binary_simvol[const_unsigned_char_bit];//массив unsigned char



void obratnoe_preobrazovanie_unsigned_char() {
	int counter = 7, char_number = 0;

	//перевод в 10 с.с
	for (int i = 0; i < const_unsigned_char_bit; i++) 
	{
		char_number = char_number + (binary_simvol[i] * pow(2, counter));
		counter--;
	}

	unsigned char new_char = (char)char_number;//преобразование числа в символ
	//cout << endl;

	std::cout << "Полученный символ: " << new_char << std::endl;
}

void obratnoe_preobrazovanie_float() {
	int new_P = 0, size_P = 7, new_deq, twin_deq, twin_size_P = size_P + 1;
	float new_float_number = 0;

	//определение степени
	for (int i = 1; i <= 8; i++) 
	{
		new_P = new_P + (binary_float[i] * pow(2, size_P));
		size_P--;
	}

	//cout << "fff: " << new_P;
	new_deq = new_P - 127;
	twin_deq = new_deq;
	int counter_deq = new_deq;

	//перевод числа в 10 с.с
	if (new_deq != 0) 
	{
		new_float_number = pow(2, counter_deq);
		counter_deq--;
	}
	else
	{
		counter_deq--;
	}

	//целая часть
	for (int i = 9; i <= twin_size_P + new_deq; i++) {
		new_float_number = new_float_number + (binary_float[i] * pow(2, counter_deq));
		counter_deq--;
	}
	//cout << endl;
	//cout << new_float_number;
	
	//дробная часть
	for (int i = twin_size_P + 1 + twin_deq; i < const_float_bit; i++) {
		new_float_number = new_float_number + (binary_float[i] * pow(2, counter_deq));
		counter_deq--;
	}

	//cout << endl;

	if (binary_float[0] == 1)
	{
		new_float_number *= -1;
	}

	std::cout << "Полученное число: " << new_float_number << std::endl;
}

void preobrazovanie_unsigned_char() {
	int key_char;
	int vvod_elder_bit, kol_bit, zamena;
	//ввод данных
	std::cout << "Введите старший бит, с которого будет начинаться преобразование (от 0 до 7): "; std::cin >> vvod_elder_bit;
	std::cout << "Введите количество бит, которое вы хотите изменить: "; std::cin >> kol_bit;
	std::cout << "Введите на что будут меняться биты (0 или 1): "; std::cin >> zamena;

	//преобразование
	for (int i = (const_unsigned_char_bit - vvod_elder_bit - 1); i < const_unsigned_char_bit - vvod_elder_bit + kol_bit - 1; i++)
	{
		binary_simvol[i] = zamena;
	}

	//вывод преобразованного массива
	std::cout << "Преобразованный код: ";
	for (int counter_simvol = 0; counter_simvol < const_unsigned_char_bit; counter_simvol++)
	{
		std::cout << binary_simvol[counter_simvol] << " ";
	}

	std::cout << std::endl
		      << "Номер бита:          ";

	for (int counter_simvol = 7; counter_simvol >= 0; --counter_simvol)
	{
		std::cout << counter_simvol << " ";
	}

	std::cout << std::endl;

	std::cout << "Хотите ли вы получить символ обратно из этого кода?";
	std::cout << std::endl;

	enum Variants { exit_program = -1, yes = 1, no = 2 };
	std::cout << "Нажмите '1', чтобы получить символ" << std::endl;
	std::cout << "Нажмите '2', чтобы выйти в главное меню" << std::endl;
	std::cout << "Нажмите '-1', если хотите выйти." << std::endl;
	std::cin >> key_char;

	switch (key_char) {
	case yes:
		obratnoe_preobrazovanie_unsigned_char(); 
		break;
	case no:
		break;
	case exit_program:
		exit(1); 
		break;
	default:
		std::cout << "Повторите попытку";
		break;
	}
	std::cout << std::endl;
}

void preobrazovanie_float() {
	int key_float;
	int vvod_elder_bit, kol_bit, zamena;
	//ввод данных
	std::cout << "Введите старший бит, с которого будет начинаться преобразование (от 0 до 31): "; std::cin >> vvod_elder_bit;
	std::cout << "Введите количество бит, которое вы хотите изменить: "; std::cin >> kol_bit;
	std::cout << "Введите на что будут меняться биты (0 или 1): "; std::cin >> zamena;

	//преобразование
	for (int i = (const_float_bit - vvod_elder_bit - 1); i < const_float_bit - vvod_elder_bit + kol_bit - 1; i++)
	{
		binary_float[i] = zamena;
	}

	//вывод преобразованного массива
	std::cout << "Преобразованное представление числа: ";
	for (int i = 0; i < const_float_bit; i++)
	{
		if (i < 22)
		{
			std::cout << binary_float[i] << "  ";
		}
		else
		{
			std::cout << binary_float[i] << " ";
		}
	}

	std::cout << std::endl << std::endl;

	std::cout << "Номер бита:                          ";

	for (int counter_simvol = 31; counter_simvol >= 0; --counter_simvol)
	{
		std::cout << counter_simvol << " ";
	}

	std::cout << std::endl << std::endl;

	std::cout << "Хотите ли вы получить вещественное число обратно из этого кода?";
	std::cout << std::endl;

	enum Variants { exit_program = -1, yes = 1, no = 2 };
	std::cout << "Нажмите '1', чтобы получить число" << std::endl;
	std::cout << "Нажмите '2', чтобы выйти в главное меню" << std::endl;
	std::cout << "Нажмите '-1', если хотите выйти." << std::endl;
	std::cin >> key_float;
	switch (key_float) {
	case yes:
		obratnoe_preobrazovanie_float(); 
		break;
	case no:
		break;
	case exit_program:
		exit(1); 
		break;
	default:
		std::cout << "Повторите попытку";
		break;
	}
	std::cout << std::endl;
}

void function_for_unsigned_char() {
	int key_char;
	unsigned char simvol;
	std::cout << "Введите символ: ";

	while (!(std::cin >> simvol) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			std::cout << "Повторите попытку" << std::endl;
		}
	}

	//запись двоичного кода символа в массив
	for (int counter_simvol = 0; counter_simvol < const_unsigned_char_bit; counter_simvol++)
	{
		binary_simvol[const_unsigned_char_bit - 1 - counter_simvol] = (simvol >> counter_simvol) & 1;
	}

	//вывод результата
	std::cout << "Представление символа в двоичной системе счисления: ";
	for (int counter_simvol = 0; counter_simvol < const_unsigned_char_bit; counter_simvol++)
	{
		std::cout << binary_simvol[counter_simvol] << " ";
	}
	
	std::cout << std::endl 
			  << "Номер бита:                                         ";

	for (int counter_simvol = 7; counter_simvol >= 0; --counter_simvol)
	{
		std::cout << counter_simvol << " ";
	}

	std::cout << std::endl;


	std::cout << "Хотите ли заменить биты на другие?";
	std::cout << std::endl;

	enum Variants { exit_program = -1, yes = 1, no = 2 };
	std::cout << "Нажмите '1', чтобы преобразовать" << std::endl;
	std::cout << "Нажмите '2', чтобы выйти в главное меню" << std::endl;
	std::cout << "Нажмите '-1', если хотите выйти." << std::endl;
	std::cin >> key_char;
	
	switch (key_char) 
	{
	case yes:
		preobrazovanie_unsigned_char(); 
		break;
	case no:
		break;
	case exit_program:
		exit(1); 
		break;
	default:
		std::cout << "Повторите попытку";
		break;
	}
}

void function_for_float() {
	int key_float;
	float number;//вводимое число

	std::cout << "Введите число: ";
	//cin >> number; 
	int twin_binary_float[const_float_bit];//2 массива
	int k = 0, deq;//счетчик и степень
	int signed_ = 0;//знак
	int twin_const;//переменная для запоминания
	int twin_k;

	//проверка на допустимость вводимого
	while (!(std::cin >> number) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			std::cout << "Повторите попытку" << std::endl;
		}
	}

	//определение знака
	if (number < 0) 
	{
		number = number * (-1);
		signed_ = 1;
	}

	//выделение целой части
	int int_float_number = (int)number;

	//выделение дробной части
	float float_number = number - int_float_number;
	int proverka_float = int_float_number;

	//цикл для определения 1-ой части мантиссы

	for (int i = 0; i < const_float_bit; i++) 
	{

		if (int_float_number == 0)
		{
			break;
		}

		if (int_float_number % 2 == 0) 
		{
			twin_binary_float[i] = 0;
			k++;
		}

		if (int_float_number % 2 != 0) 
		{
			twin_binary_float[i] = 1;
			k++;
		}

		int_float_number /= 2;
		if (int_float_number == 0)
		{
			break;
		}

	}

	//разворот-поворот этой части
	twin_k = k - 1;
	for (int i = 0; i < twin_k; i++) 
	{
		twin_const = twin_binary_float[i];
		twin_binary_float[i] = twin_binary_float[twin_k];
		twin_binary_float[twin_k] = twin_const;
		twin_k--;
	}


	//определение степени и порядка
	deq = k - 1;
	int P = deq + 127;
	if (proverka_float == 0)
		P++;

	//цикл для определения 2-ой части мантиссы
	for (int i = k; i < const_float_bit; i++)
	{
		if (float_number == 0)
		{
			break;
		}

		float_number *= 2;

		if (float_number < 1)
		{
			twin_binary_float[i] = 0;
		}

		if (float_number >= 1) 
		{
			twin_binary_float[i] = 1;
			float_number--;
		}
		//k = i;
	}

	//цикл для определения порядка в 2 с.с
	k = 0;
	for (int i = 1; i < const_float_bit; i++) 
	{
		if (P % 2 == 0) 
		{
			binary_float[i] = 0;
			k++;
		}

		if (P % 2 != 0) 
		{
			binary_float[i] = 1;
			k++;
		}

		P /= 2;
		if (P == 0)
		{
			break;
		}
	}

	//разворот-поворот
	twin_k = k;
	if (proverka_float == 0)
	{
		twin_k++;
	}

	for (int i = 1; i < twin_k; i++) 
	{
		twin_const = binary_float[i];
		binary_float[i] = binary_float[twin_k];
		binary_float[twin_k] = twin_const;
		twin_k--;
	}

	//добавление знака в массив
	binary_float[0] = signed_;

	//присоединение мантиссы
	k++;
	if (proverka_float == 0) 
	{
		k++;
		for (int i = k; i < const_float_bit; i++) 
		{
			if (twin_binary_float[i - k] < 0)
			{
				binary_float[i] = 0;
			}
			else
			{
				binary_float[i] = twin_binary_float[i - k];
			}
		}
	}
	else 
	{
		for (int i = k; i < const_float_bit; i++) 
		{
			if (twin_binary_float[i - k + 1] < 0)
			{
				binary_float[i] = 0;
			}
			else
			{
				binary_float[i] = twin_binary_float[i - k + 1];
			}
		}
	}

	//вывод результата
	std::cout << "Представление числа типа данных float в IEEE-стандарте: ";
	for (int i = 0; i < const_float_bit; i++)
	{
		if (i < 22)
		{
			std::cout << binary_float[i] << "  ";
		}
		else 
		{
			std::cout << binary_float[i] << " ";
		}
	}

	std::cout << std::endl << std::endl;

	std::cout << "Номер бита:                                             ";

	for (int counter_simvol = 31; counter_simvol >= 0; --counter_simvol)
	{
		std::cout << counter_simvol << " ";
	}

	std::cout << std::endl;

	std::cout << "Хотите ли заменить биты на другие?";
	std::cout << std::endl;

	enum Variants { exit_program = -1, yes = 1, no = 2 };
	std::cout << "Нажмите '1', чтобы преобразовать" << std::endl;
	std::cout << "Нажмите '2', чтобы выйти в главное меню" << std::endl;
	std::cout << "Нажмите '-1', если хотите выйти." << std::endl;

	//проверка на допустимость вводимого
	while (!(std::cin >> key_float) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n')
		{
			std::cout << "Повторите попытку" << std::endl;

		}
	}

	switch (key_float) 
	{
	case yes:
		preobrazovanie_float(); 
		break;
	case no:
		break;
	case exit_program:
		exit(1); 
		break;
	default:
		std::cout << "Повторите попытку";
		break;
	}

}

void main_menu() {
	enum Variants { exit_program = -1, unsig_char = 1, float_num = 2 };
	while (main_key == tap) 
	{
		std::cout << "Нажмите '1', чтобы ввести символ" << std::endl;
		std::cout << "Нажмите '2', чтобы ввести вещественное число" << std::endl;
		std::cout << "Нажмите '-1', если хотите выйти." << std::endl;

		while (!(std::cin >> main_key) || (std::cin.peek() != '\n'))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Повторите попытку" << std::endl;
			break;
		}

		switch (main_key) 
		{
		case unsig_char:
			function_for_unsigned_char(); 
			break;
		case float_num:
			function_for_float();
			break;
		case exit_program:
			exit(1); 
			break;
		default:
			std::cout << "Повторите попытку";
			break;
		}

		std::cout << std::endl;
		main_key = tap;
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Добро пожаловать" << std::endl;
	main_menu();

	return 0;
}
