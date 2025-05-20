//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
    char *city;
    float salary;
} Person;

typedef struct {
    int num_persons;
    Person *persons;
} Dataset;

Dataset *load_dataset(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    Dataset *dataset = malloc(sizeof(Dataset));
    if (dataset == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    fscanf(fp, "%d", &dataset->num_persons);

    dataset->persons = malloc(dataset->num_persons * sizeof(Person));
    if (dataset->persons == NULL) {
        perror("Error allocating memory");
        free(dataset);
        return NULL;
    }

    for (int i = 0; i < dataset->num_persons; i++) {
        fscanf(fp, "%d %s %d %s %f", &dataset->persons[i].id, dataset->persons[i].name, &dataset->persons[i].age, dataset->persons[i].city, &dataset->persons[i].salary);
    }

    fclose(fp);

    return dataset;
}

void free_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_persons; i++) {
        free(dataset->persons[i].name);
        free(dataset->persons[i].city);
    }

    free(dataset->persons);
    free(dataset);
}

void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_persons; i++) {
        printf("%d %s %d %s %f\n", dataset->persons[i].id, dataset->persons[i].name, dataset->persons[i].age, dataset->persons[i].city, dataset->persons[i].salary);
    }
}

int main() {
    Dataset *dataset = load_dataset("data.csv");
    if (dataset == NULL) {
        return EXIT_FAILURE;
    }

    print_dataset(dataset);

    free_dataset(dataset);

    return EXIT_SUCCESS;
}