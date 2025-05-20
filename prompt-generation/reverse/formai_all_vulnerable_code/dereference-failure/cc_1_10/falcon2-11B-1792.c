//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>

#define SERVER_PORT 110

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create a socket address struct for the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from a text string to binary form
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // Copy the server's IPv4 address into the socket address struct
    memcpy((char*) &serv_addr.sin_addr.s_addr, (char*) server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Receive and print the server's banner
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR reading banner");
        exit(1);
    }

    printf("Banner: %s\n", buffer);

    // Send username and password
    char username[100], password[100];
    printf("Username: ");
    fgets(username, 100, stdin);
    printf("Password: ");
    fgets(password, 100, stdin);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    // Receive server response
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR reading server response");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}