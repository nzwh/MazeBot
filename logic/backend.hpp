bool is_valid(int n, int row, int col) {
  return row >= 0 && row < n && col >= 0 && col < n;
}

bool is_unblocked(vector2d board, int row, int col) {
  if (board[row][col] == 1)
    return true;
  return false;
}

bool is_end(point end, int row, int col) {
  if (end.first == row && end.second == col)
    return true;
  return false;
}

double get_h(point end, int row, int col) {
  return abs(row - end.first) + abs(col - end.second);
}

void a_star(vector2d board, point start, point end) {

}