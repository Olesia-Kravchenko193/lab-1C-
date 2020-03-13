#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;


struct book
{
	string author;
	string genre;
	string title;
	unsigned int edition;
};


const int NUM_OF_BOOK = 3;
book informacion[NUM_OF_BOOK];


void datainput()
{
	string authorm[NUM_OF_BOOK] = { "Пушкин","Толстой","Шевченко" };
	string genrem[NUM_OF_BOOK] = { "Фикшн","Роман","Поэзия" };
	string titlem[NUM_OF_BOOK] = { "Пиковая дама","Война и мир","Кобзар" };

	for (int i = 0; i < NUM_OF_BOOK; i++)
	{
		informacion[i].author = authorm[i];
		informacion[i].genre = genrem[i];
		informacion[i].title = titlem[i];

		cout << "Автор: " << informacion[i].author << "\n";
		cout << "Жанр: " << informacion[i].genre << "\n";
		cout << "Название: " << informacion[i].title << "\n";
		cout << "Введите тираж: ";
		cin >> informacion[i].edition;
		cout << endl;
	}
	cout << "\n\n";
}

void output()
{
	for (int i = 0; i < NUM_OF_BOOK; i++)
	{
		if (informacion[i].edition < 10000)
		{
			cout << "автор: " << informacion[i].author << endl;
			cout << "жанр: " << informacion[i].genre << endl;
			cout << "название: " << informacion[i].title << endl;
			cout << "тираж: " << informacion[i].edition << endl;
			cout << endl;
		}
	}
}

void Task1()
{
	datainput();
	output();

	/*return 0;*/
}
///////////////////////////////////
struct Goods
{
	string name;
	int madeDay;
	int madeMonth;
	int madeYear;
	string goden;
	int price;
	int SerialNum;
	string FinalDate;
};

const int GoodsCount = 5;
Goods num[GoodsCount];

void Task2()
{
	int allTime, y, m, d;
	string name[GoodsCount] = { "Pelmeshki", "Shaverma", "Borstch", "Pizza", "cheese" };
	for (int i = 0; i < GoodsCount; i++)
	{
		//Заполняем рандомно все поля 
		num[i].madeYear = 2019;
		num[i].madeMonth = rand() % 12 + 1;
		num[i].madeDay = rand() % 30 + 1;
		num[i].name = name[i];
		num[i].SerialNum = rand() % 9999 + 1000;
		num[i].price = rand() % 100 + 30;
		num[i].goden = rand() % 364 + 1;
		//Вычисляем количество дней которые "прожил" продукт
		allTime = num[i].madeYear * 365 + num[i].madeMonth * 30 + num[i].madeDay;
		cout << "Колличество дней действительности продукта: " << allTime << endl;

		//cout << allTime<<"  ";
			//Вывод готовых данных ->
		cout << num[i].name << " -> ";
		cout << "годен до: ";
		y = floor(allTime / 365);//Находим год производства, Floor используется для округления в МЕНЬШУЮ сторону
		cout << y << "/";
		m = floor((allTime - floor(allTime / 365) * 365) / 30);//месяц
		cout << m << "/";
		d = allTime - (y * 365 + m * 30);//день
		cout << d << "\n";
		cout << endl;
	}
}

//////////////////////////////

struct STUDENT
{
	string name;
	int marks[4];//Оценки
	float mediummark;//Средний балл
};

const short Students = 7;

STUDENT sort[1];//Перевалочный элемент структуры для сортировки студентов
STUDENT info[Students];//Основной массив структур

void input(int i)//Функция ввода данных
{
	for (int j = 0; j < 4; j++)
	{
		cout << "Введите оценку " << info[i].name << " по " << j + 1 << "-му предмету по 5-бальной системе: ";
		cin >> info[i].marks[j];
		fflush(stdin);

	}
	cout << endl;

}

void Task3()
{
	string names[Students + 4] = { "Корнев А.С.", "Савченко И.Р", "Гордиенко Г.А.", "Дмитриева А.А.", "Иванов И.И.","Петров А.О.","Сидоров С.М.","Ткаченко Л.Н.","Барабан А.А.","Синичкин.А.И.","Петрушка П.П." };
	for (int i = 0; i < Students; i++)
	{
		srand(time(NULL));
		info[i].name = names[rand() % 11];
		input(i);
	}



	//Считаем средний балл
	for (int i = 0; i < Students; i++)
	{
		double sum = 0;
		for (int j = 0; j < 4; j++)
		{
			sum += info[i].marks[j];
		}
		info[i].mediummark = sum / 4;
		cout << "Средний балл " << i + 1 << "-го студента: " << info[i].mediummark << endl;
	}

	//Начало цикла замены записей по убыванию
	for (int i = 0; i < Students - 1; i++)
	{
		for (int j = 1; j < Students; j++)
		{
			if (info[j].mediummark < info[j - 1].mediummark)
			{
				sort[1] = info[i];
				info[i] = info[j];
				info[j] = sort[1];

			}
		}
	}
	//////Закончили сортировку

  //Выводим данные о студентах со средним Баллом >= 4
	for (int i = 0; i < Students; i++)
	{
		if (info[i].mediummark >= 4)
		{
			cout << "Имя студента: " << info[i].name << "\n";
			cout << "Средний балл студента: " << info[i].mediummark << "\n";
			for (int j = 0; j < 4; j++)
			{
				cout << "Балл по " << j + 1 << "-му предмету: " << info[i].marks[j] << "\n";
			}

		}
		cout << endl;
	}

	//Заменяем (т.е. очищаем) на пустоту и нули запись с самым низким ср.Баллом
	info[Students - 1].name = ' ';
	for (int i = 0; i < 4; i++) info[Students - 1].marks[i] = 0;
	info[Students - 1].mediummark = 0;
	////
}

int main()
{
	setlocale(LC_ALL, "rus");

	int numTask;
	cout << "Enter num of task: ";
	cin >> numTask;
	cout << endl;

	switch (numTask)
	{
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;

	}
}