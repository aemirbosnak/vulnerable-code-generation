//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

struct node {
    int id;
    char ip[16];
    int port;
    struct node *next;
};

struct node *head = NULL;

void add_node(int id, char *ip, int port) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->id = id;
    strcpy(new_node->ip, ip);
    new_node->port = port;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list() {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("ID: %d, IP: %s, Port: %d\n", temp->id, temp->ip, temp->port);
        temp = temp->next;
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 12345\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected with ID %d, IP %s, Port %d\n", client_addr.sin_port, inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

        add_node(client_addr.sin_port, inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

        close(client_socket);
    }

    return 0;
}