//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    int num_rows;
    int num_cols;
    char data[MAX_DATA_SIZE];
} table;

table *create_table(int num_rows, int num_cols) {
    table *t = (table *)malloc(sizeof(table));
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    return t;
}

void destroy_table(table *t) {
    free(t);
}

void set_data(table *t, int row, int col, char *data) {
    int offset = (row * t->num_cols) + col;
    if (offset < MAX_DATA_SIZE) {
        strncpy(t->data + offset, data, MAX_DATA_SIZE - offset);
    }
}

char *get_data(table *t, int row, int col) {
    int offset = (row * t->num_cols) + col;
    if (offset < MAX_DATA_SIZE) {
        return t->data + offset;
    }
    return NULL;
}

int main() {
    table *t = create_table(5, 3);
    set_data(t, 0, 0, "Name");
    set_data(t, 0, 1, "Age");
    set_data(t, 0, 2, "Gender");
    set_data(t, 1, 0, "Alice");
    set_data(t, 1, 1, "25");
    set_data(t, 1, 2, "Female");
    set_data(t, 2, 0, "Bob");
    set_data(t, 2, 1, "30");
    set_data(t, 2, 2, "Male");
    set_data(t, 3, 0, "Charlie");
    set_data(t, 3, 1, "35");
    set_data(t, 3, 2, "Male");
    set_data(t, 4, 0, "David");
    set_data(t, 4, 1, "40");
    set_data(t, 4, 2, "Male");

    char *name = get_data(t, 1, 0);
    char *age = get_data(t, 1, 1);
    char *gender = get_data(t, 1, 2);

    printf("Name: %s, Age: %s, Gender: %s\n", name, age, gender);

    destroy_table(t);
    return 0;
}