//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s host port\n", argv[0]);
        exit(1);
    }

    char host[MAX_REQUEST_SIZE];
    strncpy(host, argv[1], MAX_REQUEST_SIZE);

    int port = atoi(argv[2]);
    char request[MAX_REQUEST_SIZE];

    sprintf(request, "GET / HTTP/1.1\nHost: %s\n\n", host);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0) {
        perror("Error opening socket!");
        exit(1);
    }

    struct hostent *server = gethostbyname(host);

    if (server == NULL) {
        printf("Error: No such host!\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));

    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr_list[0], (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server!");
        exit(1);
    }

    if (write(socket_fd, request, strlen(request)) < 0) {
        perror("Error writing to socket!");
        exit(1);
    }

    char response[MAX_REQUEST_SIZE];
    bzero(response, sizeof(response));

    if (read(socket_fd, response, sizeof(response)) < 0) {
        perror("Error reading from socket!");
        exit(1);
    }

    printf("%s\n", response);

    close(socket_fd);

    return 0;
}