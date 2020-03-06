#include <iostream>
#include <Windows.h>
using namespace std;

void task1()
{
	struct StudentsMarks
	{
		char secondName[56];

		unsigned short group;

		unsigned short physics;

		unsigned short inform;

		unsigned short history;
	};

	float average = 0;

	const unsigned short Amount = 5;

	struct StudentsMarks students[Amount];

	for (size_t i = 0; i < Amount; i++)
	{
		cout << "Введите фамилию студента" << endl;

		cin.ignore(std::cin.rdbuf()->in_avail());

		cin.getline(students[i].secondName, 56);

		cout << "Введите номер группы" << endl;

		if (!(cin >> students[i].group))
		{
			cout << "Некорректный ввод числового значения!" << endl;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(65535, '\n');
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		students[i].physics = rand() % 5 + 1;

		students[i].inform = rand() % 5 + 1;

		students[i].history = rand() % 5 + 1;

		average += students[i].physics;
	}

	average /= Amount;

	cout << "Средняя оценка по физике: " << average << endl;

	for (size_t i = 0; i < Amount; i++)
	{
		if (students[i].inform == 5)
		{
			cout << "Студент:" << students[i].secondName << endl << "Группа: " << students[i].group << endl << "Оценка по физике: " << students[i].physics << endl << "Оценка по информатике: " << students[i].inform << endl << "Оценка по истории: " << students[i].history << endl;
		}
	}
}

void task2()
{
	struct AboutWorkers
	{
		char firstName[56];

		char middleName[56];

		char lastName[56];

		char position[40];

		char gender[12];

		unsigned short year;
	};

	const unsigned short AmountOfWorkers = 5;

	double AverageExperience = 0;

	struct AboutWorkers ListOfWorkers[AmountOfWorkers];

	for (size_t i = 0; i < AmountOfWorkers; i++)
	{
		cout << "Введите фамилию" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(ListOfWorkers[i].lastName, 56);

		cout << "Введите имя" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(ListOfWorkers[i].firstName, 56);

		cout << "Введите отчество" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(ListOfWorkers[i].middleName, 56);

		cout << "Введите должность" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(ListOfWorkers[i].position, 40);

		cout << "Введите пол" << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(ListOfWorkers[i].gender, 12);

		ListOfWorkers[i].year = rand() % 21 + 2000;
		AverageExperience += 2020 - ListOfWorkers[i].year;

		cout << endl;
	}

	AverageExperience /= AmountOfWorkers;

	cout << endl << "Средний стаж " << AverageExperience << endl << endl;

	for (size_t i = 0; i < AmountOfWorkers; i++)
	{
		if (2020 - ListOfWorkers[i].year > AverageExperience)
			cout << ListOfWorkers[i].lastName << " " << ListOfWorkers[i].firstName << " " << ListOfWorkers[i].middleName << endl << "Должность: " << ListOfWorkers[i].position << endl << "Пол: " << ListOfWorkers[i].gender << endl << "Дата приема на работу: " << ListOfWorkers[i].year << endl << endl;
	}
}

const int AmountOfStudents = 3;

bool SimileFac(char CurrentFac[30], char NextFac[30])
{
	for (size_t i = 0; i < 30; i++)
	{
		if (CurrentFac[i] != NextFac[i])
			return 0;
	}
	return 1;
}

bool SimileGroup(unsigned short CurrentGroup, unsigned short NextGroup)
{
	return CurrentGroup == NextGroup;
}

struct NAME
{
	char FirstName;

	char LastName[56];

	char MiddleName;

	void getName()
	{
		cout << "Введите фамилию и инициалы" << endl;

		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(LastName, 56);
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> FirstName;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> MiddleName;
	}
};

struct DATE_
{
	unsigned short day;

	unsigned short month;

	unsigned short year;

	void getDate()
	{
		cout << "Введите дату поступления дд-мм-г" << endl;

		if (!(cin >> day >> month >> year))
		{
			cout << "Некорректный ввод числового значения!" << endl;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(65535, '\n');
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	bool isCorrect()
	{
		bool result = false;
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}
		default:
			result = false;
		}
		return result;
	}
};

struct PERSON
{
	NAME Name;

	char FAC[30];

	unsigned short Group;

	DATE_ Date;

	bool isDisplayed = 0;
};

bool DateComparison(DATE_ CurrentStudent, DATE_ NextStudent)
{
	if (CurrentStudent.year > NextStudent.year)
		return 1;

	else
	{
		if (CurrentStudent.year == NextStudent.year)

			if (CurrentStudent.month > NextStudent.month)
				return 1;

			else if (CurrentStudent.month == NextStudent.month)

				if (CurrentStudent.day > NextStudent.day)
					return 1;
	}

	return 0;
}

bool isDateEqual(DATE_ CurrentStudent, DATE_ NextStudent)
{
	if (CurrentStudent.day == NextStudent.day && CurrentStudent.month == NextStudent.month && CurrentStudent.year == NextStudent.year)
		return 1;

	else return 0;
}

bool AlphabetComparison(char CurrentStudent[56], char NextStudent[56])
{
	for (size_t i = 0; i < 56; i++)
	{
		if (int(CurrentStudent[i]) < int(NextStudent[i]))
			return 0;
		else if (int(CurrentStudent[i]) > int(NextStudent[i]))
			return 1;
	}
	return 0;
}

void AlphabetSort(struct PERSON VUZ[AmountOfStudents], int* InSameDate, int AmountInSameDate)
{
	for (size_t i = 0; i < AmountInSameDate; i++)
	{
		for (size_t j = 0; j < AmountInSameDate - 1; j++)
		{
			if (AlphabetComparison(VUZ[InSameDate[j]].Name.LastName, VUZ[InSameDate[j + 1]].Name.LastName))
				swap(InSameDate[j], InSameDate[j + 1]);
		}
	}

	for (size_t i = 0; i < AmountInSameDate; i++)
	{
		cout << "ФИО " << VUZ[InSameDate[i]].Name.LastName << " " << VUZ[InSameDate[i]].Name.FirstName << " " << VUZ[InSameDate[i]].Name.MiddleName << endl;

		VUZ[InSameDate[i]].isDisplayed = true;
	}
}

void DateSort(struct PERSON VUZ[AmountOfStudents], int* InSameGroup, int AmountInSameGroup)
{
	int AmountInSameDate = 0, counter = 0;

	for (size_t i = 0; i < AmountInSameGroup; i++)
	{
		if (VUZ[InSameGroup[i]].isDisplayed == false)
		{
			for (size_t j = i; j < AmountInSameGroup; j++)
			{
				if (isDateEqual(VUZ[InSameGroup[i]].Date, VUZ[InSameGroup[j]].Date))
					AmountInSameDate++;
			}

			if (AmountInSameGroup > 1)
			{
				int* InSameDate = new int[AmountInSameDate];

				for (size_t j = i; j < AmountInSameGroup; j++)
				{
					if (isDateEqual(VUZ[InSameGroup[i]].Date, VUZ[InSameGroup[j]].Date))
						InSameDate[counter] = InSameGroup[j], counter++;
				}

				cout << "Дата " << VUZ[InSameGroup[i]].Date.day << "." << VUZ[InSameGroup[i]].Date.month << "." << VUZ[InSameGroup[i]].Date.year << endl;

				AlphabetSort(VUZ, InSameDate, AmountInSameDate);

				delete[] InSameDate;
			}
			else
			{
				cout << "Дата " << VUZ[InSameGroup[i]].Date.day << "." << VUZ[InSameGroup[i]].Date.month << "." << VUZ[InSameGroup[i]].Date.year << endl;

				cout << "ФИО " << VUZ[InSameGroup[i]].Name.LastName << " " << VUZ[InSameGroup[i]].Name.FirstName << " " << VUZ[InSameGroup[i]].Name.MiddleName << endl;

				VUZ[InSameGroup[i]].isDisplayed = true;
			}

			AmountInSameDate = 0, counter = 0;
		}
	}
}

void GroupSort(struct PERSON VUZ[AmountOfStudents], int* InSameFAC, int AmountInSameFAC)
{
	int AmountInSameGroup = 0, counter = 0;

	for (size_t i = 0; i < AmountInSameFAC; i++)
	{
		if (VUZ[InSameFAC[i]].isDisplayed == false)
		{
			for (size_t j = i; j < AmountInSameFAC; j++)
			{
				if (SimileGroup(VUZ[InSameFAC[i]].Group, VUZ[InSameFAC[j]].Group))
					AmountInSameGroup++;
			}

			if (AmountInSameGroup > 1)
			{
				int* InSameGroup = new int[AmountInSameGroup];

				for (size_t j = i; j < AmountInSameFAC; j++)
				{
					if (SimileGroup(VUZ[InSameFAC[i]].Group, VUZ[InSameFAC[j]].Group))
						InSameGroup[counter] = InSameFAC[j], counter++;
				}

				cout << "Группа " << VUZ[InSameFAC[i]].Group << endl;

				DateSort(VUZ, InSameGroup, AmountInSameGroup);

				delete[] InSameGroup;
			}

			else
			{
				cout << "Группа " << VUZ[InSameFAC[i]].Group << endl;

				cout << "Дата " << VUZ[InSameFAC[i]].Date.day << "." << VUZ[InSameFAC[i]].Date.month << "." << VUZ[InSameFAC[i]].Date.year << endl;

				cout << "ФИО " << VUZ[InSameFAC[i]].Name.LastName << " " << VUZ[InSameFAC[i]].Name.FirstName << " " << VUZ[InSameFAC[i]].Name.MiddleName << endl;

				VUZ[InSameFAC[i]].isDisplayed = true;
			}

			AmountInSameGroup = 0, counter = 0;
		}
	}
}

void FACSort(struct PERSON VUZ[AmountOfStudents])
{
	int AmountInSameFAC = 0, counter = 0;

	for (size_t i = 0; i < AmountOfStudents; i++)
	{
		if (VUZ[i].isDisplayed == false)
		{
			for (size_t j = i; j < AmountOfStudents; j++)
			{
				if (SimileFac(VUZ[i].FAC, VUZ[j].FAC))
					AmountInSameFAC++;
			}

			if (AmountInSameFAC > 1)
			{
				int* InSameFAC = new int[AmountInSameFAC];

				for (size_t j = i; j < AmountOfStudents; j++)
				{
					if (SimileFac(VUZ[i].FAC, VUZ[j].FAC))
						InSameFAC[counter] = j, counter++;
				}

				cout << "Факультет " << VUZ[i].FAC << endl;

				GroupSort(VUZ, InSameFAC, AmountInSameFAC);

				delete[] InSameFAC;
			}
			else
			{
				cout << "Факультет " << VUZ[i].FAC << endl;

				cout << "Группа " << VUZ[i].Group << endl;

				cout << "Дата " << VUZ[i].Date.day << "." << VUZ[i].Date.month << "." << VUZ[i].Date.year << endl;

				cout << "ФИО " << VUZ[i].Name.LastName << " " << VUZ[i].Name.FirstName << " " << VUZ[i].Name.MiddleName << endl;

				VUZ[i].isDisplayed = true;
			}

			AmountInSameFAC = 0, counter = 0;
		}
	}
}

void task3()
{
	struct PERSON VUZ[AmountOfStudents];

	//заполнение всех полей

	for (size_t i = 0; i < AmountOfStudents; i++)
	{
		VUZ[i].Name.getName();

		cout << "Введите факультет" << endl;

		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(VUZ[i].FAC, 30);

		cout << "Введите группу" << endl;

		while (!(cin >> VUZ[i].Group))
		{
			cout << "Некорректный ввод числового значения!" << endl;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(65535, '\n');
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		do
		{
			VUZ[i].Date.getDate();
		} while (!(VUZ[i].Date.isCorrect()));

		cout << endl;
	}

	//сортировка по дате внутри массива VUZ

	for (size_t j = 0; j < AmountOfStudents; j++)
	{
		for (size_t i = 0; i < AmountOfStudents - 1; i++)
		{
			if (DateComparison(VUZ[i].Date, VUZ[i + 1].Date))
				swap(VUZ[i], VUZ[i + 1]);
		}
	}

	FACSort(VUZ);

	cout << endl;

	//Вывод информации из массива VUZ

	/*for (size_t i = 0; i < Amount; i++)
	{
		cout << "Факультет " << VUZ[i].FAC << endl;

		cout << "Группа " << VUZ[i].Group << endl;

		cout << "Дата " << VUZ[i].Date.day << "." << VUZ[i].Date.month << "." << VUZ[i].Date.year << endl;

		cout << "ФИО " << VUZ[i].Name.LastName << " " << VUZ[i].Name.FirstName << " " << VUZ[i].Name.MiddleName << endl;
	}*/
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;

	while (true)
	{
		cout << "Выберите задание: 1)низкий уровень, 2)средний уровень, 3)высокий уровень" << endl;

		while (!(cin >> choice))
		{
			cout << "Некорректный ввод числового значения!" << endl;
			cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
			cin.ignore(65535, '\n');
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		switch (choice)
		{
		case 1:
			task1();
			break;

		case 2:
			task2();
			break;

		case 3:
			task3();
			break;

		default:
			cout << "Неверный номер" << endl;
			break;
		}
	}
}