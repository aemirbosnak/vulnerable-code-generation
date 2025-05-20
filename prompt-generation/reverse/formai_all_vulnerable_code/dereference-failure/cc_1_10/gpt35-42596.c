//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct graph {
    int vertices[MAX][MAX];
    int num_vertices;
}Graph;


void init_graph(Graph *g) {
    int i,j;
    g->num_vertices = 0;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            g->vertices[i][j] = 0;
        }
    }
}

void add_edges(Graph *g, int u, int v) {
    g->vertices[u-1][v-1] = 1;
    g->vertices[v-1][u-1] = 1;
}

void display(Graph *g) {
    int i,j;
    for(i=0;i<g->num_vertices;i++) {
        printf("%d: ",i+1);
        for(j=0;j<g->num_vertices;j++) {
            if(g->vertices[i][j] == 1) {
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph *g;
    g = (Graph*)malloc(sizeof(Graph));
    init_graph(g);
    
    add_edges(g,1,2);
    add_edges(g,1,3);
    add_edges(g,2,4);
    add_edges(g,3,4);
    add_edges(g,4,5);
    add_edges(g,4,6);
    add_edges(g,5,6);
    display(g);
    
    free(g);
    return 0;
}