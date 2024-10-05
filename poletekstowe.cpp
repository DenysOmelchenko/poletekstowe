#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE konsola;

void rysujObszar()
{
    COORD pozycja = { 10, 10 };
    SetConsoleTextAttribute(konsola, BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 25; ++i)
    {
        SetConsoleCursorPosition(konsola, pozycja);
        cout << " ";
        pozycja.X++;
    }
    SetConsoleTextAttribute(konsola, 0);
}

void obslugaWejscia()
{
    SetConsoleTextAttribute(konsola, BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    COORD pozycja = { 10, 10};
    int kodZnaku = 0;
    SetConsoleCursorPosition(konsola, pozycja);

    while ((kodZnaku = _getch()) != 27)
    {
        if (kodZnaku == 224)
        {
            
            kodZnaku = _getch();
        }

        switch (kodZnaku)
        {
        case 75:
            if (pozycja.X > 5)
            {
                pozycja.X--;
                SetConsoleCursorPosition(konsola, pozycja);
            }
            break;
        case 77:
            if (pozycja.X < 29)
            {
                pozycja.X++;
                SetConsoleCursorPosition(konsola, pozycja);
            }
            break;
        case 8:
            if (pozycja.X > 5)
            {
                pozycja.X--;
                SetConsoleCursorPosition(konsola, pozycja);
                cout << " ";
                SetConsoleCursorPosition(konsola, pozycja);
            }
            break;
        default:
            if (kodZnaku >= 32 && kodZnaku <= 126 && pozycja.X < 34)
            {
                cout << char(kodZnaku);
                pozycja.X++;
            }
        }
    }

    SetConsoleTextAttribute(konsola, 0);
    cout << "\nWyjście z programu...\n";
}

int main()
{
    konsola = GetStdHandle(STD_OUTPUT_HANDLE);
    rysujObszar();
    obslugaWejscia();
    return 0;
}
