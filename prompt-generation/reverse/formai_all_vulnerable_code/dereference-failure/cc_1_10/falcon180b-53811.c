//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    double latitude;
    double longitude;
    char name[MAX_NAME_LENGTH];
} point_t;

void read_points(point_t points[], int *num_points) {
    FILE *file = fopen("points.txt", "r");

    if (file == NULL) {
        printf("Error: could not open points file.\n");
        exit(1);
    }

    char line[1024];
    int i = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        if (i >= MAX_POINTS) {
            printf("Error: too many points in file.\n");
            exit(1);
        }

        point_t point;
        sscanf(token, "%lf,%lf", &point.latitude, &point.longitude);
        strcpy(point.name, strtok(NULL, ","));

        points[i++] = point;
    }

    *num_points = i;

    fclose(file);
}

void print_points(point_t points[], int num_points) {
    for (int i = 0; i < num_points; i++) {
        printf("%s: (%lf, %lf)\n", points[i].name, points[i].latitude, points[i].longitude);
    }
}

int main() {
    srand(time(NULL));

    point_t points[MAX_POINTS];
    int num_points;

    read_points(points, &num_points);

    int start_index = rand() % num_points;
    int end_index = rand() % num_points;

    double distance = 0;

    for (int i = start_index; i <= end_index; i++) {
        distance += hypot(points[i].latitude - points[(i - 1 + num_points) % num_points].latitude,
                          points[i].longitude - points[(i - 1 + num_points) % num_points].longitude);
    }

    printf("Total distance: %.2lf km\n", distance / 1000);

    return 0;
}