//LLAMA2-13B DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_SHAPES 5
#define MAX_SIZE 100

typedef struct shape {
    char name[20];
    int x, y, w, h;
} shape_t;

shape_t shapes[] = {
    {"square", 10, 10, 50, 50},
    {"circle", 20, 20, 30, 30},
    {"triangle", 30, 30, 40, 50},
    {"rectangle", 40, 40, 60, 80},
    {"rhombus", 50, 50, 70, 90}
};

int main() {
    int i, j, shape_index;
    shape_t current_shape;

    srand(time(NULL));

    printf("Welcome to Shape Shifter!\n");

    while (1) {
        // Generate a random shape index
        shape_index = rand() % (sizeof(shapes) / sizeof(shapes[0]));

        // Print the current shape
        printf("Current shape: %s (%d, %d, %d, %d)\n", shapes[shape_index].name,
            shapes[shape_index].x, shapes[shape_index].y, shapes[shape_index].w, shapes[shape_index].h);

        // Get the user's input to change the shape
        printf("Enter a new shape (1-5 or 'q' to quit): ");
        scanf("%d", &i);

        // Check for invalid input
        if (i < 1 || i > MAX_SHAPES || i == 'q') {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // Calculate the new shape's size based on the user's input
        switch (i) {
            case 1:
                current_shape.w = 10 + (rand() % 20);
                current_shape.h = 10 + (rand() % 20);
                break;
            case 2:
                current_shape.w = 30 + (rand() % 20);
                current_shape.h = 30 + (rand() % 20);
                break;
            case 3:
                current_shape.w = 40 + (rand() % 20);
                current_shape.h = 50 + (rand() % 20);
                break;
            case 4:
                current_shape.w = 60 + (rand() % 20);
                current_shape.h = 80 + (rand() % 20);
                break;
            case 5:
                current_shape.w = 70 + (rand() % 20);
                current_shape.h = 90 + (rand() % 20);
                break;
            default:
                printf("Invalid input. Try again.\n");
                continue;
        }

        // Update the current shape
        strcpy(current_shape.name, shapes[i].name);
        current_shape.x = shapes[i].x;
        current_shape.y = shapes[i].y;

        // Print the updated shape
        printf("Current shape: %s (%d, %d, %d, %d)\n", current_shape.name,
            current_shape.x, current_shape.y, current_shape.w, current_shape.h);
    }

    return 0;
}