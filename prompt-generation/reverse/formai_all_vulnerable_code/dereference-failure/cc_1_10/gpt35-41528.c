//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char *serverURL = argv[1];
    char *port = "80";
    char *path = "/";
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes_read;
    char request[1024];
    char response[4096];

    if(argc < 2) {
        printf("Usage: %s <server URL>\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server host info
    server = gethostbyname(serverURL);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(1);
    }

    // Set server address info
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    // Connect to server
    if (connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Build HTTP request 
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, serverURL);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }

    // Read HTTP response
    bytes_read = recv(sockfd, response, sizeof(response), 0);
    while (bytes_read > 0) {
        printf("%.*s", bytes_read, response);
        bytes_read = recv(sockfd, response, sizeof(response), 0);
    }
    
    // Close socket
    close(sockfd);

    return 0;
}