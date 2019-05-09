// Ian Catapano
// Tick Tack Toe Game

#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 5;

void displayBoard(const char b[][SIZE]);  // This function displays the current state of the game board.
bool hasWon(char player, const char b[][SIZE]);   // Check to see if either player had won or if the game was a draw.

int main()
{
	char board[SIZE][SIZE] = {{}};
	for(int r = 0; r < SIZE; r++)
		for(int c = 0; c < SIZE; c++)
			board[r][c] = '*';

	char player = 'X';
	bool playerXWin = false;
	bool playerOWin = false;
	bool tieGame = false;


	while (playerXWin == false && playerOWin == false && tieGame == false)
	{
		displayBoard(board);
		int xCoord = NULL;
		int yCoord = NULL;

		if(player == 'X')
		{
			bool checks = false;
			cout << "Player X enter the row then column you want to mark." << endl;
			cin >> xCoord >> yCoord;
			cout << endl;
			if((0 <= xCoord && xCoord <= 4) && (0 <= yCoord && yCoord <= 4) && board[xCoord][yCoord] == '*')
				checks = true;

			while(checks == false)
			{
				cout << "Player X your entry was not valid, please enter a row and column that is not marked." << endl;
				cin >> xCoord >> yCoord;
				cout << endl;
				if((0 <= xCoord && xCoord <= 4) && (0 <= yCoord && yCoord <= 4) && board[xCoord][yCoord] == '*')
					checks = true;
			}
			board[xCoord][yCoord] = 'X';
			player = 'O';
		}
		else
		{
			bool checks = false;
			cout << "Player O enter the row then column you want to mark." << endl;
			cin >> xCoord >> yCoord;
			cout << endl;
			if((0 <= xCoord && xCoord <= 4) && (0 <= yCoord && yCoord <= 4) && board[xCoord][yCoord] == '*')
					checks = true;

			while(checks == false)
			{
				cout << "Player O your entry was not valid, please enter a row and column that is not marked." << endl;
				cin >> xCoord >> yCoord;
				cout << endl;
				if((0 <= xCoord && xCoord <= 4) && (0 <= yCoord && yCoord <= 4) && board[xCoord][yCoord] == '*')
					checks = true;
			}
			board[xCoord][yCoord] = 'O';
			player = 'X';
		}
		playerXWin = hasWon(player, board);
		playerOWin = hasWon(player, board);
		tieGame = hasWon(player, board);
	}
	if(playerXWin == true)
		cout << "Player X has WON!" << endl;
	else if(playerOWin == true)
		cout << "Player O has WON!" << endl;
	else
		cout << "The game is a draw!" << endl;

system("PAUSE");
}

void displayBoard(const char b[][SIZE])  // This function displays the current state of the game board.
{
	cout << "  " << setw(2) << "|" << setw(2) << "0" << setw(2) << "1" << setw(2) << "2" << setw(2) << "3" << setw(2) << "4" << endl;
	cout << setw(2) << "-" << setw(2) << "|" << setw(2) << "-" << setw(2) << "-" << setw(2) << "-" << setw(2) << "-" << setw(2) << "-" << endl;
	for(int r = 0; r < SIZE; r++)
	{
		cout << setw(2) << r << setw(2) << "|";
		for(int c = 0; c < SIZE; c++)
		{
			cout << setw(2) << b[r][c];
		}
		cout << endl;
	}
	cout << endl;
	return;
}

bool hasWon(char player, const char b[][SIZE]) // Check to see if either player had won or if the game was a draw.
{
	int tieCheck = 0;

	for(int i = 0; i < SIZE; i++)
	{
		if(b[i][0] == player && b[i][1] == player && b[i][2] == player && b[i][3] == player && b[i][4] == player)
			return true;
	}

	for(int j = 0; j < SIZE; j++)
	{
		if(b[0][j] == player && b[1][j] == player && b[2][j] == player && b[3][j] == player && b[4][j] == player)
			return true;
	}

	if(b[0][0] == player && b[1][1] == player && b[2][2] == player && b[3][3] == player && b[4][4] == player)
		return true;
	
	if(b[4][0] == player && b[3][1] == player && b[2][2] == player && b[1][3] == player && b[0][4] == player)
		return true;	
		
	for(int r = 0; r < SIZE; r++)
	{
		for(int c = 0; c < SIZE; c++)
			if (b[r][c] == '*')
				tieCheck++;
	}
	if(tieCheck > 0)
		return false;
	else
		return true;
}
