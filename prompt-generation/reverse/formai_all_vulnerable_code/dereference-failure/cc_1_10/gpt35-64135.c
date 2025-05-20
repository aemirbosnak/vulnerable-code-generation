//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address = "mail.example.com";
    int server_port = 143;
    char *username = "username";
    char *password = "password";
    char buffer[BUFFER_SIZE], command[BUFFER_SIZE];
    ssize_t bytes;
    struct sockaddr_in server;
    struct hostent *hp;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    hp = gethostbyname(server_address);
    if (hp == NULL) {
        perror("Error: Host address not found\n");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    memcpy(&server.sin_addr.s_addr, hp->h_addr, hp->h_length);
    server.sin_port = htons(server_port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error: Connection failed\n");
        exit(EXIT_FAILURE);
    }

    bytes = read(sockfd, buffer, BUFFER_SIZE);
    if (bytes < 0) {
        perror("Error: Failed to read from server\n");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes, buffer); // Print server response

    sprintf(command, "LOGIN %s %s\r\n", username, password);
    write(sockfd, command, strlen(command));

    bytes = read(sockfd, buffer, BUFFER_SIZE);
    if (bytes < 0) {
        perror("Error: Failed to read from server\n");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes, buffer); // Print server response

    sprintf(command, "SELECT INBOX\r\n");
    write(sockfd, command, strlen(command));

    bytes = read(sockfd, buffer, BUFFER_SIZE);
    if (bytes < 0) {
        perror("Error: Failed to read from server\n");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes, buffer); // Print server response

    sprintf(command, "FETCH 1 FULL\r\n");
    write(sockfd, command, strlen(command));

    bytes = read(sockfd, buffer, BUFFER_SIZE);
    if (bytes < 0) {
        perror("Error: Failed to read from server\n");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes, buffer); // Print server response

    sprintf(command, "LOGOUT\r\n");
    write(sockfd, command, strlen(command));

    close(sockfd);

    return 0;
}