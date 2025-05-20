//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_Insert(CSV_Node *head, char **row);

int main() {
    CSV_Node *head = NULL;

    // Read CSV file
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }

    // Allocate memory for the CSV node
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));

    // Insert the first row into the CSV node
    char **row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "John Doe";
    row[1] = "New York";
    newNode->data = row;
    CSV_Insert(head, row);

    // Insert the second row into the CSV node
    row = malloc(MAX_COLS * sizeof(char *));
    row[0] = "Jane Doe";
    row[1] = "Los Angeles";
    CSV_Insert(head, row);

    // Print the CSV data
    CSV_Node *current = head;
    while (current) {
        for (int i = 0; i < current->data[0] - 1; i++) {
            printf("%s, ", current->data[i + 1]);
        }
        printf("\n");
        current = current->next;
    }

    fclose(fp);
    return EXIT_SUCCESS;
}

CSV_Node *CSV_Insert(CSV_Node *head, char **row) {
    CSV_Node *newNode = malloc(sizeof(CSV_Node));
    newNode->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));

    // Copy the row data into the new node
    newNode->data = row;

    // Insert the new node into the linked list
    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }

    return head;
}