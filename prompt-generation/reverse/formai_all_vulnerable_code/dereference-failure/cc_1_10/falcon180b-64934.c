//Falcon-180B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000000

typedef struct {
    char *line;
    struct line_node *next;
} line_node;

line_node *head = NULL;

void add_line(char *line) {
    line_node *new_node = (line_node *)malloc(sizeof(line_node));
    new_node->line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    strcpy(new_node->line, line);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        line_node *current_node = head;
        while (current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
        num_lines++;

        if (num_lines == MAX_NUM_LINES) {
            printf("Error: Maximum number of lines reached.\n");
            exit(1);
        }
    }

    fclose(file);

    printf("Number of lines: %d\n", num_lines);

    line_node *current_node = head;
    while (current_node!= NULL) {
        printf("%s", current_node->line);
        current_node = current_node->next;
    }

    return 0;
}