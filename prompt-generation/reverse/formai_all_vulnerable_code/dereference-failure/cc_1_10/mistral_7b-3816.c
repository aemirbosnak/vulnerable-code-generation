//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char *line;
    struct Node *next;
} Node;

Node *head = NULL;

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LENGTH];
    size_t len = 0;
    ssize_t read;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while ((read = getline(&line, sizeof(line), file)) != -1) {
        Node *new_node = (Node *) malloc(sizeof(Node));
        new_node->line = strdup(line);
        new_node->next = head;
        head = new_node;
    }

    fclose(file);
}

void print_list() {
    Node *current = head;

    while (current != NULL) {
        printf("%s", current->line);
        Node *temp = current;
        current = current->next;
        free(temp->line);
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    print_list();

    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp->line);
        free(temp);
    }

    head = NULL;

    return 0;
}