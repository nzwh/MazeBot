struct point;
struct cell;
struct state;

typedef vector<vector<cell>> vector2d;
typedef tuple<double, int, int> node;

enum legend {
    WALL = 0, PATH = 1,
};

struct point {

    int x, y;

    point():
        x(-1), y(-1) {}
    point(int x, int y):
        x(x), y(y) {}
};

struct state {

    point parent; 
    double g, h;

    state():
        parent(-1, -1), g(FLT_MAX), h(FLT_MAX) {}
    state(point p, double g, double h):
        parent(p), g(g), h(h) {}
};

struct cell {

    bool value;
    double f;

    bool explored;
    state details;

    cell():
        value(-1), f(FLT_MAX), explored(false), details() {}
    cell(int v): 
        value(v), f(FLT_MAX), explored(false), details() {}
};

