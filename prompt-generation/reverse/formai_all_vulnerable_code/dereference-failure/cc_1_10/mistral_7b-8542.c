//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

typedef struct {
    char *line;
    int len;
    struct Line *next;
} Line;

Line *head = NULL;

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LEN];
    Line *new_line = NULL;

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    while (fgets(buffer, MAX_LEN, file) != NULL) {
        if (head == NULL) {
            head = (Line *)malloc(sizeof(Line));
            head->len = strlen(buffer);
            head->line = (char *)malloc((head->len + 1) * sizeof(char));
            strcpy(head->line, buffer);
            head->next = NULL;
        } else {
            new_line = (Line *)malloc(sizeof(Line));
            new_line->len = strlen(buffer);
            new_line->line = (char *)malloc((new_line->len + 1) * sizeof(char));
            strcpy(new_line->line, buffer);
            new_line->next = head;
            head = new_line;
        }
    }

    fclose(file);
}

void print_lines() {
    Line *current = head;

    while (current != NULL) {
        printf("%s", current->line);
        free(current->line);
        free(current);
        current = head;
        head = head->next;
    }
}

void free_memory() {
    Line *current = head;

    while (head != NULL) {
        current = head;
        head = head->next;
        free(current->line);
        free(current);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    print_lines();
    free_memory();

    return 0;
}