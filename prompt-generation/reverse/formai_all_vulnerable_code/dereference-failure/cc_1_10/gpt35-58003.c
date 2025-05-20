//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
/* Ada Lovelace Fractal Generation Example */

#include<stdio.h>
#include<stdlib.h>

#define WIDTH 50
#define HEIGHT 50

void createFractal(int **arr, int width, int height, int cx, int cy, int size);

int main() {
    int **fractal;
    int i,j;
    
    fractal = (int**)malloc(sizeof(int*) * HEIGHT);
    for(i=0; i<HEIGHT; i++) {
        fractal[i] = (int*)malloc(sizeof(int) * WIDTH);
    }
    
    createFractal(fractal, WIDTH, HEIGHT, WIDTH/2, HEIGHT/2, WIDTH/2);
    
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            if(fractal[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    for(i=0; i<HEIGHT; i++) {
        free(fractal[i]);
    }
    free(fractal);
    
    return 0;
}

void createFractal(int **arr, int width, int height, int cx, int cy, int size) {
    int i,j;
    
    if(size == 1) {
        arr[cy][cx] = 1;
        return;
    }
    
    createFractal(arr, width, height, cx-size/2, cy-size/2, size/2);
    createFractal(arr, width, height, cx+size/2, cy-size/2, size/2);
    createFractal(arr, width, height, cx-size/2, cy+size/2, size/2);
    createFractal(arr, width, height, cx+size/2, cy+size/2, size/2);
}