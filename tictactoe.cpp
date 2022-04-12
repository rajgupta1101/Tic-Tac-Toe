#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int check(char a[]);
void fill(char a[]);
int vuser(char a[]);
int check1(char a[]);
int check2(char a[]);
int blankcheck(char a[], int b[]);
int blankcheckrandom(char a[], int b[]);

int main(int argc, char const *argv[])
{
    char arr[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    cout << "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9\n";

    cout << "YOu wil play with 'o' and computer will play with 'x'\n\n\n";
tryagain:
{
    cout << "Enter who will play first\n 1.) you\n 2.) computer\nEnter choice "
            ":- ";
    int n, i, k;
    cin >> k;
    switch (k)
    {

    case 1:
    {
    repeat:
        for (i = 0; i < 4; ++i)
        {
            cout << "choose your position(1-9) :- ";
            int b[9], j = blankcheck(arr, b), i;
            do
            {
                cin >> n;
                for (i = 0; i < j; i++)
                {
                    if (n - 1 == b[i])
                    {
                        arr[n - 1] = 'o';
                        break;
                    }
                }
                if (i == j)
                    cout << "Invalid choice\nchoose again :- ";
            } while (i == j);
            if (check2(arr) == 1)
            {
                cout << "you won the game!congratulation\n";
                break;
            }
            fill(arr);
            for (int j = 0; j < 9; ++j)
            {
                cout << arr[j] << " | ";
                if ((j + 1) % 3 == 0)
                    cout << "\n-----------\n";
            }
            if (check2(arr) == 1)
            {
                cout << "computer won the game!so sad try again\n";
                break;
            }
        }
        if (i == 4)
        {
            cout << "Game draw!Try again\n";
        }
        for (i = 0; i < 9; ++i)
        {
            cout << arr[i] << " | ";
            if ((i + 1) % 3 == 0)
                cout << "\n-----------\n";
        }
        break;
    }
    case 2:
    {
        srand(time(0));
        int k = rand() % 9;
        arr[k] = 'x';
        for (i = 0; i < 9; ++i)
        {
            cout << arr[i] << " | ";
            if ((i + 1) % 3 == 0)
                cout << "\n-----------\n";
        }
        goto repeat;
        break;
    }
    default:
    {
        cout << "Wrong choice Try again!\n";
        goto tryagain;
    }
    }
}

    return 0;
}

int blankcheck(char a[], int b[])
{
    int j = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (a[i] == ' ')
        {
            b[j++] = i;
        }
    }
    return j;
}

int blankcheckrandom(char a[], int b[])
{
    srand(time(0));
    int j = 0;
    for (int i = 0;; i = rand() % 9)
    {
        if (a[i] == ' ')
        {
            b[j++] = i;
        }
        if (j == 8)
            break;
    }
    return j;
}

void fill(char arr[])
{
    int c = 0;
    if (arr[4] == ' ')
        arr[4] = 'x';
    else
    {
        char temp[9];
        for (int i = 0; i < 9; ++i)
        {
            if (arr[i] == 'x')
                temp[i] = 'o';
            else if (arr[i] == 'o')
                temp[i] = 'x';
            else
                temp[i] = arr[i];
        }
        int p = check(temp);
        if (p != 9)
            arr[p] = 'x';
        else
        {
            c++;
        }
    }
    if (c == 1)
    {
        int p = check(arr);
        if (p != 9)
        {
            arr[p] = 'x';
            return;
        }
    }
    if (c == 1)
    {
        int b[9], j = blankcheckrandom(arr, b), l;
        for (l = 0; l < j; l++)
        {
            arr[b[l]] = 'x';
            int k = vuser(arr);
            if (k != 1)
            {
                arr[b[l]] = ' ';
                continue;
            }
            else
            {
                arr[b[l]] = 'x';
                break;
            }
        }
        if (l == j)
        {
            char temp[9];
            for (int i = 0; i < 9; ++i)
            {
                if (arr[i] == 'x')
                    temp[i] = 'o';
                else if (arr[i] == 'o')
                    temp[i] = 'x';
                else
                    temp[i] = arr[i];
            }
            for (l = 0; l < j; l++)
            {
                temp[b[l]] = 'o';
                arr[b[l]] = 'x';
                int k = check(temp);
                if (k != 9)
                {
                    temp[k] = 'x';
                    arr[k] = 'o';
                    if (check1(arr) == 1)
                    {
                        temp[k] = ' ';
                        temp[b[l]] = ' ';
                        arr[k] = ' ';
                        arr[b[l]] = ' ';
                    }
                    else
                    {
                        arr[b[l]] = 'x';
                        arr[k] = ' ';
                        break;
                    }
                }
                else
                {
                    temp[b[l]] = ' ';
                    arr[b[l]] = ' ';
                }
            }
        }
    }
    return;
}

