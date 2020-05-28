#include "minesweepclass.h"
void fillup(char board[][50], char f[][50], int r, int c)
{
    if (board[r - 1][c] == '0')
    {
        board[r - 1][c] = 'O';
        f[r - 1][c] = board[r - 1][c];
        fillup(board, f, r - 1, c);
    }

    if (board[r + 1][c] == '0')
    {
        board[r + 1][c] = 'O';
        f[r + 1][c] = board[r + 1][c];
        fillup(board, f, r + 1, c);
    }

    if (board[r][c + 1] == '0')
    {
        board[r][c + 1] = 'O';
        f[r][c + 1] = board[r][c + 1];
        fillup(board, f, r, c + 1);
    }

    if (board[r][c - 1] == '0')
    {
        board[r][c - 1] = 'O';
        f[r][c - 1] = board[r][c - 1];

        fillup(board, f, r, c - 1);
    }
}
void givenumber(char board[][50], char f[][50], int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (f[i][j] == '-')
            {

                if (f[i - 1][j] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i][j + 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i + 1][j] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i - 1][j - 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i - 1][j + 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i + 1][j - 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i + 1][j + 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
                if (f[i][j - 1] == 'O')
                {
                    f[i][j] = board[i][j];
                }
            }
        }
    }
}
int check(char f[][50], char b[][50], int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (f[i][j] == '-')
            {
                if (b[i][j] == '*')
                {
                    continue;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
void minesweeper::startGame()
{
    Initialize();
    int r, c;
    show_fakeboard();
    show_board();
    cout << "\n To Start the Game ..Enter the row and col:";
    cin >> r >> c;
    if (board[r][c] == '*')
    {
        Initialize();
    }

    while (board[r][c] != '*')
    {
        if (board[r][c] == '0')
        {
            fillup(board, fakeboard, r, c);

            givenumber(board, fakeboard, rows, col);
        }

        fakeboard[r][c] = board[r][c];
        show_fakeboard();
        show_board();

        int cont = check(fakeboard, board, rows, col);
        if (cont == 1)
        {
            cout << "\n\t\t\n\n\t CONGRATULATIONS!!!!!!\n\t\tYou Have won the Game\n\n";
            cout << "\n Real Board:\n";
            show_board(); //Real Board

            exit(0);
        }
        else
        {
            cout << "\nEnter the row and col:";
            cin >> r >> c;
            if (board[r][c] == '*')
            {
                cout << "\n\t\n\tOOPS!!! YOU STEPPED ON THE MINE \n NEED MORE BRAIN TO SOLVE IT\n\tBETTER LUCK NEXT TIME :p\n\n";
                cout << "\n \n\t And here is the real board..\n\n";
                show_board(); //Real Board
                break;
            }
        }
    }
}
