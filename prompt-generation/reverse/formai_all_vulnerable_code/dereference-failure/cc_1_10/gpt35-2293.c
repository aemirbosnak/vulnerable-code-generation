//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, port;
    char *server_ip, *message;
    struct sockaddr_in server_addr;
    char buf[BUFSIZE];

    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <Server IP> <Server Port> <Message>\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);
    message = argv[3];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) < 0) {
        perror("Error converting IP to network address\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server\n");
        exit(1);
    }

    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server\n");
        exit(1);
    }

    if (recv(client_socket, buf, BUFSIZE, 0) < 0) {
        perror("Error receiving message from server\n");
        exit(1);
    }

    printf("Response from server: %s\n", buf);

    close(client_socket);

    return 0;
}