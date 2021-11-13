#include "../src/mazes.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<vector<bool>> input_matrix;

TEST(GoogleTestCi, mazes_positive_one_line) {
  input_matrix = {{1, 0, 0, 0, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 1, 0, 0},
                  {0, 0, 1, 1, 0},
                  {0, 0, 0, 1, 1}};

  ASSERT_TRUE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_positive_multiple_line) {
  input_matrix = {{1, 0, 0, 0, 0},
                  {1, 1, 1, 1, 1},
                  {0, 1, 0, 0, 1},
                  {0, 1, 0, 0, 1},
                  {0, 1, 1, 1, 1}};

  ASSERT_TRUE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_positive_zig_zag) {
  input_matrix = {{1, 0, 0, 0, 1},
                  {1, 0, 0, 1, 1},
                  {1, 0, 1, 1, 1},
                  {1, 1, 1, 0, 1},
                  {1, 0, 0, 0, 1}};

  ASSERT_TRUE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_negative_no_way) {
  input_matrix = {{1, 0, 0, 0, 0},
                  {0, 0, 0, 1, 1},
                  {0, 0, 0, 0, 1},
                  {0, 1, 0, 0, 1},
                  {0, 1, 1, 1, 1}};

  ASSERT_FALSE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_negative_diagonal_path) {
  input_matrix = {{1, 0, 0, 0, 0},
                  {0, 1, 0, 0, 0},
                  {0, 0, 1, 0, 0},
                  {0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 1}};

  ASSERT_FALSE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_negative_small_shape) {
  input_matrix = {{1, 0}, {0, 1}};

  ASSERT_FALSE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_positive_small_shape) {
  input_matrix = {{1, 1}, {0, 1}};

  ASSERT_TRUE(check_path(input_matrix));
}

TEST(GoogleTestCi, mazes_negative_big_shape) {
  vector<vector<bool>> test_vector(50, std::vector<bool>(50, 0));

  ASSERT_FALSE(check_path(test_vector));
}

TEST(GoogleTestCi, mazes_positive_big_shape) {
  vector<vector<bool>> test_vector(50, std::vector<bool>(50, true));

  ASSERT_TRUE(check_path(test_vector));
}

TEST(GoogleTestCi, mazes_size_negative_too_big) {
  vector<vector<bool>> test_vector(51, std::vector<bool>(51, 0));

  EXPECT_THROW(
      {
        try {
          check_path(test_vector);
        } catch (const runtime_error& e) {
          EXPECT_STREQ("Wrong format: maximum allowd matrix size 50x50",
                       e.what());
          throw;
        }
      },
      runtime_error);
}

TEST(GoogleTestCi, mazes_size_negative_too_small) {
  vector<vector<bool>> test_vector(1, std::vector<bool>(1, 0));

  EXPECT_THROW(
      {
        try {
          check_path(test_vector);
        } catch (const runtime_error& e) {
          EXPECT_STREQ("Wrong format: minimum allowd matrix size 2x2",
                       e.what());
          throw;
        }
      },
      runtime_error);
}

TEST(GoogleTestCi, mazes_size_negative_not_square) {
  vector<vector<bool>> test_vector(4, std::vector<bool>(5, 0));

  EXPECT_THROW(
      {
        try {
          check_path(test_vector);
        } catch (const runtime_error& e) {
          EXPECT_STREQ("Wrong format: matrix must be square", e.what());
          throw;
        }
      },
      runtime_error);
}
