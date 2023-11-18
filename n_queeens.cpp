#include<iostream>
#include<vector>
using namespace std;

vector<int> board;
vector<int> col;
vector<int> ld;
vector<int> rd;
int N;            // board size

bool placeQueen(int i) {
    for(int j = 1; j <= N; j++) {
        if (col[j - 1] == 0 && 
        ld[i + N - j] == 0 && 
        rd[i + j - 1] == 0) {
          board[i - 1] = j;
          col[j - 1] = 1;
          ld[i + N - j] = 1;
          rd[i + j - 1] = 1;

          if (i == N) {
            return true;
          } else if (placeQueen(i + 1) == true) {
            return true;
          }

          board[i - 1] = 0;
          col[j - 1] = 0;
          ld[i + N - j] = 0;
          rd[i + j - 1] = 0;
        }
    }

  return false;
}

void assign(vector<int>& arr, int size) {     //hardcoding the position with 0 intialisation
  for(int i = 0; i < size; i++) {
    arr.push_back(0);
  }
}

void display(vector<int> arr){                // for displaying array
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i]<<" ";
  }
}

int main() {
  cout<<"Enter size of board: ";
  cin>>N;
  
  assign(board, N);
  assign(col, N);
  assign(ld, 2 * N - 1);
  assign(rd, 2 * N - 1);

  placeQueen(1);
  cout<<"Queens are placed in following columns: ";
  display(board);
  
  return 0;
}