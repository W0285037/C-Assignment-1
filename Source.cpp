#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Validator
{
public:
	bool inputMechanism(string *inputString, char c, int *chosen)
	{
		if (c == 'e')
			cout << "Invalid move, please try again" << endl;
		else
			cout << "Please make your move" << endl;
		char tempKey;
		*inputString = "";
		const static int maxLineLength = 1;
		do
		{
			tempKey = _getch();
			if ((*inputString).length() < maxLineLength)
			{
				if (49 <= tempKey <= 57)
				{
					if (maxLineLength > (*inputString).length())//if valid print to screen and add to string
					{
						(*inputString += tempKey);
						printf("%c", tempKey);
					}
				}
			}
			else if (tempKey == 8)//backspace pressed
			{
				if ((*inputString).length() > 0) {
					(*inputString).erase((*inputString).length() - 1, 1);
					printf("\b \b"); //pop char off string
				}
			}
			else if (tempKey == -32) //drop off arrow keys pressed
			{
				_getch();
			}
			else if (tempKey == 13)
			{
				break;
			}
		} while (true);
		printf("\n");
		try {
			stoi(*inputString);
			if (*inputString == "")
				throw invalid_argument("Invalid move.");
			
			for (int i = 1; i<10 ;i++) { //loop through chosen to see if number has been taken
				if (stoi(*inputString) == chosen[i])
				{
					throw invalid_argument("Invalid move.");
				}
			}
			chosen[chosen[0]++] = stoi(*inputString);
		}
		catch (invalid_argument) {
			inputMechanism(inputString, 'e', chosen);
		}
		return true;
	}
};

class AI
{
private:
	bool centerX = false;
	bool centerO = false;
	int move;

public:
	void calculateMove(string b[][3], int turnNumber, string pMove, int *chosen)
	{
		
		srand(time(NULL)); //set seed for rand()

		switch (turnNumber)
		{
			case 1:
				b[1][1] = "O"; //take center right away
				centerO = true;
				move = 5;
				break;
			case 2:
				if (centerO)
				{
					switch (stoi(pMove))
					{
						case 1:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 2:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							}
							break;
						case 3:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 4:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 6:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 7:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 8:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[0][2] = "O"; //top right corner
								move = 9;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
						case 9:
							switch (rand() % 8) //randomly generate placement
							{
							case 0:
								b[0][0] = "O"; //top left corner
								move = 7;
								break;
							case 1:
								b[2][0] = "O"; //bottom left corner
								move = 1;
								break;
							case 2:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 3:
								b[2][2] = "O"; //bottom right corner
								move = 3;
								break;
							case 4:
								b[0][1] = "O"; //middle top
								move = 8;
								break;
							case 5:
								b[1][0] = "O"; //middle left
								move = 4;
								break;
							case 6:
								b[1][2] = "O"; //middle right
								move = 6;
								break;
							case 7:
								b[2][1] = "O"; //middle bottom
								move = 2;
								break;
							}
							break;
					}
				}
				else if (b[1][1] != "X") //check center
				{
					b[1][1] = "O"; //center
					move = 5;
					centerO = true;
				}
				else if (b[1][1] == "X") //check center
				{
					centerX = true;
					switch (rand() % 4) //only use of ran because it doesn't really matter where you place your piece here
					{
						case 0:
							b[0][0] = "O"; //top left corner
							move = 7;
							break;
						case 1:
							b[0][2] = "O"; //top right corner
							move = 9;
							break;
						case 2:
							b[2][0] = "O"; //bottom left corner
							move = 1;
							break;
						case 3:
							b[2][2] = "O"; //bottom right corner
							move = 3;
							break;
					}//end nested switch
				}
				break;
			default:
				move = calcMoveRowCol(b, move);
				if (!move)
				{
					for (int i = 1; i < 10; i++) {
						int ran = (rand() % 9) + 1;
						for (int row = 0; row < 3; row++)
						{
							for (int col = 0; col < 3; col++)
							{
								if (b[i][i] != "X" && b[i][i] != "O")
									move = stoi(b[i][i]);
							}// end nested nested for
						}//end nested for
					}//end for
				}
			//no need to check center anymore; center taken guarunteed or your money back
			//we just to know who has the center
			//case 3:
			//	if (centerO)
			//	{

			//	}
			//	break;
			//case 4:
			//	break;
			//case 5:
			//	break;
			//case 6:
			//	break;
			//case 7:
			//	break;
			//case 8:
			//	break;
			//case 9:
			//	break;

		}//end switch

