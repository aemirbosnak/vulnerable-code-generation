//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

void create_list(struct list *list) {
    list->head = (struct node *) malloc(sizeof(struct node));
    list->tail = list->head;
    list->head->data = 1;
    list->head->next = NULL;
}

void add_node(struct list *list, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail == list->head) {
        list->tail = new_node;
        list->head->next = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct list list;
    create_list(&list);
    add_node(&list, 2);
    add_node(&list, 4);
    add_node(&list, 6);
    print_list(&list);
    return 0;
}