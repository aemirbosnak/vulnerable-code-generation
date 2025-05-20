//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char *hostname;
    char *path;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(0);
    }

    // Extract hostname and path from URL
    char *url = argv[1];
    char *http = strstr(url, "http://");
    if (http != NULL) url = url + 7;

    char *slash = strchr(url, '/');
    if (slash == NULL) {
        hostname = url;
        path = "/";
    } else {
        *slash = '\0';
        hostname = url;
        path = slash + 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get IP address from hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host %s\n", hostname);
        exit(1);
    }

    // Clear serv_addr structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set server address
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(80);
    
    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Build HTTP request
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s:80\r\nConnection: close\r\n\r\n", path, hostname);

    // Send request to server
    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read response from server
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(sockfd, buffer, BUFFER_SIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    // Close socket
    close(sockfd);

    return 0;
}