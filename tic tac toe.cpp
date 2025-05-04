#include <iostream>
using namespace std;

// The game board initialized with numbers (1-9)
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

char turn = 'X'; // Keeps track of whose turn it is ('X' or 'O')
int row, col;    // To store the selected row and column
int moves = 0;   // To count the number of moves made

// Function to display the game board
void display_board() {
    system("cls");  // Clears the screen (Windows only)
    cout << "\n\n\t\t\t\tT i c k\tT a c k\tT o e\n";
    cout << "\t\tPlayer1 [X]\n\t\tPlayer2 [O]\n\n";

    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t\t\t     |     |     \n";
}

// Function to handle a player's turn
void player_turn() {
    int choice;
    while (true) {
        cout << "\n\tPlayer";
        if (turn == 'X') {
            cout << "\n\tPlayer1 [X] turn: ";
        }
        else {
            cout << "\n\tPlayer2 [O] turn: ";
        }

        cin >> choice;

        // Map the choice to a row and column on the board
        switch (choice) {
        case 1: row = 0, col = 0; break;
        case 2: row = 0, col = 1; break;
        case 3: row = 0, col = 2; break;
        case 4: row = 1, col = 0; break;
        case 5: row = 1, col = 1; break;
        case 6: row = 1, col = 2; break;
        case 7: row = 2, col = 0; break;
        case 8: row = 2, col = 1; break;
        case 9: row = 2, col = 2; break;
        default:
            cout << "Invalid choice! Please try again.\n";
            continue;  // Prompt again for a valid input
        }

        // Check if the chosen cell is valid
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = turn;  // Mark the cell
            turn = (turn == 'X') ? 'O' : 'X';  // Switch turn
            moves++;  // Increment the move counter
            break;  // Exit the loop after a valid move
        }
        else {
            cout << "Box already filled! Please try again.\n";
        }
    }
}

// Function to check if the game is over
bool game_over() {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;  // Row win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;  // Column win
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;  // Main diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;  // Anti-diagonal

    return false;  // No win condition met
}

// Main function to execute the game
int main() {
    while (true) {
        display_board();
        player_turn();

        // Check for a win or draw
        if (game_over()) {
            display_board();
            cout << "\n\tPlayer" << (turn == 'X' ? "2 [O]" : "1 [X]") << " Wins! Congratulations!\n";
            break;
        }

        if (moves == 9) {  // All moves filled, it's a draw
            display_board();
            cout << "\n\tIt's a Draw! Well played both players!\n";
            break;
        }
    }

    return 0;
}
