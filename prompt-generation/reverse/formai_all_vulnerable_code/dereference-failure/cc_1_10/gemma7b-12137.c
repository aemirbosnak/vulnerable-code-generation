//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_Node {
    char **data;
    struct CSV_Node *next;
} CSV_Node;

CSV_Node *CSV_CreateNode(int lines, int cols) {
    CSV_Node *node = malloc(sizeof(CSV_Node));
    node->data = malloc(lines * sizeof(char *) + 1);
    for (int i = 0; i < lines; i++) {
        node->data[i] = malloc(cols * sizeof(char) + 1);
    }
    node->next = NULL;
    return node;
}

void CSV_Parse(FILE *fp, CSV_Node *node) {
    char line[MAX_LINES];
    char **cols = NULL;
    int lineNumber = 0;
    while (fgets(line, MAX_LINES, fp) != NULL) {
        cols = NULL;
        char *ptr = line;
        while (ptr) {
            char *col = strchr(ptr, ',');
            if (col) {
                *cols = malloc(MAX_COLS * sizeof(char) + 1);
                strncpy(*cols, ptr, col - ptr);
                cols++;
            } else {
                *cols = malloc(MAX_COLS * sizeof(char) + 1);
                strncpy(*cols, ptr, strlen(ptr) + 1);
                cols++;
            }
            ptr = col ? col + 1 : NULL;
        }
        node->data[lineNumber] = cols;
        lineNumber++;
    }
}

int main() {
    CSV_Node *node = CSV_CreateNode(MAX_LINES, MAX_COLS);
    FILE *fp = fopen("data.csv", "r");
    CSV_Parse(fp, node);
    fclose(fp);
    return 0;
}