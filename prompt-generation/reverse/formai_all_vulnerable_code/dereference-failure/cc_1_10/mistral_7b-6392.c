//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"

struct knight_message {
    char command[16];
    char data[100];
};

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    struct knight_message message;

    // Initialize message
    strcpy(message.command, "REQUEST_KNIGHT_DATA");

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the castle
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Send knight data request
    if (send(sockfd, &message, sizeof(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print received message
    printf("Received message from castle:\n%s\n", buffer);

    // Close connection
    close(sockfd);
    return 0;
}