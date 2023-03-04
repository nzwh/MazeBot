void load_board(vector<vector<int>>* board, string path) {

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
            board->at(i).at(j) = row[j];
        }
    }

    file.close();
}

void print_board(vector<vector<int>>* board) {

    for (int i = 0; i < (int)board->size(); i++) {
        for (int j = 0; j < (int)board->at(i).size(); j++) {
            printf("%c ", board->at(i).at(j));
        }
        cout << endl;
    }
}