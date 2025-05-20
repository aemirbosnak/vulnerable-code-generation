//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Shape {
    int type;
    int x;
    int y;
    struct Shape* next;
} Shape;

Shape* insertShape(Shape* head, int type, int x, int y) {
    Shape* newShape = (Shape*)malloc(sizeof(Shape));
    newShape->type = type;
    newShape->x = x;
    newShape->y = y;
    newShape->next = NULL;

    if (head == NULL) {
        head = newShape;
    } else {
        head->next = newShape;
    }

    return head;
}

void drawShapes(Shape* head) {
    while (head) {
        switch (head->type) {
            case 1:
                printf("Draw a circle at (%d, %d)\n", head->x, head->y);
                break;
            case 2:
                printf("Draw a rectangle at (%d, %d), (%d, %d)\n", head->x, head->y, head->x + MAX_SIZE, head->y + MAX_SIZE);
                break;
            case 3:
                printf("Draw a triangle at (%d, %d), (%d, %d), (%d, %d)\n", head->x, head->y, head->x + MAX_SIZE, head->y, head->x + MAX_SIZE / 2, head->y + MAX_SIZE);
                break;
            default:
                printf("Invalid shape type\n");
                break;
        }
        head = head->next;
    }
}

int main() {
    Shape* head = NULL;

    insertShape(head, 1, 10, 10);
    insertShape(head, 2, 20, 20);
    insertShape(head, 3, 30, 30);

    drawShapes(head);

    return 0;
}