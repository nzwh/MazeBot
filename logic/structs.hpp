typedef pair<int, int> point;
typedef tuple<double, int, int> cell;
typedef vector<cell> vector2d;

enum legend {
    EXPLORED = -1, WALL = 0, PATH = 1,
};

struct state {
    point parent; 
    double f, g, h;
};