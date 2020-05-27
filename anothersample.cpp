#include <iostream>
using namespace std;
void fillup(char ar[][10], int r, int c)
{
    if (ar[r - 1][c] == '*')
    {
        ar[r - 1][c] = 'X';
        fillup(ar, r - 1, c);
    }

    if (ar[r + 1][c] == '*')
    {
        ar[r + 1][c] = 'X';
        fillup(ar, r + 1, c);
    }

    if (ar[r][c + 1] == '*')
    {
        ar[r][c + 1] = 'X';
        fillup(ar, r, c + 1);
    }

    if (ar[r][c - 1] == '*')
    {
        ar[r][c - 1] = 'X';
        fillup(ar, r, c - 1);
    }
}
void show(char[][10], int, int);
int main()
{
    char ar[10][10];
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> ar[i][j];
        }
    }

    cout << "\n Your Matrix:\n\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    int rows, col;
    cout << "\n Enter the row and col:";
    cin >> rows >> col;
    fillup(ar, rows, col);
    show(ar, r, c);
    return 0;
}
void show(char ar[][10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
}