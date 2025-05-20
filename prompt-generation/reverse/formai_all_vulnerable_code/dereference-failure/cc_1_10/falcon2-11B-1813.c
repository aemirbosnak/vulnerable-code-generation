//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if command-line arguments are provided correctly
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_host> <server_port>\n", argv[0]);
        exit(1);
    }

    // Get the server host and port from command-line arguments
    char *host = argv[1];
    char *port = argv[2];

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve the server's address and port
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    struct in_addr *addr = (struct in_addr *)server->h_addr_list[0];
    int port_num = atoi(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)addr, sizeof(struct in_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive data from the client
    char buf[1024];
    int len = recv(sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }

    // Send the data to the server
    if (send(sockfd, buf, len, 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive data from the server
    len = recv(sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        perror("recv");
        exit(1);
    }

    // Send the data to the client
    if (send(sockfd, buf, len, 0) < 0) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}