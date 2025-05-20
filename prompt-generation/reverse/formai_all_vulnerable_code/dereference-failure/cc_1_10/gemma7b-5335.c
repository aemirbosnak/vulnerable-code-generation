//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *insert_node(CSV_Node *head, char **data) {
    CSV_Node *newNode = (CSV_Node *)malloc(sizeof(CSV_Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void print_csv(CSV_Node *head) {
    CSV_Node *curr = head;

    while (curr) {
        for (int i = 0; curr->data[i] != NULL; i++) {
            printf("%s,", curr->data[i]);
        }
        printf("\n");
        curr = curr->next;
    }
}

int main() {
    CSV_Node *head = NULL;

    char **data = (char **)malloc(sizeof(char *) * MAX);
    for (int i = 0; i < MAX; i++) {
        data[i] = (char *)malloc(sizeof(char) * MAX);
    }

    // Insert data into the CSV node
    data[0] = "John Doe";
    data[1] = "New York";
    data[2] = "USA";

    data[3] = "Jane Doe";
    data[4] = "Los Angeles";
    data[5] = "USA";

    head = insert_node(head, data);

    // Print the CSV data
    print_csv(head);

    // Free memory
    for (int i = 0; i < MAX; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}