//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_CHAR 256

typedef struct {
    int x, y;
    char ch;
    int flag;
} Point;

Point *image;

void init() {
    image = (Point *)malloc(WIDTH * HEIGHT * sizeof(Point));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].x = rand() % WIDTH;
        image[i].y = rand() % HEIGHT;
        image[i].ch = rand() % MAX_CHAR;
        image[i].flag = 0;
    }
}

void print_image() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", image[i].ch);
    }
    printf("\n");
}

void embed_watermark(char *watermark) {
    int watermark_size = strlen(watermark);
    for (int i = 0; i < watermark_size; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (image[y * WIDTH + x].flag) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        image[y * WIDTH + x].ch = watermark[i];
        image[y * WIDTH + x].flag = 1;
    }
}

void extract_watermark(char *watermark) {
    int watermark_size = strlen(watermark);
    for (int i = 0; i < watermark_size; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (image[y * WIDTH + x].flag!= 1 || image[y * WIDTH + x].ch!= watermark[i]) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        image[y * WIDTH + x].flag = 0;
    }
}

int main() {
    init();
    print_image();
    char watermark[MAX_CHAR] = "This is a secret message";
    embed_watermark(watermark);
    print_image();
    char extracted_watermark[MAX_CHAR] = {0};
    extract_watermark(extracted_watermark);
    printf("Extracted watermark: %s\n", extracted_watermark);
    return 0;
}