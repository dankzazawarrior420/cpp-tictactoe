#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>

char gameBoard[3][3] =
{	{ '_', '_', '_' },
	{ '_', '_', '_'},
	{ '_', '_', '_'} 
};

bool winnerwinnerChickenDinner = 0; 

bool checkWin(int row, int col, char board[3][3], char player);
bool checkDraw(char board[3][3]);

void static drawBoard() {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			std::cout << gameBoard[i][j] << '\t';

		}

		std::cout << std::endl;
	}

}

void playerInput(int& row, int& col, char player)
{

	std::cout << "Please Enter Row and Col [0-2] \n";
	std::cin >> row >> col;

	if (row >= 0 && row < 3 && col >= 0 && col < 3 && gameBoard[row][col] == '_')
	{
		gameBoard[row][col] = player;
	}
	else
	{
		std::cout << "Invalid Input #ERROR \n"; 

		playerInput(row, col, player); 
	}

	
}

void updateBoard()
{

	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{

			std::cout << gameBoard[i][j] << '\t';

			

		}

		std::cout << std::endl;
	}


}


void winner(char player) {


	std::cout << "Congrats! Player " << player << " You Won. \n";
	
}




int main() {

	int row;
	int col;
	char player = 'X';

	bool gameisOpen = true;


	while (gameisOpen)

	{


		drawBoard();
		playerInput(row, col, player);


		if (checkWin(row, col, gameBoard, player))
		{
			winner(player);
			
			char user{};

			

		}
		else if (checkDraw(gameBoard))
		{
			drawBoard();
			gameisOpen = false;

		}
		else
		{
			player = (player == 'X') ? 'O' : 'X';

		}


	}









	return 0;
}


bool checkWin(int row, int col, char board[3][3], char player)
{


	// checks rows, columns
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
		{
			winnerwinnerChickenDinner = 1;
			return true;
		}
		else if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
		{
			winnerwinnerChickenDinner = 1;
			return true;
		}
	}


	// check diagonals 

	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		winnerwinnerChickenDinner = 1;
		return true;
	}
	else if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	{
		winnerwinnerChickenDinner = 1;
		return true;
	}


	return false;
}

bool checkDraw(char board[3][3])
{
	bool isFull = true;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			if (board[i][j] == '_')
			{

				isFull = false;
				break;

			}



		}

		if (!isFull)
			break; 
	}


	if (isFull)
	{

		std::cout << "Game is Draw! \n";
		return true; 
	}


	return false; 
}