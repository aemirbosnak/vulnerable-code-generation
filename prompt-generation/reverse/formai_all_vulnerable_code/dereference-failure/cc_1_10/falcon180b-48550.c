//Falcon-180B DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 10000
#define MAX_DATA_NAME_SIZE 50

typedef struct {
    char name[MAX_DATA_NAME_SIZE];
    int data_size;
    int data[MAX_DATA_SIZE];
} DataSet;

DataSet* create_dataset(char* name) {
    DataSet* dataset = (DataSet*)malloc(sizeof(DataSet));
    strcpy(dataset->name, name);
    dataset->data_size = 0;
    return dataset;
}

void add_data(DataSet* dataset, int data) {
    if (dataset->data_size == MAX_DATA_SIZE) {
        printf("Error: Data set is full!\n");
        return;
    }
    dataset->data[dataset->data_size++] = data;
}

int get_dataset_size(DataSet* dataset) {
    return dataset->data_size;
}

int get_data(DataSet* dataset, int index) {
    if (index >= dataset->data_size) {
        printf("Error: Index out of bounds!\n");
        return -1;
    }
    return dataset->data[index];
}

void destroy_dataset(DataSet* dataset) {
    free(dataset);
}

int main() {
    DataSet* dataset1 = create_dataset("Dataset 1");
    DataSet* dataset2 = create_dataset("Dataset 2");

    add_data(dataset1, 1);
    add_data(dataset1, 2);
    add_data(dataset1, 3);

    add_data(dataset2, 4);
    add_data(dataset2, 5);
    add_data(dataset2, 6);

    printf("Dataset 1 size: %d\n", get_dataset_size(dataset1));
    printf("Dataset 2 size: %d\n", get_dataset_size(dataset2));

    int data1 = get_data(dataset1, 1);
    int data2 = get_data(dataset2, 2);

    printf("Dataset 1 data: %d\n", data1);
    printf("Dataset 2 data: %d\n", data2);

    destroy_dataset(dataset1);
    destroy_dataset(dataset2);

    return 0;
}