//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIST_SIZE 100
#define ELEMENT_SIZE sizeof(struct Element)
#define ECHO_TIME 10000000

typedef struct Element {
    int data;
    struct Element *next;
} Element;

Element *create_node(int data) {
    Element *new_node = (Element *) malloc(ELEMENT_SIZE);
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append_to_list(Element **head, Element *new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Element *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(Element *head) {
    Element *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void echo_and_delete(Element *node) {
    write(STDOUT_FILENO, &node->data, sizeof(node->data));
    usleep(ECHO_TIME);
    free(node);
}

void delete_node(Element **head, Element *node) {
    if (*head == node) {
        *head = node->next;
        echo_and_delete(node);
        return;
    }

    Element *current = *head;
    while (current->next != node) {
        current = current->next;
    }
    current->next = node->next;
    echo_and_delete(node);
}

int main() {
    Element *head = NULL;
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        Element *new_node = create_node(rand() % 100);
        append_to_list(&head, new_node);
    }

    printf("Initial list:\n");
    print_list(head);

    Element *node_to_delete = head;
    while (node_to_delete != NULL) {
        Element *next_node = node_to_delete->next;
        if (next_node != NULL && next_node->data > node_to_delete->data) {
            Element *temp = node_to_delete->next;
            delete_node(&head, node_to_delete);
            append_to_list(&head, temp);
        }
        node_to_delete = next_node;
    }

    printf("Sorted list:\n");
    print_list(head);

    free(head);
    return 0;
}