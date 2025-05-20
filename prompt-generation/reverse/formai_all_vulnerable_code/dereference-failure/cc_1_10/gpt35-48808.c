//FormAI DATASET v1.0 Category: Fractal Generation ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

const int WIDTH = 800;
const int HEIGHT = 800;

void generateFractal(int x, int y, int size, int depth, unsigned char* imageData) {
    if (depth == 0) {
        return;
    }
    
    int subSize = size / 3;
    int startX = x + subSize;
    int startY = y + subSize;
    
    for (int i = startX - subSize; i < startX + subSize; i++) {
        for (int j = startY - subSize; j < startY + subSize; j++) {
            int offset = i + j * WIDTH;
            if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGHT && offset < WIDTH * HEIGHT) {
                imageData[offset] = 255 - depth * 20;
            }
        }
    }
    
    generateFractal(x, y, subSize, depth - 1, imageData);
    generateFractal(x + subSize, y, subSize, depth - 1, imageData);
    generateFractal(x + 2 * subSize, y, subSize, depth - 1, imageData);
    generateFractal(x, y + subSize, subSize, depth - 1, imageData);
    generateFractal(x + 2 * subSize, y + subSize, subSize, depth - 1, imageData);
    generateFractal(x, y + 2 * subSize, subSize, depth - 1, imageData);
    generateFractal(x + subSize, y + 2 * subSize, subSize, depth - 1, imageData);
    generateFractal(x + 2 * subSize, y + 2 * subSize, subSize, depth - 1, imageData);
}

int main() {
    unsigned char* imageData = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        imageData[i] = 0;
    }
    
    generateFractal(0, 0, WIDTH, 10, imageData);
    
    FILE *fp;
    char filename[] = "fractal.pgm";
    fp = fopen(filename, "wb");
    fprintf(fp, "P2\n%d %d\n255\n", WIDTH, HEIGHT);
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", imageData[j + i * WIDTH]);
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    free(imageData);
    
    printf("Fractal generated successfully!\n");
    
    return 0;
}