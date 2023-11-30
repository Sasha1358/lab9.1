#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { COMPUTER_SC, MATH, ECONOMIC };
string specialtyStr[] = { "КН", "Фізмат", "Економіка" };

struct Student
{
    string prizv;
    unsigned rik_nar;
    int kurs;
    Specialty specialty;
    int physicsm;
    int mathm;
    int computerm;
};

void Create(Student* p, const int N)
{
    int specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << " Прізвище: "; getline(cin, p[i].prizv);
        cout << " Рік народження: "; cin >> p[i].rik_nar;
        cout << " Курс: "; cin >> p[i].kurs;
        cout << " (0 - КН, 1 - Фізмат, 2 - Економіка): ";

        cin >> specialty;
        p[i].specialty = static_cast<Specialty>(specialty);

        switch (p[i].specialty)
        {
        case COMPUTER_SC:
            cout << " Оцінка з фізики : "; cin >> p[i].physicsm;
            cout << " Оцінка з математики : "; cin >> p[i].mathm;
            cout << " Оцінка з інформатики : "; cin >> p[i].computerm;
            break;
        case MATH:
            cout << " Оцінка з фізики : "; cin >> p[i].physicsm;
            cout << " Оцінка з математики : "; cin >> p[i].mathm;
            cout << " Оцінка з інформатики : "; cin >> p[i].computerm;
            break;
        case ECONOMIC:
            cout << " Оцінка з фізики : "; cin >> p[i].physicsm;
            cout << " Оцінка з математики : "; cin >> p[i].mathm;
            cout << " Оцінка з інформатики : "; cin >> p[i].computerm;
        }

        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "================================================================================= " << endl;
    cout << "|  №  |  Прізвище  | Курс |  Спеціальність  | Фізика | Математика | Інформатика | " << endl;
    cout << "--------------------------------------------------------------------------------- " << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " "
            << "| " << setw(13) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(11) << left << specialtyStr[p[i].specialty] << " "

            << "|    " << setw(8) << right << p[i].physicsm << " "
            << "| " << setw(11) << right << p[i].mathm << " "
            << "| " << setw(7) << right << p[i].computerm << " "
            << "| " << endl;
    }
    cout << "================================================================================= " << endl;
    cout << endl;
}

int GoodGradeCount(Student* p, const int N)
{
    cout << "Кількість оцінок 'добре' з кожного предмету:" << endl;
    int goodPhysics = 0;
    int goodMath = 0;
    int goodInfo = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].physicsm == 4 || p[i].physicsm == 5)
            goodPhysics++;

        if (p[i].mathm == 4 || p[i].mathm == 5)
            goodMath++;

        if (p[i].computerm == 4 || p[i].computerm == 5)
            goodInfo++;
    }

    cout << "Фізика: " << goodPhysics << endl;
    cout << "Математика: " << goodMath << endl;
    cout << "Інформатика: " << goodInfo << endl;

    return 0;
}

double PercentageOfStudentsWith5(Student* p, const int N)
{
    int count5PhysicsMath = 0;

    for (int i = 0; i < N; i++)
    {
        if ((p[i].physicsm == 5) && (p[i].mathm == 5))
            count5PhysicsMath++;
    }

    return 100.0 * count5PhysicsMath / N;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);

    GoodGradeCount(p, N);

    double percent5PhysicsMath = PercentageOfStudentsWith5(p, N);
    cout << "Процент студентів, які отримали 5 із фізики і математики: " << percent5PhysicsMath << "%" << endl;

    delete[] p;

    return 0;
}
