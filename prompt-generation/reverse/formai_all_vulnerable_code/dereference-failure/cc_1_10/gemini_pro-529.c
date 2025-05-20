//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PORT_NUM 65535
#define MAX_HOSTNAME_LEN 256

// Function to print usage message and exit
void usage(const char *argv0) {
    fprintf(stderr, "Usage: %s <hostname> [<start_port>] [<end_port>]\n", argv0);
    exit(EXIT_FAILURE);
}

// Function to resolve hostname to IP address
int resolve_hostname(const char *hostname, char *ip_addr) {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(errno));
        return EXIT_FAILURE;
    }

    if (res->ai_canonname) {
        strncpy(ip_addr, res->ai_canonname, MAX_HOSTNAME_LEN);
    } else if (res->ai_addrlen == sizeof(struct sockaddr_in)) {
        struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
        inet_ntop(AF_INET, &addr->sin_addr, ip_addr, MAX_HOSTNAME_LEN);
    } else {
        fprintf(stderr, "Unknown address family: %d\n", res->ai_family);
        freeaddrinfo(res);
        return EXIT_FAILURE;
    }

    freeaddrinfo(res);
    return EXIT_SUCCESS;
}

// Function to scan ports on a remote host
int scan_ports(const char *ip_addr, unsigned short start_port, unsigned short end_port) {
    int sockfd;
    struct sockaddr_in addr;

    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range: start_port > end_port\n");
        return EXIT_FAILURE;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    // Set the socket address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip_addr, &addr.sin_addr) != 1) {
        fprintf(stderr, "inet_pton() failed: %s\n", strerror(errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Scan ports
    for (unsigned short port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);

        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %u: open\n", port);
        } else if (errno != ECONNREFUSED) {
            perror("connect()");
            close(sockfd);
            return EXIT_FAILURE;
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME_LEN];
    char ip_addr[MAX_HOSTNAME_LEN];
    unsigned short start_port, end_port;

    // Parse command-line arguments
    if (argc < 2 || argc > 4) {
        usage(argv[0]);
    }
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);

    if (argc >= 3) {
        start_port = (unsigned short)atoi(argv[2]);
    } else {
        start_port = 0;
    }

    if (argc == 4) {
        end_port = (unsigned short)atoi(argv[3]);
    } else {
        end_port = MAX_PORT_NUM;
    }

    // Resolve hostname to IP address
    if (resolve_hostname(hostname, ip_addr) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    // Scan ports
    if (scan_ports(ip_addr, start_port, end_port) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}