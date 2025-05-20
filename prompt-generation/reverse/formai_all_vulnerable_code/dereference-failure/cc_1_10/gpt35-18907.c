//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

//Graph node structure
struct GraphNode{
    int vertex;
    struct GraphNode* next;
};

//Graph structure
struct Graph{
    int V; //Number of vertices
    int E; //Number of edges
    int* color; //Array to store color of each vertex
    struct GraphNode** adjList; //Adjacency list for each vertex
};

//Function to create a new graph node
struct GraphNode* createGraphNode(int v){
    struct GraphNode* newNode = (struct GraphNode*) malloc(sizeof(struct GraphNode));
    newNode -> vertex = v;
    newNode -> next = NULL;
    return newNode;
}

//Function to create a new graph
struct Graph* createGraph(int V, int E){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph -> V = V;
    graph -> E = E;
    graph -> color = (int*) malloc(sizeof(int) * V);
    graph -> adjList = (struct GraphNode**) malloc(sizeof(struct GraphNode*) * V);

    int i;
    for(i = 0; i < V; i++){
        graph -> color[i] = -1; //To indicate vertex is not yet colored
        graph -> adjList[i] = NULL;
    }

    return graph;
}

//Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v){
    //Add edge from u to v
    struct GraphNode* newNode1 = createGraphNode(v);
    newNode1 -> next = graph -> adjList[u];
    graph -> adjList[u] = newNode1;

    //Add edge from v to u
    struct GraphNode* newNode2 = createGraphNode(u);
    newNode2 -> next = graph -> adjList[v];
    graph -> adjList[v] = newNode2;
}

//Function to check if a vertex can be colored with a particular color
int isSafe(struct Graph* graph, int v, int c){
    int i;
    for(i = 0; i < graph -> V; i++){
        struct GraphNode* temp = graph -> adjList[v];
        while(temp){
            if(graph -> color[temp -> vertex] == c){
                return 0;
            }
            temp = temp -> next;
        }
    }
    return 1;
}

//Function to recursively color the graph
int colorGraph(struct Graph* graph, int v, int numColors){
    if(v == graph -> V){ //If all vertices are colored
        return 1;
    }

    int c;
    for(c = 0; c < numColors; c++){
        if(isSafe(graph, v, c)){
            graph -> color[v] = c; //Color the vertex
            if(colorGraph(graph, v + 1, numColors)){ //Recursive call for next vertex
                return 1;
            }
            graph -> color[v] = -1; //Backtrack
        }
    }

    return 0; //No color possible for this vertex
}

//Main function
int main(){
    int V = 6;
    int E = 6;
    struct Graph* graph = createGraph(V, E);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int numColors = 3;
    if(colorGraph(graph, 0, numColors)){
        printf("The coloring of the graph is as follows:\n");
        int i;
        for(i = 0; i < V; i++){
            printf("Vertex %d colored with color %d\n", i, graph -> color[i]);
        }
    }
    else{
        printf("No coloring possible for the graph with %d colors\n", numColors);
    }

    return 0;
}