int vuser(char arr[])
{
    int b[9], j = blankcheck(arr, b), i;
    for (i = 0; i < j; ++i)
    {
        arr[b[i]] = 'o';
        int n = check1(arr);
        if (n == 1)
        {
            arr[b[i]] = ' ';
            return 0;
            break;
        }
        else
            arr[b[i]] = ' ';
    }
    if (i == j)
    {
        return 1;
    }
    return 0;
}

int check(char a[])
{
    if (a[0] == 'o' & a[1] == 'o' & a[2] == ' ')
        return 2;
    if (a[0] == 'o' & a[2] == 'o' & a[1] == ' ')
        return 1;
    if (a[2] == 'o' & a[1] == 'o' & a[0] == ' ')
        return 0;
    if (a[3] == 'o' & a[4] == 'o' & a[5] == ' ')
        return 5;
    if (a[4] == 'o' & a[5] == 'o' & a[3] == ' ')
        return 3;
    if (a[3] == 'o' & a[5] == 'o' & a[4] == ' ')
        return 4;
    if (a[6] == 'o' & a[7] == 'o' & a[8] == ' ')
        return 8;
    if (a[6] == 'o' & a[8] == 'o' & a[7] == ' ')
        return 7;
    if (a[7] == 'o' & a[8] == 'o' & a[6] == ' ')
        return 6;
    if (a[0] == 'o' & a[3] == 'o' & a[6] == ' ')
        return 6;
    if (a[0] == 'o' & a[6] == 'o' & a[3] == ' ')
        return 3;
    if (a[3] == 'o' & a[6] == 'o' & a[0] == ' ')
        return 0;
    if (a[2] == 'o' & a[5] == 'o' & a[8] == ' ')
        return 8;
    if (a[2] == 'o' & a[8] == 'o' & a[5] == ' ')
        return 5;
    if (a[5] == 'o' & a[8] == 'o' & a[2] == ' ')
        return 2;
    if (a[4] == 'o' & a[1] == 'o' & a[7] == ' ')
        return 7;
    if (a[7] == 'o' & a[1] == 'o' & a[4] == ' ')
        return 4;
    if (a[7] == 'o' & a[4] == 'o' & a[1] == ' ')
        return 1;
    if (a[0] == 'o' & a[4] == 'o' & a[8] == ' ')
        return 8;
    if (a[0] == 'o' & a[8] == 'o' & a[4] == ' ')
        return 4;
    if (a[4] == 'o' & a[8] == 'o' & a[0] == ' ')
        return 0;
    if (a[2] == 'o' & a[4] == 'o' & a[6] == ' ')
        return 6;
    if (a[4] == 'o' & a[6] == 'o' & a[2] == ' ')
        return 2;
    if (a[2] == 'o' & a[6] == 'o' & a[4] == ' ')
        return 4;
    else
        return 9;
}

