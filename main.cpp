#include "libraries.hpp"

int main() {

    esqncs();
    clrscr();

    vector2d board;
    point start, end;
    vector<point> path;
    bool found = false;
    int explored = 0;

    cout << endl << endl;
    typewriter(0.02, 2, LRED "   Welcome to the MazeBot Visualizer!\n\n" KRST);
    load_board(&board, &start, &end, file_input());

    print_iter(&board, start, end, false);
    typewriter(0.02, 1, LBLU "\n   Travelling from (" + to_string(start.x) + ", " + to_string(start.y) + ") to (" + to_string(end.x) + ", " + to_string(end.y) + ").\n" KRST);
    typewriter(0.02, 2, LBLU "   Press the enter key to start animation." KRST);
    
    fflush(stdin);
    getchar();

    a_star(&board, start, end, path, &found, &explored);
    print_iter(&board, start, end, true);
    typewriter(0.02, 1, found ? LGRN "\n   Path found!\n" : LRED "   Path not found\n");
    typewriter(0.02, 1, LBLU "   From (" + to_string(start.x) + ", " + to_string(start.y) + ") to (" + to_string(end.x) + ", " + to_string(end.y) + ").\n" KRST);

    typewriter(0.02, 1, LYEL "\n   Explored " + to_string(explored) + " nodes.\n" KRST);
    typewriter(0.02, 1, LYEL "   Pathed " + to_string(path.size()) + " nodes.\n" KRST);

    typewriter(0.02, 2, LWHT "\n   Terminating program...\n\n" KRST);
    
    return 0;
}