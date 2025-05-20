//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/~`"

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Shape;

void generate_random_shape(Shape *shape, int num_points) {
    shape->points = (Point *) malloc(sizeof(Point) * num_points);
    shape->num_points = num_points;

    for (int i = 0; i < num_points; i++) {
        shape->points[i].x = rand() % MAX_WIDTH;
        shape->points[i].y = rand() % MAX_HEIGHT;
    }
}

int is_valid_char(char c) {
    for (int i = 0; i < strlen(CHAR_SET); i++) {
        if (CHAR_SET[i] == c) {
            return 1;
        }
    }
    return 0;
}

void print_shape(Shape *shape) {
    for (int i = 0; i < shape->num_points; i++) {
        printf("%c", CHAR_SET[shape->points[i].y * MAX_WIDTH + shape->points[i].x]);
    }
}

int main() {
    int width, height;
    char *image_data;
    Shape shape;

    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    image_data = (char *) malloc(sizeof(char) * width * height);

    if (fread(image_data, sizeof(char), width * height, stdin)!= width * height) {
        printf("Error reading image data.\n");
        return 1;
    }

    generate_random_shape(&shape, 100);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (is_valid_char(image_data[i * width + j])) {
                shape.points[0].x = j;
                shape.points[0].y = i;
                print_shape(&shape);
            }
        }
    }

    free(image_data);
    return 0;
}