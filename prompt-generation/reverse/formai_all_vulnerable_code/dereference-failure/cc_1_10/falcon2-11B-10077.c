//Falcon2-11B DATASET v1.0 Category: Image Classification system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} rectangle;

typedef struct {
    char* name;
    float width;
    float height;
    point top_left;
    point bottom_right;
    rectangle bounding_box;
} image;

image load_image(char* filename) {
    // Load the image from the file and convert it to grayscale
    image img;
    img.name = (char*)malloc(strlen(filename) + 1);
    strcpy(img.name, filename);
    img.width = 0;
    img.height = 0;
    img.top_left.x = 0;
    img.top_left.y = 0;
    img.bottom_right.x = 0;
    img.bottom_right.y = 0;
    img.bounding_box.x1 = 0;
    img.bounding_box.y1 = 0;
    img.bounding_box.x2 = 0;
    img.bounding_box.y2 = 0;
    img.width = img.height = 0;
    return img;
}

int main() {
    // Load an image
    image img = load_image("image.jpg");
    printf("Image name: %s\n", img.name);
    printf("Image width: %d\n", img.width);
    printf("Image height: %d\n", img.height);
    printf("Top-left point: (%f, %f)\n", img.top_left.x, img.top_left.y);
    printf("Bottom-right point: (%f, %f)\n", img.bottom_right.x, img.bottom_right.y);
    printf("Bounding box: (%d, %d) - (%d, %d)\n", img.bounding_box.x1, img.bounding_box.y1, img.bounding_box.x2, img.bounding_box.y2);
    return 0;
}