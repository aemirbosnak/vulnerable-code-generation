//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int row;
    int col;
} Index;

Index *database[MAX_ROWS][MAX_COLS];

void insert(Index *index) {
    database[index->row][index->col] = index;
}

Index *lookup(char *name) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            Index *index = database[i][j];
            if (index != NULL && strcmp(index->name, name) == 0) {
                return index;
            }
        }
    }
    return NULL;
}

int main() {
    Index *index1 = malloc(sizeof(Index));
    strncpy(index1->name, "John Doe", MAX_NAME_LENGTH - 1);
    index1->row = 0;
    index1->col = 0;
    insert(index1);

    Index *index2 = malloc(sizeof(Index));
    strncpy(index2->name, "Jane Smith", MAX_NAME_LENGTH - 1);
    index2->row = 0;
    index2->col = 1;
    insert(index2);

    Index *lookup_result = lookup("John Doe");
    if (lookup_result != NULL) {
        printf("Found %s at [%d, %d]\n", lookup_result->name, lookup_result->row, lookup_result->col);
    } else {
        printf("John Doe not found\n");
    }

    return 0;
}