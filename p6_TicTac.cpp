#include <iostream>
#include <iomanip>
using namespace std;

char turn = 'X';
int row, col;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void display_board() {
    system("cls"); // This command clears the screen
    cout << "\n\n  T i c k   C r o s s    G a m e" << endl;
    cout << "\tPlayer1 [X] \n\tPlayer2 [O]\n\n" << endl;
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t\t     |     |     \n";
}

void play_game() {
    int choice;
    if (turn == 'X') cout << "\n\tPlayer1 [X] turn: ";
    if (turn == 'O') cout << "\n\tPlayer2 [O] turn: ";
    cin >> choice;

    switch(choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "Invalid choice\n"; break;
    }

    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'O';
        turn = 'X';
    } else {
        cout << "Box is full!\n Please try again!! \n\n";
        play_game();
    }
}

int gameover() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) return 1;

    // Check for draw
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') draw = false;
        }
    }
    if (draw) return 0;
    return -1; // Game continues
}

int main() {
    int status = -1;
    while (status == -1) {
        display_board();
        play_game();
        status = gameover();
    }

    display_board();
    if (status == 1) {
        if (turn == 'X') cout << "\nPlayer2 [O] wins!";
        else cout << "\nPlayer1 [X] wins!";
    } else {
        cout << "\nIt's a draw!";
    }
    return 0;
}