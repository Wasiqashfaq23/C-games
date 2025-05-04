//The difficulty in tic tac toe was added (4x4)
//to do this a seperate 4x4 array was introduced and a seperate board was made 
//for checking wining condition a seprate win condition was applied to check win in 4x4 in row coloumn diognal and anti diognal
//the problem was that the number 10 11 12 13 14 15 16 were being displayed as 0 1 2 3 4 5 6 because the array was of datatypr (char)
//to tackle that string array was used and the X and O were dislplayed as string in that 

#include <iostream>
#include <ctime>
using namespace std;

// Function prototypes for Hangman game
void hangman(char);
int checkguess(char, string, string&);
void play_hangman();

// Global variables for Hangman game
int tries = 3;
string message = "You have 3 chances!";

// Function prototypes for Tic Tac Toe game
void display_board(int);
void player_turn(int);
bool game_over(int);
void play_tic_tac_toe(int);

// Global variables for Tic Tac Toe game
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} }; // 3x3 Tic Tac Toe board
string board_four[4][4] = { {"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"} };   //4x4 tic tac toe board
char turn = 'X'; // Keeps track of whose turn it is ('X' or 'O')
int row, col;    // To store the selected row and column
int moves = 0;   // To count the number of moves made





// Main menu function that allows the user to choose the game
void main_menu() {
    while (true) {
        cout << "\n\n========== Welcome to the Game Menu ==========\n";
        cout << "1. Play Hangman\n";
        cout << "2. Play Tic Tac Toe\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        int difficulty;
        cin >> choice;

        switch (choice) {
        case 1:
            play_hangman(); // Call to play Hangman game
            break;
        case 2:
            while (true)
            {
                system("cls");
                cout << "Select difficulty level for tic tac toe\n1.Easy\n2.Hard\nChoice=";
                cin >> difficulty;
            if(difficulty==1 || difficulty==2)
            { 
            play_tic_tac_toe(difficulty); // Call to play Tic Tac Toe game
            break;
            }
            else
            {
                cout << "Invalid! .Enter valid choice  ";
            }
            break;
            }
            break;
        case 3:
            cout << "Thank you for playing! Goodbye!\n"; // Exit the program
            return;
        default:
            cout << "Invalid choice! Please try again.\n"; // Invalid choice handling
        }
    }
}





// Hangman game implementation
void play_hangman() {
    char letter;
    string mystring[19] = {
        "monday", "tuesday", "wednesday",
        "thursday", "friday", "saturday", "sunday", "january", "february",
        "march", "april", "may", "june", "july", "august", "september",
        "october", "november", "december"
    };

    srand(time(NULL)); // for random number generation
    int randomnumber = rand() % 20; // Select a random word from the list
    string realword = mystring[randomnumber]; // Store the selected word
    string hiddenmonth(realword.length(), 'X'); // Mask the word with 'X' initially

    system("cls"); // Clear screen

    tries = 3; // Reset tries for each game
    message = "You have 3 chances!"; // Reset message

    while (tries != 0) { // Continue until tries are 0
        hangman('n'); // Display neutral state
        cout << "\t\t\t\tCan be Month or Day" << endl;
        cout << "\t\t\t\tLife: " << tries << endl; // Display remaining tries
        cout << "\t\t\t\tWord: " << hiddenmonth << endl; // Display the word with masked letters
        cout << "\t\t\t\tGuess a letter: ";
        cin >> letter;
        system("cls"); // Clear screen

        if (checkguess(letter, realword, hiddenmonth) == 0) { // Incorrect guess
            message = "Incorrect Letter!";
            tries--; // Reduce tries on incorrect guess
        }
        else { // Correct guess
            message = "Nice! Correct guess.";
        }

        if (hiddenmonth == realword) { // If the word is completely guessed
            message = "You are free!";
            hangman('f'); // Display winning state
            cout << "\t\t\t\tLife: " << tries << endl;
            cout << "\t\t\t\tThe word is: " << realword << endl;
            break; // Exit the game loop
        }
    }

    if (tries == 0) { // If tries reach 0
        message = "You are Hanged!";
        hangman('h'); // Display hanged state
        cout << "\t\t\t\tThe word was: " << realword << endl;
    }
}