int check1(char a[])
{
    int k = 0;
    if (a[0] == 'o' & a[1] == 'o' & (a[2] == ' ' || a[2] == 'o'))
        k++;
    if (a[0] == 'o' & a[2] == 'o' & (a[1] == ' ' || a[1] == 'o'))
        k++;
    if (a[2] == 'o' & a[1] == 'o' & (a[0] == ' ' || a[0] == 'o'))
        k++;
    if (a[3] == 'o' & a[4] == 'o' & (a[5] == ' ' || a[5] == 'o'))
        k++;
    if (a[4] == 'o' & a[5] == 'o' & (a[3] == ' ' || a[3] == 'o'))
        k++;
    if (a[3] == 'o' & a[5] == 'o' & (a[4] == ' ' || a[4] == 'o'))
        k++;
    if (a[6] == 'o' & a[7] == 'o' & (a[8] == ' ' || a[8] == 'o'))
        k++;
    if (a[6] == 'o' & a[8] == 'o' & (a[7] == ' ' || a[7] == 'o'))
        k++;
    if (a[7] == 'o' & a[8] == 'o' & (a[6] == ' ' || a[6] == 'o'))
        k++;
    if (a[0] == 'o' & a[3] == 'o' & (a[6] == ' ' || a[6] == 'o'))
        k++;
    if (a[0] == 'o' & a[6] == 'o' & (a[3] == ' ' || a[3] == 'o'))
        k++;
    if (a[3] == 'o' & a[6] == 'o' & (a[0] == ' ' || a[0] == 'o'))
        k++;
    if (a[2] == 'o' & a[5] == 'o' & (a[8] == ' ' || a[8] == 'o'))
        k++;
    if (a[2] == 'o' & a[8] == 'o' & (a[5] == ' ' || a[5] == 'o'))
        k++;
    if (a[5] == 'o' & a[8] == 'o' & (a[2] == ' ' || a[2] == 'o'))
        k++;
    if (a[4] == 'o' & a[1] == 'o' & (a[7] == ' ' || a[7] == 'o'))
        k++;
    if (a[7] == 'o' & a[1] == 'o' & (a[4] == ' ' || a[4] == 'o'))
        k++;
    if (a[7] == 'o' & a[4] == 'o' & (a[1] == ' ' || a[1] == 'o'))
        k++;
    if (a[0] == 'o' & a[4] == 'o' & (a[8] == ' ' || a[8] == 'o'))
        k++;
    if (a[0] == 'o' & a[8] == 'o' & (a[4] == ' ' || a[4] == 'o'))
        k++;
    if (a[4] == 'o' & a[8] == 'o' & (a[0] == ' ' || a[0] == 'o'))
        k++;
    if (a[2] == 'o' & a[4] == 'o' & (a[6] == ' ' || a[6] == 'o'))
        k++;
    if (a[4] == 'o' & a[6] == 'o' & (a[2] == ' ' || a[2] == 'o'))
        k++;
    if (a[2] == 'o' & a[6] == 'o' & (a[4] == ' ' || a[4] == 'o'))
        k++;
    if (k >= 2)
    {
        return 1;
    }
    else
        return 0;
}

int check2(char a[])
{
    if (a[0] == a[1] & a[1] == a[2] & a[2] != ' ')
        return 1;
    if (a[3] == a[4] & a[4] == a[5] & a[5] != ' ')
        return 1;
    if (a[6] == a[7] & a[7] == a[8] & a[8] != ' ')
        return 1;
    if (a[0] == a[4] & a[8] == a[0] & a[0] != ' ')
        return 1;
    if (a[2] == a[4] & a[4] == a[6] & a[6] != ' ')
        return 1;
    if (a[0] == a[3] & a[3] == a[6] & a[6] != ' ')
        return 1;
    if (a[1] == a[4] & a[4] == a[7] & a[7] != ' ')
        return 1;
    if (a[5] == a[2] & a[2] == a[8] & a[8] != ' ')
        return 1;
    else
        return 0;
}