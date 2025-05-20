//FormAI DATASET v1.0 Category: Port Scanner ; Style: scientific
/* 
   C Port Scanner
   This code scans for open TCP ports on a given host.
   It uses the socket library to create a connection and check
   for open ports. It also includes options for port range, 
   timeout, and verbosity level.

   Author: John Smith
   Date: August 17th, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <stdbool.h>

#define START_PORT 1 // default start port
#define END_PORT 1024 // default end port
#define TIMEOUT 3 // default timeout in seconds
#define VERBOSE 0 // default verbosity level
#define BUF_SIZE 1024 // buffer size for receiving data

int scan_port(char *host, int port);

int main(int argc, char *argv[]) {
    int start_port = START_PORT;
    int end_port = END_PORT;
    int timeout = TIMEOUT;
    int verbosity = VERBOSE;
    char *host;

    // parse command line arguments
    if (argc < 2 || argc > 6) {
        printf("Usage: %s [-s <start_port>] [-e <end_port>] [-t <timeout>] [-v] <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    } else {
        host = argv[argc-1];
        for (int i = 1; i < argc-1; i++) {
            if (strcmp(argv[i], "-s") == 0) {
                start_port = atoi(argv[i+1]);
            } else if (strcmp(argv[i], "-e") == 0) {
                end_port = atoi(argv[i+1]);
            } else if (strcmp(argv[i], "-t") == 0) {
                timeout = atoi(argv[i+1]);
            } else if (strcmp(argv[i], "-v") == 0) {
                verbosity = 1;
            }
        }
    }

    if (verbosity) {
        printf("Scanning host %s from port %d to %d\n", host, start_port, end_port);
    }

    // scan open ports using TCP connection
    for (int i = start_port; i <= end_port; i++) {
        int result = scan_port(host, i);
        if (result == 0 && verbosity) {
            printf("%d/tcp open\n", i);
        }
    }

    return 0;
}

/* 
   Scan a single port on a given host using a TCP connection.
   Returns 0 if the port is open, -1 otherwise.
*/
int scan_port(char *host, int port) {
    struct sockaddr_in addr;
    struct hostent *host_info;
    int sock_fd;
    fd_set set;
    struct timeval timeout;
    char buf[BUF_SIZE];
    int result;

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("Error resolving hostname");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr = *((struct in_addr *)host_info->h_addr);
    addr.sin_port = htons(port);

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set timeout for socket
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    FD_ZERO(&set);
    FD_SET(sock_fd, &set);

    if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        result = 0; // port is open
    } else {
        result = -1; // port is closed
    }

    close(sock_fd);
    return result;
}