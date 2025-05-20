//Falcon-180B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line in the file
#define MAX_NUM_LINES 1000 // Maximum number of lines in the file

typedef struct {
    char* line;
    struct line_node* next;
} line_node;

line_node* create_line_node(char* line) {
    line_node* new_node = (line_node*) malloc(sizeof(line_node));
    new_node->line = strdup(line);
    new_node->next = NULL;
    return new_node;
}

void add_line_node(line_node** head, char* line) {
    line_node* new_node = create_line_node(line);
    if (*head == NULL) {
        *head = new_node;
    } else {
        line_node* curr_node = *head;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

void print_lines(line_node* head) {
    line_node* curr_node = head;
    while (curr_node!= NULL) {
        printf("%s\n", curr_node->line);
        curr_node = curr_node->next;
    }
}

void free_lines(line_node* head) {
    line_node* curr_node = head;
    while (curr_node!= NULL) {
        free(curr_node->line);
        free(curr_node);
        curr_node = curr_node->next;
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    line_node* lines = NULL;
    char line_buffer[MAX_LINE_LENGTH];
    int num_lines = 0;

    while (fgets(line_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        add_line_node(&lines, line_buffer);
        num_lines++;
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Maximum number of lines reached.\n");
            exit(1);
        }
    }

    fclose(input_file);

    print_lines(lines);

    free_lines(lines);

    return 0;
}