//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    char name[50];
    struct node* next;
} node;

node* head = NULL;

void add_to_list(int id, char* name) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->name, name);
    new_node->id = id;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    node* temp = head;
    while (temp!= NULL) {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
}

void search_by_name(char* name) {
    node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found name '%s' with ID %d\n", temp->name, temp->id);
        }
        temp = temp->next;
    }
}

void search_by_id(int id) {
    node* temp = head;
    while (temp!= NULL) {
        if (temp->id == id) {
            printf("Found ID %d with name '%s'\n", id, temp->name);
        }
        temp = temp->next;
    }
}

int main() {
    add_to_list(1, "Alice");
    add_to_list(2, "Bob");
    add_to_list(3, "Charlie");
    add_to_list(4, "David");

    print_list();

    search_by_name("Alice");
    search_by_name("Bob");
    search_by_name("Charlie");

    search_by_id(1);
    search_by_id(3);

    return 0;
}