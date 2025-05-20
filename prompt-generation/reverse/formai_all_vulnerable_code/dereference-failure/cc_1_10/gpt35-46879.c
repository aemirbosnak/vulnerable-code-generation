//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    int port;
    int interval;
    
    if (argc != 4) {
        fprintf(stderr, "usage: %s <host> <port> <interval>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    interval = atoi(argv[3]);

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    inet_pton(AF_INET, host, &sin.sin_addr);

    int sock_fd;
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sock_fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        fprintf(stderr, "Could not connect to server: %s\n", strerror(errno));
        exit(1);
    }

    char buf[BUFSIZE];
    memset(buf, 0, sizeof(buf));

    fd_set readfds;
    struct timeval timeout;
    int rv;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sock_fd, &readfds);

        timeout.tv_sec = interval;
        timeout.tv_usec = 0;

        rv = select(sock_fd + 1, &readfds, NULL, NULL, &timeout);
        if (rv < 0) {
            perror("select");
            exit(1);
        } else if (rv == 0) {
            printf("No data from server within interval %d seconds\n", interval);
        } else {
            int len = recv(sock_fd, buf, sizeof(buf), 0);
            if (len < 0) {
                perror("recv");
                exit(1);
            } else if (len == 0) {
                printf("Server disconnected.\n");
                break;
            } else {
                printf("%s", buf);
            }
        }
    }

    close(sock_fd);
    return 0;
}