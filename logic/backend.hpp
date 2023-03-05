// This function checks if a given position is within the boundaries of a board of size dim
bool is_valid(int dim, int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

// This function checks a given position on the board is unblocked/not a wall
bool is_unblocked(vector2d board, int row, int col) {
    if (board[row][col] == 1)
        return true;
    return false;
}

// This function checks a given position is the end goal
bool is_end(point end, int row, int col) {
    if (end.first == row && end.second == col)
        return true;
    return false;
}

// This function returns the heuristic by solving the Manhattan distance between the given point and the end point
double get_h(point end, int row, int col) {
    return abs(row - end.first) + abs(col - end.second);
}

// This function prints out the path found by the A* algorithm
void trace_path(vector<cell> cells, point end) {
    stack<point> path;

    int row = end.first;
    int col = end.second;

    // Trace the path back from the end point to the start point using the parent cells
    while (!(cells[row][col].parent.first == row && 
           && ells[row][col].parent.second == col)) {
        path.push(make_pair(row, col));
        int temp_row = cells[row][col].parent.first;
		int temp_col = cells[row][col].parent.second;
		row = temp_row;
		col = temp_col;        
    }

    // Add the start point to the path
    path.push(make_pair(row, col));

    // Prints out the path
    while (!path.empty()) {
        point trail = path.top();
        path.pop();
        printf("-> (%d,%d) ", trail.first, trail.second);
    }
}

// This function implements the A* algorithm to find the shortest path from the start point to the end point.
void a_star(vector2d board, point start, point end) {
    int dim = board.size()

    // Create a vector to keep track of which cells have been explored
    vector<bool> explored;
    explored.resize(dim);
    fill(explored.begin(), explored.end(), false);

    // Create a vector to store the properties of each cell on the board
    vector<state> cells;
    cells.resize(dim);

    int i, j; 

    // Initialize the properties of each cell to default values
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            cells[i][j].parent.first = -1;
            cells[i][j].parent.second = -1;
            cells[i][j].f = FLT_MAX;
            cells[i][j].g = FLT_MAX;
            cells[i][j].h = FLT_MAX;
        }
    }

    // Set the start cell's parent, f, g, and h values
    i = start.first;
    j = start.second;
    cells[i][j].parent.first = i;
    cells[i][j].parent.second = j;
    cells[i][j].f = 0.0;
    cells[i][j].g = 0.0;
    cells[i][j].h = 0.0;

    // Initialize the priority queue to store the cells to be explored
    std::priority_queue<cell, vector<cell>, greater<cell>> frontier;
    
    frontier.emplace(0.0, i, j);

    // Loop while there are still cells to explore in the frontier
    while (!frontier.empty()) {
        // Get the next cell to explore from the frontier
        cell exploring = frontier.top();
        i = get<1>(exploring);
        j = get<2>(exploring);

        // Remove the cell from the frontier and mark it as explored
        frontier.pop();
        explored[i][j] = true;

        double f_succ, g_succ, h_succ;

        // Up (North)
        // Check if the cell above the current cell is a valid cell to explore
        if (is_valid(dim, i - 1, j)) {
            // If the cell above is the end cell, we have found the path
            if (is_end(end, i - 1, j)) {
                cells[i - 1][j].parent.first = i;
                cells[i - 1][j].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            // If the cell above is unexplored and unblocked, calculate its f, g, and h values
            else if (explored[i - 1][j] == false
                    && is_unblocked(board, i - 1, j) == true) {
                g_succ = cells[i - 1][j].g + 1.0;
                h_succ = get_h(end, i - 1, j);
                f_succ = g_succ + h_succ;

                // If the cell has not been visited before or if the new f value is lower,
                // add it to the frontier and update its parent, f, g, and h values
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

        // Down (South)
        // Check if the cell below the current cell is a valid cell to explore
        if (is_valid(dim, i + 1, j)) {
            if (is_end(end, i + 1, j)) {
                cells[i + 1][j].parent.first = i;
                cells[i + 1][j].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            // If the cell below is unexplored and unblocked, calculate its f, g, and h values
            else if (explored[i + 1][j] == false
                    && is_unblocked(board, i + 1, j) == true) {
                g_succ = cells[i + 1][j].g + 1.0;
                h_succ = get_h(end, i + 1, j);
                f_succ = g_succ + h_succ;

                // If the cell has not been visited before or if the new f value is lower,
                // add it to the frontier and update its parent, f, g, and h values
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

        // Right (East)
        // Check if the cell at the right side of the current cell is a valid cell to explore
        if (is_valid(dim, i, j + 1)) {
            if (is_end(end, i, j + 1)) {
                cells[i][j + 1].parent.first = i;
                cells[i][j + 1].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            // If the cell at the right side is unexplored and unblocked, calculate its f, g, and h values
            else if (explored[i][j + 1] == false
                    && is_unblocked(board, i, j + 1) == true) {
                g_succ = cells[i][j + 1].g + 1.0;
                h_succ = get_h(end, i, j + 1);
                f_succ = g_succ + h_succ;

                // If the cell has not been visited before or if the new f value is lower,
                // add it to the frontier and update its parent, f, g, and h values
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

        // Left (West)
        // Check if the cell at the left side of the current cell is a valid cell to explore
        if (is_valid(dim, i, j - 1)) {
            if (is_end(end, i, j - 1)) {
                cells[i][j - 1].parent.first = i;
                cells[i][j - 1].parent.second = j;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            // If the cell at the left side is unexplored and unblocked, calculate its f, g, and h values
            else if (explored[i][j - 1] == false
                    && is_unblocked(board, i, j - 1) == true) {
                g_succ = cells[i][j + 1].g + 1.0;
                h_succ = get_h(end, i, j - 1);
                f_succ = g_succ + h_succ;

                // If the cell has not been visited before or if the new f value is lower,
                // add it to the frontier and update its parent, f, g, and h values
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