// Function to check if the guessed letter is correct
int checkguess(char guess, string realword, string& hiddenword) {
    int matches = 0;
    int len = realword.length();
    for (int i = 0; i < len; i++) {
        if (guess == hiddenword[i]) { // Letter already guessed
            return 0;
        }
        if (guess == realword[i]) { // Correct guess
            hiddenword[i] = guess;
            matches++; // Increment match count
        }
    }
    return matches; // Return the number of correct matches
}

// Function to display the hangman image based on the game state
void hangman(char state) {
    string stage = "=";
    string handle = "\\";
    string head_string = "|";
    if (state == 'f') {
        head_string = " "; // No head on winning state
    }
    else if (state == 'h') {
        stage = " "; // No stage on hanged state
        handle = "/"; // Different handle for hanged state
    }
    // Hangman board
    cout << "\t\t\t\t___________________" << endl;
    cout << "\t\t\t\t          " << head_string << "       | " << endl;
    cout << "\t\t\t\t          O       |" << endl;
    cout << "\t\t\t\t         / \\      |" << "\t     " << message << endl;
    cout << "\t\t\t\t          |       |" << "\t         /" << endl;
    cout << "\t\t\t\t         / \\      |           O  " << endl;
    cout << "\t\t\t\t       =" << stage << stage << stage << stage << stage << "=    |          / \\" << endl;
    cout << "\t\t\t\t       |     |    |       " << handle << "   | " << endl;
    cout << "\t\t\t\t       |     |    |      === / \\" << endl;
    cout << "\t\t\t\t=========================|=|===============" << endl;
}




// Tic Tac Toe game implementation
void play_tic_tac_toe(int difficulty) {
    // Reset Tic Tac Toe board and variables
    if (difficulty == 1)
    {
        char initial_board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) {
                board[i][j] = initial_board[i][j]; // Reset board
            }
        }
    }
    if (difficulty == 2)
    {
        string initial_board[4][4] = {{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"}};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
            {
                board_four[i][j] = initial_board[i][j]; // Reset board
            }
        }
    } 

    turn = 'X'; // Reset turn to 'X' for Player 1
    moves = 0;   // Reset moves

    while (true) { // Loop until the game is over
        display_board(difficulty); // Display the game board
        player_turn(difficulty);   // Allow the current player to make a move

        if (game_over(difficulty)) { // Check if the game is over
            display_board(difficulty); // Display the final board
            cout << "\n\tPlayer" << (turn == 'X' ? "2 [O]" : "1 [X]") << " Wins! Congratulations!\n";  //ternary operator for winning condition for winning player
            break; // End the game if there's a winner
        }

        if (moves == (difficulty == 1 ? 9 : 16)) { // If all cells are filled and no winner, it's a draw
            display_board(difficulty);
            cout << "\n\tIt's a Draw! Well played both players!\n";
            break; // End the game as draw
        }
    }
}

