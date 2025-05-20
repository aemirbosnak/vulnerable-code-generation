//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int sock;
    int value;
};

void *convert_binary(void *arg) {
    struct node *node = arg;
    int sock = node->sock;
    int value = node->value;

    // Convert binary number to decimal
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if (value & (1 << i)) {
            result += pow(2, i);
        }
    }

    // Send result to client
    send(sock, &result, sizeof(int), 0);

    // Close socket
    close(sock);

    return NULL;
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    // Connect to server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send binary number to server
    int binary = 0b11010110;
    send(sock, &binary, sizeof(int), 0);

    // Create nodes
    struct node *node1 = malloc(sizeof(struct node));
    node1->sock = sock;
    node1->value = binary;

    // Spawn nodes
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Child node
        convert_binary(node1);
        exit(0);
    }

    // Create more nodes
    struct node *node2 = malloc(sizeof(struct node));
    node2->sock = sock;
    node2->value = binary;

    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Child node
        convert_binary(node2);
        exit(0);
    }

    // Wait for all nodes to finish
    wait(NULL);

    // Close socket
    close(sock);

    return 0;
}