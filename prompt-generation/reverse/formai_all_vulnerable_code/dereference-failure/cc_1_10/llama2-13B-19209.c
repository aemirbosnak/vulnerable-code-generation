//LLAMA2-13B DATASET v1.0 Category: Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_INT 2147483647

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

typedef struct {
    Line l1;
    Line l2;
} Shape;

Shape* createShape(void) {
    Shape* shape = malloc(sizeof(Shape));
    shape->l1.p1.x = 0;
    shape->l1.p1.y = 0;
    shape->l1.p2.x = 10;
    shape->l1.p2.y = 10;
    shape->l2.p1.x = 10;
    shape->l2.p1.y = 10;
    shape->l2.p2.x = 20;
    shape->l2.p2.y = 20;
    return shape;
}

void drawShape(Shape* shape) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == j) {
                continue;
            }
            printf("%d ", shape->l1.p1.x + x + j * (shape->l1.p2.x - shape->l1.p1.x) / 2);
            printf("%d ", shape->l1.p1.y + y + j * (shape->l1.p2.y - shape->l1.p1.y) / 2);
            printf("---------\n");
        }
        x += 10;
        y = 0;
    }
}

int main() {
    srand(time(NULL));
    Shape* shape = createShape();
    drawShape(shape);
    free(shape);
    return 0;
}