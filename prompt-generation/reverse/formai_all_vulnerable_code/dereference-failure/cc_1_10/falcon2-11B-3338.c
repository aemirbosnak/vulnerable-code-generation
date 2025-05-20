//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// Define a struct to hold the data
struct data {
    char name[50];
    int age;
};

// Define a function to sort the data by name
int cmp(const void *a, const void *b) {
    const struct data *x = *((struct data **) a);
    const struct data *y = *((struct data **) b);
    if (strcmp(x->name, y->name)!= 0) {
        return strcmp(x->name, y->name);
    } else {
        return x->age - y->age;
    }
}

// Define a function to search for a record by name
struct data *search(const char *name) {
    struct data *data = (struct data *) malloc(sizeof(struct data));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(data->name, name);
    data->age = 0;
    qsort(data, 1, sizeof(struct data), cmp);
    return data;
}

// Define a function to insert a new record into the database
struct data *insert(const char *name, int age) {
    struct data *data = (struct data *) malloc(sizeof(struct data));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(data->name, name);
    data->age = age;
    qsort(data, 1, sizeof(struct data), cmp);
    return data;
}

// Define a function to delete a record from the database
void delete(struct data *data) {
    free(data);
}

int main() {
    // Create an empty database
    struct data *data = (struct data *) malloc(sizeof(struct data));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Insert some records into the database
    insert("John Doe", 25);
    insert("Jane Smith", 30);
    insert("Bob Johnson", 40);

    // Search for a record by name
    struct data *found = search("John Doe");
    if (found!= NULL) {
        printf("Found: %s, Age: %d\n", found->name, found->age);
    } else {
        printf("Record not found!\n");
    }

    // Delete a record from the database
    delete(found);

    // Search for the deleted record
    found = search("John Doe");
    if (found!= NULL) {
        printf("Found: %s, Age: %d\n", found->name, found->age);
    } else {
        printf("Record not found!\n");
    }

    return 0;
}