//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 10
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    struct list_node *next;
} list_node;

typedef struct {
    list_node *head;
    int size;
} list_manager;

void add_list(list_manager *manager, char *name, char *email) {
    list_node *new_node = malloc(sizeof(list_node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (manager->head == NULL) {
        manager->head = new_node;
        manager->size = 1;
    } else {
        list_node *current = manager->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_node;
        manager->size++;
    }
}

void remove_list(list_manager *manager, char *name) {
    list_node *current = manager->head;
    list_node *prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                manager->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            manager->size--;
            break;
        }
        prev = current;
        current = current->next;
    }
}

void display_lists(list_manager *manager) {
    list_node *current = manager->head;

    printf("Mailing Lists:\n");
    while (current!= NULL) {
        printf("Name: %s\n", current->name);
        printf("Email: %s\n", current->email);
        current = current->next;
    }
}

int main() {
    list_manager manager;
    manager.head = NULL;
    manager.size = 0;

    add_list(&manager, "John Doe", "johndoe@example.com");
    add_list(&manager, "Jane Smith", "janesmith@example.com");
    add_list(&manager, "Bob Johnson", "bobjohnson@example.com");

    display_lists(&manager);

    remove_list(&manager, "John Doe");

    display_lists(&manager);

    return 0;
}