		chosen[chosen[0]++] = move;

	}//end calculateMove
	int calcMoveRowCol(string b[][3], int move) {
		bool didSomething = false;
		
		for (int i = 0; i < 3; i++) { //loop and check for winning moves in columns and rows
			if (b[i][0] == b[i][1]) {
				if (b[i][2] != "X" && b[i][2] != "O") {
					move = stoi(b[i][2]);
					b[i][2] = "O";
					didSomething = true;
				}
				break;
			}
			else if (b[i][1] == b[i][2]) {
				if (b[i][0] != "X" && b[i][0] != "O") {
					move = stoi(b[i][0]);
					b[i][0] = "O";
					didSomething = true;
				}
				break;
			}
			else if (b[i][0] == b[i][2]) {
				if (b[i][1] != "X" && b[i][1] != "O") {
					move = stoi(b[i][1]);
					b[i][1] = "O";
					didSomething = true;
				}
				break;
			} //end row check
			else if (b[0][i] == b[1][i]) {
				if (b[2][i] != "X" && b[2][i] != "O") {
					move = stoi(b[2][i]);
					b[2][i] = "O";
					didSomething = true;
				}
				break;
			}
			else if (b[1][i] == b[2][i]) {
				if (b[0][i] != "X" && b[0][i] != "O") {
					move = stoi(b[0][i]);
					b[0][i] = "O";
					didSomething = true;
				}
				break;
			}
			else if (b[0][i] == b[2][i]) {
				if (b[1][i] != "X" && b[1][i] != "O") {
					move = stoi(b[1][i]);
					b[1][i] = "O";
					didSomething = true;
				}
				break;
			}//end column check
		}
		if (!didSomething) {
			if (b[0][0] == b[1][1]) {
				if (b[2][2] != "X" && b[2][2] != "O"){
					b[2][2] = "O";
					move = 3;
				}
			}
			else if (b[1][1] == b[2][2]) {
				if (b[0][0] != "X" && b[0][0] != "O") {
					b[0][0] = "O";
					move = 7;
				}
			}
			else if (b[2][0] == b[1][1]) {
				if (b[0][2] != "X" && b[0][2] != "O") {
					b[0][2] = "O";
					move = 9;
				}
			}
			else if (b[0][2] == b[1][1]) {
				if (b[2][0] != "X" && b[2][0] != "O") {
					b[2][0] = "O";
					move = 1;
				}
			}
			return move;
		}
	}//end calculating moves for rows and columns
};//end AI class

class Board
{
public:
	void drawBoard(string b[][3])
	{
		int rowSize = sizeof(*b) / sizeof(*b[0]);
		int colSize = 3;
		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				cout << b[row][col] << " ";
			}
			cout << endl;
		}
	}
	void updateBoard(string b[][3], string choice, char move)
	{
		int rowSize = sizeof(*b) / sizeof(*b[0]);
		int colSize = 3;
		for (int row = 0; row < rowSize; row++)
		{
			for (int col = 0; col < colSize; col++)
			{
				if (b[row][col] == choice)
					b[row][col] = move;
			}
		}
	}
	string checkWin(string b[][3]) {
		for (int i = 0; i < 3; i++) { //loop and check for winning moves in columns and rows
			if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
				return b[i][0];
			else if (b[0][i] == b[1][i] && b[1][i] == b[2][i])
				return b[0][1];
			if (i == 0) {
				if (b[i][i] == b[i + 1][i + 1] && b[i + 1][i + 1] == b[i + 2][i + 2])
					return b[i][i];
			}else if (i == 2) {
				if (b[i][i] == b[i - 1][i - 1] && b[i - 1][i - 1] == b[i - 2][i - 2])
					return b[i][i];
			}
		}
		return "";
	}
};

int main()
{

	Validator myVal;
	AI myAI;
	Board board;

	string input = "";
	while (true) {

		string b[3][3] = { { "7","8","9" },{ "4","5","6" },{ "1","2","3" } };
		string playerMove = "";
		string winner = "";

		int chosen[10] = { 0,0,0,0,0,0,0,0,0,0 };

		int moves = 1;
		char replay = 'e';
		bool playerTurn = true;

		cout << "Welcome to TicTacToe!" << endl << "The human player will always be \"X\"'s and the AI will always be \"O\"'s" << endl;

		bool cond = true;
		while (cond) //ask player who goes first 1 = player, 2 = ai
		{
			cout << "Do you wish to go first or second?(1/2)" << endl;
			char response;
			cin >> response;
			switch (response)
			{
			case '1': //player
				playerTurn = true;
				cond = false;
				break;
			case '2': //ai
				playerTurn = false;
				cond = false;
				break;
			default: cout << "Invalid choice" << endl;
			}
		}

		do
		{
			if (playerTurn) {
				board.drawBoard(b);
				myVal.inputMechanism(&input, 'n', chosen);
				playerMove = input;
				board.updateBoard(b, playerMove, 'X');
				playerTurn = false;
			}
			else {
				myAI.calculateMove(b, moves, playerMove, chosen);
				playerTurn = true;
			}
			if (moves >= 5)
				winner = board.checkWin(b);
			if (winner == "X")
				cout << "You win! How did you manage this?" << endl;
			else if (winner == "O")
				cout << "You lose! HAHAHAHAHA!" << endl;
			moves++;

		} while (moves < 10); //end main loop

		if (winner != "O" && winner != "X")
			cout << "It's a tie! Just as it should be for any competent TicTacToe player." << endl;

		board.drawBoard(b);
		cout << "Play again (y/n)?" << endl;
		cin >> replay;
		if (replay == 'N')
			break;
	}
	return 0;
}