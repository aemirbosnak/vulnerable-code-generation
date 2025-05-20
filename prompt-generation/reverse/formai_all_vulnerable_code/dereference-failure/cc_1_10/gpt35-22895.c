//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: pop3client hostname port\n");
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];

    struct addrinfo *result;
    struct addrinfo hints;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, port, &hints, &result) != 0) {
        printf("Failed to get address info\n");
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Read the server greeting
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    read(sockfd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // Send the username
    printf("Enter username: ");
    char username[MAX_BUFFER];
    fgets(username, MAX_BUFFER, stdin);
    sprintf(buffer, "USER %s", username);
    write(sockfd, buffer, strlen(buffer));

    // Read the server response
    memset(buffer, 0, MAX_BUFFER);
    read(sockfd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // Send the password
    printf("Enter password: ");
    char password[MAX_BUFFER];
    fgets(password, MAX_BUFFER, stdin);
    sprintf(buffer, "PASS %s", password);
    write(sockfd, buffer, strlen(buffer));

    // Read the server response
    memset(buffer, 0, MAX_BUFFER);
    read(sockfd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // List the messages
    write(sockfd, "LIST", strlen("LIST"));
    memset(buffer, 0, MAX_BUFFER);
    read(sockfd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // Quit the session
    write(sockfd, "QUIT", strlen("QUIT"));
    memset(buffer, 0, MAX_BUFFER);
    read(sockfd, buffer, MAX_BUFFER);
    printf("%s", buffer);

    // Cleanup
    freeaddrinfo(result);
    close(sockfd);

    return 0;
}