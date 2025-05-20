//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        error("ERROR opening socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    if (listen(server_fd, 5) < 0)
        error("ERROR on listen");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len);
        if (client_fd < 0)
            error("ERROR on accept");
	
        // process request from client
        // forward request to target server
        // receive response from target server
        // forward response to client

        close(client_fd);
    }

    close(server_fd);
    return 0;
}