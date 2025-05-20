//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define START_PORT 1
#define END_PORT 65535

int main(int argc , char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <ip-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host;
    struct sockaddr_in sockin;
    int sock;

    host = gethostbyname(argv[1]);
    if (!host) {
        perror("Error resolving hostname");
        exit(EXIT_FAILURE);
    }

    memset(&sockin, 0, sizeof(struct sockaddr_in));
    sockin.sin_family = AF_INET;
    memcpy(&sockin.sin_addr, host->h_addr, host->h_length);

    // loop through all possible ports
    for (int port = START_PORT; port <= END_PORT; port++) {
        sockin.sin_port = htons(port);

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        // set timeout to 200 ms
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 200000;
        if (setsockopt (sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
            perror("Error setting socket options");
            exit(EXIT_FAILURE);
        }

        // connect to the port
        int res = connect(sock, (struct sockaddr *)&sockin, sizeof(sockin));

        if (res == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            close(sock);
        }
    }

    printf("Port scanning complete\n");
    return 0;
}