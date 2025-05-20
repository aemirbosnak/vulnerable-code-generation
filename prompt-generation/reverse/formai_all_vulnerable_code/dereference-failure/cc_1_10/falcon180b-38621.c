//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

typedef struct node {
    char name[MAX_NAME_LEN];
    int age;
    struct node *next;
} Node;

typedef struct linked_list {
    Node *head;
    int size;
} LinkedList;

LinkedList *create_linked_list() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Error: Failed to create linked list.\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_node(LinkedList *list, char *name, int age) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Failed to add node.\n");
        exit(1);
    }
    strncpy(node->name, name, MAX_NAME_LEN - 1);
    node->age = age;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *curr = list->head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = node;
    }
    list->size++;
}

void print_list(LinkedList *list) {
    Node *curr = list->head;
    while (curr!= NULL) {
        printf("Name: %s, Age: %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

int main() {
    LinkedList *list = create_linked_list();
    add_node(list, "Linus Torvalds", 52);
    add_node(list, "Greg Kroah-Hartman", 47);
    add_node(list, "Andrew Morton", 65);
    print_list(list);
    free(list);
    return 0;
}