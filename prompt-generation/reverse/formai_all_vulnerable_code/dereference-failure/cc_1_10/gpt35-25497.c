//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if user entered a URL
    if(argc != 2) {
        printf("Please enter a URL.\n");
        return 1;
    }

    char *url = argv[1];

    // Split URL into host and path
    char *host;
    char *path;
    char *buffer = malloc(strlen(url) + 1);
    strcpy(buffer, url);

    host = buffer + 7;  // Skip "http://"
    path = strchr(host, '/');

    if(path == NULL) {
        path = "/";
    }
    else {
        *path = '\0';
        path++;
    }

    // Resolve host IP address
    struct hostent *he = gethostbyname(host);

    if(he == NULL) {
        printf("Could not resolve host: %s\n", host);
        return 1;
    }

    struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;
    char *ip_address = inet_ntoa(*addr_list[0]);

    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("Could not create socket.\n");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(80);

    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not connect to server.\n");
        return 1;
    }

    // Compose request
    char request[BUFFER_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    // Send request
    if(send(sockfd, request, strlen(request), 0) < 0) {
        printf("Could not send request.\n");
        return 1;
    }

    // Receive response
    char response[BUFFER_SIZE];
    int response_len = 0;
    int bytes_received;

    while((bytes_received = recv(sockfd, response + response_len, BUFFER_SIZE - response_len, 0)) > 0) {
        response_len += bytes_received;
    }

    if(bytes_received < 0) {
        printf("Error while receiving response.\n");
        return 1;
    }

    // Print response
    printf("%.*s", response_len, response);

    // Close socket
    close(sockfd);
    free(buffer);

    return 0;
}