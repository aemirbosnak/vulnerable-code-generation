//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

#define EMPTY 0
#define WALL 1
#define VISITED 2

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* generateMaze(int w, int h) {
    srand(time(NULL));
    int x, y, n = 0;
    Node* head = NULL;
    while (n < w * h) {
        x = rand() % w;
        y = rand() % h;
        if (head == NULL || x != head->x || y != head->y) {
            head = malloc(sizeof(Node));
            head->x = x;
            head->y = y;
            head->next = NULL;
            n++;
        }
    }
    return head;
}

void drawMaze(Node* head) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (head != NULL && head->x == x && head->y == y) {
                printf("O ");
            } else if (x == 0 || y == 0) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node* head = generateMaze(WIDTH, HEIGHT);
    drawMaze(head);
    return 0;
}