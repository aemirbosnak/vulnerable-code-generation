//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table {
    char name[50];
    int columns;
    int rows;
    int *data;
};

struct table create_table(char name[], int columns, int rows) {
    struct table t;
    strcpy(t.name, name);
    t.columns = columns;
    t.rows = rows;
    t.data = (int *)malloc(rows * sizeof(int));
    return t;
}

void add_row(struct table t, int *data) {
    int i;
    for (i = 0; i < t.columns; i++) {
        t.data[t.rows * i] = data[i];
    }
    t.rows++;
}

void delete_row(struct table t, int row) {
    int i;
    for (i = row; i < t.rows - 1; i++) {
        t.data[i] = t.data[i + 1];
    }
    t.rows--;
}

void display_table(struct table t) {
    int i;
    printf("Table: %s\n", t.name);
    printf("Columns: %d\n", t.columns);
    printf("Rows: %d\n", t.rows);
    for (i = 0; i < t.rows; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < t.columns; j++) {
            printf("%d ", t.data[i * t.columns + j]);
        }
        printf("\n");
    }
}

int main() {
    struct table t1 = create_table("employees", 5, 0);
    int data1[] = {1, 2, 3, 4, 5};
    add_row(t1, data1);
    display_table(t1);
    delete_row(t1, 1);
    display_table(t1);
    free(t1.data);
    return 0;
}