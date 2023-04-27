#include <iostream>  
using namespace std;  
#define N 9
void print(int arr[N][N])
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
  
bool isSafe(int board[N][N], int row, 
                       int col, int num)
{
    
    for (int x = 0; x <= 8; x++){
        if (board[row][x] == num){
            return false;
        if (board[x][col] == num){
            return false;
        }
    }
}   
    
    int startRow = row - row % 3, 
            startCol = col - col % 3;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + 
                            startCol] == num)
                return false;
  
    return true;
}
  

bool SudokuSolver(int board[N][N], int row, int col)
{
    
    if (row == N - 1 && col == N){
        return true;
    }
  
    
    if (col == N) {
        row++;
        col = 0;
    }
    
    
    if (board[row][col] > 0){
        return SudokuSolver(board, row, col + 1);
    }
  
    for (int num = 1; num <= N; num++) 
    {
          
        
        if (isSafe(board, row, col, num)) 
        {
              
           
            board[row][col] = num;
            

            if (SudokuSolver(board, row, col + 1))
                return true;
        }
        
        // Removing the assigned num , 
        // since our assumption
        // was wrong , and we go for 
        // next assumption with
        // diff num value
        board[row][col] = 0;
    }
    return false;
}
  
// Driver Code
int main()
{
    // 0 means unassigned cells
    int board[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
  
    if (SudokuSolver(board, 0, 0))
        print(board);
    else
        cout << "no solution  exists " << endl;
  
    return 0;
    // This is code is contributed by Pradeep Mondal P
}
