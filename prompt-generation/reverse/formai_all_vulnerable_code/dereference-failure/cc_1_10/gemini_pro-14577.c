//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 100
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port1> [port2] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the host address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Create the sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)host->h_addr)));

    // Scan the ports
    for (int i = 2; i < argc; i++) {
        int port = atoi(argv[i]);
        if (port < 0 || port > 65535) {
            fprintf(stderr, "Invalid port: %s\n", argv[i]);
            continue;
        }

        addr.sin_port = htons(port);

        // Connect to the port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                perror("connect");
                return EXIT_FAILURE;
            }
        } else {
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}