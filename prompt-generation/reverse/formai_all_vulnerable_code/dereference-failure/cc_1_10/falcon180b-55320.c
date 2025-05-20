//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} Node;

Node *create_node(char *data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error: could not allocate new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void delete_node(Node *node) {
    if (node == NULL) {
        printf("Error: attempting to delete a null node\n");
        exit(1);
    }
    free(node->data);
    free(node);
}

void add_to_list(Node **list, char *data) {
    Node *new_node = create_node(data);
    Node *current = *list;
    if (current == NULL) {
        *list = new_node;
        return;
    }
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(Node *list) {
    Node *current = list;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *list = NULL;
    char input[100];
    printf("Enter strings to add to the list (enter 'done' to finish):\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        add_to_list(&list, input);
    }
    printf("List:\n");
    print_list(list);
    delete_node(list);
    return 0;
}