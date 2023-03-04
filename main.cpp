#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "logic/helpers.hpp"
#include "logic/backend.hpp"
#include "interface/gui.hpp"

int main() {

    vector<vector<int>> board;
    load_board(&board, "mazes/01.txt");
    print_board(&board);
    
    return 0;
}