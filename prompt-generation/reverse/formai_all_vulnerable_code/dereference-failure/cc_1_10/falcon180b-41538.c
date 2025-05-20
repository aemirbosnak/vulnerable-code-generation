//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    char* data;
    int size;
    struct node* next;
} node;

node* create_node(char* data, int size) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = (char*) malloc(size * sizeof(char));
    new_node->size = size;
    new_node->next = NULL;
    strncpy(new_node->data, data, size);
    return new_node;
}

void add_node(node** head, char* data, int size) {
    node* new_node = create_node(data, size);
    new_node->next = *head;
    *head = new_node;
}

void delete_node(node** head, char* data) {
    node* temp = *head;
    node* prev = NULL;

    while (temp!= NULL && strcmp(temp->data, data)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp->data);
    free(temp);
}

void search_node(node* head, char* data) {
    node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Node not found.\n");
}

void print_list(node* head) {
    node* temp = head;

    while (temp!= NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    node* head = NULL;

    add_node(&head, "Neo", 4);
    add_node(&head, "Morpheus", 8);
    add_node(&head, "Trinity", 7);
    add_node(&head, "Agent Smith", 11);

    print_list(head);

    delete_node(&head, "Morpheus");

    print_list(head);

    search_node(head, "Trinity");

    return 0;
}