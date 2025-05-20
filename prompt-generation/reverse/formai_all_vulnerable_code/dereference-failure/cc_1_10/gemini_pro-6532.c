//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    if ((host = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = atoi(argv[2]);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    int nbytes;
    char buf[BUFSIZE];

    while ((nbytes = recv(sock, buf, BUFSIZE, 0)) > 0) {
        write(1, buf, nbytes);
    }

    if (nbytes == -1) {
        perror("recv");
        return 1;
    }

    close(sock);

    return 0;
}