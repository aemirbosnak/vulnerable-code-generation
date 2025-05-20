//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} table;

table *create_table(char *name, int num_rows, int num_cols) {
    table *t = (table *)malloc(sizeof(table));
    t->name = strdup(name);
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    t->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        t->data[i] = (char *)malloc(num_cols * MAX_DATA_SIZE);
        memset(t->data[i], 0, num_cols * MAX_DATA_SIZE);
    }
    return t;
}

void delete_table(table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        free(t->data[i]);
    }
    free(t->data);
    free(t->name);
    free(t);
}

int main() {
    table *t1 = create_table("table1", 2, 3);
    table *t2 = create_table("table2", 3, 2);

    strcpy(t1->data[0], "1");
    strcpy(t1->data[1], "2");
    strcpy(t1->data[0]+5, "3");
    strcpy(t1->data[1]+5, "4");

    strcpy(t2->data[0], "a");
    strcpy(t2->data[1], "b");
    strcpy(t2->data[2], "c");

    printf("Table 1:\n");
    for (int i = 0; i < t1->num_rows; i++) {
        for (int j = 0; j < t1->num_cols; j++) {
            printf("%s ", t1->data[i]+j*MAX_DATA_SIZE);
        }
        printf("\n");
    }

    printf("\nTable 2:\n");
    for (int i = 0; i < t2->num_rows; i++) {
        for (int j = 0; j < t2->num_cols; j++) {
            printf("%s ", t2->data[i]+j*MAX_DATA_SIZE);
        }
        printf("\n");
    }

    delete_table(t1);
    delete_table(t2);

    return 0;
}