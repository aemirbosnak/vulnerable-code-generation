//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

typedef struct point {
    double x, y;
} point;

typedef struct line {
    point p1, p2;
} line;

typedef struct circle {
    point c;
    double r;
} circle;

double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int ccw(point p1, point p2, point p3) {
    double dx1 = p2.x - p1.x, dy1 = p2.y - p1.y;
    double dx2 = p3.x - p2.x, dy2 = p3.y - p2.y;
    double t = dx1 * dy2 - dx2 * dy1;
    if (fabs(t) < EPS) return 0;
    return t < 0 ? -1 : 1;
}

int intersect(line l1, line l2) {
    return ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2) < 0 && ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2) < 0;
}

int intersect_circle(circle c, point p) {
    return dist(c.c, p) < c.r + EPS;
}

int main() {
    int n;
    scanf("%d", &n);
    point p[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &p[i].x, &p[i].y);
    }
    int m;
    scanf("%d", &m);
    line l[m];
    for (int i = 0; i < m; i++) {
        scanf("%lf %lf %lf %lf", &l[i].p1.x, &l[i].p1.y, &l[i].p2.x, &l[i].p2.y);
    }
    int k;
    scanf("%d", &k);
    circle c[k];
    for (int i = 0; i < k; i++) {
        scanf("%lf %lf %lf", &c[i].c.x, &c[i].c.y, &c[i].r);
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (intersect(l[j], (line){p[i], p[(i + 1) % n]})) cnt++;
        }
        for (int j = 0; j < k; j++) {
            if (intersect_circle(c[j], p[i])) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}