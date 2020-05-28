#include "minesweepclass.h"
//DEFINATION OF THE FUNCTION
void minesweeper::Initialize() //Initializing the board and numbers
{
    InitializeBoard();
    InitializingNumbers();
}

void minesweeper::InitializeBoard() //Initializing the board
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = '0';
        }
    }
    srand(time(0));
    for (int i = 0; i < rows; i++)
    {
        int r = rand() % rows;
        int c = rand() % col;
        board[r][c] = '*';
    }
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         if (board[i][j] != '*')
    //         {
    //             board[i][j] = '0';
    //         }
    //     }
    // }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fakeboard[i][j] = '-';
        }
    }
}
void minesweeper::InitializingNumbers() //Initializing the number
{

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < col; j++)
        {
            int counter = '0';
            if (board[i][j] != '*')
            {
                if (i > 0 && j > 0 && i < rows - 1 && j < col - 1)
                {
                    if (board[i - 1][j] == '*')
                    {
                        counter++;
                    }
                    if (board[i][j + 1] == '*')
                    {
                        counter++;
                    }
                    if (board[i + 1][j] == '*')
                    {
                        counter++;
                    }
                    if (board[i - 1][j - 1] == '*')
                    {
                        counter++;
                    }
                    if (board[i - 1][j + 1] == '*')
                    {
                        counter++;
                    }
                    if (board[i + 1][j - 1] == '*')
                    {
                        counter++;
                    }
                    if (board[i + 1][j + 1] == '*')
                    {
                        counter++;
                    }
                    if (board[i][j - 1] == '*')
                    {
                        counter++;
                    }
                    board[i][j] = (char)counter;
                }
                else
                {
                    if (i == 0 && j == 0)
                    {
                        if (board[i + 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j + 1] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (i == 0 && j == col - 1)
                    {
                        if (board[i + 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j - 1] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (i == rows - 1 && j == col - 1)
                    {
                        if (board[i][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (i == rows - 1 && j == 0)
                    {
                        if (board[i][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (i == 0)
                    {
                        if (board[i][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j + 1] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (j == 0)
                    {
                        if (board[i - 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (i == rows - 1)
                    {
                        if (board[i][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j + 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j + 1] == '*')
                        {
                            counter++;
                        }
                    }
                    else if (j == col - 1)
                    {
                        if (board[i - 1][j] == '*')
                        {
                            counter++;
                        }
                        if (board[i - 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j - 1] == '*')
                        {
                            counter++;
                        }
                        if (board[i + 1][j] == '*')
                        {
                            counter++;
                        }
                    }

                    board[i][j] = (char)counter;
                }
            }
        }
    }
}
void minesweeper::show_board() //Showing the board
{
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void minesweeper::show_fakeboard() //Showing the board
{
    cout << endl
         << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    int counter = 0;
    cout << "    ";
    for (int i = 0; i < rows; i++)
        cout << counter++ << "  ";
    cout << endl
         << endl;
    counter = 0;
    for (int i = 0; i < rows; i++)
    {
        cout << counter++ << "   ";
        for (int j = 0; j < col; j++)
        {

            cout << fakeboard[i][j] << "  ";
        }
        cout << endl
             << endl;
    }
}
