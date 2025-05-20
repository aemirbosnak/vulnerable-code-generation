//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_HOSTNAME 256
#define MAX_MESSAGE 1024


int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME];
    char message[MAX_MESSAGE];
    int sock;
    struct hostent *host;
    struct sockaddr_in dest;

    if(argc!= 3) {
        fprintf(stderr, "Usage: %s host message\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    strncpy(message, argv[2], MAX_MESSAGE);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(hostname);

    if(host == NULL) {
        fprintf(stderr, "Unknown host: %s\n", hostname);
        exit(1);
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(12345);
    memcpy(&dest.sin_addr, host->h_addr, host->h_length);

    if(connect(sock, (struct sockaddr *)&dest, sizeof(dest)) == -1) {
        perror("connect");
        exit(1);
    }

    send(sock, message, strlen(message), 0);

    close(sock);

    return 0;
}