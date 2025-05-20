//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <server port>\n", argv[0]);
        exit(1);
    }

    // Create a socket for the client
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket()");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect()");
        exit(1);
    }

    // Send a message to the server
    char message[] = "My heart is aflame with passion for thee, O Juliet!";
    if (send(client_sock, message, sizeof(message), 0) == -1) {
        perror("send()");
        exit(1);
    }

    // Receive a message from the server
    char buffer[BUF_SIZE];
    if (recv(client_sock, buffer, BUF_SIZE, 0) == -1) {
        perror("recv()");
        exit(1);
    }

    // Print the message from the server
    printf("Juliet says: %s\n", buffer);

    // Close the client socket
    close(client_sock);

    return 0;
}