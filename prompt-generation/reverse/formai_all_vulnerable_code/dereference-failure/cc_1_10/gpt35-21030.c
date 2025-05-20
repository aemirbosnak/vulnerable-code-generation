//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *url = argv[1];

    //Extracting URL parts
    char *protocol = strtok(url, ":");
    char *website = strtok(NULL, "/");
    char *path = strtok(NULL, "");

    int port = 80;
    if(strcmp(protocol, "https") == 0) {
        port = 443;
    }

    struct hostent *hostInfo;
    struct sockaddr_in server;

    hostInfo = gethostbyname(website);
    if(!hostInfo) {
        fprintf(stderr, "Error: Could not obtain host information for %s.\n", website);
        exit(EXIT_FAILURE);
    }

    server.sin_addr = *((struct in_addr*) hostInfo->h_addr);
    server.sin_port = htons(port);
    server.sin_family = AF_INET;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Error: Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Error: Could not establish connection to server.\n");
        exit(EXIT_FAILURE);
    }

    char request[MAX_BUFFER_SIZE];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, website);

    if(send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error: Could not send request to server.\n");
        exit(EXIT_FAILURE);
    }

    //Receiving response from server
    char response[MAX_BUFFER_SIZE];
    if(recv(sockfd, response, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Error: Could not receive response from server.\n");
        exit(EXIT_FAILURE);
    }

    //Printing response
    printf("%s", response);

    //Closing socket
    close(sockfd);

    return EXIT_SUCCESS;
}