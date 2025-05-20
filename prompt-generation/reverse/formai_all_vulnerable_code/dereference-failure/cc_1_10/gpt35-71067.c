//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_ADDR "ftp.server.com"
#define SERVER_PORT 21

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd, n;
    char buffer[256];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket.");
        exit(1);
    }

    // resolve server hostname
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve server hostname.");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server.");
        exit(1);
    }

    // send login credentials
    printf("Username: ");
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: Could not send username.");
        exit(1);
    }

    printf("Password: ");
    fgets(buffer, 255, stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: Could not send password.");
        exit(1);
    }

    // receive server response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read server response.");
        exit(1);
    }

    printf("Server Response: %s", buffer);

    // close socket
    close(sockfd);

    return 0;
}