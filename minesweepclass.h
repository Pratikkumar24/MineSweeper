#include <iostream>
using namespace std;
class minesweeper
{
    char board[50][50];
    char fakeboard[50][50];
    int rows, col;

public:
    minesweeper(int rows, int col)
    {
        this->rows = rows;
        this->col = col;
    }
    void startGame();           //Starts the game
    void Initialize();          //Calls the initializing function to initialize
    void InitializeBoard();     //initializes the board with mines
    void InitializingNumbers(); //initializes the mines with the numbers around it
    void show_board();          //Shows the output of the matrix(board)
    void show_fakeboard();      //Shows the output of the matrix(board)
};
//END OF CLASS
/******************************************************************************************/
