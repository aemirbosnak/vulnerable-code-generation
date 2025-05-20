//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct node {
    point pt;
    int cost;
    struct node *parent;
} node;

typedef struct minheap {
    node **nodes;
    int size;
    int capacity;
} minheap;

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

minheap *create_minheap(int capacity) {
    minheap *heap = (minheap *)malloc(sizeof(minheap));
    heap->nodes = (node **)malloc(sizeof(node *) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void minheapify(minheap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->nodes[left]->cost < heap->nodes[smallest]->cost) {
        smallest = left;
    }

    if (right < heap->size && heap->nodes[right]->cost < heap->nodes[smallest]->cost) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&heap->nodes[smallest], &heap->nodes[index]);
        minheapify(heap, smallest);
    }
}

node *extract_min(minheap *heap) {
    node *min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    minheapify(heap, 0);
    return min;
}

void insert_minheap(minheap *heap, node *new_node) {
    heap->size++;
    int index = heap->size - 1;
    while (index > 0 && heap->nodes[(index - 1) / 2]->cost > new_node->cost) {
        heap->nodes[index] = heap->nodes[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap->nodes[index] = new_node;
}

bool is_in_heap(minheap *heap, node *n) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->nodes[i] == n) {
            return true;
        }
    }
    return false;
}

bool is_valid(int x, int y, int width, int height) {
    return (x >= 0 && x < width) && (y >= 0 && y < height);
}

node *get_neighbor(int x, int y, int width, int height, int **grid) {
    if (!is_valid(x, y, width, height)) {
        return NULL;
    }

    node *n = (node *)malloc(sizeof(node));
    n->pt.x = x;
    n->pt.y = y;
    n->cost = grid[y][x];
    n->parent = NULL;
    return n;
}

int manhattan_distance(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool astar(int **grid, int width, int height, point start, point end, node **path) {
    minheap *open_set = create_minheap(width * height);
    node *start_node = get_neighbor(start.x, start.y, width, height, grid);
    start_node->cost = 0;
    insert_minheap(open_set, start_node);

    while (open_set->size > 0) {
        node *current = extract_min(open_set);

        if (current->pt.x == end.x && current->pt.y == end.y) {
            *path = current;
            return true;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                node *neighbor = get_neighbor(current->pt.x + i, current->pt.y + j, width, height, grid);
                if (neighbor && !is_in_heap(open_set, neighbor)) {
                    neighbor->parent = current;
                    neighbor->cost = current->cost + neighbor->cost;
                    insert_minheap(open_set, neighbor);
                }
            }
        }
    }

    return false;
}

void print_path(node *path) {
    if (!path) {
        return;
    }

    printf("Path: ");
    while (path) {
        printf("(%d, %d) -> ", path->pt.x, path->pt.y);
        path = path->parent;
    }
    printf("END\n");
}

int main() {
    int width = 5;
    int height = 5;
    int grid[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1},
    };

    point start = {1, 1};
    point end = {3, 3};
    node *path = NULL;

    if (astar(grid, width, height, start, end, &path)) {
        print_path(path);
    } else {
        printf("No path found\n");
    }

    return 0;
}