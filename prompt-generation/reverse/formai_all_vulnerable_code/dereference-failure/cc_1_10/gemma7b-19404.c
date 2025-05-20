//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* CreateNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void GenerateMaze(Node* start) {
    srand(time(NULL));
    int w, h, x, y, r, direction;
    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    start->x = rand() % w;
    start->y = rand() % h;

    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            r = rand() % 10;
            if (r < 5) {
                Node* newNode = CreateNode(x, y);
                newNode->next = start;
                start = newNode;
            }
        }
    }

    direction = rand() % 4;
    switch (direction) {
        case 0:
            start->next = CreateNode(start->x - 1, start->y);
            break;
        case 1:
            start->next = CreateNode(start->x + 1, start->y);
            break;
        case 2:
            start->next = CreateNode(start->x, start->y - 1);
            break;
        case 3:
            start->next = CreateNode(start->x, start->y + 1);
            break;
    }
}

int main() {
    Node* start = CreateNode(0, 0);
    GenerateMaze(start);
    return 0;
}