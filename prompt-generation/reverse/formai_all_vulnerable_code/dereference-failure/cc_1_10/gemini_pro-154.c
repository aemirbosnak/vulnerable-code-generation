//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

// Data structures
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int count;
} PointSet;

// Function prototypes
PointSet *createPointSet(int count);
void destroyPointSet(PointSet *set);
void addPoint(PointSet *set, Point point);
Point *getPoint(PointSet *set, int index);
int getPointCount(PointSet *set);
void printPointSet(PointSet *set);
double distanceBetweenPoints(Point *p1, Point *p2);
double areaOfTriangle(Point *a, Point *b, Point *c);

// Main function

int main()
{
    // Create a point set
    PointSet *set = createPointSet(100);

    // Add some points to the set
    for (int i = 0; i < 100; i++) {
        Point point;
        point.x = rand() % 100;
        point.y = rand() % 100;
        addPoint(set, point);
    }

    // Print the set
    printPointSet(set);

    // Calculate the area of a triangle formed by three random points
    Point *p1 = getPoint(set, rand() % 100);
    Point *p2 = getPoint(set, rand() % 100);
    Point *p3 = getPoint(set, rand() % 100);
    double area = areaOfTriangle(p1, p2, p3);

    // Print the area
    printf("Area of triangle: %f\n", area);

    // Destroy the set
    destroyPointSet(set);

    return 0;
}

// Function definitions

PointSet *createPointSet(int count)
{
    PointSet *set = malloc(sizeof(PointSet));
    set->points = malloc(sizeof(Point) * count);
    set->count = 0;
    return set;
}

void destroyPointSet(PointSet *set)
{
    free(set->points);
    free(set);
}

void addPoint(PointSet *set, Point point)
{
    set->points[set->count++] = point;
}

Point *getPoint(PointSet *set, int index)
{
    return &set->points[index];
}

int getPointCount(PointSet *set)
{
    return set->count;
}

void printPointSet(PointSet *set)
{
    for (int i = 0; i < set->count; i++) {
        Point *point = &set->points[i];
        printf("(%d, %d)\n", point->x, point->y);
    }
}

double distanceBetweenPoints(Point *p1, Point *p2)
{
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return sqrt(dx*dx + dy*dy);
}

double areaOfTriangle(Point *a, Point *b, Point *c)
{
    double ab = distanceBetweenPoints(a, b);
    double bc = distanceBetweenPoints(b, c);
    double ca = distanceBetweenPoints(c, a);
    double s = (ab + bc + ca) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}