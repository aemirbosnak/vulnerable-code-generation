//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

struct node {
    char name[MAX_NAME_LENGTH];
    struct node* next;
};

struct index_node {
    char keyword[MAX_NAME_LENGTH];
    struct index_node* next;
    struct node* head;
};

void insert_node(struct node** head, char* name) {
    struct node* new_node = malloc(sizeof(struct node));
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_index_node(struct index_node** head, char* keyword) {
    struct index_node* new_node = malloc(sizeof(struct index_node));
    strcpy(new_node->keyword, keyword);
    new_node->next = NULL;
    new_node->head = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct index_node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int search_node(struct node* head, char* name) {
    struct node* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    struct node* head = NULL;
    insert_node(&head, "John Doe");
    insert_node(&head, "Jane Doe");
    insert_node(&head, "Peter Pan");

    struct index_node* index_head = NULL;
    insert_index_node(&index_head, "Doe");
    insert_index_node(&index_head, "Pan");

    if (search_node(head, "John Doe") == 1) {
        printf("John Doe found.\n");
    }

    if (search_node(head, "Peter Pan") == 1) {
        printf("Peter Pan found.\n");
    }

    return 0;
}