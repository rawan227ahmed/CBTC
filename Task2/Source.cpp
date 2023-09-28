#include"iostream"
using namespace std;
void displayBoard(char* board) {
	system("cls");
	cout << "\t\t\t-------------------TIC TAC TOE-------------------\n\n";
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
	cout << "---|---|---\n";
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
	cout << "---|---|---\n";
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool isFinished(char* board) {
	bool finish = true;
	for (int i = 0; i < 9; i++) {
		if ((board[i] != 'X') && (board[i] != 'O'))
			finish = false;
	}
	return finish;
}
bool isValid(char* board, int position) {
	if ((board[position] != 'X') && (board[position] != 'O'))
		return true;
	else
		return false;
}
bool win(char* board) {
	bool win = false;
	int winPositions[8][3] = {                    
		{0,1,2},                            //first row 
		{3,4,5},                            //second row
		{6,7,8},                            //third row
		{0,3,6},                            //first column
		{1,4,7},                            //second column
		{2,5,8},                            //third column
		{0,4,8},                            //diagonals
		{2,4,6} 
	};              
	for (int i = 0; i < 8; i++) {
		char a = board[winPositions[i][0]];
		char b = board[winPositions[i][1]];
		char c = board[winPositions[i][2]];
		if (a == b && b == c)               //winning condition
			win = true;
	}
	return win;
}
int main() {
	bool playAgain = true;
	while (playAgain) {
		char board[9] = { '0','1','2','3','4','5','6','7','8' };
		char player = 'X';
		int position;
		bool isFinish = isFinished(board);
		bool won = win(board);
		displayBoard(board);
		while (!isFinish && !won)
		{
			cout << "\n Player" << player << "'s turn\n";
			cout << " Pick a number: ";
			cin >> position;
			while (position < 0 || position>8) {
				cout << "this position does not exist!\nPlease,Enter a right number: ";
				cin >> position;
			}
			while (!isValid(board, position)) {
				cout << "This Position is not valid\nPick another one: ";
				cin >> position;
			}
			board[position] = player;
			displayBoard(board);
			isFinish = isFinished(board);
			won = win(board);
			if (won) {
				cout << "  Player " << player << " won!\n";
				break;
			}
			else if (isFinish && !won) {
				cout << "  Tie!\n";
			}
			else {
				if (player == 'X')
					player = 'O';
				else
					player = 'X';
			}
		}
		char y;
		cout << "Play Again?(y/n)";
		cin >> y;
		playAgain = (y == 'y') ? true : false;
	}
	return 0;
}