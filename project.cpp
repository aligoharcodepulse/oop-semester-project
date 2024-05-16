#include <iostream>
using namespace std;

class Box {
private:
	char symbol;
	bool filled;

public:
	Box() : symbol(' '), filled(false) {}

	void setSymbol(char sym) {
		if (!filled) {
			symbol = sym;
			filled = true;
		}
		else {
			cout << "Box already filled. Choose another box." << endl;
		}
	}

	char getSymbol() const {
		return symbol;
	}

	bool isFilled() const {
		return filled;
	}
};

class TicTacToe {
private:
	Box board[3][3]; // 3x3 board
	int currentPlayer; // 1 for player 1, 2 for player 2

public:
	TicTacToe() : currentPlayer(1) {
		// Initialize the board
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				board[i][j] = Box();
			}
		}
	}

void printBoard() const {
    cout << "\t Tic-Tac-Toe" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j].getSymbol();
            if (j < 2) cout << "\t|";
       }
        cout << endl;
        if (i < 2) cout << "________|_______|________" << endl ; 
        else cout << "        |       |     " << endl;
    }
}

	void switchPlayer() {
		currentPlayer = (currentPlayer == 1) ? 2 : 1;
	}

	bool makeMove(int row, int col, char symbol) {
		if (row >= 0 && row < 3 && col >= 0 && col < 3) {
			if (!board[row][col].isFilled()) {
				board[row][col].setSymbol(symbol);
				return true; // Move successful
			}
			else {
				cout << "Box already filled. Choose another box." << endl;
			}
		}
		else {
			cout << "Invalid box coordinates." << endl;
		}
		return false; // Move unsuccessful
	}

	bool checkWinner(char symbol) const {
		// Check rows, columns, and diagonals for the given symbol
		for (int i = 0; i < 3; i++) {
			if (board[i][0].getSymbol() == symbol && board[i][1].getSymbol() == symbol && board[i][2].getSymbol() == symbol)
				return true; // Row check
			if (board[0][i].getSymbol() == symbol && board[1][i].getSymbol() == symbol && board[2][i].getSymbol() == symbol)
				return true; // Column check
		}
			if (board[0][0].getSymbol() == symbol && board[1][1].getSymbol() == symbol && board[2][2].getSymbol() == symbol)
				return true; // Diagonal check
			if (board[0][2].getSymbol() == symbol && board[1][1].getSymbol() == symbol && board[2][0].getSymbol() == symbol)
				return true; // Diagonal check
		
				return false;
	}

	void playGame() {
		int row, col;
		char symbol;
		bool gameOver = false;
		int movesMade = 0; // Track the number of moves made

		while (!gameOver) {
			printBoard();
			symbol = (currentPlayer == 1) ? 'X' : 'O';
			cout << "Player " << currentPlayer << "(" << symbol << "), enter row and column (0-2): ";
			cin >> row >> col;

			if (makeMove(row, col, symbol)) {
				movesMade++; // Increment moves made
				if (checkWinner(symbol)) {
					printBoard();
					cout << "Player " << currentPlayer << " wins!" << endl;
					gameOver = true;
				}
				else if (movesMade == 9) { // All boxes filled, no winner
					printBoard();
					cout << "Game is draw!" << endl;
					gameOver = true;
				}
				else {
					switchPlayer();
				}
			}
		}
	}
};

int main() {
	TicTacToe game;
	game.playGame();
	return 0;
}