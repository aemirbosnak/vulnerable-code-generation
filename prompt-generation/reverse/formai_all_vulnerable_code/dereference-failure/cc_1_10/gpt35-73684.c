//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: safe
#include <stdio.h> 
#include <stdlib.h> 

//Structure that defines each node of the graph
struct Node { 
    int id; //ID of the node
    int num_edges; //Number of edges going out of this node
    struct Edge* edges; //Array of edges from this node 
    struct Node* next; //Next node in the graph
}; 
  
//Structure that defines each edge
struct Edge { 
    int weight; //Weight of the edge
    struct Node* dest; //Destination node of the edge
}; 

//Structure that defines the graph
struct Graph {
    struct Node* start; //Start node of the graph
};

//Function to create a new node in the graph
struct Node* create_node(int id) {
    struct Node* new_node = malloc(sizeof(struct Node)); //Allocate memory for new node
    new_node->id = id;
    new_node->num_edges = 0;
    new_node->edges = NULL;
    new_node->next = NULL;
    return new_node;
}

//Function to create a new edge in the graph
struct Edge* create_edge(struct Node* dest, int weight) {
    struct Edge* new_edge = malloc(sizeof(struct Edge)); //Allocate memory for new edge
    new_edge->dest = dest;
    new_edge->weight = weight;
    return new_edge;
}

//Function to add an edge to a node in the graph
void add_edge(struct Node* node, struct Node* dest, int weight) {
    struct Edge* new_edge = create_edge(dest, weight); //Create new edge
    node->num_edges++; //Increment number of edges in node
    node->edges = realloc(node->edges, node->num_edges*sizeof(struct Edge)); //Reallocate memory for edges array
    node->edges[node->num_edges-1] = *new_edge; //Add new edge to array
}

//Function to create a new graph
struct Graph* create_graph() {
    struct Graph* new_graph = malloc(sizeof(struct Graph)); //Allocate memory for new graph
    new_graph->start = NULL;
    return new_graph;
}

//Function to add a node to a graph
void add_node(struct Graph* graph, int id) {
    struct Node* new_node = create_node(id); //Create new node
    if(graph->start == NULL) { //If graph is empty
        graph->start = new_node; //Make new node the start node
    }
    else { //If graph is not empty
        struct Node* current_node = graph->start;
        while(current_node->next != NULL) { //Traverse to end of graph
            current_node = current_node->next;
        }
        current_node->next = new_node; //Add new node to graph
    }
}

//Function to find a node in a graph
struct Node* find_node(struct Graph* graph, int id) {
    struct Node* current_node = graph->start;
    while(current_node != NULL) { //Traverse through graph
        if(current_node->id == id) { //If node with given id is found
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL; //If node with given id is not found
}

//Function to print the graph
void print_graph(struct Graph* graph) {
    struct Node* current_node = graph->start;
    while(current_node != NULL) { //Traverse through graph
        printf("Node %d: ", current_node->id);
        for(int i=0; i < current_node->num_edges; i++) { //Traverse through edges of node
            printf("(%d, %d) ", current_node->edges[i].dest->id, current_node->edges[i].weight);
        }
        printf("\n");
        current_node = current_node->next;
    }
}

//Function to perform breadth-first search in the graph
void bfs(struct Graph* graph, int start_id, int end_id) {
    struct Node* start_node = find_node(graph, start_id); //Find start node
    struct Node* end_node = find_node(graph, end_id); //Find end node
    if(start_node == NULL || end_node == NULL) { //If start or end node not found
        printf("Start or End node not found in graph\n");
        return;
    }
    int* visited = calloc(100000, sizeof(int)); //Array to store visited nodes
    int* parent = calloc(100000, sizeof(int)); //Array to store parents of nodes
    for(int i=0; i<100000; i++) { //Initialize arrays
        visited[i] = 0;
        parent[i] = -1;
    }
    visited[start_node->id] = 1; //Mark start node as visited
    struct Node** queue = malloc(100000*sizeof(struct Node*)); //Queue for BFS
    int front = 0, rear = 0;
    queue[rear++] = start_node; //Add start node to queue
    while(front != rear) { //While queue is not empty
        struct Node* current_node = queue[front++]; //Dequeue from queue
        if(current_node == end_node) { //If end node is found
            break;
        }
        for(int i=0; i < current_node->num_edges; i++) { //Traverse through edges of current node
            struct Node* next_node = current_node->edges[i].dest; //Find next node
            if(visited[next_node->id] == 0) { //If next node has not been visited
                visited[next_node->id] = 1; //Mark next node as visited
                parent[next_node->id] = current_node->id; //Set parent of next node
                queue[rear++] = next_node; //Enqueue next node
            }
        }
    }
    if(parent[end_node->id] == -1) { //If end node cannot be reached
        printf("End node cannot be reached from start node\n");
    }
    else { //If end node can be reached
        printf("Path from start node to end node:");
        int path[100000], path_index = 0;
        int current_node_id = end_node->id;
        while(current_node_id != start_node->id) { //Traverse back from end node to start node
            path[path_index++] = current_node_id;
            current_node_id = parent[current_node_id];
        }
        printf(" %d", start_node->id);
        for(int i=path_index-1; i>=0; i--) { //Print path from start node to end node
            printf("-%d", path[i]);
        }
        printf("\n");
    }
}

//Function main
int main() {
    struct Graph* graph = create_graph(); //Create graph
    add_node(graph, 1); //Add nodes to graph
    add_node(graph, 2);
    add_node(graph, 3);
    add_node(graph, 4);
    add_node(graph, 5);
    add_node(graph, 6);
    add_node(graph, 7);

    add_edge(find_node(graph,1), find_node(graph,2), 1); //Add edges to graph
    add_edge(find_node(graph,1), find_node(graph,3), 1);
    add_edge(find_node(graph,2), find_node(graph,4), 1);
    add_edge(find_node(graph,3), find_node(graph,4), 3);
    add_edge(find_node(graph,4), find_node(graph,5), 2);
    add_edge(find_node(graph,5), find_node(graph,6), 1);
    add_edge(find_node(graph,6), find_node(graph,7), 1);

    print_graph(graph); //Print graph

    bfs(graph, 1, 7); //Perform breadth-first search in graph

    return 0;
}