#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { COMPUTER_SC, MATH, ECONOMIC };
string specialtyStr[] = { "��", "Գ����", "��������" };

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
        cout << "������� � " << i + 1 << ":" << endl;

        cin.get();
        cin.sync();

        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " г� ����������: "; cin >> p[i].rik_nar;
        cout << " ����: "; cin >> p[i].kurs;
        cout << " (0 - ��, 1 - Գ����, 2 - ��������): ";

        cin >> specialty;
        p[i].specialty = static_cast<Specialty>(specialty);

        switch (p[i].specialty)
        {
        case COMPUTER_SC:
            cout << " ������ � ������ : "; cin >> p[i].physicsm;
            cout << " ������ � ���������� : "; cin >> p[i].mathm;
            cout << " ������ � ����������� : "; cin >> p[i].computerm;
            break;
        case MATH:
            cout << " ������ � ������ : "; cin >> p[i].physicsm;
            cout << " ������ � ���������� : "; cin >> p[i].mathm;
            cout << " ������ � ����������� : "; cin >> p[i].computerm;
            break;
        case ECONOMIC:
            cout << " ������ � ������ : "; cin >> p[i].physicsm;
            cout << " ������ � ���������� : "; cin >> p[i].mathm;
            cout << " ������ � ����������� : "; cin >> p[i].computerm;
        }

        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "================================================================================= " << endl;
    cout << "|  �  |  �������  | ���� |  ������������  | Գ���� | ���������� | ����������� | " << endl;
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
    cout << "ʳ������ ������ '�����' � ������� ��������:" << endl;
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

    cout << "Գ����: " << goodPhysics << endl;
    cout << "����������: " << goodMath << endl;
    cout << "�����������: " << goodInfo << endl;

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
    cout << "������ ������� ��������: "; cin >> N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);

    GoodGradeCount(p, N);

    double percent5PhysicsMath = PercentageOfStudentsWith5(p, N);
    cout << "������� ��������, �� �������� 5 �� ������ � ����������: " << percent5PhysicsMath << "%" << endl;

    delete[] p;

    return 0;
}
