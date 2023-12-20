// Game of snake, can be played in the terminal of IDE but runs better as an executable

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
// width and height of the game
const int width = 20;
const int height = 20;
// head of the snake 
int x, y, fruitX, fruitY, score, tailX[100], tailY[100], nTail;
// direction of the snake
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {

    // initialize gameOver to false
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width; // random number between 0 and 19
    fruitY = rand() % height; // random number between 0 and 19
    score = 0;
}

// Draw the game
void Draw() {
    system("cls"); 

    // top border
    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;

    // left and right border
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width + 2; j++) {
            if (j == 0) {
                cout << "#";
            }
            if (i == y && j == x) {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print) {
                    cout << " ";
                }
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) {
        cout << "#";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input() {
    // if a key is pressed
    if (_kbhit()) {
        // getch is a function that gets the character that was pressed without echo
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// Game logic: collision detection, score, direction
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    // this is for when the snake hits the wall
    if (x >= width) {
        x = 0;
    }
    else if (x < 0) {
        x = width - 1;
    }
    if (y >= height) {
        y = 0;
    }
    else if (y < 0) {
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width; // random number between 0 and 19
        fruitY = rand() % height; // random number between 0 and 19
        nTail++;
    }
}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(10); 
    }
    return 0;
}

