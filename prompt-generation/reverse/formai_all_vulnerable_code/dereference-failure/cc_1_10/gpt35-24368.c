//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int x, y;
    int g; // Cost to reach this node from start
    int h; // Estimated cost to reach goal from this node
    int f; // g + h
    struct node* parent;
} Node;

// Heap implementation
typedef struct heap {
    Node** arr;
    int size;
} Heap;

Node* create_node(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = NULL;
    return node;
}

// Calculate Euclidean distance between two nodes
int calculate_distance(Node* a, Node* b) {
    int dx = abs(a->x - b->x);
    int dy = abs(a->y - b->y);
    return (int)sqrt(dx*dx + dy*dy);
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

Heap* create_heap(int capacity) {
    Heap* heap = malloc(sizeof(Heap));
    heap->arr = malloc(sizeof(Node*) * (capacity+1));
    heap->size = 0;
    return heap;
}

void heapify_up(Heap* heap, int index) {
    if (index == 1) return;
    int parent = index / 2;
    if (heap->arr[parent]->f > heap->arr[index]->f) {
        swap(&heap->arr[parent], &heap->arr[index]);
        heapify_up(heap, parent);
    }
}

void heapify_down(Heap* heap, int index) {
    int left = index * 2;
    int right = index * 2 + 1;
    int smallest = index;
    if (left <= heap->size && heap->arr[left]->f < heap->arr[smallest]->f) {
        smallest = left;
    }
    if (right <= heap->size && heap->arr[right]->f < heap->arr[smallest]->f) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapify_down(heap, smallest);
    }
}

void add_to_heap(Heap* heap, Node* node) {
    heap->size++;
    heap->arr[heap->size] = node;
    heapify_up(heap, heap->size);
}

Node* remove_from_heap(Heap* heap) {
    if (heap->size == 0) return NULL;
    Node* node = heap->arr[1];
    heap->arr[1] = heap->arr[heap->size];
    heap->size--;
    heapify_down(heap, 1);
    return node;
}

void free_heap(Heap* heap) {
    for (int i = 1; i <= heap->size; i++) {
        free(heap->arr[i]);
    }
    free(heap->arr);
    free(heap);
}

// Check if node is within bounds of the grid and is not blocked
int is_valid_node(int x, int y, int grid[ROWS][COLS]) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return 0;
    if (grid[x][y] == 1) return 0;
    return 1;
}

Node* find_path(int start_x, int start_y, int goal_x, int goal_y, int grid[ROWS][COLS]) {
    // Initialize start and goal nodes
    Node* start = create_node(start_x, start_y);
    Node* goal = create_node(goal_x, goal_y);
    // Initialize closed list
    int closed[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            closed[i][j] = 0;
        }
    }
    // Initialize open list heap
    Heap* open = create_heap(ROWS*COLS);
    add_to_heap(open, start);
    // Loop until goal node is found or open list is empty
    while (open->size > 0) {
        Node* current = remove_from_heap(open);
        if (current->x == goal->x && current->y == goal->y) {
            free_heap(open);
            return current; // Path found!
        }
        closed[current->x][current->y] = 1;
        // Check neighbors and add to open list if valid
        for (int x_offset = -1; x_offset <= 1; x_offset++) {
            for (int y_offset = -1; y_offset <= 1; y_offset++) {
                int x = current->x + x_offset;
                int y = current->y + y_offset;
                if (is_valid_node(x, y, grid) && closed[x][y] == 0) {
                    Node* neighbor = create_node(x, y);
                    neighbor->parent = current;
                    neighbor->g = current->g + calculate_distance(current, neighbor);
                    neighbor->h = calculate_distance(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;
                    add_to_heap(open, neighbor);
                }
            }
        }
    }
    free_heap(open);
    return NULL; // No path found :(
}

int main() {
    int grid[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Node* path = find_path(0, 0, 9, 9, grid);
    if (path == NULL) {
        printf("No path found :(\n");
    } else {
        Node* current = path;
        while (current != NULL) {
            printf("(%d, %d)\n", current->x, current->y);
            current = current->parent;
        }
    }
    return 0;
}