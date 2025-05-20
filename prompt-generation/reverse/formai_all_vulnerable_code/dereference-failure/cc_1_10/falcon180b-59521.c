//Falcon-180B DATASET v1.0 Category: Educational ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Vector2D {
    double x, y;
};

struct Vector3D {
    double x, y, z;
};

void rand_vector(struct Vector3D* v) {
    v->x = rand() % 1000 - 500;
    v->y = rand() % 1000 - 500;
    v->z = rand() % 1000 - 500;
}

double rand_double(double min, double max) {
    return min + (max - min) * rand() / RAND_MAX;
}

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_vector(struct Vector3D v) {
    printf("(%d, %d, %d)\n", v.x, v.y, v.z);
}

int main() {
    srand(time(NULL));

    int n = rand_int(1, 10);
    struct Vector3D* points = malloc(n * sizeof(struct Vector3D));

    for (int i = 0; i < n; i++) {
        rand_vector(points + i);
    }

    struct Vector3D centroid;
    centroid.x = centroid.y = centroid.z = 0;

    for (int i = 0; i < n; i++) {
        centroid.x += points[i].x;
        centroid.y += points[i].y;
        centroid.z += points[i].z;
    }

    centroid.x /= n;
    centroid.y /= n;
    centroid.z /= n;

    double radius = 0;

    for (int i = 0; i < n; i++) {
        double dx = points[i].x - centroid.x;
        double dy = points[i].y - centroid.y;
        double dz = points[i].z - centroid.z;
        double dist = sqrt(dx * dx + dy * dy + dz * dz);

        if (dist > radius) {
            radius = dist;
        }
    }

    printf("The radius of the sphere that contains all the points is: %f\n", radius);

    free(points);

    return 0;
}