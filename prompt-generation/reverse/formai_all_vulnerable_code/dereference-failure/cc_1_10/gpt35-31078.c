//FormAI DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

int main(int argc, char **argv)
{

    if (argc != 4) {
        printf("Usage: %s <Host> <Starting Port> <Ending Port>\n", argv[0]);
        return 0;
    }

    char *hostname = argv[1];
    int startPort = atoi(argv[2]);
    int endPort = atoi(argv[3]);

    if (startPort < 1 || endPort > 65535 || startPort > endPort) {
        printf("Invalid Port Range!\n");
        return 0;
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));

    target.sin_family = AF_INET;

    if (inet_pton(AF_INET, hostname, &target.sin_addr) <= 0) {
        printf("Invalid Host Name!\n");
        return 0;
    }

    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket Creation Failed: %s\n", strerror(errno));
        return sockfd;
    }

    int port;
    struct sockaddr_in sin;
    printf("Scanning %s ports %d to %d\n", hostname, startPort, endPort);
    for (port = startPort; port <= endPort; port++) {
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_port = htons(port);
        sin.sin_addr.s_addr = target.sin_addr.s_addr;

        if (connect(sockfd, (struct sockaddr *) &sin, sizeof(sin))) {
            printf("%d Port is Closed.\n", port);
        } else {
            printf("%d Port is Opened.\n", port);
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                printf("Socket Creation Failed: %s\n", strerror(errno));
                return sockfd;
            }
        }
    }
    close(sockfd);
    return 0;
}