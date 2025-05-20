//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: ./http_client <URL>");
        return 1;
    }

    // Parsing the URL into Hostname and Path
    char* url = argv[1];
    char* hostname = strtok(url, "/");
    char* path = strtok(NULL, "");

    // Creating Hostent Struct
    struct hostent *server;
    server = gethostbyname(hostname);

    if(server == NULL) {
        printf("Error: No such host found\n");
        return 1;
    }

    // Creating the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0) {
        printf("Error: Socket could not be created\n");
        return 1;
    }

    // Specifying the Socket Address
    struct sockaddr_in servaddr;
    bzero((char*)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(80);

    // Establishing the Connection
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    // Creating the Request
    char request[BUFFER_SIZE] = {0};
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Writing the Request to the Socket
    if(write(sockfd, request, strlen(request)) < 0) {
        printf("Error: Could not write request to socket\n");
        return 1;
    }

    // Reading the Response
    char response[BUFFER_SIZE] = {0};
    int bytes_read, total_bytes = 0;
    while((bytes_read = read(sockfd, response + total_bytes, BUFFER_SIZE)) > 0) {
        total_bytes += bytes_read;
    }

    // Printing the Response
    printf("%s\n", response);

    // Closing the Socket
    close(sockfd);

    return 0;
}