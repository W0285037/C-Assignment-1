#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class Validator
{
public:
	bool inputMechanism(string *inputString)
	{
		cout << "inputMechanism method involked" << endl;
		char tempKey;
		const static int maxLineLength = 1;
		do
		{
			tempKey = _getch();
			if ((*inputString).length() < maxLineLength)
			{
				if (tempKey >= 49 && tempKey <= 57)
				{
					if (maxLineLength > (*inputString).length())//if valid print to screen
					{
						(*inputString += tempKey);
						printf("%c", tempKey);
					}
				}
				if (tempKey == 13)
				{
					continue;
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
		return true;
	}
};

class AI
{
public:
	int calculateMove() {

	}
};

int main()
{
	string input;
	Validator myVal;
	int c = 0;

	while (c < 10) {
		myVal.inputMechanism(&input);
		c++;
	}
	_getch();

	return 0;
}