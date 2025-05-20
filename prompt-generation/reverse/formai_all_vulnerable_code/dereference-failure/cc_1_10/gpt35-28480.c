//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Struct for each node of the graph
typedef struct node {
    int x;
    int y;
    int f_score;
    int g_score;
    int h_score;
    int visited;
    struct node* parent;
} Node;

// Function to calculate the Manhattan distance between two nodes
int calc_distance(Node* current, Node* end) {
    int x_distance = abs(current->x - end->x);
    int y_distance = abs(current->y - end->y);
    return x_distance + y_distance;
}

// Function to find the node with the lowest f score
Node* get_lowest_f_node(Node* nodes[], int num_nodes) {
    Node* lowest_node = NULL;
    int lowest_score = 0;
    for (int i = 0; i < num_nodes; i++) {
        if (!nodes[i]->visited && (lowest_node == NULL || nodes[i]->f_score < lowest_score)) {
            lowest_node = nodes[i];
            lowest_score = lowest_node->f_score;
        }
    }
    return lowest_node;
}

// Function to print the path from start to end (as reversed list)
void print_path(Node* end) {
    Node* current = end;
    while (current) {
        printf("(%d,%d) ", current->x, current->y);
        current = current->parent;
    }
    printf("\n");
}

// A* pathfinding algorithm
void a_star_pathfinding(Node* start, Node* end, Node* graph[], int width, int height) {
    start->g_score = 0;
    start->h_score = calc_distance(start, end);
    start->f_score = start->h_score;
    Node* current = start;
    while (current != end) {
        current->visited = 1;
        for (int x = current->x - 1; x <= current->x + 1; x++) {
            for (int y = current->y - 1; y <= current->y + 1; y++) {
                if (x >= 0 && x < width && y >= 0 && y < height && (x == current->x || y == current->y)) {
                    Node* neighbor = graph[x + y * width];
                    if (!neighbor->visited) {
                        int tentative_g_score = current->g_score + calc_distance(current, neighbor);
                        if (tentative_g_score < neighbor->g_score || neighbor->g_score == -1) {
                            neighbor->g_score = tentative_g_score;
                            neighbor->h_score = calc_distance(neighbor, end);
                            neighbor->f_score = neighbor->g_score + neighbor->h_score;
                            neighbor->parent = current;
                        }
                    }
                }
            }
        }
        current = get_lowest_f_node(graph, width * height);
        if (current == NULL) {
            printf("No path found!\n");
            return;
        }
    }
    print_path(end);
}

int main() {
    int width = 5;
    int height = 5;
    Node* graph[width * height];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Node* node = (Node*)malloc(sizeof(Node));
            node->x = x;
            node->y = y;
            node->g_score = -1;
            node->visited = 0;
            node->parent = NULL;
            graph[x + y * width] = node;
        }
    }
    Node* start = graph[0];
    Node* end = graph[4 + 3 * width];
    a_star_pathfinding(start, end, graph, width, height);

    for (int i = 0; i < width * height; i++) {
        free(graph[i]);
    }
    return 0;
}