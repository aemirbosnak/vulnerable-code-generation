//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define LENGTH 100
#define DATA_SIZE sizeof(int)
#define NODE_SIZE (DATA_SIZE + sizeof(void *))

typedef struct Node {
    int data;
    void *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void error_handler(const char *msg) {
    fprintf(stderr, "%s", msg);
    exit(EXIT_FAILURE);
}

Node *create_node(int data) {
    Node *new_node = mmap(NULL, NODE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (new_node == MAP_FAILED)
        error_handler("Failed to allocate memory for new node\n");

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void free_node(Node *node) {
    munmap(node, NODE_SIZE);
}

void insert_at_head(int data) {
    Node *new_node = create_node(data);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_tail(int data) {
    Node *new_node = create_node(data);

    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_list() {
    Node *current = head;

    printf("Linked List:\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int i;

    for (i = 0; i < LENGTH / 2; i++)
        insert_at_head(i);

    for (i = 0; i < LENGTH / 2; i++) {
        int temp = i;
        insert_at_tail(temp);
    }

    print_list();

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free_node(temp);
    }

    return EXIT_SUCCESS;
}