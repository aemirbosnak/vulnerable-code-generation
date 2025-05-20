//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data point
typedef struct {
    int id;
    char *name;
    int age;
} data_point;

// Define a data set
typedef struct {
    int num_points;
    data_point *points;
} data_set;

// Create a new data point
data_point *new_data_point(int id, char *name, int age) {
    data_point *point = malloc(sizeof(data_point));
    point->id = id;
    point->name = strdup(name);
    point->age = age;
    return point;
}

// Create a new data set
data_set *new_data_set() {
    data_set *set = malloc(sizeof(data_set));
    set->num_points = 0;
    set->points = NULL;
    return set;
}

// Add a data point to a data set
void add_data_point(data_set *set, data_point *point) {
    set->points = realloc(set->points, (set->num_points + 1) * sizeof(data_point));
    set->points[set->num_points++] = *point;
}

// Print a data set
void print_data_set(data_set *set) {
    for (int i = 0; i < set->num_points; i++) {
        printf("Data point %d:\n", set->points[i].id);
        printf("  Name: %s\n", set->points[i].name);
        printf("  Age: %d\n", set->points[i].age);
    }
}

// Free a data set
void free_data_set(data_set *set) {
    for (int i = 0; i < set->num_points; i++) {
        free(set->points[i].name);
    }
    free(set->points);
    free(set);
}

// Main function
int main() {
    // Create a new data set
    data_set *set = new_data_set();

    // Add some data points to the data set
    add_data_point(set, new_data_point(1, "John", 30));
    add_data_point(set, new_data_point(2, "Mary", 25));
    add_data_point(set, new_data_point(3, "Bob", 40));

    // Print the data set
    print_data_set(set);

    // Free the data set
    free_data_set(set);

    return 0;
}