struct cell;
struct state;

typedef pair<int, int> point;
typedef vector<vector<cell>> vector2d;

enum legend {
    WALL = 0, PATH = 1,
};

struct state {

    point parent; 
    double g, h;

    state():
        parent(make_pair(-1, -1)), g(-1.0), h(-1.0) {}
};

struct cell {

    bool value;
    double f;

    bool explored;
    state details;

    cell():
        value(-1), f(-1.0), explored(false), details() {}
    cell(int v): 
        value(v), f(-1.0), explored(false), details() {}
};