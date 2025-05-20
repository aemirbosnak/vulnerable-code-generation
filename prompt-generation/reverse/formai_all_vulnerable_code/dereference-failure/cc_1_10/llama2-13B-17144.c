//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 10
#define MAX_DATA 100

struct node {
    int data;
    struct node *next;
};

void* dist_linked_list_create(int nodes) {
    struct node *head = NULL;
    int i;

    for (i = 0; i < nodes; i++) {
        struct node *node = malloc(sizeof(struct node));
        node->data = i % 2 ? 1 : 2;
        node->next = head;
        head = node;
    }

    return head;
}

void dist_linked_list_insert(void* head_ptr, int data) {
    struct node *head = head_ptr;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void dist_linked_list_delete(void* head_ptr, int data) {
    struct node *head = head_ptr;
    struct node *current = head;

    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL && current->next->data == data) {
        current->next = current->next->next;
    }
}

void dist_linked_list_traverse(void* head_ptr) {
    struct node *head = head_ptr;
    struct node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main(int argc, char** argv) {
    int nodes = atoi(argv[1]);
    void* head_ptr = dist_linked_list_create(nodes);

    for (int i = 0; i < nodes; i++) {
        dist_linked_list_insert(head_ptr, i % 2 ? 1 : 2);
    }

    dist_linked_list_delete(head_ptr, 1);

    dist_linked_list_traverse(head_ptr);

    return 0;
}