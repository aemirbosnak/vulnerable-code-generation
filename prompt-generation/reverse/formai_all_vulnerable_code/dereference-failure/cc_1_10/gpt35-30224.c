//FormAI DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAXPORT 65535

void usage()
{
    printf("Usage: ./portscan <ip> <startport> <endport>\n");
    printf("Example usage: ./portscan 127.0.0.1 1 100\n");
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        usage();
        exit(1);
    }

    int sockfd, port, startport, endport, status;
    struct hostent *he;
    struct sockaddr_in target;

    memset(&target, 0, sizeof(target));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    he = gethostbyname(argv[1]);

    if (!he) {
        printf("Error resolving hostname. Error code: %d\n", h_errno);
        exit(1);
    }

    startport = atoi(argv[2]);
    endport = atoi(argv[3]);

    target.sin_family = AF_INET;
    target.sin_addr = *((struct in_addr*)he->h_addr);
    target.sin_port = htons(startport);

    printf("Scanning %s from port %d to %d\n", inet_ntoa(target.sin_addr), startport, endport);

    while (target.sin_port <= htons(endport)) {
        status = connect(sockfd, (struct sockaddr *)&target, sizeof(target));
        if (status == 0) {
            printf("Port %d is open\n", ntohs(target.sin_port));
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                perror("Socket creation error");
                exit(1);
            }
        } else {
            printf("Port %d is closed\n", ntohs(target.sin_port));
        }

        target.sin_port = htons(ntohs(target.sin_port) + 1);
    }

    printf("Scanning complete.\n");

    return 0;
}