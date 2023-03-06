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

string parse_point(point p) {
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

void print_board(vector2d* board, point* start, point* end) {

    cout << "From " << parse_point(*start) << " to " << parse_point(*end) << endl;
    for (int i = 0; i < (int)board->size(); i++) {
        
        for (int j = 0; j < (int)board->at(i).size(); j++) {
            
            if (board->at(i).at(j).pathed) 
                cout << "\x1B[31m";
            
            if (board->at(i).at(j).value == WALL) {
                cout << "# ";
            } else if (i == start->x && j == start->y) {
                cout << "S ";
            } else if (i == end->x && j == end->y) {
                cout << "G ";
            } else {
                cout << board->at(i).at(j).value << " ";
            }

            cout << "\x1B[0m";
        }
        cout << endl;
    }
}