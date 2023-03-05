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
void trace_path(vector2d board, point start, point end) {

    stack<point> path;

    // Initialize the row and column indices to the end point
    int row = end.x;
    int col = end.y;

    // Trace the path back from the end point to the start point using the parent cells
    while (!(board[row][col].details.parent.x == start.x
           && board[row][col].details.parent.y == start.y)) {

        path.emplace(point(row, col));
        int temp_row = board[row][col].details.parent.x;
		int temp_col = board[row][col].details.parent.y;
		row = temp_row;
		col = temp_col;      
    }

    // Add the start point to the path
    path.emplace(point(row, col));

    // Prints out the path
    while (!path.empty()) {
        point trail = path.top();
        path.pop();
        printf("-> (%d,%d) ", trail.x, trail.y);
    }
}

void move(point parent, point next, vector2d* board, int dim, point start, point end, minheap& frontier) {

    int x = next.x, y = next.y;

    if (!is_valid(dim, x, y)) {
        return;
    }

    // Check if the coordinates match the end point
    if (is_end(end, x, y)) {
        // Update the parent coordinates for the current cell and print the path
        board->at(x).at(y).details.parent.x = parent.x;
        board->at(x).at(y).details.parent.y = parent.y;
        printf("The path is found.\n");
        trace_path(*board, start, end);
        //foundDest = true;

    } else if (!board->at(x).at(y).explored 
        && is_unblocked(*board, x, y)) {
            
        // Calculate the cost of moving to the current cell
        double g_succ = board->at(x).at(y).details.g + 1.0;
        double h_succ = get_h(end, x, y);
        double f_succ = g_succ + h_succ;

        // Check if the current cell has not been explored or if the cost to reach it is lower than the previous cost
        if (board->at(x).at(y).f == FLT_MAX
            || board->at(x).at(y).f > f_succ) {
            // Update the cost and details of the current cell
            board->at(x).at(y).f = f_succ;
            board->at(x).at(y).details = state(point(parent.x, parent.y), g_succ, h_succ);

            // Push the cell to the frontier
            frontier.emplace(f_succ, x, y);
        }
    }
}

// This function implements the A* algorithm to find the shortest path from the start point to the end point.
void a_star(vector2d* board, point start, point end) {
    
    // Get the size of the board
    int dim = board->size();

    // Set the starting point
    int x = start.x;
    int y = start.y;
    board->at(x).at(y).f = 0.0;
    board->at(x).at(y).details = state(point(x, y), 0.0, 0.0);

    // Create a priority queue to store the nodes to be explored
    minheap frontier;
    frontier.emplace(0.0, x, y);

    // Loop while there are still cells to explore in the frontier
    while (!frontier.empty()) {

        // Get the next cell to explore from the frontier
        node exploring = frontier.top();
        x = get<1>(exploring);
        y = get<2>(exploring);

        // Remove the cell from the frontier and mark it as explored
        frontier.pop();
        board->at(x).at(y).explored = true;

        // Move to the adjacent cells
        move(point(x, y), point(x + 1, y), board, dim, start, end, frontier);
        move(point(x, y), point(x - 1, y), board, dim, start, end, frontier);
        move(point(x, y), point(x, y + 1), board, dim, start, end, frontier);
        move(point(x, y), point(x, y - 1), board, dim, start, end, frontier);
    }
}