typedef pair<int, int> point;
typedef vector<vector<int>> vector2d;

enum legend {
    EXPLORED = -1, WALL = 0, PATH = 1,
};

struct state {
    point parent; 
    double f, g, h;
};