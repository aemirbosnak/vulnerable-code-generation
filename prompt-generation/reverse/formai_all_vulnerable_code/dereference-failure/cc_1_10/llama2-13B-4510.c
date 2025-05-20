//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_MESSAGE_LEN 1024

struct node {
    int sock;
    char name[50];
    struct node *next;
};

void create_nodes(int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->sock = socket(AF_INET, SOCK_STREAM, 0);
        node->name[0] = '\0';
        node->next = NULL;
        if (node->sock == -1) {
            perror("socket creation failed");
            exit(EXIT_FAILURE);
        }
        printf("Node %d: %s\n", i, node->name);
    }
}

void send_message(int sock, char *message) {
    int bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    printf("Message sent to node %d: %s\n", sock, message);
}

void recv_message(int sock, char *message) {
    int bytes_recv = recv(sock, message, MAX_MESSAGE_LEN, 0);
    if (bytes_recv < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Message received from node %d: %s\n", sock, message);
}

void print_network(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("Node %d: %s\n", current->sock, current->name);
        current = current->next;
    }
}

int main() {
    int num_nodes = 5;
    struct node *head = NULL;

    create_nodes(num_nodes);

    // Create connections between nodes
    for (int i = 0; i < num_nodes; i++) {
        int random_node = rand() % num_nodes;
        send_message(head->sock, "Hello, neighbor!");
        recv_message(head->sock, NULL);
        head = head->next;
    }

    // Simulate network activity
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < num_nodes; j++) {
            int random_node = rand() % num_nodes;
            send_message(random_node, "Hello, world!");
            recv_message(random_node, NULL);
        }
    }

    // Print the network
    print_network(head);

    return 0;
}