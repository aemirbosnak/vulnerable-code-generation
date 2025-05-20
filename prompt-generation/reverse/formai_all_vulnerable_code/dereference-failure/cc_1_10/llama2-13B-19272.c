//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
};

void create_list(struct list *list) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = 10;
    new_node->next = NULL;
    list->head = new_node;
}

void add_node(struct list *list, int data) {
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

void delete_node(struct list *list, int data) {
    struct node *current = list->head;
    struct node *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    struct list list;
    create_list(&list);

    // Distributed list operations
    int sock;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
    };
    connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    add_node(&list, 20);
    add_node(&list, 30);
    add_node(&list, 40);

    // Send list to server
    struct node *node = list.head;
    send(sock, (void *) &node, sizeof(struct node), 0);

    // Receive list from server
    struct node *received_node = (struct node *) malloc(sizeof(struct node));
    recv(sock, (void *) received_node, sizeof(struct node), 0);

    // Print received list
    print_list(&received_node);

    // Delete node 30 from received list
    delete_node(&received_node, 30);

    // Send updated list to server
    struct node *updated_node = received_node->next;
    send(sock, (void *) &updated_node, sizeof(struct node), 0);

    // Receive updated list from server
    received_node = (struct node *) malloc(sizeof(struct node));
    recv(sock, (void *) received_node, sizeof(struct node), 0);

    // Print updated list
    print_list(&received_node);

    close(sock);
    return 0;
}