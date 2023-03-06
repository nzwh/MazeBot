struct point;
struct cell;
struct state;

typedef vector<vector<cell>> vector2d;
typedef tuple<double, int, int> node;
typedef priority_queue<node, vector<node>, greater<node>> minheap;

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
        parent(-1, -1), g(-1), h(-1) {}
    state(point p, double g, double h):
        parent(p), g(g), h(h) {}
};

struct cell {

    bool value;
    double f;

    bool explored;
    state details;

    bool pathed;

    cell():
        value(-1), f(-1), explored(false), details(), pathed(false) {}
    cell(int v): 
        value(v), f(-1), explored(false), details(), pathed(false) {}
};

