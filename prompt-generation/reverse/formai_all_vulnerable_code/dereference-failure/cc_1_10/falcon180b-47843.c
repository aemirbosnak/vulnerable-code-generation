//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_LEN 1024
#define MAX_RESPONSE_LEN 4096
#define PORT 80

char *request_method = "GET";
char *request_path = "/";
char *request_version = "HTTP/1.1";

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *request = malloc(MAX_REQUEST_LEN);
    char *response = malloc(MAX_RESPONSE_LEN);
    char *ptr;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Build request
    sprintf(request, "%s %s HTTP/%s\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n", request_method, request_path, request_version);

    // Send request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    // Receive response
    memset(response, 0, MAX_RESPONSE_LEN);
    if (recv(sockfd, response, MAX_RESPONSE_LEN, 0) == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Print response
    printf("Response:\n%s", response);

    // Close socket
    close(sockfd);

    return 0;
}