//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // parse command line arguments
    char *host = argv[1];
    unsigned short port = atoi(argv[2]);

    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // set socket options
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // initialize socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_aton(host, &addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // send data to the server
    char *data = "Hello, world!";
    if (send(sock, data, strlen(data), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // receive data from the server
    char buffer[1024];
    int n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // print the received data
    printf("%s\n", buffer);

    // close the socket
    close(sock);

    return EXIT_SUCCESS;
}