//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFF 1024 // Maximum buffer size for response

int main(int argc, char *argv[]) {
    if (argc != 2) { // Must provide a URL to connect to
        printf("Usage: %s url\n", argv[0]);
        exit(0);
    }

    char *url = argv[1]; // Get URL
    char *hostname;
    char *path;
    int port = 80; // Default HTTP port

    // Remove 'http://' prefix from URL
    if (strstr(url, "http://") != NULL) {
        url += strlen("http://");
    }

    // Parse hostname, path, and port
    char *saveptr;
    hostname = strtok_r(url, "/", &saveptr);
    path = strtok_r(NULL, "", &saveptr);
    char *colon = strchr(hostname, ':');
    if (colon != NULL) {
        *colon = '\0';
        port = atoi(colon + 1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get IP address of hostname
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: unknown host %s\n", hostname);
        exit(1);
    }
    struct in_addr **addr_list = (struct in_addr **)server->h_addr_list;
    char *ip_addr = inet_ntoa(*addr_list[0]);

    // Connect to server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0) {
        printf("Error: invalid IP address %s\n", ip_addr);
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Create HTTP request
    char request[MAX_BUFF];
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    // Send HTTP request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }

    // Receive HTTP response
    char response[MAX_BUFF];
    memset(response, 0, MAX_BUFF);
    if (recv(sockfd, response, MAX_BUFF, 0) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    // Print HTTP response
    printf("%s", response);

    // Close socket
    close(sockfd);

    return 0;
}