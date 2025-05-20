//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR 5
#define MAX_NODES 1000

typedef struct {
    int color;
    int degree;
    int index;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int n_nodes;
    int n_colors;
    int color_count[MAX_COLOR];
} Graph;

int main() {
    Graph graph;
    graph.n_nodes = 0;
    graph.n_colors = 0;

    Node node;
    node.color = 0;
    node.degree = 0;
    node.index = 0;

    char* graph_file = "graph.txt";
    FILE* fp = fopen(graph_file, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", graph_file);
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* str = strtok(line, " \t");
        int num = atoi(str);
        node.degree = num;
        str = strtok(NULL, " \t");
        node.index = atoi(str);
        graph.nodes[graph.n_nodes] = node;
        graph.n_nodes++;
    }

    int* colors = (int*)malloc(graph.n_nodes * sizeof(int));
    for (int i = 0; i < graph.n_nodes; i++) {
        colors[i] = i + 1;
    }

    int num_colors = 0;
    while (num_colors < MAX_COLOR) {
        int found = 0;
        for (int i = 0; i < graph.n_nodes; i++) {
            int node_color = colors[i];
            if (node_color!= -1 && node_color!= num_colors) {
                found = 1;
                break;
            }
        }
        if (found == 1) {
            num_colors++;
        }
    }

    printf("Number of colors: %d\n", num_colors);

    for (int i = 0; i < graph.n_nodes; i++) {
        Node node = graph.nodes[i];
        int node_color = colors[i];
        node.color = node_color;
        printf("%d -> %d\n", node.index, node_color);
    }

    free(colors);
    fclose(fp);

    return 0;
}