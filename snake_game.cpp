#include <bits/stdc++.h>
#include <conio.h> //console input output..

using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define vi vector<int>
#define fi first
#define se second

bool gameOver;
const int width = 22, height = 22;
int posx, posy, fruitx, fruity, score, length = 0;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;
map<pair<int, int>, int> mp;

struct tailNodes
{
    int x, y;
};

tailNodes arr[40];

void setup()
{
    gameOver = false;
    dir = STOP;
    posx = width / 2;
    posy = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}

void draw()
{
    system("cls");
    cout << endl
         << endl
         << endl;
    for (int i = 0; i < 22; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 1; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout << "#";
            }
            else if (i == posx && j == posy)
            {
                cout << "O";
            }
            else if (i == fruitx && j == fruity)
            {
                cout << "*";
            }
            else if (mp[{i, j}] == 1)
            {
                cout << "o";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 22; i++)
    {
        cout << "#";
    }
    cout << endl
         << "Score: " << score << endl;
}

void input()
{
    if (_kbhit())
    { //return a boolean value if any key on the keyboard is HIT !..
        char x1 = _getch();
        //cout<<x1<<endl;
        if (x1 == 'a')
        {
            dir = LEFT;
        }
        else if (x1 == 'w')
        {
            dir = UP;
        }
        else if (x1 == 's')
        {
            dir = DOWN;
        }
        else if (x1 == 'd')
        {
            dir = RIGHT;
        }
        else if (x1 == 'x')
        {
            gameOver = true;
        }
    }
}

void createLogic()
{
    int prevx = posx, prevy = posy;
    switch (dir)
    {
    case UP:
        posx--;
        break;
    case DOWN:
        posx++;
        break;
    case LEFT:
        posy--;
        break;
    case RIGHT:
        posy++;
        break;
    default:
        break;
    }
    if (posx <= 0 || posy <= 0 || posx >= 22 || posy >= 22)
    {
        cout << "Game Over" << endl;
        cout << "Your final score is: " << score << " points" << endl;
        gameOver = true;
        return;
    }
    if (posx == fruitx && posy == fruity)
    {
        score += 10;
        fruitx = (rand() % (width - 2)) + 1;
        fruity = (rand() % (height - 2)) + 1;
        length++;
        return;
    }
    if (length > 0)
    {
        mp[{arr[length - 1].x, arr[length - 1].y}] = 0;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        if (i == 0)
            break;
        arr[i].x = arr[i - 1].x;
        arr[i].y = arr[i - 1].y;
        mp[{arr[i].x, arr[i].y}] = 1;
    }
    if (length > 0)
    {
        arr[0].x = prevx;
        arr[0].y = prevy;
        mp[{arr[0].x, arr[0].y}] = 1;
    }
}

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        createLogic();
    }

    return 0;
}