//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char data[20];
    struct node *next;
};

struct node *create_node(char data[]) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->data, data);
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head_ref, char data[]) {
    struct node *new_node = create_node(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct node *current = *head_ref;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(struct node **head_ref, char data[]) {
    struct node *current = *head_ref;
    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        fprintf(stderr, "Node not found\n");
        exit(EXIT_FAILURE);
    }
    if (current == *head_ref) {
        *head_ref = current->next;
    } else {
        struct node *prev = *head_ref;
        while (prev->next!= current) {
            prev = prev->next;
        }
        prev->next = current->next;
    }
    free(current);
}

void print_list(struct node *head) {
    struct node *current = head;
    while (current!= NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    insert_node(&head, "apple");
    insert_node(&head, "banana");
    insert_node(&head, "cherry");
    insert_node(&head, "date");
    print_list(head);
    delete_node(&head, "banana");
    print_list(head);
    return 0;
}