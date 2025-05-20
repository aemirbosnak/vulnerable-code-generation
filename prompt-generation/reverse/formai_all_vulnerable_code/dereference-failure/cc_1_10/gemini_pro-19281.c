//GEMINI-pro DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

struct node {
    int sockfd;
    struct sockaddr_in addr;
    struct node *next;
};

struct node *head = NULL;

void add_node(int sockfd, struct sockaddr_in addr) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->sockfd = sockfd;
    new_node->addr = addr;
    new_node->next = head;
    head = new_node;
}

void remove_node(int sockfd) {
    struct node *curr_node = head;
    struct node *prev_node = NULL;

    while (curr_node != NULL) {
        if (curr_node->sockfd == sockfd) {
            if (prev_node != NULL) {
                prev_node->next = curr_node->next;
            } else {
                head = curr_node->next;
            }
            free(curr_node);
            break;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Bind server socket to address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, addr_len) == -1) {
        perror("bind");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) == -1) {
        perror("listen");
        return -1;
    }

    // Main loop
    while (1) {
        // Accept incoming connection
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Add client to list of nodes
        add_node(client_sockfd, client_addr);

        // Send message to client
        char *message = "Hello, world!\n";
        if (send(client_sockfd, message, strlen(message), 0) == -1) {
            perror("send");
            remove_node(client_sockfd);
            continue;
        }

        // Receive message from client
        char buffer[1024];
        int bytes_received = recv(client_sockfd, buffer, 1024, 0);
        if (bytes_received == -1) {
            perror("recv");
            remove_node(client_sockfd);
            continue;
        } else if (bytes_received == 0) {
            // Client has closed connection
            remove_node(client_sockfd);
            continue;
        }

        // Print message from client
        printf("Received message from client: %s", buffer);

        // Broadcast message to all other clients
        struct node *curr_node = head;
        while (curr_node != NULL) {
            if (curr_node->sockfd != client_sockfd) {
                if (send(curr_node->sockfd, buffer, bytes_received, 0) == -1) {
                    perror("send");
                    remove_node(curr_node->sockfd);
                }
            }
            curr_node = curr_node->next;
        }

        // Close client socket
        close(client_sockfd);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}