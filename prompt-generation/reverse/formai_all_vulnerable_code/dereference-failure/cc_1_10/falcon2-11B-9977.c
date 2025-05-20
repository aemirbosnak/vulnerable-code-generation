//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Convert the hostname to a C-style string
    char hostname[1024];
    strncpy(hostname, argv[1], sizeof(hostname));

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    // Prepare the address structure
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the hostname
    struct addrinfo* addrinfo = NULL;
    int err = getaddrinfo(hostname, NULL, &hints, &addrinfo);
    if (err) {
        fprintf(stderr, "Error: %s\n", gai_strerror(err));
        return 1;
    }

    // Create a TCP connection
    struct addrinfo* addr = NULL;
    for (addr = addrinfo; addr!= NULL; addr = addr->ai_next) {
        int sock_fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        if (sock_fd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock_fd, addr->ai_addr, addr->ai_addrlen) == -1) {
            perror("connect");
            close(sock_fd);
            continue;
        }

        // Send a ping request
        char ping_request[1024] = "PING 1\r\n";
        send(sock_fd, ping_request, sizeof(ping_request), 0);

        // Receive a pong response
        char pong_response[1024] = "PONG\r\n";
        int bytes_received = recv(sock_fd, pong_response, sizeof(pong_response), 0);
        if (bytes_received == -1) {
            perror("recv");
            close(sock_fd);
            continue;
        }

        // Close the connection
        close(sock_fd);

        // Print the response
        printf("Received: %s\n", pong_response);
        break;
    }

    // Clean up the address structure
    freeaddrinfo(addrinfo);

    // Close the socket
    close(socket_fd);

    return 0;
}