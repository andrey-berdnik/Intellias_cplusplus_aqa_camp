#include "mazes.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  vector<vector<bool>> input_matrix;

  input_matrix = {{1, 0, 1, 1, 1},
                  {1, 1, 1, 0, 1},
                  {0, 0, 1, 0, 1},
                  {0, 0, 0, 0, 0},
                  {0, 0, 1, 0, 1}};

  std::cout << check_path(input_matrix);
}