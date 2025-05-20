//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {

    // Default port number and host
    int port = 80; 
    char *host = "www.example.com";
    char *path = "/";

    // Parse command line arguments if any
    if (argc > 1) {
        host = argv[1];

        if (argc > 2) {
            port = atoi(argv[2]);
        }

        if (argc > 3) {
            path = argv[3];
        }
    }

    // Resolve host address and create a socket
    struct hostent *he;
    he = gethostbyname(host);
    if (he == NULL) {
        printf("Could not resolve host %s\n", host);
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        printf("Could not connect to server\n");
        exit(1);
    }

    // Prepare the HTTP request
    char *request = malloc(strlen(path) + strlen(host) + 50);
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // Send the HTTP request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Could not send HTTP request\n");
        exit(1);
    }

    // Receive the HTTP response
    char *response = malloc(1024);
    int bytes_received = recv(sockfd, response, 1024, 0);
    if (bytes_received == -1) {
        printf("Could not receive HTTP response\n");
        exit(1);
    }

    // Print the HTTP response
    printf("%.*s", bytes_received, response);

    // Clean up
    free(request);
    free(response);
    close(sockfd);

    return 0;
}