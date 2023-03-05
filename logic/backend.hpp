// This function checks if a given position is within the boundaries of a board of size dim
bool is_valid(int dim, int row, int col) {
    return row >= 0 && row < dim && col >= 0 && col < dim;
}

// This function checks a given position on the board is unblocked/not a wall
bool is_unblocked(vector2d board, int row, int col) {
    return board[row][col].value;
}

// This function checks a given position is the end goal
bool is_end(point end, int row, int col) {
    return end.x == row && end.y == col;
}

// This function returns the heuristic by solving the Manhattan distance between the given point and the end point
double get_h(point end, int row, int col) {
    return abs(row - end.x) + abs(col - end.y);
}

// This function prints out the path found by the A* algorithm
void trace_path(vector<vector<cell>> cells, point end) {
    stack<point> path;

    int row = end.x;
    int col = end.y;

    // Trace the path back from the end point to the start point using the parent cells
    while (!(cells[row][col].details.parent.x == row
           && cells[row][col].details.parent.y == col)) {
        path.push(point(row, col));
        int temp_row = cells[row][col].details.parent.x;
		int temp_col = cells[row][col].details.parent.y;
		row = temp_row;
		col = temp_col;        
    }

    // Add the start point to the path
    path.push(point(row, col));

    // Prints out the path
    while (!path.empty()) {
        point trail = path.top();
        path.pop();
        printf("-> (%d,%d) ", trail.x, trail.y);
    }
}

// This function implements the A* algorithm to find the shortest path from the start point to the end point.
void a_star(vector2d board, point start, point end) {
    
    int dim = board.size();

    int x = start.x;
    int y = start.y;
    board[x][y].f = 0.0;
    board[x][y].details = state(point(x, y), 0.0, 0.0);

    priority_queue<node, vector<node>, greater<node>> frontier;
    
    frontier.emplace(0.0, x, y);

    // Loop while there are still cells to explore in the frontier
    while (!frontier.empty()) {
        // Get the next cell to explore from the frontier
        node exploring = frontier.top();
        x = get<1>(exploring);
        y = get<2>(exploring);

        // Remove the cell from the frontier and mark it as explored
        frontier.pop();
        board[x][y].explored = true;

        double f_succ, g_succ, h_succ;

        // Up (North)
        // Check if the cell above the current cell is a valid cell to explore
        if (is_valid(dim, x - 1, y)) {
            // If the cell above is the end cell, we have found the path
            if (is_end(end, x - 1, y)) {
                board[x - 1][y].details.parent.x = x;
                board[x - 1][y].details.parent.y = y;
                printf("The path is found.\n");
                //tracePath(cellDetails, dest);
				//foundDest = true;
                return;
            }
            // If the cell above is unexplored and unblocked, calculate its f, g, and h values
            else if (board[x - 1][y].explored == false
                    && is_unblocked(board, x - 1, y) == true) {
                g_succ = board[x - 1][y].details.g + 1.0;
                h_succ = get_h(end, x - 1, y);
                f_succ = g_succ + h_succ;

                // If the cell has not been visited before or if the new f value is lower,
                // add it to the frontier and update its parent, f, g, and h values
                if (board[x - 1][y].f == FLT_MAX
                    || board[x - 1][y].f > f_succ) {
                    frontier.emplace(f_succ, x - 1, y);

                    board[x - 1][y].f = f_succ;
                    board[x - 1][y].details = state(point(x, y), g_succ, h_succ);
                }
            }
        }
    }
}