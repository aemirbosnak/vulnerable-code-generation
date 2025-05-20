//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROWS 1000
#define COLS 1000
#define PI 3.14159265359

void update_wave_heights(float **prev_height_map, float **curr_height_map) {
    int i, j;
    float dt = 0.01;
    float dx = 5.0;
    float dy = 5.0;
    float c = 15.0;
    float dampening = 0.05;
    float laplacian, delta;
    float r1, r2, r3, r4;
    float x_factor, y_factor;
    float theta;
    
    for (i = 1; i < ROWS-1; i++) {
        for (j = 1; j < COLS-1; j++) {
            laplacian = -4 * prev_height_map[i][j] + prev_height_map[i-1][j] + prev_height_map[i+1][j] + prev_height_map[i][j-1] + prev_height_map[i][j+1];
            delta = pow(c*dt/dx, 2) * laplacian;
            r1 = (float)rand()/RAND_MAX;
            r2 = (float)rand()/RAND_MAX;
            r3 = (float)rand()/RAND_MAX;
            r4 = (float)rand()/RAND_MAX;
            x_factor = cos(2*PI*r1) * sqrt(-2*log(r2));
            y_factor = sin(2*PI*r1) * sqrt(-2*log(r2));
            theta = 2*PI*r3;
            curr_height_map[i][j] = (2 - dampening*dt) * prev_height_map[i][j] - prev_height_map[i][j] + delta;
            curr_height_map[i][j] += dampening * (r4 - 0.5) * dt;
            curr_height_map[i][j] += x_factor * sin(theta) + y_factor * cos(theta);
        }
    }
}

int main() {
    float **height_map;
    float **prev_height_map;
    int i, j, k;
    float time_elapsed = 0.0;
    clock_t start_time, end_time;  
    
    height_map = (float **)malloc(ROWS * sizeof(float *));
    for (i = 0; i < ROWS; i++) {
        height_map[i] = (float *)malloc(COLS * sizeof(float));
    }
    prev_height_map = (float **)malloc(ROWS * sizeof(float *));
    for (i = 0; i < ROWS; i++) {
        prev_height_map[i] = (float *)malloc(COLS * sizeof(float));
    }
    
    //initialize height map
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            height_map[i][j] = 0.0;
            prev_height_map[i][j] = 0.0;
        }
    }
    
    //main loop
    start_time = clock();
    for (k = 0; k < 500; k++) {
        update_wave_heights(prev_height_map, height_map);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                prev_height_map[i][j] = height_map[i][j];
            }
        }
        time_elapsed += 0.01;
    }
    end_time = clock();
    
    printf("Time Elapsed: %.2f seconds\n", time_elapsed);
    printf("Performance Time: %.2f seconds\n", (double)(end_time - start_time)/CLOCKS_PER_SEC);
    
    //free memory
    for (i = 0; i < ROWS; i++) {
        free(height_map[i]);
        free(prev_height_map[i]);
    }
    free(height_map);
    free(prev_height_map);
    
    return 0;
}