//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char* name;
    struct list* next;
};

struct list* head = NULL;

void add_to_list(char* name) {
    struct list* new_node = (struct list*) malloc(sizeof(struct list));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->name = strdup(name);
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct list* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display_list() {
    struct list* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp!= NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

void remove_from_list(char* name) {
    struct list* temp = head;
    struct list* prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp->name);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Name not found in list\n");
}

int main() {
    add_to_list("Alice");
    add_to_list("Bob");
    add_to_list("Charlie");
    display_list();
    remove_from_list("Bob");
    display_list();
    remove_from_list("Charlie");
    display_list();
    remove_from_list("Alice");
    display_list();
    return 0;
}