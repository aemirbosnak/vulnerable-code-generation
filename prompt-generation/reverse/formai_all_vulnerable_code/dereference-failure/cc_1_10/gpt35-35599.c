//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024

char host[256];
char page[1024];
char request[MAX_REQUEST_SIZE];
int port = 80;
bool is_secure = false; // Assuming HTTP by default

int main(int argc, char *argv[]) {
    
    // Parsing command line arguments
    
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Extracting host and page from URL
    
    if (strstr(argv[1], "https://") == NULL) {
        is_secure = false;
    } else {
        is_secure = true;
        port = 443; // HTTPS port
    }
    
    int start_index = is_secure ? 8 : 7;
    int end_index = strstr(argv[1], "/") - argv[1];
    strncpy(host, argv[1] + start_index, end_index - start_index);
    strncpy(page, argv[1] + end_index, strlen(argv[1]) - end_index);
    
    // Creating request message
    
    sprintf(request, "GET %s HTTP/1.1\r\n", page);
    sprintf(request + strlen(request), "Host: %s\r\n", host);
    sprintf(request + strlen(request), "Connection: close\r\n");
    sprintf(request + strlen(request), "\r\n");
    
    // Establishing connection to server
    
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket\n");
        exit(EXIT_FAILURE);
    }
    
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server\n");
        exit(EXIT_FAILURE);
    }
    
    // Sending request message and receiving response
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Could not send request message\n");
        exit(EXIT_FAILURE);
    }
    
    char response[4096];
    memset(response, '\0', sizeof(response));
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response + bytes_received, sizeof(response) - bytes_received, 0)) > 0) {
        // Do nothing
    }
    
    // Parsing response message and printing headers and content
    
    char *body_start = strstr(response, "\r\n\r\n") + 4;
    *(body_start - 4) = '\0';
    printf("%s\n\n", response);
    printf("%s\n", body_start);
    
    close(sockfd);
    return 0;
}