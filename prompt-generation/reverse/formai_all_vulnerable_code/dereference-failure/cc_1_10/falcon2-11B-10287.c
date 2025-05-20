//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 80
#define MAX_CHAR_LENGTH 256

struct node {
    char *data;
    struct node *next;
};

struct node *head = NULL;

void add_node(char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (!new_node) {
        perror("Error allocating memory");
        exit(1);
    }
    new_node->data = strdup(data);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void display_lines(struct node *node) {
    struct node *current = node;
    while (current!= NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    char *buffer = NULL;
    size_t length = 0;
    int c = getc(stdin);
    while (c!= EOF) {
        length += 1;
        if (length >= MAX_CHAR_LENGTH) {
            rewind(stdin);
            return 1;
        }
        buffer = realloc(buffer, length + 1);
        if (!buffer) {
            perror("Error allocating memory");
            exit(1);
        }
        c = getc(stdin);
        buffer[length] = '\0';
    }
    char *line = strtok(buffer, "\n");
    while (line!= NULL) {
        add_node(line);
        line = strtok(NULL, "\n");
    }
    display_lines(head);
    return 0;
}