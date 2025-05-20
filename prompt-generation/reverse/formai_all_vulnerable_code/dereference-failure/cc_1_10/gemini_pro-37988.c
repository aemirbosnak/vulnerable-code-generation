//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphN{
    int v;
    struct GraphN *next;
}GraphN;

typedef struct Graph{
    GraphN **vertex;
    int *vis;
    int size;
}Graph;

Graph *init(int s){
    Graph *g = malloc(sizeof(Graph));
    g->size = s;
    g->vertex = malloc(sizeof(GraphN *) * s);
    g->vis = malloc(sizeof(int) * s);
    for(int i=0; i<s; i++){
        g->vertex[i] = NULL;
        g->vis[i] = 0;
    }
    return g;
}

void addE(Graph *g, int u, int v){
    GraphN *en = malloc(sizeof(GraphN));
    en->v = v;
    en->next = g->vertex[u];
    g->vertex[u] = en;
}

void print(Graph *g){
    for(int i=0; i<g->size; i++){
        GraphN *n = g->vertex[i];
        printf("%d : ", i);
        while(n!=NULL){
            printf("%d ", n->v);
            n = n->next;
        }
        printf("\n");
    }
}

void dfs(Graph *g, int u){
    g->vis[u] = 1;
    printf("%d ", u);
    GraphN *n = g->vertex[u];
    while(n!=NULL) {
        if(!g->vis[n->v]){
            dfs(g, n->v);
        }
        n = n->next;
    }
}

void destroy(Graph *g){
    for(int i=0; i<g->size; i++){
        GraphN *n = g->vertex[i];
        while(n!=NULL){
            GraphN *t = n;
            n = n->next;
            free(t);
        }
    }
    free(g->vertex);
    free(g->vis);
    free(g);
}

int main(int argc, char *argv[]){
    int s = 4;
    Graph *g = init(s);
    addE(g, 0, 1);
    addE(g, 0, 2);
    addE(g, 1, 3);
    addE(g, 1, 2);
    addE(g, 2, 3);
    addE(g, 2, 0);
    addE(g, 3, 1);
    dfs(g, 0);
    printf("\n");
    destroy(g);
    return 0;
}