//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Graph structure
typedef struct Graph {
    int num_vertices;
    int num_edges;
    Node **adj_list;
} Graph;

// Queue structure
typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

// Mutex for thread safety
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new graph
Graph *create_graph(int num_vertices) {
    Graph *new_graph = (Graph *)malloc(sizeof(Graph));
    new_graph->num_vertices = num_vertices;
    new_graph->num_edges = 0;
    new_graph->adj_list = (Node **)malloc(num_vertices * sizeof(Node *));
    for (int i = 0; i < num_vertices; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int src, int dest) {
    // Check if the vertices are valid
    if (src < 0 || src >= graph->num_vertices || dest < 0 || dest >= graph->num_vertices) {
        printf("Error: Invalid vertex.\n");
        return;
    }

    // Create a new node for the destination vertex
    Node *new_node = create_node(dest);

    // Add the new node to the adjacency list of the source vertex
    pthread_mutex_lock(&mutex);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
    graph->num_edges++;
    pthread_mutex_unlock(&mutex);
}

// Function to create a new queue
Queue *create_queue() {
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    new_queue->head = NULL;
    new_queue->tail = NULL;
    return new_queue;
}

// Function to enqueue a node into the queue
void enqueue(Queue *queue, Node *node) {
    pthread_mutex_lock(&mutex);
    if (queue->tail == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
    pthread_mutex_unlock(&mutex);
}

// Function to dequeue a node from the queue
Node *dequeue(Queue *queue) {
    pthread_mutex_lock(&mutex);
    if (queue->head == NULL) {
        return NULL;
    } else {
        Node *temp = queue->head;
        queue->head = queue->head->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        pthread_mutex_unlock(&mutex);
        return temp;
    }
}

// Function to perform breadth-first search on the graph
void bfs(Graph *graph, int start_vertex) {
    // Check if the vertex is valid
    if (start_vertex < 0 || start_vertex >= graph->num_vertices) {
        printf("Error: Invalid vertex.\n");
        return;
    }

    // Create a queue for visited vertices
    Queue *visited_queue = create_queue();

    // Mark the start vertex as visited
    enqueue(visited_queue, create_node(start_vertex));

    // While the queue is not empty
    while (visited_queue->head != NULL) {
        // Dequeue the next vertex from the queue
        Node *current_node = dequeue(visited_queue);

        // Print the vertex
        printf("%d ", current_node->data);

        // For each adjacent vertex
        for (Node *adj_node = graph->adj_list[current_node->data]; adj_node != NULL; adj_node = adj_node->next) {
            // If the adjacent vertex has not been visited
            if (!is_visited(visited_queue, adj_node->data)) {
                // Mark the adjacent vertex as visited
                enqueue(visited_queue, create_node(adj_node->data));
            }
        }
    }

    // Free the visited queue
    free(visited_queue);
}

// Function to check if a vertex has been visited
int is_visited(Queue *queue, int vertex) {
    for (Node *node = queue->head; node != NULL; node = node->next) {
        if (node->data == vertex) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create a graph
    Graph *graph = create_graph(6);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 4, 5);

    // Perform breadth-first search on the graph
    bfs(graph, 0);

    // Free the graph
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *node = graph->adj_list[i];
        while (node != NULL) {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(graph);

    return 0;
}