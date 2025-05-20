//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 1024

int main(int argc, char *argv[]) {

    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s [url]\n", argv[0]);
        return 1;
    }

    // Parse url into host and path
    char url[strlen(argv[1])];
    strcpy(url, argv[1]);
    char *host = strtok(url, "/");
    char *path = strtok(NULL, "");

    // Get IP address from host name
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Error: Unknown host %s\n", host);
        return 2;
    }
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    char *ip = inet_ntoa(*addr_list[0]);

    // Create socket for HTTP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return 3;
    }

    // Connect to the server using IP address and port 80
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server\n");
        return 4;
    }

    // Send HTTP GET request for the path
    char request[1024];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request\n");
        return 5;
    }

    // Receive response from server
    char response[MAX_RESPONSE_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }
    if (bytes_received < 0) {
        printf("Error: Could not receive response\n");
        return 6;
    }

    // Clean up and exit
    close(sockfd);
    return 0;
}