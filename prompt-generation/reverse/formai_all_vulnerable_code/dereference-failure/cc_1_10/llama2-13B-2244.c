//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int data;
    struct node* next;
};

struct list {
    struct node* head;
    struct node* tail;
};

void create_list(struct list* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insert_node(struct list* list, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(struct list* list) {
    struct node* current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct list list;

    create_list(&list);

    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    insert_node(&list, 5);

    print_list(&list);

    return 0;
}