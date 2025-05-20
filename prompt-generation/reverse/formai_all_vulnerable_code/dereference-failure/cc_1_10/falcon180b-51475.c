//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in target;
    int port;
    char *ip;
    int opt = 1;
    struct hostent *he;
    int max_fd;
    fd_set master_fds;
    fd_set read_fds;
    int retval;
    int max_sd;
    int sd;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket failed");
        exit(1);
    }

    // Set socket option
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Resolve IP address
    he = gethostbyname(ip);
    if (he == NULL) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Fill in target structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    memcpy(&target.sin_addr, he->h_addr, he->h_length);

    // Connect to target
    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            perror("connect");
        }
        close(sock);
        exit(1);
    }

    printf("Port %d is open\n", port);
    close(sock);

    return 0;
}