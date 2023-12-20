// Recursively find a path for the knight to visit all the squares on the chessboard.

#include <iostream>
using namespace std;

const int N = 8;
int board[N][N];


// Check if (x, y) is valid chess board coordinates
bool isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Print the solution
void printSolution()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << board[x][y] << " ";
        cout << endl;
    }
}

// variables x and y are the current position of the knight
// movei is the current move number
// xMove[] and yMove[] are the next move of the knight
bool solveKT(int x, int y, int movei, int xMove[], int yMove[])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return true;

    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y))
        {
            board[next_x][next_y] = movei;
            if (solveKT(next_x, next_y, movei + 1, xMove, yMove))
                return true;
            else
                board[next_x][next_y] = -1;
        }
    }
    return false;
}

int main()
{
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = -1;

    board[0][0] = 0;

    
    if (!solveKT(0, 0, 1, xMove, yMove))
        cout << "Solution does not exist";
    else
        printSolution();

    return 0;
}

