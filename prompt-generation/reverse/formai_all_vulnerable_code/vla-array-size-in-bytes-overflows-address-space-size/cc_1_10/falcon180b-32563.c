//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

struct point {
    int x;
    int y;
};

struct line {
    int a;
    int b;
    int c;
};

int is_point_on_line(struct point p, struct line l);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    struct point points[n];
    struct line lines[m];
    for(int i=0; i<n; i++) {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &lines[i].a, &lines[i].b, &lines[i].c);
    }
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(is_point_on_line(points[i], lines[j])) {
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}

int is_point_on_line(struct point p, struct line l) {
    int a = l.a;
    int b = l.b;
    int c = l.c;
    int x = p.x;
    int y = p.y;
    int det = b*y - a*x - c;
    if(det == 0) {
        return 0;
    }
    return 1;
}