//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_PORT 65535
#define MIN_PORT 1
#define TIMEOUT 5

// Function to perform port scanning
void scan_port(char* hostname, int port) {
    struct sockaddr_in addr;
    int sd, status, flags;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(hostname);

    // Create socket
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set socket to non-blocking mode
    flags = fcntl(sd, F_GETFL, 0);
    fcntl(sd, F_SETFL, flags | O_NONBLOCK);

    // Attempt to connect to port
    status = connect(sd, (struct sockaddr*)&addr, sizeof(addr));
    if (status < 0 && errno != EINPROGRESS) {
        perror("Failed to connect to port");
        exit(1);
    }

    // Wait for connection or timeout
    struct timeval timeout;
    fd_set readfds, writefds;

    FD_ZERO(&readfds);
    FD_SET(sd, &writefds);

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    status = select(sd + 1, NULL, &writefds, NULL, &timeout);

    if (status < 0) {
        perror("Select error");
        exit(1);
    } else if (status == 0) {
        printf("Port %d closed\n", port);
        exit(0);
    } else {
        printf("Port %d open\n", port);
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    char* hostname;
    int start_port, end_port;

    if (argc != 4 || strcmp(argv[1], "-h") != 0) {
        fprintf(stderr, "Usage: %s -h <hostname> <start_port>-<end_port>\n", argv[0]);
        exit(1);
    }

    hostname = argv[2];

    // Parse port range string
    char* port_range = argv[3];
    char* end_range = strchr(port_range, '-');
    if (end_range == NULL) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    *end_range = '\0';
    start_port = atoi(port_range);
    end_port = atoi(end_range + 1);

    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    printf("Scanning ports %d to %d on %s\n", start_port, end_port, hostname);

    // Perform port scanning
    int i;
    for (i = start_port; i <= end_port; i++) {
        scan_port(hostname, i);
    }

    return 0;
}