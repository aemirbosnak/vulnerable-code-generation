//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int **field;
    int width;
    int height;
} Field;

Field *new_field(int width, int height) {
    Field *field = malloc(sizeof(Field));
    field->field = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        field->field[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            field->field[i][j] = 0;
        }
    }
    field->width = width;
    field->height = height;
    return field;
}

void free_field(Field *field) {
    for (int i = 0; i < field->height; i++) {
        free(field->field[i]);
    }
    free(field->field);
    free(field);
}

void draw_filled_rectangle(Field *field, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            field->field[j][i] = 1;
        }
    }
}

void draw_hollow_rectangle(Field *field, int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        field->field[y1][i] = 1;
        field->field[y2][i] = 1;
    }
    for (int j = y1 + 1; j < y2; j++) {
        field->field[j][x1] = 1;
        field->field[j][x2] = 1;
    }
}

void print_field(Field *field) {
    for (int i = 0; i < field->height; i++) {
        for (int j = 0; j < field->width; j++) {
            printf("%d", field->field[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0) {
        printf("Error: Width and height must be positive integers.\n");
        return 1;
    }

    Field *field = new_field(width, height);

    draw_filled_rectangle(field, 0, 0, width - 1, height - 1);
    draw_hollow_rectangle(field, 10, 5, 20, 10);

    print_field(field);

    free_field(field);

    return 0;
}