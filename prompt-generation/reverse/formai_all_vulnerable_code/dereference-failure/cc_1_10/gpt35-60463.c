//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv) 
{
    if (argc < 3) {
        fprintf(stderr, "Usage : ./port_scanner [target_ip] [starting_port] [ending_port] \n");
        exit(1);
    }

    const char *ip_str = argv[1];
    int starting_port = atoi(argv[2]);
    int ending_port = atoi(argv[3]);
    int sockfd, optval = 1;
    struct sockaddr_in target;
    int port;
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket. \n");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        fprintf(stderr, "Error: could not set socket options. \n");
        exit(1);
    }

    target.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip_str, &(target.sin_addr)) < 0) {
        fprintf(stderr, "Failed to convert IP address %s. \n", ip_str);
        exit(1);
    }

    for (port = starting_port; port <= ending_port; port++) {
        memset(buffer, 0, sizeof(buffer));
        target.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) < 0) {
            if (errno != ECONNREFUSED) {
                fprintf(stderr, "Error while connecting to port %d: %s \n", port, strerror(errno));
            }
        } else {
            snprintf(buffer, sizeof(buffer), "Port %d is open. \n", port);
            printf("%s", buffer);
        }
    }

    close(sockfd);
    printf("Scan complete...\n");

    return 0;
}