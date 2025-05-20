//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct Line {
    char **data;
    int length;
    struct Line *next;
} Line;

Line **insert_line(Line **head, char **line, int len) {
    Line *new_line = malloc(sizeof(Line));
    new_line->data = malloc(len * sizeof(char));
    new_line->length = len;
    new_line->next = NULL;

    if (*head == NULL) {
        *head = new_line;
    } else {
        (*head)->next = new_line;
    }

    return head;
}

void format_lines(Line **head) {
    Line *current = head;

    while (current) {
        int i = 0;
        for (i = 0; i < current->length; i++) {
            printf("%c", current->data[i]);
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    Line **head = NULL;

    // Insert some lines
    insert_line(&head, "This is the first line.", 23);
    insert_line(&head, "The second line has a longer text.", 34);
    insert_line(&head, "The third line has even more text.", 40);

    // Format the lines
    format_lines(head);

    return 0;
}