//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: grateful
// Grateful Image Editor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    char *name;
    int x, y, w, h;
} image_t;

image_t images[10];
int cur_image = 0;

void load_image(char *file_name) {
    FILE *fp = fopen(file_name, "r");
    char line[1024];
    int x, y, w, h;

    fgets(line, 1024, fp); // skip first line
    sscanf(line, "%d %d %d %d", &x, &y, &w, &h);
    images[cur_image].name = strdup(file_name);
    images[cur_image].x = x;
    images[cur_image].y = y;
    images[cur_image].w = w;
    images[cur_image].h = h;
    cur_image++;
}

void draw_image(int x, int y) {
    int i = 0;
    for (; i < cur_image; i++) {
        if (images[i].x <= x && x <= images[i].x + images[i].w &&
                images[i].y <= y && y <= images[i].y + images[i].h) {
            break;
        }
    }
    if (i == cur_image) {
        printf("Image not found\n");
        return;
    }
    printf("Found image %s at (%d, %d)\n", images[i].name, x, y);
}

int main() {
    int x, y, w, h;
    char file_name[1024];

    printf("Welcome to the Grateful Image Editor\n");

    while (1) {
        printf("Please enter a file name: ");
        fgets(file_name, 1024, stdin);
        load_image(file_name);

        printf("Now, please enter the coordinates where you want to draw the image (x, y): ");
        scanf("%d %d", &x, &y);
        draw_image(x, y);
    }

    return 0;
}