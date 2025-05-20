//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *insert_node(CSV_Node *head, char **row) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = row;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

int main() {
    CSV_Node *head = NULL;

    // Read CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        return 1;
    }

    // Allocate memory for rows and columns
    char **rows = malloc(MAX_ROWS * sizeof(char *));
    for (int i = 0; i < MAX_ROWS; i++) {
        rows[i] = malloc(MAX_COLS * sizeof(char));
    }

    // Get CSV data
    char line[MAX_COLS];
    int row_num = 0;
    while (fgets(line, MAX_COLS, fp) != NULL) {
        // Split line into columns
        char *column = strtok(line, ",");
        while (column) {
            strcpy(rows[row_num][0], column);
            column = strtok(NULL, ",");
        }

        row_num++;
    }

    // Insert nodes into linked list
    for (int i = 0; i < row_num; i++) {
        insert_node(head, rows[i]);
    }

    // Print CSV data
    for (CSV_Node *node = head; node; node) {
        for (int i = 0; node->data[i] != NULL; i++) {
            printf("%s,", node->data[i]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_ROWS; i++) {
        free(rows[i]);
    }
    free(rows);

    fclose(fp);

    return 0;
}