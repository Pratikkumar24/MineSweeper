#include "minesweepclass.h"

int main()
{
    int difficulty;
    cout << "\n\t\t DIFFICULTY LEVEL\n";
    cout << "\n1:Beginner -- 9x9";
    cout << "\n2:Intermidiate -- 15x15";
    cout << "\n3:Advance -- 20x20";
    cout << "\n\t\n Enter Your choice:";
    cin >> difficulty;
    int row, col;
    switch (difficulty)
    {
    case 1:
        row = 9;
        col = 9;
        break;
    case 2:
        row = 15;
        col = 15;
        break;
    case 3:
        row = 20;
        col = 20;
        break;
    default:
        cout << "\n Wrong Option";
    }
    minesweeper m(row, col);
    m.Initialize();
    return 0;
}