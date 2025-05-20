//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define NUM_WATERMARKS 3

typedef struct {
    int x, y;
    char message[64];
    int length;
} Watermark;

void apply_watermark(unsigned char* image, int width, int height, Watermark* watermark) {
    int x = watermark->x;
    int y = watermark->y;
    int length = watermark->length;
    for (int i = 0; i < length; i++) {
        int pixel = (int)image[(y * width + x) * 3 + 0] + (int)watermark->message[i] - 'A';
        image[(y * width + x) * 3 + 0] = pixel % 256;
    }
}

int main() {
    unsigned char* image = malloc(WIDTH * HEIGHT * 3);
    memset(image, 0, WIDTH * HEIGHT * 3);

    Watermark watermarks[NUM_WATERMARKS] = {
        {10, 10, "Hello", 5},
        {WIDTH - 10, HEIGHT - 10, "World", 6},
        {10, HEIGHT - 10, "Digital", 7}
    };

    for (int i = 0; i < NUM_WATERMARKS; i++) {
        apply_watermark(image, WIDTH, HEIGHT, &watermarks[i]);
    }

    FILE* fp = fopen("watermarked.bmp", "wb");
    if (!fp) {
        printf("Could not open file!\n");
        return 1;
    }

    fwrite(image, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    printf("Watermarking completed successfully!\n");
    return 0;
}