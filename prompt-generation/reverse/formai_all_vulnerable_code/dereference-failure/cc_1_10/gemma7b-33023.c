//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_InsertNode(CSV_Node *head, int num_cols, char **data) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(sizeof(char *) * num_cols);
    for (int i = 0; i < num_cols; i++) {
        newNode->data[i] = strdup(data[i]);
    }
    newNode->next = head;
    return newNode;
}

int CSV_Parse(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    char line[MAX_LINES];
    CSV_Node *head = NULL;

    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **data = malloc(sizeof(char *) * MAX_COLS);
        int num_cols = 0;

        // Split the line into columns
        char *p = strtok(line, ",");
        while (p) {
            data[num_cols++] = p;
            p = strtok(NULL, ",");
        }

        // Insert a new node into the linked list
        head = CSV_InsertNode(head, num_cols, data);
    }

    fclose(fp);

    return 0;
}

int main() {
    CSV_Parse("data.csv");

    return 0;
}