bool is_valid(int dim, int row, int col) {
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

void trace_path(vector<cell> cells, point end) {
    stack<point> path;

    int row = end.first;
    int col = end.second;

    while (!(cells[row][col].parent.first == row && 
           && ells[row][col].parent.second == col)) {
        path.push(make_pair(row, col));
        int temp_row = cells[row][col].parent.first;
		int temp_col = cells[row][col].parent.second;
		row = temp_row;
		col = temp_col;        
    }

    path.push(make_pair(row, col));

    while (!path.empty()) {
        point trail = path.top();
        path.pop();
        printf("-> (%d,%d) ", trail.first, trail.second);
    }
}

void a_star(vector2d board, point start, point end) {
    int dim = board.size()
    vector<bool> explored;
    explored.resize(dim);
    fill(explored.begin(), explored.end(), false);

    vector<state> cells;
    cells.resize(dim);

    int i, j; 

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            cells[i][j].parent.first = -1;
            cells[i][j].parent.second = -1;
            cells[i][j].f = FLT_MAX;
            cells[i][j].g = FLT_MAX;
            cells[i][j].h = FLT_MAX;
        }
    }

    i = start.first;
    j = start.second;
    cells[i][j].parent.first = i;
    cells[i][j].parent.second = j;
    cells[i][j].f = 0.0;
    cells[i][j].g = 0.0;
    cells[i][j].h = 0.0;

    std::priority_queue<cell, vector<cell>, greater<cell>> frontier;
    
    frontier.emplace(0.0, i, j);

    while (!frontier.empty()) {
        cell exploring = frontier.top();
        i = get<1>(exploring);
        j = get<2>(exploring);

        frontier.pop();
        explored[i][j] = true;

        double f_succ, g_succ, h_succ;

        // Up
        if (is_valid(dim, i - 1, j)) {
            if (is_end(end, i - 1, j)) {
                cells[i - 1][j].parent.first = i;
                cells[i - 1][j].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            else if (explored[i - 1][j] == false
                    && is_unblocked(board, i - 1, j) == true) {
                g_succ = cells[i - 1][j].g + 1.0;
                h_succ = get_h(end, i - 1, j);
                f_succ = g_succ + h_succ;

                if (cells[i - 1][j] == FLT.MAX
                    || cells[i - 1][j] > f_succ) {
                    frontier.emplace(f_succ, i - 1, j);

                    cells[i - 1][j].parent.first = i;
                    cells[i - 1][j].parent.second = j;
                    cells[i - 1][j].f = f_succ;
                    cells[i - 1][j].g = g_succ;
                    cells[i - 1][j].h = h_succ;
                }
            }
        }

        // Down
        if (is_valid(dim, i + 1, j)) {
            if (is_end(end, i + 1, j)) {
                cells[i + 1][j].parent.first = i;
                cells[i + 1][j].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            else if (explored[i + 1][j] == false
                    && is_unblocked(board, i + 1, j) == true) {
                g_succ = cells[i + 1][j].g + 1.0;
                h_succ = get_h(end, i + 1, j);
                f_succ = g_succ + h_succ;

                if (cells[i + 1][j] == FLT.MAX
                    || cells[i + 1][j] > f_succ) {
                    frontier.emplace(f_succ, i + 1, j);

                    cells[i + 1][j].parent.first = i;
                    cells[i + 1][j].parent.second = j;
                    cells[i + 1][j].f = f_succ;
                    cells[i + 1][j].g = g_succ;
                    cells[i + 1][j].h = h_succ;
                }
            }
        }

        // Right
        if (is_valid(dim, i, j + 1)) {
            if (is_end(end, i, j + 1)) {
                cells[i][j + 1].parent.first = i;
                cells[i][j + 1].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            else if (explored[i][j + 1] == false
                    && is_unblocked(board, i, j + 1) == true) {
                g_succ = cells[i][j + 1].g + 1.0;
                h_succ = get_h(end, i, j + 1);
                f_succ = g_succ + h_succ;

                if (cells[i][j + 1] == FLT.MAX
                    || cells[i][j + 1] > f_succ) {
                    frontier.emplace(f_succ, i, j + 1);

                    cells[i][j + 1].parent.first = i;
                    cells[i][j + 1].parent.second = j;
                    cells[i][j + 1].f = f_succ;
                    cells[i][j + 1].g = g_succ;
                    cells[i][j + 1].h = h_succ;
                }
            }
        }

        // Left
        if (is_valid(dim, i, j - 1)) {
            if (is_end(end, i, j - 1)) {
                cells[i][j - 1].parent.first = i;
                cells[i][j - 1].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            else if (explored[i][j - 1] == false
                    && is_unblocked(board, i, j - 1) == true) {
                g_succ = cells[i][j + 1].g + 1.0;
                h_succ = get_h(end, i, j - 1);
                f_succ = g_succ + h_succ;

                if (cells[i][j - 1] == FLT.MAX
                    || cells[i][j - 1] > f_succ) {
                    frontier.emplace(f_succ, i, j - 1);

                    cells[i][j - 1].parent.first = i;
                    cells[i][j - 1].parent.second = j;
                    cells[i][j - 1].f = f_succ;
                    cells[i][j - 1].g = g_succ;
                    cells[i][j - 1].h = h_succ;
                }
            }
        }
    }
}