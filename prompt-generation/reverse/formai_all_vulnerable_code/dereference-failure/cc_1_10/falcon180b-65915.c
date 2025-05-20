//Falcon-180B DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    char *gender;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} DataSet;

void init_dataset(DataSet *ds, int capacity) {
    ds->data = malloc(capacity * sizeof(Person));
    ds->size = 0;
    ds->capacity = capacity;
}

void free_dataset(DataSet *ds) {
    free(ds->data);
}

void add_person(DataSet *ds, const char *name, int age, const char *gender) {
    if (ds->size == ds->capacity) {
        ds->capacity *= 2;
        ds->data = realloc(ds->data, ds->capacity * sizeof(Person));
    }

    Person *p = &ds->data[ds->size];
    p->name = strdup(name);
    p->age = age;
    p->gender = strdup(gender);

    ds->size++;
}

void print_dataset(const DataSet *ds) {
    for (int i = 0; i < ds->size; i++) {
        printf("Name: %s, Age: %d, Gender: %s\n", ds->data[i].name, ds->data[i].age, ds->data[i].gender);
    }
}

void mine_data(DataSet *ds) {
    double avg_age = 0;
    int male_count = 0;

    for (int i = 0; i < ds->size; i++) {
        avg_age += ds->data[i].age;

        if (strcmp(ds->data[i].gender, "Male") == 0) {
            male_count++;
        }
    }

    avg_age /= ds->size;

    printf("Average Age: %.2f\n", avg_age);
    printf("Male Count: %d\n", male_count);
}

int main() {
    DataSet ds;
    init_dataset(&ds, 10);

    add_person(&ds, "John Doe", 25, "Male");
    add_person(&ds, "Jane Doe", 30, "Female");
    add_person(&ds, "Bob Smith", 40, "Male");
    add_person(&ds, "Alice Smith", 35, "Female");

    print_dataset(&ds);

    mine_data(&ds);

    free_dataset(&ds);

    return 0;
}