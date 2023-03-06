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
void trace_path(vector2d* board, point start, point end, vector<point>& r_path) {

    stack<point> path;

    // Initialize the row and column indices to the end point
    int cur_x = end.x;
    int cur_y = end.y;
    int nextx, nexty;

    // Trace the path back from the end point to the start point using the parent cells
    while (!(nextx == start.x && nexty == start.y)) {
        
        path.emplace(point(cur_x, cur_y));
        board->at(cur_x).at(cur_y).pathed = true;
        
		nextx = board->at(cur_x).at(cur_y).details.parent.x;
		nexty = board->at(cur_x).at(cur_y).details.parent.y;   

        cur_x = nextx;
        cur_y = nexty;
    }

    // Add the start point to the path
    path.emplace(point(cur_x, cur_y));
    path.emplace(point(start.x, start.y));

    // Add the path to the return path
    while (!path.empty()) {
        r_path.emplace_back(path.top());
        path.pop();
    }
}

void move(point parent, point next, vector2d* board, point start, point end, minheap& frontier, vector<point>& r_path, bool* found) {

    int x = next.x, y = next.y;

    if (!is_valid(board->size(), x, y)) {
        return;
    }

    // Check if the coordinates match the end point
    if (is_end(end, x, y)) {
        // Update the parent coordinates for the current cell and print the path
        board->at(x).at(y).details.parent.x = parent.x;
        board->at(x).at(y).details.parent.y = parent.y;
        trace_path(board, start, end, r_path);
        *found = true;

    } else if (!board->at(x).at(y).explored && is_unblocked(*board, x, y)) {
            
        // Calculate the cost of moving to the current cell
        double g_succ = board->at(x).at(y).details.g + 1.0;
        double h_succ = get_h(end, x, y);
        double f_succ = g_succ + h_succ;

        // Check if the current cell has not been explored or if the cost to reach it is lower than the previous cost
        if (board->at(x).at(y).f == -1
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
void a_star(vector2d* board, point start, point end, vector<point>& r_path, bool* found, int* explored) {

    // Set the starting point
    int x = start.x;
    int y = start.y;
    board->at(x).at(y).f = 0.0;
    board->at(x).at(y).details = state(point(x, y), 0.0, 0.0);

    // Create a priority queue to store the nodes to be explored
    minheap frontier;
    frontier.emplace(0.0, x, y);

    // Loop while there are still cells to explore in the frontier
    while (!frontier.empty() && *found == false) {

        // Get the next cell to explore from the frontier
        node exploring = frontier.top();
        x = get<1>(exploring);
        y = get<2>(exploring);

        // Remove the cell from the frontier and mark it as explored
        frontier.pop();
        board->at(x).at(y).explored = true;
        (*explored)++;

        // Move to the adjacent cells
        move(point(x, y), point(x + 1, y), board, start, end, frontier, r_path, found);
        move(point(x, y), point(x - 1, y), board, start, end, frontier, r_path, found);
        move(point(x, y), point(x, y + 1), board, start, end, frontier, r_path, found);
        move(point(x, y), point(x, y - 1), board, start, end, frontier, r_path, found);

        print_iter(board, start, end, false);
    }
}