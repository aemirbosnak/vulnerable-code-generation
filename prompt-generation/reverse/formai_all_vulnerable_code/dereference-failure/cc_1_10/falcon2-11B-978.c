//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) {
        perror("Error setting socket option");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address))) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send request
    char request[100];
    bzero(request, sizeof(request));
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (write(socket_fd, request, strlen(request))!= strlen(request)) {
        perror("Error writing request");
        exit(1);
    }

    // Receive response
    char response[1000];
    bzero(response, sizeof(response));
    int response_length = read(socket_fd, response, sizeof(response));
    if (response_length <= 0) {
        perror("Error reading response");
        exit(1);
    }
    printf("%s\n", response);

    // Close socket
    close(socket_fd);

    return 0;
}