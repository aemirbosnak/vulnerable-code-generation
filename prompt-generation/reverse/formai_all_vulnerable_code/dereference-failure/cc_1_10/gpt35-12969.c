//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Struct for the nodes of the graph
typedef struct node_t
{
    int value;
    struct node_t** neighbours;
    int num_neighbours;
} node;

// Struct for the queue used in BFS
typedef struct queue_t
{
    node** nodes;
    int front;
    int rear;
} queue;

// Function to create a new node with a given value
node* createNode(int value)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->value = value;
    newNode->neighbours = NULL;
    newNode->num_neighbours = 0;
    return newNode;
}

// Function to add an edge between two nodes
void addEdge(node* first, node* second)
{
    first->num_neighbours++;
    first->neighbours = (node**) realloc(first->neighbours, 
                               sizeof(node*) * first->num_neighbours);
    first->neighbours[first->num_neighbours-1] = second;
}

// Function to print the path from the source to the destination
void printPath(int* path, int pathLength)
{
    printf("Path: ");
    for(int i=0; i<pathLength; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

// Function to perform BFS on the graph
int* BFS(node* source, node* dest, int* pathLength)
{
    // Create a queue and enqueue the source node
    queue* q = (queue*) malloc(sizeof(queue));
    q->nodes = (node**) malloc(sizeof(node*) * 100);
    q->front = -1;
    q->rear = -1;
    q->nodes[++q->rear] = source;
    
    // Array to keep track of visited nodes
    int* visited = (int*) calloc(100, sizeof(int));
    
    // Array to keep track of the path
    int* path = (int*) malloc(sizeof(int) * 100);
    int index = 0;
    
    // Perform BFS
    while(q->front != q->rear)
    {
        // Dequeue a node from the queue
        node* current = q->nodes[++q->front];
        
        // If the node is the destination, we have found the path
        if(current == dest)
        {
            *pathLength = index;
            return path;
        }
        
        // Mark the node as visited
        visited[current->value] = 1;
        
        // Enqueue all unvisited neighbours of the current node
        for(int i=0; i<current->num_neighbours; i++)
        {
            node* neighbour = current->neighbours[i];
            if(!visited[neighbour->value])
            {
                q->nodes[++q->rear] = neighbour;
                visited[neighbour->value] = 1;
                
                // Add the neighbour to the path
                path[index++] = neighbour->value;
            }
        }
    }
    
    printf("No path found!\n");
    return NULL;
}

int main()
{
    // Create the graph
    node* zero = createNode(0);
    node* one = createNode(1);
    node* two = createNode(2);
    node* three = createNode(3);
    node* four = createNode(4);
    
    addEdge(zero, one);
    addEdge(zero, two);
    addEdge(one, three);
    addEdge(two, three);
    addEdge(three, four);
    
    // Find the shortest path between nodes 0 and 4
    int pathLength;
    int* path = BFS(zero, four, &pathLength);
    if(path)
    {
        printPath(path, pathLength);
    }
    
    return 0;
}