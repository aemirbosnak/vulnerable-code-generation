//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_R 10.0
#define MIN_R 0.0

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point point;
    double resistance;
    double capacitance;
} Node;

void draw_circle(Node* node, double radius) {
    double angle = 0.0;
    while (angle <= 2 * PI) {
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        printf("%f %f\n", x, y);
        angle += 0.01;
    }
}

int main() {
    Node* node1 = malloc(sizeof(Node));
    node1->point.x = 0.0;
    node1->point.y = 0.0;
    node1->resistance = 1.0;
    node1->capacitance = 1.0;

    Node* node2 = malloc(sizeof(Node));
    node2->point.x = 3.0;
    node2->point.y = 0.0;
    node2->resistance = 2.0;
    node2->capacitance = 2.0;

    Node* node3 = malloc(sizeof(Node));
    node3->point.x = 0.0;
    node3->point.y = 3.0;
    node3->resistance = 3.0;
    node3->capacitance = 3.0;

    Point* points[3] = {&node1->point, &node2->point, &node3->point};
    double max_r = MAX_R;
    double min_r = MIN_R;

    while (max_r - min_r > 0.001) {
        double mid_r = (max_r + min_r) / 2.0;
        draw_circle(node1, mid_r);
        draw_circle(node2, mid_r);
        draw_circle(node3, mid_r);

        double total_voltage = node1->resistance * node1->capacitance * node1->point.x +
                               node2->resistance * node2->capacitance * node2->point.x +
                               node3->resistance * node3->capacitance * node3->point.x;

        if (total_voltage > 0.0) {
            max_r = mid_r;
        } else {
            min_r = mid_r;
        }
    }

    printf("The maximum radius is %f.\n", max_r);
    free(node1);
    free(node2);
    free(node3);
    return 0;
}