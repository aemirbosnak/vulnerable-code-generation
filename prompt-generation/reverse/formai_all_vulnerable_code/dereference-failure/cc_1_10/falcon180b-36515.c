//Falcon-180B DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 100000

struct line {
    char *text;
    int length;
    struct line *next;
};

struct line *head = NULL;
int num_lines = 0;

void add_line(char *text) {
    struct line *new_line = malloc(sizeof(struct line));
    new_line->text = strdup(text);
    new_line->length = strlen(text);
    new_line->next = NULL;

    if (head == NULL) {
        head = new_line;
    } else {
        struct line *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_line;
    }

    num_lines++;
}

void print_lines() {
    struct line *current = head;
    while (current!= NULL) {
        printf("%s\n", current->text);
        current = current->next;
    }
}

int main() {
    char line_buffer[MAX_LINE_LENGTH];
    char *line_text = NULL;
    size_t line_capacity = 0;
    ssize_t line_length;

    while ((line_length = getline(&line_text, &line_capacity, stdin))!= -1) {
        if (line_capacity > MAX_LINE_LENGTH) {
            printf("Line too long: %zd characters\n", line_length);
            continue;
        }

        add_line(line_text);

        if (num_lines >= MAX_NUM_LINES) {
            printf("Maximum number of lines reached: %d\n", MAX_NUM_LINES);
            break;
        }
    }

    print_lines();

    return 0;
}