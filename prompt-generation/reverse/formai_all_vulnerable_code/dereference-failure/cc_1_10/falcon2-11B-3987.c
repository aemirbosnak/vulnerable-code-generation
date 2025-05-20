//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
    bool visited[10][10];
} Grid;

typedef struct {
    Coordinate cell;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

bool is_valid_cell(Grid *grid, Coordinate cell) {
    return cell.x >= 0 && cell.x < grid->start.x && cell.y >= 0 && cell.y < grid->start.y;
}

void print_path(Queue *queue) {
    Node *node = queue->front;
    while (node!= NULL) {
        printf("%d,%d ", node->cell.x, node->cell.y);
        node = node->next;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int grid_size = 10;
    Grid grid = {
       .start = {.x = rand() % grid_size,.y = rand() % grid_size},
       .end = {.x = rand() % grid_size,.y = rand() % grid_size}
    };

    Queue queue = {
       .front = NULL,
       .rear = NULL,
       .size = 0
    };

    Node *current_node = malloc(sizeof(Node));
    current_node->cell = grid.start;
    current_node->next = NULL;
    queue.front = current_node;
    queue.rear = current_node;
    queue.size = 1;

    grid.visited[grid.start.x][grid.start.y] = true;

    while (true) {
        if (grid.visited[grid.end.x][grid.end.y]) {
            print_path(&queue);
            break;
        }

        Node *next_node = malloc(sizeof(Node));
        next_node->cell = grid.end;
        next_node->next = NULL;

        if (queue.front == NULL) {
            queue.rear = next_node;
        } else {
            queue.front->next = next_node;
        }

        queue.front = next_node;
        queue.rear = next_node;
        queue.size++;

        grid.visited[grid.end.x][grid.end.y] = true;

        if (queue.size > grid_size * grid_size) {
            break;
        }
    }

    return 0;
}