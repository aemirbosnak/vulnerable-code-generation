//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WINDOW_SIZE 900
#define MAX_DEPTH 5

typedef struct{
    int r, g, b;
}COLOR;

typedef struct{
    int x, y;
}POINT;

typedef struct fractal{
    POINT start;
    POINT end;
    struct fractal* left_child;
    struct fractal* right_child;
    int depth;
}FRACTAL;

int generate_random_number(int min, int max){
    return (rand() % (max +1 - min)) + min;
}

COLOR generate_random_color(){
    COLOR color;
    color.r = generate_random_number(0, 255);
    color.g = generate_random_number(0, 255);
    color.b = generate_random_number(0, 255);
    return color;
}

void clear_screen(){
    printf("\033[2J\033[1;1H");
}

void plot_pixel(int x, int y, COLOR color){
    printf("\033[%d;%dH\033[48;2;%d;%d;%dm \033[0m", y, x, color.r, color.g, color.b);
}

void draw_line(POINT start, POINT end, COLOR color){
    int range_x = abs(end.x - start.x);
    int range_y = abs(end.y - start.y);
    int increment_x = (end.x > start.x) ? 1 : -1;
    int increment_y = (end.y > start.y) ? 1 : -1;
    int error = ((range_x > range_y) ? range_x : -range_y) / 2;
    int current_x = start.x; 
    int current_y = start.y;

    while(true){
        plot_pixel(current_x, current_y, color);
        if(current_x == end.x && current_y == end.y) return;
        int error_copy = error;
        if(error_copy > -range_x){ 
            error -= range_y;
            current_x += increment_x;
        }
        if(error_copy < range_y){ 
            error += range_x;
            current_y += increment_y;
        }
    }
}

FRACTAL* create_fractal(int depth, POINT start, POINT end){
    FRACTAL* fractal = malloc(sizeof(FRACTAL));
    fractal->depth = depth;
    fractal->start = start;
    fractal->end = end;
    if(depth <= 0) return fractal;
 
    int midpoint_x = (start.x + end.x) / 2;
    int midpoint_y = (start.y + end.y) / 2;
    POINT midpoint = { midpoint_x, midpoint_y };
    fractal->left_child = create_fractal(depth - 1, start, midpoint); 
    fractal->right_child = create_fractal(depth - 1, midpoint, end);
    return fractal;
}

void destroy_fractal(FRACTAL* fractal){
    if(fractal->left_child) destroy_fractal(fractal->left_child);
    if(fractal->right_child) destroy_fractal(fractal->right_child);
    free(fractal);
}

void draw_fractal(FRACTAL* fractal){
    if(fractal->depth == 0){
        COLOR color = generate_random_color();
        draw_line(fractal->start, fractal->end, color);
        return;
    }
    draw_fractal(fractal->left_child);
    draw_fractal(fractal->right_child);
}

int main(){
    srand(time(NULL));
    FRACTAL* fractal = create_fractal(MAX_DEPTH, (POINT){WINDOW_SIZE/2, WINDOW_SIZE-50}, (POINT){50, 50});
    clear_screen();
    draw_fractal(fractal);
    destroy_fractal(fractal);
    return 0;
}