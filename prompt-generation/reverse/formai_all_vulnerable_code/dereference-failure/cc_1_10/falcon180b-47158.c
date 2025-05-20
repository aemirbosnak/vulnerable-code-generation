//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *server_addr;
    const char *hostname = "ftp.example.com";
    int port = 21;
    char username[64] = "anonymous";
    char password[64] = "anonymous@example.com";
    char buf[BUF_SIZE];
    int nbytes;
    int connected = 0;

    memset(&buf, 0, BUF_SIZE);

    // Initialize the server address structure
    if ((server_addr = malloc(sizeof(struct addrinfo))) == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for server address structure.\n");
        exit(EXIT_FAILURE);
    }

    memset(server_addr, 0, sizeof(struct addrinfo));
    server_addr->ai_family = AF_INET;
    server_addr->ai_socktype = SOCK_STREAM;
    server_addr->ai_protocol = IPPROTO_TCP;

    // Get the server address
    if ((nbytes = getaddrinfo(hostname, NULL, server_addr, NULL))!= 0) {
        fprintf(stderr, "Error: Could not resolve hostname.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if ((sockfd = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol)) == -1) {
        fprintf(stderr, "Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, server_addr->ai_addr, server_addr->ai_addrlen) == -1) {
        fprintf(stderr, "Error: Could not connect to server.\n");
        exit(EXIT_FAILURE);
    }

    connected = 1;

    // Send the USER command
    snprintf(buf, BUF_SIZE, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send USER command.\n");
        exit(EXIT_FAILURE);
    }

    // Send the PASS command
    snprintf(buf, BUF_SIZE, "PASS %s\r\n", password);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        fprintf(stderr, "Error: Could not send PASS command.\n");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    nbytes = recv(sockfd, buf, BUF_SIZE, 0);
    if (nbytes <= 0) {
        fprintf(stderr, "Error: Could not receive server response.\n");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}