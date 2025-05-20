//FormAI DATASET v1.0 Category: Fractal Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

void generateFractal(int x1, int y1, int x2, int y2, int depth, char** matrix){
    if(depth <= 0) return;

    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = sqrt(dx*dx + dy*dy);

    float offsetX = dy / distance * (rand() % 20 + 10); // Adding random offset to the coordinates
    float offsetY = dx / distance * (rand() % 20 + 10);

    int nx1 = (int)(x1 + offsetX);
    int ny1 = (int)(y1 + offsetY);
    int nx2 = (int)(x2 + offsetX);
    int ny2 = (int)(y2 + offsetY);

    generateFractal(x1, y1, nx1, ny1, depth-1, matrix);
    generateFractal(nx1, ny1, nx2, ny2, depth-1, matrix);
    generateFractal(nx2, ny2, x2, y2, depth-1, matrix);

    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            if(abs(j - i) < 2){
                matrix[i][j] = '#';
            }
        }
    }
}

int main() {
    char **matrix = (char**)malloc(sizeof(char*) * WIDTH);

    for(int i = 0; i < WIDTH; i++){
        matrix[i] = (char*)malloc(sizeof(char) * HEIGHT + 1);
        for(int j = 0; j < HEIGHT; j++){
            matrix[i][j] = ' ';
        }
        matrix[i][HEIGHT] = '\0';
    }

    generateFractal(0, 0, WIDTH-1, HEIGHT-1, 8, matrix);

    for(int i = 0; i < WIDTH; i++){
        printf("%s\n", matrix[i]);
    }

    for(int i = 0; i < WIDTH; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}