//FormAI DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    int sock, port;
    struct sockaddr_in sa;
    struct hostent *host;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    if (isdigit(argv[1][0])) {
        port = atoi(argv[1]);
    } else {
        printf("\n\tInvalid port number. Set to default: 80.\n\n");
        port = 80;
    }

    memset(&sa, 0, sizeof(sa));

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Unknown host %s\n", argv[1]);
        exit(1);
    }

    memcpy(&sa.sin_addr, host->h_addr, host->h_length);
    sa.sin_family = host->h_addrtype;
    sa.sin_port = htons(port);

    sock = socket(host->h_addrtype, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        fprintf(stderr, "Failed to connect to %s on port %d\n", argv[1], port);
    } else {
        printf("%s is listening on port %d\n", argv[1], port);
        close(sock);
    }

    exit(0);
}