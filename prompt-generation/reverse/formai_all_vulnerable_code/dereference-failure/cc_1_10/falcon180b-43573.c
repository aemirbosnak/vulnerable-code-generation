//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    struct node *next;
} NODE;

NODE *create_node(char *name) {
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->name = strdup(name);
    node->next = NULL;
    return node;
}

void delete_node(NODE *node) {
    free(node->name);
    free(node);
}

void print_list(NODE *head) {
    NODE *current = head;
    while (current!= NULL) {
        printf("%s -> ", current->name);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    NODE *head = NULL;
    char input[MAX_SIZE];

    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        char *name = strtok(input, " ");
        if (name == NULL)
            continue;

        NODE *node = create_node(name);
        if (head == NULL) {
            head = node;
        } else {
            NODE *current = head;
            while (current->next!= NULL)
                current = current->next;
            current->next = node;
        }
    }

    printf("Linked List:\n");
    print_list(head);

    return 0;
}