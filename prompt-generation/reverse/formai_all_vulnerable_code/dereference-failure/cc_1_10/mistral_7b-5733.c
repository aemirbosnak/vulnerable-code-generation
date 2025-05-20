//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define NUM_COLUMNS 5

typedef struct {
    char name[50];
    double x, y, z;
} Point;

int main() {
    FILE *file = fopen("points.csv", "r");
    char line[MAX_LINE_LEN];
    Point points[NUM_COLUMNS];
    int i = 0;

    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        char *token = strtok(line, ",");
        strcpy(points[i].name, token);

        token = strtok(NULL, ",");
        points[i].x = atof(token);

        token = strtok(NULL, ",");
        points[i].y = atof(token);

        token = strtok(NULL, ",");
        points[i].z = atof(token);

        i++;
    }

    fclose(file);

    // Mathematical calculations with the read data
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_z = 0.0;
    double sum_xy = 0.0;
    double sum_xz = 0.0;
    double sum_yz = 0.0;

    for (i = 0; i < NUM_COLUMNS; i++) {
        sum_x += points[i].x;
        sum_y += points[i].y;
        sum_z += points[i].z;
        sum_xy += points[i].x * points[i].y;
        sum_xz += points[i].x * points[i].z;
        sum_yz += points[i].y * points[i].z;
    }

    double mean_x = sum_x / NUM_COLUMNS;
    double mean_y = sum_y / NUM_COLUMNS;
    double mean_z = sum_z / NUM_COLUMNS;

    double variance_x = 0.0;
    double variance_y = 0.0;
    double variance_z = 0.0;

    for (i = 0; i < NUM_COLUMNS; i++) {
        variance_x += pow(points[i].x - mean_x, 2);
        variance_y += pow(points[i].y - mean_y, 2);
        variance_z += pow(points[i].z - mean_z, 2);
    }

    double stddev_x = sqrt(variance_x / NUM_COLUMNS);
    double stddev_y = sqrt(variance_y / NUM_COLUMNS);
    double stddev_z = sqrt(variance_z / NUM_COLUMNS);

    printf("Mean X: %.2f, Mean Y: %.2f, Mean Z: %.2f\n", mean_x, mean_y, mean_z);
    printf("Standard Deviation X: %.2f, Standard Deviation Y: %.2f, Standard Deviation Z: %.2f\n", stddev_x, stddev_y, stddev_z);
    printf("Sum of XY: %.2f, Sum of XZ: %.2f, Sum of YZ: %.2f\n", sum_xy, sum_xz, sum_yz);

    return 0;
}