// Function to display the Tic Tac Toe board
void display_board(int difficulty) {
    if (difficulty == 1) //board for 3x3
    {

    system("cls"); // Clear the screen
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
    if (difficulty == 2)//bord for 4x4
    {
        system("cls"); // Clear the screen
        cout << "\n\n\t\t\t\tT i c k\tT a c k\tT o e\n";
        cout << "\t\tPlayer1 [X]\n\t\tPlayer2 [O]\n\n";

        cout << "\t\t\t     |     |     |     \n";
        cout << "\t\t\t  " << board_four[0][0] << "  |  " << board_four[0][1] << "  |  " << board_four[0][2] << "  |  " << board_four[0][3] << "  \n";
        cout << "\t\t\t_____|_____|_____|_____\n";
        cout << "\t\t\t     |     |     |     \n";
        cout << "\t\t\t  " << board_four[1][0] << "  |  " << board_four[1][1] << "  |  " << board_four[1][2] << "  |  " << board_four[1][3] << "  \n";
        cout << "\t\t\t_____|_____|_____|_____\n";
        cout << "\t\t\t     |     |     |     \n";
        cout << "\t\t\t  " << board_four[2][0] << "  |  " << board_four[2][1] << "  |  " << board_four[2][2] << "  |  " << board_four[2][3] << "  \n";
        cout << "\t\t\t_____|_____|_____|_____\n";
        cout << "\t\t\t     |     |     |     \n";
        cout << "\t\t\t  " << board_four[3][0] << "  |  " << board_four[3][1] << "  |  " << board_four[3][2] << "  |  " << board_four[3][3] << "  \n";
        cout << "\t\t\t     |     |     |     \n";
    }
}

void player_turn(int difficulty) {
    int choice;
    while (true) {
        cout << "\n\tPlayer";
        if (turn == 'X') {
            cout << "\n\tPlayer1 [X] turn: "; // Display Player 1's turn
        }
        else {
            cout << "\n\tPlayer2 [O] turn: "; // Display Player 2's turn
        }

        cin >> choice; // Get the player's choice (1-9 for 3x3, 1-16 for 4x4)

        // Check if the game is already over or the number of moves has reached the maximum
        if (difficulty == 1 && moves >= 9) {
            cout << "Game over! All moves have been made.\n";
            return; // Game is over, return from the function
        }
        if (difficulty == 2 && moves >= 16) {
            cout << "Game over! All moves have been made.\n";
            return; // Game is over, return from the function
        }

        // Map the choice to a row and column on the board
        if (difficulty == 1) { //for 3x3 check if place is not filled
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
                cout << "Invalid choice! Please try again.\n"; // If the input is invalid, prompt again
                continue;
            }
        }
        else if (difficulty == 2) {  //for 4x4 check if place is not filled
            switch (choice) {
            case 1: row = 0, col = 0; break;
            case 2: row = 0, col = 1; break;
            case 3: row = 0, col = 2; break;
            case 4: row = 0, col = 3; break;
            case 5: row = 1, col = 0; break;
            case 6: row = 1, col = 1; break;
            case 7: row = 1, col = 2; break;
            case 8: row = 1, col = 3; break;
            case 9: row = 2, col = 0; break;
            case 10: row = 2, col = 1; break;
            case 11: row = 2, col = 2; break;
            case 12: row = 2, col = 3; break;
            case 13: row = 3, col = 0; break;
            case 14: row = 3, col = 1; break;
            case 15: row = 3, col = 2; break;
            case 16: row = 3, col = 3; break;
            default:
                cout << "Invalid choice! Please try again.\n"; // If the input is invalid, prompt again
                continue;
            }
        }

        // Check if the chosen cell is available (not already filled with 'X' or 'O')
        if ((difficulty == 1 && board[row][col] != 'X' && board[row][col] != 'O') ||
            (difficulty == 2 && board_four[row][col] != "X" && board_four[row][col] != "O")) {
            // Update the board with the player's symbol
            if (difficulty == 1)
                board[row][col] = turn;
            else
                board_four[row][col] = turn;

            // Switch turns
            turn = (turn == 'X') ? 'O' : 'X';
            moves++;  // Increment the move counter
            break;  // Exit the loop after a valid move
        }
        else {
            cout << "Box already filled! Please try again.\n"; // Prompt for a valid move if the cell is already filled
        }
    }
}




// Function to check if the game is over (either a win or a draw)
bool game_over(int difficulty)
{ 
    if (difficulty == 1)//check for win in 3x3
    {
        // Check for a win in the rows and columns
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Row win
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Column win
        }

        // Check for a win in the diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Main diagonal
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Anti-diagonal
    }
    else if (difficulty == 2) //check for win in 4x4
    {
        // Check for a win in the rows and columns
        for (int i = 0; i < 4; i++)
        {
            if (board_four[i][0] == board_four[i][1] && board_four[i][1] == board_four[i][2]  && board_four[i][2] == board_four[i][3]) return true; // Row win
            if (board_four[0][i] == board_four[1][i] && board_four[1][i] == board_four[2][i]  && board_four[2][i] == board_four[3][i]) return true; // Column win
        }

        // Check for a win in the diagonals
        if (board_four[0][0] == board_four[1][1] && board_four[1][1] == board_four[2][2] && board_four[2][2] == board_four[3][3]) return true; // Main diagonal
        if (board_four[0][3] == board_four[1][2] && board_four[1][2] == board_four[2][1] && board_four[2][1] == board_four[3][0]) return true; // Anti-diagonal

    }
        return false;  // No winner yet
}




// Main function that initiates the game menu and selects the game to play
int main() {
    main_menu();  // Start the game menu
    return 0;
}

