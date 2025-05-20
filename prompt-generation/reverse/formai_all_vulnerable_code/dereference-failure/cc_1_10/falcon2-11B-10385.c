//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Create a TCP/IP socket
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Parse command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve hostname: %s\n", argv[1]);
        exit(1);
    }

    // Fill in the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Send a greeting message to the server
    char msg[1024];
    sprintf(msg, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, msg, strlen(msg), 0);

    // Receive the server's response
    char response[1024];
    int n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("ERROR receiving response");
        exit(1);
    }

    // Print the server's response
    printf("Response from server: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}