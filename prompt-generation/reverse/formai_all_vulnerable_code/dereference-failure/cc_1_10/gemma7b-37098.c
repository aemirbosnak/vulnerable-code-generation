//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *insert_node(CSV_Node *head, char **data) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void read_csv(char *file_path) {
    FILE *file = fopen(file_path, "r");
    CSV_Node *head = NULL;

    char line[MAX_ROWS][MAX_COLS];
    int row = 0;

    if (file) {
        while (fgets(line[row], MAX_COLS, file) != NULL) {
            row++;
            char **data = malloc(sizeof(char *) * MAX_COLS);
            int col = 0;

            for (char *word = strtok(line[row - 1], ","); word; word = strtok(NULL, ",")) {
                data[col++] = strdup(word);
            }

            insert_node(head, data);
        }

        fclose(file);
    }
}

int main() {
    read_csv("example.csv");

    return 0;
}