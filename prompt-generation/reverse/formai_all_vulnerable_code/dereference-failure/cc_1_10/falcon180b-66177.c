//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *data;
    struct node *next;
} node_t;

node_t *create_node(char *data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void delete_node(node_t *node) {
    free(node->data);
    free(node);
}

void print_list(node_t *head) {
    while (head!= NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

void reverse_list(node_t **head) {
    node_t *prev = NULL;
    node_t *curr = *head;
    while (curr!= NULL) {
        node_t *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    node_t *head = NULL;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            node_t *new_node = create_node(word);
            if (head == NULL) {
                head = new_node;
            } else {
                node_t *last_node = head;
                while (last_node->next!= NULL) {
                    last_node = last_node->next;
                }
                last_node->next = new_node;
            }
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Original list:\n");
    print_list(head);

    reverse_list(&head);

    printf("Reversed list:\n");
    print_list(head);

    delete_node(head);
    head = NULL;
    return 0;
}