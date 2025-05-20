//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct Node {
    int data;
    struct Node *next;
};

struct List {
    struct Node *head;
};

void createList(struct List *list) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = 1;
    node->next = NULL;
    list->head = node;
}

void addToList(struct List *list, int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

void printList(struct List *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct List list;
    createList(&list);

    // Distributed list operations
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    // Client 1
    addToList(&list, 1);
    send(sock, "1", 2, 0);

    // Client 2
    addToList(&list, 2);
    send(sock, "2", 2, 0);

    // Client 3
    addToList(&list, 3);
    send(sock, "3", 2, 0);

    // Print list on server
    printList(&list);

    close(sock);
    return 0;
}