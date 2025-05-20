//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFSIZE 16384

void error(char *);

int main(int argc, char **argv) {

    int sockfd, newsockfd, portno, clilen, n, cached = 0;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUFFSIZE + 1] = {0};
    char *cached_response = NULL;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    // Create a new socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // Bind the socket to a port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) error("ERROR on binding");

    // Listen for incoming connections
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {

        // Accept a new connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) error("ERROR on accept");

        // Zero out the buffer
        bzero(buffer, sizeof(buffer));

        // Read request from the client
        n = read(newsockfd, buffer, BUFFSIZE);
        if (n < 0) error("ERROR reading from socket");

        // Parse the request
        char* request_method = strtok(buffer, " ");
        char* request_path = strtok(NULL, " ");
        char* request_protocol = strtok(NULL, "\r\n");

        // Parse the host and port
        char* host = strstr(request_path, "://") + strlen("://");
        host = strtok(host, "/");
        char* port = strstr(host, ":");
        if (port) *port++ = '\0';

        // Get the server by host name
        server = gethostbyname(host);
        if (server == NULL) error("ERROR, no such host");

        // Create a new socket to communicate with the server
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) error("ERROR opening socket");

        // Connect to server
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr_list[0], (char *) &serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(port ? atoi(port) : 80);
        if (connect(server_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) error("ERROR connecting");

        // Check if response is already in cache
        if (cached_response != NULL) {
            // Send cached response to client
            n = write(newsockfd, cached_response, strlen(cached_response));
            if (n < 0) error("ERROR writing to socket");
            cached = 1;
        } else {
            // Forward the request to the server
            n = write(server_sockfd, buffer, strlen(buffer));
            if (n < 0) error("ERROR writing to socket");

            // Read the response from the server
            bzero(buffer, sizeof(buffer));
            n = read(server_sockfd, buffer, BUFFSIZE);
            if (n < 0) {
                error("ERROR reading from socket");
            }

            // Send response to client
            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0) error("ERROR writing to socket");

            // Cache the response
            cached_response = (char *) malloc(strlen(buffer) + 1);
            memset(cached_response, 0, strlen(buffer) + 1);
            memcpy(cached_response, buffer, strlen(buffer));
            cached = 1;

            // Close the server socket
            close(server_sockfd);
        }

        // Close the client socket
        close(newsockfd);

        // Free the cached response
        if (cached && cached_response) {
            free(cached_response);
            cached_response = NULL;
            cached = 0;
        }

    }

    // Close the main socket
    close(sockfd);

    return 0;
}

void error(char *msg) {
    perror(msg);
    exit(1);
}