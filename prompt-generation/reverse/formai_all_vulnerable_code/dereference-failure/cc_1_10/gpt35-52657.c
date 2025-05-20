//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// define a struct to represent a node in the graph
typedef struct node
{
    int x, y; // coordinates of the node
    int f, g, h; // pathfinding parameters
    bool is_obstacle; // boolean flag for obstacles
    struct node* parent; // reference to the parent node

} Node;

// define a struct to represent the graph
typedef struct graph
{
    Node* map[ROWS][COLS];
} Graph;

// define a struct to represent a priority queue
typedef struct priority_queue
{
    int size;
    Node** heap;
} PriorityQueue;

/**
 * Helper function for priority queue heap operations
 */
void swap(Node** a, Node** b)
{
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Helper function to initialize the priority queue
 */
PriorityQueue* create_priority_queue()
{
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->heap = malloc(sizeof(Node*) * (ROWS * COLS));
    return pq;
}

/**
 * Helper function to add a node to the priority queue
 */
void push_priority_queue(PriorityQueue* pq, Node* node)
{
    // insert the node at the end of the heap
    pq->heap[pq->size] = node;
    pq->size++;

    // adjust the heap to maintain the max-heap property
    int i = pq->size - 1;
    while (i > 0 && pq->heap[i]->f < pq->heap[(i - 1) / 2]->f)
    {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * Helper function to remove and return the minimum node from the priority queue
 */
Node* pop_priority_queue(PriorityQueue* pq)
{
    if (pq->size == 0)
    {
        return NULL;
    }
    // remove the root node and store it in a temporary variable
    Node* result = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    // adjust the heap to maintain the max-heap property
    int i = 0;
    while ((2 * i + 1) < pq->size)
    {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int min_child = (right_child >= pq->size || pq->heap[left_child]->f < pq->heap[right_child]->f) ? left_child : right_child;
        if (pq->heap[i]->f >= pq->heap[min_child]->f)
        {
            swap(&pq->heap[i], &pq->heap[min_child]);
            i = min_child;
        }
        else
        {
            break;
        }
    }
    // return the removed node
    return result;
}

/**
 * Helper function to calculate the Manhattan distance between two nodes
 */
int calculate_manhattan_distance(Node* node_a, Node* node_b)
{
    return abs(node_a->x - node_b->x) + abs(node_a->y - node_b->y);
}

/**
 * Main function to run the A* pathfinding algorithm
 */
void run_a_star_algorithm(Graph* graph, Node* start_node, Node* end_node)
{
    // initialize the open and closed sets
    PriorityQueue* open_set = create_priority_queue();
    bool closed_set[ROWS][COLS] = { false };

    // add the start node to the open set
    start_node->g = 0;
    start_node->h = calculate_manhattan_distance(start_node, end_node);
    start_node->f = start_node->g + start_node->h;
    push_priority_queue(open_set, start_node);

    // loop until the open set is empty or the end node is found
    while (open_set->size > 0) 
    {
        // get the node with the lowest f value from the open set
        Node* current_node = pop_priority_queue(open_set);

        // if the current node is the end node, we're done!
        if (current_node == end_node) 
        {
            printf("\n\nCongratulations! You have reached the destination!\n");
            return;
        }

        // add the current node to the closed set
        closed_set[current_node->x][current_node->y] = true;

        // get all the neighbors of the current node
        Node* neighbors[8] = {
            current_node->x > 0 ? graph->map[current_node->x - 1][current_node->y] : NULL, // left
            current_node->y > 0 ? graph->map[current_node->x][current_node->y - 1] : NULL, // down
            current_node->x < ROWS - 1 ? graph->map[current_node->x + 1][current_node->y] : NULL, // right
            current_node->y < COLS - 1 ? graph->map[current_node->x][current_node->y + 1] : NULL, // up
            current_node->x > 0 && current_node->y > 0 ? graph->map[current_node->x - 1][current_node->y - 1] : NULL, // bottom left
            current_node->x > 0 && current_node->y < COLS - 1 ? graph->map[current_node->x - 1][current_node->y + 1] : NULL, // top left
            current_node->x < ROWS - 1 && current_node->y > 0 ? graph->map[current_node->x + 1][current_node->y - 1] : NULL, // bottom right
            current_node->x < ROWS - 1 && current_node->y < COLS - 1 ? graph->map[current_node->x + 1][current_node->y + 1] : NULL // top right
        };

        // process the current node's neighbors
        for (int i = 0; i < 8; i++)
        {
            Node* neighbor = neighbors[i];
            if (neighbor != NULL && !closed_set[neighbor->x][neighbor->y] && !neighbor->is_obstacle)
            {
                // calculate the tentative G score for the neighbor
                int tentative_g_score = current_node->g + calculate_manhattan_distance(current_node, neighbor);

                // if the neighbor is not in the open set, add it
                if (!(neighbor->f > 0))
                {
                    neighbor->g = tentative_g_score;
                    neighbor->h = calculate_manhattan_distance(neighbor, end_node);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current_node;
                    push_priority_queue(open_set, neighbor);
                }
                // if the tentative G score is lower than the neighbor's current G score, update it
                else if (tentative_g_score < neighbor->g)
                {
                    neighbor->g = tentative_g_score;
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current_node;
                }
            }
        }
    }
    // without finding the end node, means a path is not found
    printf("\n\nUnable to reach destination. Please try again with different coordinates or different obstacles!\n");
}

/**
 * Helper function to initialize the graph with obstacles
 */
void initialize_graph(Graph* graph)
{
    // initialize all nodes as walkable
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            Node* node = malloc(sizeof(Node));
            node->x = i;
            node->y = j;
            node->is_obstacle = false;
            node->parent = NULL;
            node->f = 0;
            node->g = 0;
            node->h = 0;
            graph->map[i][j] = node;
        }
    }
    
    // add some obstacles
    graph->map[3][2]->is_obstacle = true;
    graph->map[3][3]->is_obstacle = true;
    graph->map[3][4]->is_obstacle = true;
    graph->map[3][5]->is_obstacle = true;
    graph->map[4][5]->is_obstacle = true;
    graph->map[5][5]->is_obstacle = true;
    graph->map[6][5]->is_obstacle = true;
    graph->map[7][5]->is_obstacle = true;
    graph->map[7][4]->is_obstacle = true;
}

int main()
{
    Graph graph;
    initialize_graph(&graph);

    int start_x, start_y, end_x, end_y;
    printf("Welcome to A* pathfinding algorithm\n");
    printf("You will plan a path with numbers ranging from 0 to 9 with (0, 0) being the first cell\n");
    printf("Enter the starting point coordinates:\n");
    scanf("%d%d", &start_x, &start_y);
    printf("Enter the destination point coordinates:\n");
    scanf("%d%d", &end_x, &end_y);
    
    // check if start and end points are valid
    if (start_x < 0 || start_x >= ROWS || start_y < 0 || start_y >= COLS || end_x < 0 || end_x >= ROWS || end_y < 0 || end_y >= COLS)
    {
        printf("\n\nInvalid coordinates. Please try again with numbers ranging from 0 to 9 with (0, 0) being the first cell\n");
        return 0;
    }

    Node* start_node = graph.map[start_x][start_y];
    Node* end_node = graph.map[end_x][end_y];

    // check if start and end nodes are obstacles
    if (start_node->is_obstacle || end_node->is_obstacle) 
    {
        printf("\n\nStarting point and/or destination point is an obstacle. Please try again with different coordinates\n");
        return 0;
    }

    run_a_star_algorithm(&graph, start_node, end_node);

    return 0;
}