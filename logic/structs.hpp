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

    int value;
    double f;

    state details;
    bool explored;

    cell():
        value(-1), f(-1.0), details(), explored(false) {}
    cell(int v): 
        value(v), f(-1.0), details(), explored(false) {}
};