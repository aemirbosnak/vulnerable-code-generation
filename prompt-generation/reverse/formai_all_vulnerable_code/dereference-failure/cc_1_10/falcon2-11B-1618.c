//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Create an address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a ping request
    char ping_request[MAX_BUFFER_SIZE];
    sprintf(ping_request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(socket_fd, ping_request, strlen(ping_request), 0);

    // Receive the response
    char response[MAX_BUFFER_SIZE];
    if (recv(socket_fd, response, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Close the socket
    close(socket_fd);

    printf("Response from %s:\n%s\n", argv[1], response);

    return 0;
}