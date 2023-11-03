// use https://www.sudoku-solutions.com/ to generate a board
// this website also supports using particular techniques to solve for a board
// from preferences, choose Naked-Singles only or partial solving
// then click "Solve Partially", you may then cross-check with your progran output

#include <iostream>

using namespace std;

// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate

// get user input and store the game board in the 2D array b
void ReadBoard( int b[][9] )
{
    int number, i, j;

    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            cin >> number;
            b[i][j] = number;
        }
    }
}

// display the game board stored in the 2D array b
void PrintBoard( int b[][9] )
{
    int idx = 0, i, j;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            idx++;
            //print int if number is non-zero, print x if number is zero.
            if (b[i][j] != 0){
                cout << b[i][j];
            }
            else if (b[i][j] == 0){
                cout << 'x';
            }

            //print the structure of board
            if (idx == 81){
                cout << " " << endl;
            }
            else if (idx % 27 == 0){
                cout << " " << endl << "------+-------+-------" << endl;
            }
            else if (idx % 9 == 0){
                cout << " " << endl;
            }
            else if (idx % 3 == 0){
                cout << " | ";
            }
            else {
                cout << " ";
            }
        }
    }
}

//check if there are any int n's in the row for array b
int checkRow(int row, int n, int b[][9]){
    for (int i = 0; i < 9; i++){
        if (b[row][i] == n){
            return 1;
        }
    }
    return 0;
}

//check if there are any int n's in the column for array b
int checkColumn(int column, int n, int b[][9]){
    for (int i = 0; i < 9; i++){
        if (b[i][column] == n){
            return 1;
        }
    }
    return 0;
}

//check if there are any int n's in the square for array b
int checkSquare(int row, int column, int n, int b[][9]){
    row = row - (row % 3);
    column = column - (column % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(b[i + row][j + column] == n){
                return 1;
            }
        }
    }
    return 0;
}

// solve a game board stored in b using the Naked Single technique only
// the (partial) solution is stored in the input array b
void SolveBoard( int b[][9] )
{
    int row, column, n, idx;

    //find a 0, which is an empty cell
    for (row = 0; row < 9; row++){
        for (column = 0; column < 9; column++){
            if (b[row][column] == 0){
                idx = 0;
                for (n = 1; n <= 9; n++){   //these are numbers from 1 to 9 that can be inserted to the empty cell
                    //check the row, column, and the square and see if there are any numbers that are not in any of the row, column, or square.
                    if (checkRow(row, n, b) + checkColumn(column, n, b) + checkSquare(row, column, n, b) == 0){
                        idx++;
                        if (idx == 1){
                            b[row][column] = n;
                        }
                        else if (idx > 1){
                            b[row][column] = 0;
                        }
                    }
                }
                //insert the number to the empty cell when only 1 number can be inserted to that cell.
                if (idx == 1){
                    SolveBoard(b);
                }
            }
        }
    }

}

// You do not need to change anything in the main() function
int main()
{
  int board[9][9];    // the 9x9 game board

  ReadBoard( board );

  cout << "Input Sudoku board:" << endl;
  PrintBoard( board );

  // solve the board using the naked single technique only
  SolveBoard( board );

  cout << endl;
  cout << "Final Sudoku board:" << endl;
  PrintBoard( board );

  return 0;
}

