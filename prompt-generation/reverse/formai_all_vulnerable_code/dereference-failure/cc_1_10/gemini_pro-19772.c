//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <err.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFSIZE 1024
#define MAXPORTS 65536

// I wanna be a global variable!
static int sockfd; // Socket file descriptor

static void usage(char *progname) {
    fprintf(stderr, "Usage: %s [-h] <host>\n", progname);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -h  Print this help message and exit.\n");
}

static int connect_to_host(char *host, int port) {
    struct sockaddr_in addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        err(1, "socket");

    // Resolve the hostname
    struct hostent *he = gethostbyname(host);
    if (he == NULL)
        errx(1, "gethostbyname: %s", host);

    // Fill in the sockaddr_in structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *)he->h_addr);
    addr.sin_port = htons(port);

    // Connect to the host
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
        return -1;

    return 0;
}

static void scan_ports(char *host) {
    char buf[BUFSIZE];
    int port;

    // Iterate through all the ports
    for (port = 1; port <= MAXPORTS; port++) {
        // Connect to the host on the current port
        if (connect_to_host(host, port) == 0) {
            // We were able to connect, so print the port number
            printf("Port %d is open\n", port);

            // Read data from the host until we get an error
            while (read(sockfd, buf, BUFSIZE) > 0)
                printf("%s", buf);
        }

        // Close the socket
        close(sockfd);
    }
}

int main(int argc, char **argv) {
    char *host;

    // Parse the command-line arguments
    if (argc < 2 || argc > 3) {
        usage(argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-h") == 0) {
        usage(argv[0]);
        exit(0);
    }

    host = argv[1];

    // Scan the ports on the host
    scan_ports(host);

    return 0;
}