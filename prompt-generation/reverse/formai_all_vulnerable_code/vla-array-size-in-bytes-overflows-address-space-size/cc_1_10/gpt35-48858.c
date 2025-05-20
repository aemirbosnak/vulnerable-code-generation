//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    int color;
    struct Node* next;
};

void add_edge(struct Node** graph, int u, int v) {
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->value = v;
    temp1->next = graph[u];
    graph[u] = temp1;

    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    temp2->value = u;
    temp2->next = graph[v];
    graph[v] = temp2;
}

int get_degree(struct Node** graph, int V, int v) {
    int count = 0;
    struct Node* temp = graph[v];
    while(temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int find_color(struct Node** graph, int V, int* color, int v) {
    int used_colors[V];
    for(int i=0; i<V; i++)
        used_colors[i] = 0;
    struct Node* temp = graph[v];
    while(temp) {
        if(color[temp->value] != -1)
            used_colors[color[temp->value]] = 1;
        temp = temp->next;
    }
    for(int c=0; c<V; c++) {
        if(used_colors[c] == 0)
            return c;
    }
    return -1;
}

void color_graph(struct Node** graph, int V) {
    int color[V];
    for(int i=0; i<V; i++)
        color[i] = -1;
    for(int v=0; v<V; v++) {
        if(color[v] == -1) {
            int max_degree = -1, max_degree_node = -1;
            struct Node* temp = graph[v];
            while(temp) {
                int degree = get_degree(graph, V, temp->value);
                if(degree > max_degree && color[temp->value] == -1) {
                    max_degree = degree;
                    max_degree_node = temp->value;
                }
                temp = temp->next;
            }
            if(max_degree_node != -1)
                color[v] = find_color(graph, V, color, max_degree_node);
            else
                color[v] = 0;
        }
    }
    printf("\nVertex\tColor\n");
    for(int i=0; i<V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct Node* graph[V];
    for(int i=0; i<V; i++)
        graph[i] = NULL;
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges\n");
    for(int i=0; i<E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(graph, u, v);
    }
    printf("\nColoring the graph...\n");
    color_graph(graph, V);
    return 0;
}