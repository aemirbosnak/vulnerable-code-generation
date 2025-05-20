//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    int port = 8000;
    char server_address[BUFFER_SIZE];
    int sockfd;

    if (argc > 1) {
        strcpy(server_address, argv[1]);
    } else {
        strcpy(server_address, "127.0.0.1");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with server.\n");

    char buffer[BUFFER_SIZE];
    int num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[num_bytes] = '\0';

    printf("Received message from server: %s", buffer);

    char message[BUFFER_SIZE];
    printf("Enter a message to send to server: ");
    fgets(message, BUFFER_SIZE, stdin);

    int message_len = strlen(message);

    if (send(sockfd, message, message_len, 0) != message_len) {
        perror("send()");
        exit(EXIT_FAILURE);
    }

    printf("Message sent to server.\n");

    close(sockfd);
    
    return 0;

}