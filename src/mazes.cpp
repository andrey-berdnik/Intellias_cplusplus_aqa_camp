#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define our_path_id 1  // 1 - because we need check only one union

bool check_path(const vector<vector<bool>>& input) {
  int size_i = input.size();
  int size_k = input[0].size();

  vector<vector<int>> path_map(size_i, std::vector<int>(size_k, 0));

  queue<vector<int>> queue_to_check;

  set<vector<int>> visited;

  // check input format
  if (size_i != size_k) {
    throw std::runtime_error("Wrong format: matrix must be square");
  }

  if (size_i < 2 or size_k < 2) {
    throw std::runtime_error("Wrong format: minimum allowd matrix size 2x2");
  }

  if (size_i > 50 or size_k > 50) {
    throw std::runtime_error("Wrong format: maximum allowd matrix size 50x50");
  }

  // check presents input and output
  if (input[0][0] == 0 or input[size_i - 1][size_k - 1] == 0)  
  {
    return false;
  } else {
    path_map[0][0] = 1;
    queue_to_check.push({0, 0});
  }

  // Begin flow for determinate connecctions
  while (!queue_to_check.empty()) {
    vector<int> active_point;
    active_point = queue_to_check.front();
    queue_to_check.pop();
    if (visited.count(active_point) == 0) {
      if (input[active_point[0]][active_point[1]] == true) {
        path_map[active_point[0]][active_point[1]] = our_path_id;

        for (int i = -1; i <= 1; i++)  // looking around current point
        {
          for (int k = -1; k <= 1; k++) {
            if (i == 0 or k == 0)  // disable diagonal path
            {
              int i1 = active_point[0] + i;
              int k1 = active_point[1] + k;
              if (i1 >= 0 and i1 < size_i and k1 >= 0 and
                  k1 < size_k)  // check out of range
              {
                if (input[i1][k1] == true) {
                  queue_to_check.push({i1, k1});
                }
              }
            }
          }
        }
      }
    }
    visited.insert(active_point);
  }

  if (path_map[size_i - 1][size_k - 1] ==
      our_path_id)  // if output in path tree, than we have a way. Woohoo!
  {
    return true;
  }

  return false;
}
