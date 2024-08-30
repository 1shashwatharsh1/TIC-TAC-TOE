#include <iostream>

char board[3][3]; 

void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = '1' + (i * 3 + j);
        }
    }
}

void displayBoard() {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

bool isWinner(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char player) {
    int choice;
    bool validMove = false;
    
    while (!validMove) {
        std::cout << "Player " << player << ", enter your move (1-9): ";
        std::cin >> choice;
        
        if (choice >= 1 && choice <= 9) {
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = player;
                validMove = true;
            } else {
                std::cout << "Invalid move. Cell already occupied!\n";
            }
        } else {
            std::cout << "Invalid move. Enter a number between 1 and 9.\n";
        }
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameRunning = true;

    initializeBoard();
    
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    
    while (gameRunning) {
        displayBoard();
        playerMove(currentPlayer);
        
        if (isWinner(currentPlayer)) {
            displayBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        } else if (isDraw()) {
            displayBoard();
            std::cout << "It's a draw!\n";
            gameRunning = false;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
        }
    }

    std::cout << "Game over. Thanks for playing!\n";
    return 0;
}
