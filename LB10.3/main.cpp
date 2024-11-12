#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

struct Route
{
    string start_point;
    string end_point;
    int route_number;
};

void Create(Route* routes, const int N);
void Print(Route* routes, const int N);
void Sort(Route* routes, const int N);
void Search(Route* routes, const int N, const int search_number);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість маршрутів: ";
    cin >> N;

    Route* routes = new Route[N];
    int MenuItem;

    while (true)
    {
        cout << endl << endl;
        cout << "Оберіть дію:" << endl;
        cout << "1 - Ввести інформацію про маршрут" << endl;
        cout << "2 - Вивести інформацію про маршрути" << endl;
        cout << "3 - Впорядкувати за номерами маршрутів" << endl;
        cout << "4 - Пошук маршруту за номером" << endl;
        cout << "0 - Завершити роботу програми" << endl;
        cout << "Введіть: ";
        cin >> MenuItem;
        cout << endl;

        switch (MenuItem)
        {
        case 1:
            Create(routes, N);
            break;
        case 2:
            Print(routes, N);
            break;
        case 3:
            Sort(routes, N);
            Print(routes, N);
            break;
        case 4:
            int search_number;
            cout << "Введіть номер маршруту для пошуку: ";
            cin >> search_number;
            Search(routes, N, search_number);
            break;
        }
        if (MenuItem == 0) break;
    }

    delete[] routes;
    return 0;
}

void Create(Route* routes, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Маршрут №" << i + 1 << endl;
        cin.get();
        cout << "Початковий пункт: ";
        getline(cin, routes[i].start_point);
        cout << "Кінцевий пункт: ";
        getline(cin, routes[i].end_point);
        cout << "Номер маршруту: ";
        cin >> routes[i].route_number;
        cout << endl;
    }
}

void Print(Route* routes, const int N)
{
    cout << "=========================================================================" << endl;
    cout << "|  №  |   Початковий пункт   |   Кінцевий пункт    |   Номер маршруту   |" << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(4) << right << i + 1 << " ";
        cout << "|" << setw(22) << left << routes[i].start_point;
        cout << "|" << setw(21) << left << routes[i].end_point;
        cout << "|" << setw(20) << left << routes[i].route_number << "|" << endl;
    }
    cout << "=========================================================================" << endl << endl;
}

void Sort(Route* routes, const int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (routes[j].route_number > routes[j + 1].route_number)
            {
                swap(routes[j], routes[j + 1]);
            }
        }
    }
}

void Search(Route* routes, const int N, const int search_number)
{
    bool found = false;
    for (int i = 0; i < N; i++)
    {
        if (routes[i].route_number == search_number)
        {
            found = true;
            cout << "=========================================================================" << endl;
            cout << "|  №  |   Початковий пункт   |   Кінцевий пункт    |   Номер маршруту   |" << endl;
            cout << "-------------------------------------------------------------------------" << endl;

            cout << "|" << setw(4) << right << i + 1 << " ";
            cout << "|" << setw(22) << left << routes[i].start_point;
            cout << "|" << setw(21) << left << routes[i].end_point;
            cout << "|" << setw(20) << left << routes[i].route_number << "|" << endl;
            cout << "=========================================================================" << endl << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Маршрут з таким номером не знайдено." << endl;
    }
}
