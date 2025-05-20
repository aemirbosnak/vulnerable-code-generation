//Falcon2-11B DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd, portno, n;
    char buffer[256];

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve hostname\n");
        exit(1);
    }

    portno = htons(80); // default port for HTTP

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: Could not create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = portno;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Could not connect to server\n");
        exit(1);
    }

    sprintf(buffer, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Sent message: %s\n", buffer);

    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        fprintf(stderr, "ERROR: Could not read from socket\n");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}