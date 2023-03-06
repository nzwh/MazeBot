#include "libraries.hpp"

int main() {

    vector2d board;
    point start, end;
    vector<point> path;
    bool found = false;
    int explored = 0, pathed = 0;

    cout << "Welcome to the MazeBot Visualizer!" << endl;

    load_board(&board, &start, &end, file_input());

    print_iter(&board, start, end, false);
    cout << "Press any key to start animation.";
    
    fflush(stdin);
    getchar();

    a_star(&board, start, end, path, &found, &explored);
    print_iter(&board, start, end, true);

    if (!found) {
        printf("The path is not found.\n");
    } else {
        printf("The path is found.\n");
    }

    printf("Explored %d nodes.\n", explored);
    printf("Pathed %d nodes.\n", path.size());
    
    return 0;
}