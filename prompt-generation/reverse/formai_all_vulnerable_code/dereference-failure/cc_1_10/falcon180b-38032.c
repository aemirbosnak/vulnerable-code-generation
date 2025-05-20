//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int close(int fd);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <ip address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (end_port <= start_port) {
        printf("Invalid range of ports.\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    for (int port = start_port; port <= end_port; ++port) {
        server_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Error connecting to port %d.\n", port);
        }
    }

    close(sockfd);
    return 0;
}

struct hostent *gethostbyname(const char *name) {
    struct hostent *host = gethostbyname_r(name, NULL, NULL, NULL, 0);
    if (!host) {
        printf("Error resolving hostname.\n");
        exit(1);
    }
    return host;
}