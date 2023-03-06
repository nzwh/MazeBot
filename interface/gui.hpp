void typewriter(float delay, float wait, string s) {

    for (int i = 0; i < (int)s.length(); i++) {
        printf("%c", s[i]);
        sleep(delay);
    }

    sleep(wait);
}

string file_input() {

    string fi;
    
    typewriter(0.02, 0.5, LBLU "   Enter the filename that you would like to open.\n");
    typewriter(0.02, 0.5, "   Note: the file should be in the mazes folder.\n");
    typewriter(0.02, 0.5, "   No need to write \".txt\" at the end.\n\n   " LWHT "> ");
    cin >> fi;

    while (!valid_file("mazes//" + fi + ".txt")) {
        typewriter(0.02, 0.5, LRED "\n   Invalid file path. Please try again.\n\n   " LWHT "> ");
        cin >> fi;
    }

    typewriter(0.02, 0.5, LYEL "\n   Loaded file.\n");
    typewriter(0.02, 1, "   Processing...\n" KRST);
    return "mazes//" + fi + ".txt";
}

void print_iter(vector2d* board, point start, point end, bool s) {

    clrscr();

    cout << endl << endl;

    cout << "   " LBLK NCUL;
    for (int i = 0; i < ((int)board->size()*2); i++) 
        cout << NHFT;
    cout << NCUR KRST << endl;
    
    for (int i = 0; i < (int)board->size(); i++) {

        cout << "   " LBLK NVFT KRST;
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

    cout << "   " LBLK NCDL;
    for (int i = 0; i < ((int)board->size()*2); i++) 
        cout << NHFT;
    cout << NCDR KRST << endl;

    sleep(0.1);
}