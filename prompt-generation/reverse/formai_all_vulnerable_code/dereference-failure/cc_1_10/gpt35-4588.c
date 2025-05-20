//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error - Could not open socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error - Could not resolve Hostname");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error - Could not connect to the server");
        exit(EXIT_FAILURE);
    }

    char *http_request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, http_request, argv[1]);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error - Could not write to server");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error - Could not read from server");
        exit(EXIT_FAILURE);
    }

    printf("The response received from the server is:\n%s\n", buffer);
    close(sockfd);

    return 0;
}