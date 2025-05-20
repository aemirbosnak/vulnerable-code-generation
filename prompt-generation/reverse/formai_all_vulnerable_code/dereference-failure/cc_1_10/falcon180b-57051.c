//Falcon-180B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 1000000
#define MAX_ATTRIBUTES 10

typedef struct {
    int *data;
    int num_attributes;
    char **attribute_names;
} DataSet;

void generate_random_data(DataSet *dataset, int num_attributes, int num_data_points) {
    int i, j;
    dataset->num_attributes = num_attributes;
    dataset->data = (int *)malloc(num_data_points * num_attributes * sizeof(int));
    for (i = 0; i < num_data_points; i++) {
        for (j = 0; j < num_attributes; j++) {
            dataset->data[i * num_attributes + j] = rand() % 100;
        }
    }
}

void generate_random_attributes(DataSet *dataset, int num_attributes) {
    int i;
    dataset->num_attributes = num_attributes;
    dataset->attribute_names = (char **)malloc(num_attributes * sizeof(char *));
    for (i = 0; i < num_attributes; i++) {
        dataset->attribute_names[i] = (char *)malloc(10 * sizeof(char));
        sprintf(dataset->attribute_names[i], "Attr%d", i + 1);
    }
}

void print_data(DataSet *dataset, int num_data_points, int num_attributes) {
    int i, j;
    for (i = 0; i < num_data_points; i++) {
        for (j = 0; j < num_attributes; j++) {
            printf("%d ", dataset->data[i * num_attributes + j]);
        }
        printf("\n");
    }
}

void free_data(DataSet *dataset) {
    free(dataset->data);
    for (int i = 0; i < dataset->num_attributes; i++) {
        free(dataset->attribute_names[i]);
    }
    free(dataset->attribute_names);
}

int main() {
    srand(time(NULL));
    DataSet dataset;
    int num_data_points = MAX_DATA;
    int num_attributes = MAX_ATTRIBUTES;

    generate_random_attributes(&dataset, num_attributes);
    generate_random_data(&dataset, num_attributes, num_data_points);

    printf("Random Data:\n");
    print_data(&dataset, num_data_points, num_attributes);

    free_data(&dataset);

    return 0;
}