//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT 7
#define SA struct sockaddr

int main(int argc, char *argv[]) {
    int sd, ret, i;
    struct hostent *hp;
    char *host;
    char send_buf[MAX], recv_buf[MAX];
    struct sockaddr_in server;
    int addrlen;
    fd_set readfds;
    struct timeval tv;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Packets>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    int num_packets = atoi(argv[2]);

    sd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
        if (hp = gethostbyname(host)) {
            memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
        } else {
            fprintf(stderr, "No such host: %s\n", host);
            exit(1);
        }
    }

    addrlen = sizeof(server);

    for (i = 0; i < num_packets; i++) {
        sprintf(send_buf, "Ping %d", i + 1);
        sendto(sd, send_buf, strlen(send_buf), 0, (SA *) &server, addrlen);

        FD_ZERO(&readfds);
        FD_SET(sd, &readfds);

        tv.tv_sec = 5;
        tv.tv_usec = 0;

        ret = select(sd + 1, &readfds, NULL, NULL, &tv);

        if (ret <= 0) {
            printf("No response from %s\n", host);
            break;
        } else if (ret > 0) {
            ret = recv(sd, recv_buf, MAX, 0);

            if (ret <= 0) {
                printf("No response from %s\n", host);
                break;
            } else {
                recv_buf[ret] = '\0';
                printf("Response from %s: %s\n", host, recv_buf);
            }
        }
    }

    close(sd);

    return 0;
}