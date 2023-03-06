bool valid_file(string path) {

    ifstream f(path.c_str());
    return f.good();
}

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    while(clock() < startClock+secondsAhead);
    return;
}

string parse_point(point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

void load_board(vector2d* board, point* start, point* end, string path) {

    ifstream file(path);

    string line;
    getline(file, line);
    int dim = stoi(line);

    board->resize(dim);

    for (int i = 0; i < dim; i++) {

        board->at(i).resize(dim);
        string row;
        getline(file, row);

        for (int j = 0; j < dim; j++) {

            int c = row[j];
            if (row[j] == 'S') {
                *start = point(i, j);
                c = PATH;
            } else if (row[j] == 'G') {
                *end = point(i, j);
                c = PATH;
            } else if (row[j] == '.') {
                c = PATH;
            } else if (row[j] == '#') {
                c = WALL;
            }

            board->at(i).at(j) = cell(c);
        }
    }

    file.close();
}