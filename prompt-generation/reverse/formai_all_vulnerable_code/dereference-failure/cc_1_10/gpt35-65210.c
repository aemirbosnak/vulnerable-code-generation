//FormAI DATASET v1.0 Category: Fractal Generation ; Style: statistical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define WIDTH 1000
#define HEIGHT 1000

typedef struct Point{
    double x;
    double y;
}Point;

double distance(Point p1, Point p2){
    return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

double getMid(Point p1, Point p2){
    return (p1.x + p2.x)/2;
}
void drawLine(Point start,Point end,int *pixels){
    double dx = end.x - start.x;
    double dy = end.y - start.y;
    double l = distance(start,end);
    double ux = dx/l;
    double uy = dy/l;

    for(int i=0; i<(int)l; i++){
        int x = round(start.x+(double)i*ux);
        int y = round(start.y+(double)i*uy);
        pixels[(y*WIDTH)+x] = 1;
    }
}

void drawC(Point p1,Point p2,Point p3, int *pixels, int iterations){
    int x = WIDTH/2;
    int y = HEIGHT/2;
    pixels[WIDTH/2+(HEIGHT/2)*WIDTH] = 1;

    Point p4 = {.x=getMid(p1,p2), .y=getMid(p1,p2)};
    Point p5 = {.x=getMid(p2,p3), .y=getMid(p2,p3)};
    Point p6 = {.x=getMid(p3,p1), .y=getMid(p3,p1)};

    if(iterations > 0){
        drawC(p1,p4,p6,pixels, iterations-1);
        drawC(p4,p2,p5,pixels, iterations-1);
        drawC(p5,p3,p6,pixels, iterations-1);
        drawC(p4,p5,p6,pixels, iterations-1);
    }else{
        drawLine(p1,p2,pixels);
        drawLine(p2,p3,pixels);
        drawLine(p3,p1,pixels);
    }
}

int main(){
    int *pixels = calloc(WIDTH*HEIGHT,sizeof(int));
    Point p1 = {.x=WIDTH*0.1, .y=HEIGHT*0.9};
    Point p2 = {.x=WIDTH*0.9, .y=HEIGHT*0.9};
    Point p3 = {.x=WIDTH*0.5, .y=HEIGHT*0.1};

    drawC(p1,p2,p3,pixels, 5);

    for(int y=0; y<HEIGHT; y++){
        for(int x=0; x<WIDTH; x++){
            putchar(pixels[y*WIDTH+x] ? '*' : ' ');
        }
        putchar('\n');
    }

    return 0;
}