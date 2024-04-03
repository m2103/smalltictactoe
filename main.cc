#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printboard(vector<vector<int>> board) {

    cout << endl << "Current Board:" << endl << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int cur = board[i][j];
            if (cur == -1) {
                cout << '_';
            } else if (cur == 0) {
                cout << 'O';
            } else {
                cout << 'X';
            }
        }
        cout << endl;
    }
    cout << endl;
}

int gameover(vector<vector<int>> board) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][0];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++) {
            if (board[i][j] == '_') {
                return -1;
            }
        }
    }
    return 2;
        
}


int main() {

    cin.exceptions(ios::eofbit|ios::failbit);
    int x;

    cout << "tic-tac-toe?" << endl;
    vector<vector<int>> ttt;
    for (int i = 0; i < 3; i++) {
        vector<int> vec;
        for (int j = 0; j < 3; j++) {
            vec.push_back(-1);
        }
        ttt.push_back(vec);
    }

    printboard(ttt);
    bool firstturn = true;
    bool turn = 0;

    cout << "O's turn" << endl;
    cout << "Please enter the integer coordinates of your move" << endl;

    try {
        while (cin >> x) {

            int y;
            cin >> y;

            if (x < 0 || x > 2 || y < 0 || y > 2) {
                cout << "Invalid input. Try again" << endl;
                continue;
            }

            if (ttt[x][y] != -1) {
                cout << "Square already filled. Try again." << endl;
                continue;
            }
            
            if (turn == 0) {
                ttt[x][y] = 0;
            } else {
                ttt[x][y] = 1;
            }

            turn = !turn;
            firstturn = false;

            printboard(ttt);

            int gm = gameover(ttt);

            if (gm >= 0) {
                cout << "Game Over!" << endl;
                if (gm == 0) {
                    cout << "O wins!" << endl;
                } else if (gm == 1) {
                    cout << "X wins!" << endl;
                } else {
                    cout << "Tie!" << endl;
                }
                break;
            }

            if (!firstturn) {
                if (!turn) {
                cout << "O's turn" << endl;
                } else {
                    cout << "X's turn" << endl;
                }
                cout << "Please enter the integer coordinates of your move" << endl;
            }
            
        }

    } catch (ios::failure&) {}

    return 0;

}


