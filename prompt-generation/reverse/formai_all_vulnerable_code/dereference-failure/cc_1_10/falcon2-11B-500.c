//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes, n;
    struct sockaddr_in server;
    struct hostent *host;
    char message[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
    server.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *)&server, sizeof(server));

    time_t start = time(NULL);
    while (1) {
        fd_set readfds;
        struct timeval timeout;
        char port[3];

        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        n = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (n < 0) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            sprintf(message, "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
            numbytes = send(sockfd, message, strlen(message), 0);
            if (numbytes < 0) {
                perror("send");
                exit(1);
            }

            sprintf(port, "%d", ntohs(server.sin_port));
            printf("Port %s is %s\n", port, numbytes > 0? "open" : "closed");
        }
    }

    return 0;
}