//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd, portno, n;
    char buffer[MAX_BUFFER_SIZE];
    char *host, *path;

    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(0);
    }

    // split the url into host and path
    host = argv[1];
    path = strstr(host, "/");
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }

    // get the server IP address
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(0);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: cannot open socket");
        exit(0);
    }

    // set server address and port number
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    portno = DEFAULT_PORT;
    server_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: cannot connect to server");
        exit(0);
    }

    // send HTTP request
    snprintf(buffer, sizeof(buffer), "GET /%s HTTP/1.0\nHost: %s\n\n", path, host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: cannot write to socket");
        exit(0);
    }

    // receive HTTP response
    bzero(buffer, sizeof(buffer));
    while (read(sockfd, buffer, sizeof(buffer)-1) > 0) {
        printf("%s", buffer);
        bzero(buffer, sizeof(buffer));
    }

    // close socket
    close(sockfd);
    return 0;
}