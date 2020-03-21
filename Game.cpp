#include<iostream>
#include<fstream>
#include"TicTacToe.h"

using namespace std;

void calBox(int, int, int&, int&);

int main()
{
	int save = 0, size = 0;
	int row = 0, col = 0;
	int box_no = 0;
	ifstream fin;
	cout << "				---------------------------------" << endl;
	cout << "				Select an option from menu below " << endl;
	cout << "				--------------" << endl;
	cout << "				1-> New   Game" << endl;
	cout << "				--------------" << endl;
	cout << "				2-> Saved Game" << endl;
	cout << "				--------------" << endl;
	cout << "				";
	cin >> save;
	if (save == 2)
	{
		fin.open("board.txt");
		do
		{
			fin >> size;
		} while (size < 2);
	}
	if (size == 0)
	{
		cout << "				--------------------------" << endl;
		cout << "				Enter the size of board : ";
		cin >> size;
	}
	TicTacToe board(size);
	if (save == 2)
	{
		board.boardRead();
	}
	board.setSaveState(save);
	while (board.check_onPlayer1() != true && board.check_onPlayer2() != true && board.boardFill() == false)
	{

		if (board.getPlayer1() == 1)
		{
			do
			{
				if (board.getMoveValidation() != 0)
				{
					system("CLS");
					board.printBoard();
				}
				cout << endl;
				cout << endl;
				cout << endl;

				cout << "					****************" << endl;
				cout << "					*Player1's Turn*" << endl;
				cout << "					****************" << endl;

				do
				{
					cout << "		Enter Box NUmber : ";
					cin >> box_no;
					if (box_no <= (size * size))
					{

						calBox(box_no, size, row, col);
					}
					else
					{
						cout << "		Invalid Box NUmber" << endl;
					}

				} while (box_no > (size * size) || box_no <= 0);

				row = row + 1;

				cout << row << endl;
				cout << col << endl;
				board.setValue(row, col);

				if (board.getMoveValidation() == 0)
				{
					cout << "			*****Invalid move***** " << endl;
				}
			} while (board.getMoveValidation() == 0);
			system("CLS");
			board.printBoard();
			row = 0;
			col = 0;
			board.setPlayer1(0);
			board.setPlayer2(1);

		}
		else if (board.getPlayer2() == 1)
		{
			do
			{

				if (board.getMoveValidation() != 0)
				{
					system("CLS");
					board.printBoard();
				}
				cout << endl;
				cout << endl;
				cout << endl;

				cout << "					****************" << endl;
				cout << "					*Player2's Turn*" << endl;
				cout << "					****************" << endl;

				do
				{
					cout << "		Enter Box NUmber : ";
					cin >> box_no;
					if (box_no <= (size * size))
					{

						calBox(box_no, size, row, col);

					}
					else
					{
						cout << "		Invalid Box NUmber" << endl;
					}

				} while (box_no > (size * size) || box_no <= 0);

				row = row + 1;

				board.setValue(row, col);

				if (board.getMoveValidation() == 0)
				{
					cout << "			*****Invalid move***** " << endl;
				}
			} while (board.getMoveValidation() == 0);
			system("CLS");
			board.printBoard();
			board.setPlayer1(1);
			board.setPlayer2(0);
		}

	}
	if (board.check_onPlayer1() == true)
	{
		system("CLS");
		board.printBoard();
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "				***********************" << endl;
		cout << "				*Player 1 WON The Game*" << endl;
		cout << "				***********************" << endl;
	}
	else if (board.check_onPlayer2() == true)
	{
		system("CLS");
		board.printBoard();
		cout << endl;
		cout << endl;
		cout << endl;

		cout << "				***********************" << endl;
		cout << "				*Player 2 WON The Game*" << endl;
		cout << "				***********************" << endl;

	}
	else
	{
		cout << "					*************" << endl;
		cout << "					*Game is Tie* " << endl;
		cout << "					*************" << endl;

	}
	system("pause");
	return 0;
}

void calBox(int box_no, int size, int& row, int& col)
{
	if (box_no % size == 0)
	{
		row = (box_no / size) - 1;
	}
	else
	{
		row = (box_no / size);
	}

	col = box_no - (row * size);

}