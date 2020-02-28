#include <iostream>
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
    }

    AverageExperience /= AmountOfWorkers;
    cout << endl << "Средний стаж " << AverageExperience << endl << endl;

    for (size_t i = 0; i < AmountOfWorkers; i++)
    {
        if (ListOfWorkers[i].year > AverageExperience)
            cout << ListOfWorkers[i].lastName << " " << ListOfWorkers[i].firstName << " " << ListOfWorkers[i].middleName << endl << "Должность: " << ListOfWorkers[i].position << endl << "Пол: " << ListOfWorkers[i].gender << endl << "Год приема на работу: " << ListOfWorkers[i].year << endl << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int choice;
    cout << "Выберите задание: 1, 2 или 3" << endl;
again:
    cin >> choice;
    switch (choice)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        break;
    default:
        cout << "Неверный номер" << endl;
        goto again;
        break;
    }
}