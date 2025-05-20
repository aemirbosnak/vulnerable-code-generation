//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

void add_node(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void check_for_duplicate(Node* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Error: Duplicate name.\n");
            exit(1);
        }
        head = head->next;
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    add_node(&head, "John Doe");
    add_node(&head, "Jane Doe");
    add_node(&head, "Bob Smith");

    print_list(head);

    check_for_duplicate(head, "Jane Doe");

    add_node(&head, "Alice White");

    print_list(head);

    return 0;
}