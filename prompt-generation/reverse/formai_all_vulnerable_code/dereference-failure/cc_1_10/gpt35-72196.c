//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

// Function to create a surrealistic TCP connection
void surreal_connect(char * address, int port) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET , SOCK_STREAM , 0);

    if (sock < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    printf("Socket created successfully.\n");

    server.sin_addr.s_addr = inet_addr(address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to %s at port %d.\n", address, port);

    // Surrealistic conversation with server
    strcpy(buffer, "Knock, knock.\n");

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    printf("Sent: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(1);
    }

    printf("Received: %s", buffer);

    sleep(5);

    strcpy(buffer, "Who's there?\n");

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    printf("Sent: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(1);
    }

    printf("Received: %s", buffer);

    sleep(5);

    strcpy(buffer, "Boo.\n");

    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        exit(1);
    }

    printf("Sent: %s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(1);
    }

    printf("Received: %s", buffer);

    close(sock);
}

int main(int argc, char * argv[]) {
    if (argc < 3) {
        printf("Usage: %s server_address server_port\n", argv[0]);
        exit(1);
    }

    surreal_connect(argv[1], atoi(argv[2]));

    return 0;
}