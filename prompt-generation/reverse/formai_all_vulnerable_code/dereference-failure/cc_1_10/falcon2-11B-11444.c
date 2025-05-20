//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to send HTTP GET request
void send_http_request(char *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolve hostname
    server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Store the server's IP address
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Store the port number
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send HTTP GET request
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, host);
    strcat(request, "\r\n\r\n");

    send(sockfd, request, strlen(request), 0);

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    send_http_request(argv[1], atoi(argv[2]));

    return 0;
}