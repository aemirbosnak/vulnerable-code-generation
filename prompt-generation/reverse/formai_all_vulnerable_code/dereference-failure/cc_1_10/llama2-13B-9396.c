//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int sock;
    char *name;
    struct node *next;
};

void recursive_network(int sock) {
    struct node *new_node, *current_node;
    char buffer[256];

    new_node = (struct node *) malloc(sizeof(struct node));
    new_node->sock = sock;
    new_node->name = "New Node";
    new_node->next = NULL;

    current_node = NULL;

    while (1) {
        if (recv(sock, buffer, 256, 0) > 0) {
            if (strcmp(buffer, "CONNECT") == 0) {
                if (current_node == NULL) {
                    current_node = new_node;
                } else {
                    current_node->next = new_node;
                    new_node = current_node;
                }
                break;
            } else if (strcmp(buffer, "DISCONNECT") == 0) {
                if (current_node == new_node) {
                    current_node = NULL;
                }
            } else {
                printf("Invalid command: %s\n", buffer);
            }
        }

        if (current_node != NULL) {
            send(sock, "Hello, client!", 13, 0);
        }

        recursive_network(sock);
    }

    free(new_node);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    recursive_network(sock);

    close(sock);

    return 0;
}