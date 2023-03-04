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
                *start = make_pair(i, j);
                c = 1;
            } else if (row[j] == 'G') {
                *end = make_pair(i, j);
                c = 1;
            } else if (row[j] == '.') {
                c = 1;
            } else if (row[j] == '#') {
                c = 0;
            }

            board->at(i).at(j) = c;
        }
    }

    file.close();
}

string parse_point(point p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void print_board(vector2d* board, point* start, point* end) {

    cout << "From " << parse_point(*start) << " to " << parse_point(*end) << endl;
    for (int i = 0; i < (int)board->size(); i++) {
        
        for (int j = 0; j < (int)board->at(i).size(); j++) {
            printf("%d ", board->at(i).at(j));
        }
        cout << endl;
    }
}