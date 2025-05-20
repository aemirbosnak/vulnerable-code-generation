//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_STRING_LENGTH 1024
#define MAX_DATAPOINTS 100000

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    point_t *data;
    int size;
} dataset_t;

dataset_t *load_data(const char *file_name) {
    dataset_t *ds = malloc(sizeof(dataset_t));
    int i = 0;
    char line[MAX_STRING_LENGTH];

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return NULL;
    }

    while (fgets(line, MAX_STRING_LENGTH, file) != NULL) {
        double x, y;
        sscanf(line, "%lf %lf", &x, &y);
        point_t *pt = malloc(sizeof(point_t));
        pt->x = x;
        pt->y = y;
        ds->data = realloc(ds->data, (ds->size + 1) * sizeof(point_t));
        ds->data[ds->size] = *pt;
        ds->size++;
    }

    fclose(file);
    return ds;
}

void print_data(dataset_t *ds) {
    int i;
    for (i = 0; i < ds->size; i++) {
        printf("%.2lf %.2lf\n", ds->data[i].x, ds->data[i].y);
    }
}

void main() {
    dataset_t *ds = load_data("data.csv");
    print_data(ds);
    free(ds);
}