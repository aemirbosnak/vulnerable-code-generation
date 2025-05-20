//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define INFINITY INT_MAX - 1
#define NODES 10
#define EDGES 15

typedef struct node {
    int id;
    double x, y;
} Node;

typedef struct edge {
    int from, to;
    double weight;
} Edge;

typedef struct graph {
    int V, E;
    Node* nodes;
    Edge* edges;
} Graph;

// function declarations
double heuristic(int n1, int n2, Node* nodes);
void Astar(Graph* graph, int start, int goal, int* came_from, double* cost_so_far);

int main() {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = NODES;
    graph->E = EDGES;
    graph->nodes = (Node*) malloc(sizeof(Node) * NODES);
    graph->edges = (Edge*) malloc(sizeof(Edge) * EDGES);

    // initialize nodes
    for (int i = 0; i < NODES; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].x = (double) rand() / RAND_MAX;
        graph->nodes[i].y = (double) rand() / RAND_MAX;
    }

    // initialize edges
    for (int i = 0; i < EDGES; i++) {
        graph->edges[i].from = rand() % NODES;
        graph->edges[i].to = rand() % NODES;
        graph->edges[i].weight = sqrt(pow(graph->nodes[graph->edges[i].to].x - graph->nodes[graph->edges[i].from].x, 2) + pow(graph->nodes[graph->edges[i].to].y - graph->nodes[graph->edges[i].from].y, 2));
    }

    // run A* algorithm on graph
    int start = rand() % NODES;
    int goal = rand() % NODES;
    int* came_from = (int*) malloc(sizeof(int) * NODES);
    double* cost_so_far = (double*) malloc(sizeof(double) * NODES);
    Astar(graph, start, goal, came_from, cost_so_far);

    // print results
    printf("Came From: ");
    for (int i = 0; i < NODES; i++) {
        printf("%d ", came_from[i]);
    }
    printf("\nCost So Far: ");
    for (int i = 0; i < NODES; i++) {
        printf("%.2f ", cost_so_far[i]);
    }
    printf("\n");

    // free memory
    free(graph->nodes);
    free(graph->edges);
    free(graph);
    free(came_from);
    free(cost_so_far);

    return 0;
}

double heuristic(int n1, int n2, Node* nodes) {
    return sqrt(pow(nodes[n2].x - nodes[n1].x, 2) + pow(nodes[n2].y - nodes[n1].y, 2));
}

void Astar(Graph* graph, int start, int goal, int* came_from, double* cost_so_far) {
    int* open_set = (int*) malloc(sizeof(int) * NODES);
    int* closed_set = (int*) malloc(sizeof(int) * NODES);
    double* f_score = (double*) malloc(sizeof(double) * NODES);
    double* g_score = (double*) malloc(sizeof(double) * NODES);
    for (int i = 0; i < NODES; i++) {
        open_set[i] = -1;
        closed_set[i] = -1;
        f_score[i] = INFINITY;
        g_score[i] = INFINITY;
    }
    int open_set_size = 0;
    int closed_set_size = 0;

    g_score[start] = 0;
    f_score[start] = heuristic(start, goal, graph->nodes);
    open_set[open_set_size++] = start;

    while (open_set_size > 0) {
        // find node in open set with lowest f score
        double lowest_f_score = INFINITY;
        int current;
        for (int i = 0; i < open_set_size; i++) {
            if (f_score[open_set[i]] < lowest_f_score) {
                current = open_set[i];
                lowest_f_score = f_score[current];
            }
        }

        if (current == goal) {
            break;
        }

        // remove current from open set and add to closed set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current) {
                open_set[i] = open_set[--open_set_size];
                closed_set[closed_set_size++] = current;
                break;
            }
        }

        // examine neighbours
        for (int i = 0; i < graph->E; i++) {
            if (graph->edges[i].from == current) {
                int neighbour = graph->edges[i].to;
                if (closed_set_size > 0) {
                    bool skip = false;
                    for (int j = 0; j < closed_set_size; j++) {
                        if (closed_set[j] == neighbour) {
                            skip = true;
                            break;
                        }
                    }
                    if (skip == true) {
                        continue;
                    }
                }
                double tentative_g_score = g_score[current] + graph->edges[i].weight;
                if (open_set_size == 0) {
                    open_set[open_set_size++] = neighbour;
                }
                else {
                    bool already_in_open_set = false;
                    for (int j = 0; j < open_set_size; j++) {
                        if (open_set[j] == neighbour) {
                            already_in_open_set = true;
                            break;
                        }
                    }
                    if (already_in_open_set == false) {
                        open_set[open_set_size++] = neighbour;
                    }
                    else if (tentative_g_score >= g_score[neighbour]) {
                        continue;
                    }
                }
                came_from[neighbour] = current;
                g_score[neighbour] = tentative_g_score;
                f_score[neighbour] = g_score[neighbour] + heuristic(neighbour, goal, graph->nodes);
            }
        }
    }

    // free memory
    free(open_set);
    free(closed_set);
    free(f_score);
    free(g_score);
}