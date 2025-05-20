//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char name[50];
    int age;
    char gender;
    float salary;
} person;

typedef struct {
    char name[50];
    int num_rows;
    person rows[MAX_ROWS];
} table;

table *create_table(char *name) {
    table *t = malloc(sizeof(table));
    strcpy(t->name, name);
    t->num_rows = 0;
    return t;
}

void add_row(table *t, person *p) {
    if (t->num_rows < MAX_ROWS) {
        t->rows[t->num_rows++] = *p;
    } else {
        printf("Error: Table is full.\n");
    }
}

void print_table(table *t) {
    printf("Table: %s\n", t->name);
    for (int i = 0; i < t->num_rows; i++) {
        printf("  %s, %d, %c, %.2f\n", t->rows[i].name, t->rows[i].age, t->rows[i].gender, t->rows[i].salary);
    }
}

void free_table(table *t) {
    free(t);
}

int main() {
    table *t = create_table("employees");

    person p1 = {"John Doe", 30, 'M', 50000.0f};
    add_row(t, &p1);

    person p2 = {"Jane Doe", 25, 'F', 40000.0f};
    add_row(t, &p2);

    person p3 = {"Bob Smith", 40, 'M', 60000.0f};
    add_row(t, &p3);

    print_table(t);

    free_table(t);

    return 0;
}