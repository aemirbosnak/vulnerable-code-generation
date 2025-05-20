//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTICES 100

typedef struct {
    int u, v; // vertices
    int weight; // weight of edge
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

// function prototypes
void printEdges(Edge edges[], int numEdges);
int compareEdges(const void* e1, const void* e2);
int find(Subset subsets[], int i);
void Union(Subset subsets[], int x, int y);
void kruskalMST(Edge edges[], int numEdges, int numVertices);

int main() {
    int numVertices, numEdges;
    Edge edges[MAX_VERTICES * (MAX_VERTICES - 1) / 2];
    
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int weight;
            scanf("%d", &weight);
            if (weight != 0 && i < j) { // adding edges to array
                edges[numEdges].u = i;
                edges[numEdges].v = j;
                edges[numEdges].weight = weight;
                numEdges++;
            }
        }
    }

    kruskalMST(edges, numEdges, numVertices);

    return 0;
}

/*
 * Prints all the edges in the given array
 * 
 * @param edges - array of edges
 * @param numEdges - number of edges in array
 */
void printEdges(Edge edges[], int numEdges) {
    printf("Edges:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("(%d, %d, %d)\n", edges[i].u, edges[i].v, edges[i].weight);
    }
}

/*
 * Compare function for sorting edges in ascending order of weight
 */
int compareEdges(const void* e1, const void* e2) {
    Edge* edge1 = (Edge*) e1;
    Edge* edge2 = (Edge*) e2;
    return edge1->weight - edge2->weight;
}

/*
 * Find operation of disjoint-set data structure
 */
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

/*
 * Union operation of disjoint-set data structure
 */
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    }
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

/*
 * Kruskal's algorithm implementation
 * 
 * @param edges - array of edges
 * @param numEdges - number of edges in array
 * @param numVertices - number of vertices in graph
 */
void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    Edge result[numVertices - 1]; // stores MST
    Subset subsets[numVertices];
    int resultIndex = 0;

    // initialize subsets
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // sort edges in ascending order of weight
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int set_u = find(subsets, u);
        int set_v = find(subsets, v);

        // check if adding edge will form a cycle
        if (set_u != set_v) {
            result[resultIndex++] = edges[i];
            Union(subsets, set_u, set_v);
        }

        // stop when MST is complete
        if (resultIndex == numVertices - 1) {
            break;
        }
    }

    // print MST
    printf("Edges in MST:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("(%d, %d, %d)\n", result[i].u, result[i].v, result[i].weight);
    }
}