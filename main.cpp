#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
typedef pair<int, int> point;
typedef vector<vector<int>> vector2d;

#include "logic/helpers.hpp"
#include "logic/backend.hpp"
#include "interface/gui.hpp"

int main() {

    vector2d board;
    point start, end;
    load_board(&board, &start, &end, "mazes/01.txt");
    print_board(&board, &start, &end);
    
    return 0;
}