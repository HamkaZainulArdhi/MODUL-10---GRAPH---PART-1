#include <iostream>
using namespace std;

int main() {
  
  int matrix[7][7] = {{99, 5, 99, 99, 99, 15, 99}, 
                      {6, 99, 99, 5, 99, 99, 99},
                      {7, 8, 99, 5, 99, 99, 99},
                      {99, 99, 23, 99, 99, 99, 8},
                      {5, 99, 99, 99, 99, 4, 99},
                      {99, 99, 99, 7, 99, 99, 3},
                      {99, 99, 99, 9, 99, 4, 99}};

  
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
