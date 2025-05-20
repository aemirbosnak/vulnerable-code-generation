//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100000

/* Define struct for each row in the table */
typedef struct {
    int id;
    char name[21];
    char address[41];
    int age;
} row_t;

/* Define struct for each column in the index */
typedef struct {
    int id;
    int values[MAX_ROWS];
} column_t;

int main() {
    int num_rows = 0, num_cols = 0;
    row_t table[MAX_ROWS];
    column_t indexes[MAX_COLUMNS];

    /* Read in the data */
    FILE *fp;
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char line[200];
    char *token;
    int index = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        /* Parse the line */
        token = strtok(line, ",");
        table[index].id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(table[index].name, token);

        token = strtok(NULL, ",");
        strcpy(table[index].address, token);

        token = strtok(NULL, ",");
        table[index].age = atoi(token);

        /* Update the indexes */
        indexes[0].values[num_rows] = table[index].id;
        indexes[1].values[num_rows] = table[index].age;

        num_rows++;
        index++;
    }
    fclose(fp);
    num_cols = 2;

    /* Print out the table */
    printf("Table:\n");
    printf("ID\tName\t\tAddress\t\t\tAge\n");
    for (int i = 0; i < num_rows; i++) {
        printf("%d\t%-10s\t%-20s\t%d\n", table[i].id, table[i].name, table[i].address, table[i].age);
    }

    /* Print out the indexes */
    printf("\nIndexes:\n");
    for (int i = 0; i < num_cols; i++) {
        printf("Column %d:\n", i+1);
        for (int j = 0; j < num_rows; j++) {
            printf("%d\n", indexes[i].values[j]);
        }
        printf("\n");
    }

    return 0;
}