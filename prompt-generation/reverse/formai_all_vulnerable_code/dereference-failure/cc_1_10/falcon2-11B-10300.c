//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Open a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Get the server address and port number
    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(EXIT_FAILURE);
    }
    portno = htons(21);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)server->h_addr, server->h_length) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send a login request
    char username[100], password[100];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // Receive the server's response
    char response[100];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("Response: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}