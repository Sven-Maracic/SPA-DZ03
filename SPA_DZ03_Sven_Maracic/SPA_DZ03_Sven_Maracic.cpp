#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;

void printGrid(int ar, int as, int br, int bs, int curX, int curY) {
    const int gridSize = 25;

    for (int y = 1; y < gridSize + 1; ++y) {
        for (int x = 1; x < gridSize + 1; ++x) {
            if (x == ar && y == as) {
                cout << "A";
            }
            else if (x == br && y == bs) {
                cout << "B";
            }
            else if (x == curX && y == curY) {
                cout << "x";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

void visualizePath(int ar, int as, int br, int bs) {
    int curS = ar, curR = as;

    while (curS != br || curR != bs) {
        system("cls");
        printGrid(ar, as, br, bs, curS, curR);

        if (curS < br) {
            curS++;
        }
        else if (curS > br) {
            curS--;
        }

        else if (curR < bs) {
            curR++;
        }
        else if (curR > bs) {
            curR--;
        }

        this_thread::sleep_for(100ms);
    }
    system("cls");
    printGrid(ar, as, br, bs, curS, curR);
    system("pause");
}

int main() {
    int ar, as, br, bs;
    cout << "A stupac:";
    cin >> ar;
    cout << "A redak:";
    cin >> as;
    cout << "B stupac:";
    cin >> br;
    cout << "B redak:";
    cin >> bs;

    visualizePath(ar, as, br, bs);

    return 0;
}