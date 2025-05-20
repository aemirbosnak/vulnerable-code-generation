//FormAI DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 256

void error_handling(char* message);

int main(int argc, char* argv[])
{
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char message[BUF_SIZE];

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Initialize socket
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
        error_handling("socket() error");

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to server address structure
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("bind() error");

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1)
        error_handling("listen() error");

    // Accept incoming connection request
    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    if (client_sock == -1)
        error_handling("accept() error");

    // Receive message from client
    read(client_sock, message, BUF_SIZE);

    // Print received message
    printf("Message from client: %s\n", message);

    // Send message back to client
    write(client_sock, message, strlen(message));

    // Close sockets
    close(client_sock);
    close(server_sock);

    return 0;
}

void error_handling(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}