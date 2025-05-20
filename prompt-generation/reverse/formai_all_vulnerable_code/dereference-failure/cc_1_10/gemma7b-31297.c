//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *head = NULL;

void add_node(char **data) {
    CSV_Node *new_node = malloc(sizeof(CSV_Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINES];
    int line_num = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        line_num++;
        char **data = malloc(MAX_COLS * sizeof(char *));
        char *ptr = line;
        int col_num = 0;
        while (ptr && *ptr) {
            data[col_num++] = strdup(ptr);
            ptr += strcspn(ptr, ",\n") + 1;
        }
        add_node(data);
    }

    fclose(fp);
}

int main() {
    read_csv("data.csv");

    CSV_Node *node = head;
    while (node) {
        printf("%s, ", node->data[0]);
        printf("%s\n", node->data[1]);
        node = node->next;
    }

    return 0;
}