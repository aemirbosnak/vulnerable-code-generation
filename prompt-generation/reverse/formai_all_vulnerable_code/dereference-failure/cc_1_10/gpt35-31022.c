//FormAI DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define PORT 80 // The default HTTP port

void usage(char *program_name) {
    printf("Usage: %s [-t timeout] host\n", program_name);
    exit(1);
}

void ping(char *host, int timeout) {
    struct sockaddr_in address;
    int sock, status;
    struct timeval tv;
    struct hostent *server;

    // Initialize socket address structure
    bzero((char *)&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    // Resolve hostname to IP address
    server = gethostbyname(host);
    if (server == NULL) {
        printf("Cannot resolve hostname %s\n", host);
        exit(1);
    }
    memcpy(&address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Cannot create socket\n");
        exit(1);
    }

    // Set socket receive timeout
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(struct timeval));

    // Connect to the server
    status = connect(sock, (struct sockaddr *)&address, sizeof(address));
    if (status < 0) {
        printf("Ping %s timed out\n", host);
    } else {
        printf("Ping %s OK\n", host);
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    int timeout = 5; // Default timeout is 5 seconds
    char *host;

    // Parse command line arguments
    if (argc < 2) {
        usage(argv[0]);
    }
    host = argv[argc - 1];
    if (argc == 3 && strcmp(argv[1], "-t") == 0) {
        timeout = atoi(argv[2]);
    }

    // Seed random number generator
    srand(time(NULL));

    // Ping the host multiple times in random order
    for (int i = 0; i < 3; i++) {
        int delay = rand() % 5;
        sleep(delay);
        ping(host, timeout);
    }

    return 0;
}