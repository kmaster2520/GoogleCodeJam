
typedef struct vertex {
    char* id;
} vertex_t;

typedef struct edge {
    vertex_t* u;
    vertex_t* v;
    int cost;
} edge_t;

typedef struct graph {
    vertex_t* vertices;
    edge_t* edges;
} graph_t;

typedef struct path {
    vertex_t* vertices;
    int count;
    int cost;
} path_t;

path_t* shortestPath(graph_t*, vertex_t*, vertex_t*);
graph_t* minimumSpanningTree(graph_t*);
