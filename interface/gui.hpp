string file_input() {

    string fi;

    cout << "Enter the filename that you would like to open. \nNote: the file should be in the mazes folder. \nNo need to write \".txt\" at the end." << endl;
    cin >> fi;

    while (!valid_file("mazes//" + fi + ".txt")) {
        cout << "Invalid file path. Please try again." << endl;
        cin >> fi;
    }

    cout << "Valid file. Processing..." << endl;
    return "mazes//" + fi + ".txt";
}

void print_iter(vector2d* board, point start, point end, bool s) {

    system("cls");

    cout << LBLK NCUL;
    for (int i = 0; i < ((int)board->size()*2); i++) 
        cout << NHFT;
    cout << NCUR KRST << endl;
    
    for (int i = 0; i < (int)board->size(); i++) {

        cout << LBLK NVFT KRST;
        for (int j = 0; j < (int)board->at(i).size(); j++) {
            
            if (i == start.x && j == start.y) {
                cout << LCYN "S ";
            } else if (i == end.x && j == end.y) {
                cout << LBLU "G ";
            } else if (board->at(i).at(j).pathed && s) {
                cout << LRED "* ";
            } else if (board->at(i).at(j).explored) {
                cout << LYEL "* ";
            } else if (board->at(i).at(j).value == WALL) {
                cout << LBLK ": ";
            }  else {
                cout << "  ";
            }

            

            cout << KRST;
        }
        cout << LBLK NVFT KRST << endl;
    }

    cout << LBLK NCDL;
    for (int i = 0; i < ((int)board->size()*2); i++) 
        cout << NHFT;
    cout << NCDR KRST << endl;

    sleep(0.01);
}