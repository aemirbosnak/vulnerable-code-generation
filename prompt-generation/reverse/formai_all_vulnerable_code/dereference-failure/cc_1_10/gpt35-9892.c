//FormAI DATASET v1.0 Category: Chat server ; Style: modular
/*
* A simple modular chat server program in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int sock;
    struct sockaddr address;
    int addr_len;
} connection_t;

void *process(void *ptr) {
    connection_t *conn;
    long addr = 0;
    char buffer[256];
    int len;

    if (!ptr) pthread_exit(0);
    conn = (connection_t *)ptr;

    // Get the client address
    addr = (long)((struct sockaddr_in *)&conn->address)->sin_addr.s_addr;
    printf("New Client Connected: %d.%d.%d.%d\n",
            (int)(addr & 0xff), (int)((addr >> 8) & 0xff),
            (int)((addr >> 16) & 0xff), (int)((addr >> 24) & 0xff));

    // Communication Loop
    while ((len = recv(conn->sock, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received: %s", buffer);
        send(conn->sock, buffer, len, 0);
    }

    // Free resources
    close(conn->sock);
    free(conn);
    pthread_exit(0);
}

int main(int argc, char **argv) {
    int sock = -1;
    struct sockaddr_in address;
    int port;
    pthread_t thread;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Can't create socket\n");
        return -1;
    }

    // Configure address
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    sscanf(argv[1], "%d", &port);
    address.sin_port = htons(port);

    // Bind socket to address
    if (bind(sock, (struct sockaddr *)&address, sizeof(struct sockaddr)) == -1) {
        perror("Can't bind socket\n");
        return -1;
    }

    // Listen for incoming connections
    if (listen(sock, 5) == -1) {
        perror("Can't set queue limit\n");
        return -1;
    }

    printf("Chat Server started successfully on port %d\n", port);

    // Accept incoming connections
    while (1) {
        connection_t *conn;
        int addr_len = sizeof(struct sockaddr);
        printf("Waiting for Clients...\n");

        // Create connection structure for client
        conn = (connection_t *)malloc(sizeof(connection_t));
        conn->sock = accept(sock, &conn->address, &conn->addr_len);

        // Create new thread for the client connection
        if (pthread_create(&thread, NULL, process, (void *)conn) == -1) {
            perror("Can't create thread\n");
            return -1;
        }
    }

    return 0;
}