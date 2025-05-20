//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    char *server_address;
    int server_port;
    int sockfd;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    printf("Welcome to the SMTP Client example program!\n");

    if (argc < 3) {
        printf("Usage: %s server_address server_port\n", argv[0]);
        return EXIT_FAILURE;
    }

    server_address = argv[1];
    server_port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket\n");
        return EXIT_FAILURE;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        printf("Invalid server address\n");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect to server\n");
        return EXIT_FAILURE;
    }

    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    printf("Enter your email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    printf("Enter the recipient's email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    printf("Enter the email subject: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    printf("Enter the email body:\n");
    while (fgets(buffer, BUFFER_SIZE, stdin)) {
        send(sockfd, buffer, strlen(buffer), 0);
        if (buffer[0] == '.' && buffer[1] == '\n') {
            break;
        }
    }

    recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);

    printf("Email sent!\n");

    close(sockfd);
    return EXIT_SUCCESS;
}