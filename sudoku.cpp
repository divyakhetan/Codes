#include <bits/stdc++.h>
using namespace std;


bool findUnfilledSpot(int a[9][9], int &row, int &col){
  for(row = 0; row < 9; row++){
    for(col = 0; col < 9; col++)
    if(a[row][col] == 0) return true;
  }
  return false;
}

bool UsedInRow(int a[9][9], int row, int num) 
{ 
    for (int col = 0; col < 9; col++) 
        if (a[row][col] == num) 
            return true; 
    return false; 
} 
  
bool UsedInCol(int a[9][9], int col, int num) 
{ 
    for (int row = 0; row < 9; row++) 
        if (a[row][col] == num) 
            return true; 
    return false; 
} 

bool UsedInBox(int a[9][9], int boxStartRow, int boxStartCol, int num) 
{ 
    for (int row = 0; row < 3; row++) 
        for (int col = 0; col < 3; col++) 
            if (a[row+boxStartRow][col+boxStartCol] == num) 
                return true; 
    return false; 
} 

//check if num not already in row, col, box(3*3)
bool isSafe(int a[9][9], int row, int col, int num) 
{ 
    return !UsedInRow(a, row, num) && 
           !UsedInCol(a, col, num) && 
           !UsedInBox(a, row - row%3 , col - col%3, num)&& 
            a[row][col]==0; 
} 
  
  



bool SolveSudoku(int a[9][9]) 
{ 
    int row, col; 
  
    // If there is no unassigned location, we are done 
    if (!findUnfilledSpot(a, row, col)) 
       return true; // success! 
  
    // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) 
    { 
        // if looks promising 
        if (isSafe(a, row, col, num)) 
        { 
            // make tentative assignment 
            a[row][col] = num; 
  
            // return, if success, yay! 
            if (SolveSudoku(a)) 
                return true; 
  
            // failure, unmake & try again 
            a[row][col] = 0; 
        } 
    } 
    return false; // this triggers backtracking 
} 

void printGrid(int a[9][9]){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  
  cout << "Enter partially filled suduko";
  cout << "Enter 0 for unfilled squaure";
  int a[9][9];
  for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cin >> a[i][j]; 
      }
  }
  // int a[9][9] =       {{3, 0, 6, 5, 0, 8, 4, 0, 0}, 
  //                     {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
  //                     {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
  //                     {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
  //                     {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
  //                     {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
  //                     {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
  //                     {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
  //                     {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 
  
  if(SolveSudoku(a)) {
    cout << "Solution Exists" << endl;
    printGrid(a);
  }
  else cout << "No solution Exits";
}
