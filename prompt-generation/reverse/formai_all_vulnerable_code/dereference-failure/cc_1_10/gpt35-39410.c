//FormAI DATASET v1.0 Category: Client Server Application ; Style: detailed
/* This is a simple example of a client-server application using sockets in C. The server listens to incoming
   client requests and sends a message back to the client. */

#include <stdio.h>
#include <stdlib.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 256 // Buffer size

int main(int argc, char *argv[]) {
    int serv_sock, cli_sock; // Server and client sockets
    struct sockaddr_in serv_addr, cli_addr; // Server and client addresses
    socklen_t cli_addr_size;
    char buf[BUF_SIZE]; // Buffer to store incoming message from client
    int str_len;

    if(argc != 2) { // Check command-line argument
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // Set server socket address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind server socket
    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    // Listen to incoming connection requests
    if(listen(serv_sock, 5) == -1) {
        perror("listen() error");
        exit(1);
    }

    printf("Server waiting for client...\n");

    // Accept incoming connection request
    cli_addr_size = sizeof(cli_addr);
    cli_sock = accept(serv_sock, (struct sockaddr*)&cli_addr, &cli_addr_size);
    if(cli_sock == -1) {
        perror("accept() error");
        exit(1);
    }

    printf("Client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

    // Receive message from client
    str_len = read(cli_sock, buf, BUF_SIZE);
    if(str_len == -1) {
        perror("read() error");
        exit(1);
    }

    // Print client message
    buf[str_len] = '\0';
    printf("Client message: %s\n", buf);

    // Send message to client
    if(write(cli_sock, buf, str_len) == -1) {
        perror("write() error");
        exit(1);
    }

    // Close sockets
    close(cli_sock);
    close(serv_sock);

    return 0;
}