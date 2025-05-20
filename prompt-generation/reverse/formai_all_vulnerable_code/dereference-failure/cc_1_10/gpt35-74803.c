//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#define PORT 80
#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        printf("Please provide the URL to connect to.\n");
        return -1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Host not found.\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server.\n");
        return -1;
    }

    // HTTP request
    char request[MAX_BUFFER_SIZE];
    memset(request, 0, sizeof(request));
    strcpy(request, "GET / HTTP/1.1\r\n");
    strcat(request, "Host: ");
    strcat(request, argv[1]);
    strcat(request, "\r\nConnection: close\r\n\r\n");

    // Send the request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending HTTP request.\n");
        return -1;
    }

    // Receive the response from the server
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}