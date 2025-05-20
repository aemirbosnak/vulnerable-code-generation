//FormAI DATASET v1.0 Category: Networking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024 // Buffer size for sending and receiving data

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    char buffer[BUF_SIZE]; // Buffer for sending and receiving data
    int read_size;

    // Create a socket
    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(server_sock == -1)
        error_handling("socket() error");

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1])); // Use the first command line argument as port number

    // Bind the socket to the server address
    if(bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
        error_handling("bind() error");

    // Listen for incoming connections
    if(listen(server_sock, 5) == -1)
        error_handling("listen() error");

    printf("Server starts listening at port %d.\n", atoi(argv[1]));

    // Accept incoming connections
    client_addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_size);
    if(client_sock == -1)
        error_handling("accept() error");

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while(true)
    {
        // Receive data from the client
        read_size = recv(client_sock, buffer, BUF_SIZE, 0);
        if(read_size == -1)
            error_handling("recv() error");
        else if(read_size == 0)
            break;

        printf("Received data from client: %s", buffer);

        // Send data back to the client
        if(send(client_sock, buffer, strlen(buffer), 0) != strlen(buffer))
            error_handling("send() error");

        // Clear the buffer
        memset(buffer, 0, sizeof(buffer));
    }

    printf("Client disconnected.\n");

    // Close the sockets
    close(client_sock);
    close(server_sock);

    return 0;
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}