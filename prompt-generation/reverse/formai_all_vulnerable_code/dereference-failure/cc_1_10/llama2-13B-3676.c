//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void init_list(struct list *list) {
    list->head = NULL;
}

void insert_node(struct list *list, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
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
    init_list(&list);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int data = rand() % 10;
        insert_node(&list, data);
    }

    print_list(&list);

    struct node *temp = list.head;
    while (temp != NULL) {
        struct node *next = temp->next;
        temp->next = NULL;
        printf("%d ", temp->data);
        free(temp);
        temp = next;
    }

    return 0;
}