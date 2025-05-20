//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA_SIZE 1024
#define TIME_OUT 5

int main(int argc, char *argv[]) {
    int sock, ret;
    struct hostent *host;
    struct sockaddr_in server;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA_SIZE];
    int datalen;
    struct timeval timeout;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    strncpy(data, argv[2], MAX_DATA_SIZE);

    datalen = strlen(data);

    if ((host = gethostbyname(hostname)) == NULL) {
        fprintf(stderr, "Error: %s: Unknown host\n", hostname);
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(7);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        fprintf(stderr, "Error: socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    ret = sendto(sock, data, datalen, 0, (struct sockaddr *)&server, sizeof(server));

    if (ret!= datalen) {
        fprintf(stderr, "Error: sendto() failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(data, 0, MAX_DATA_SIZE);

    timeout.tv_sec = TIME_OUT;
    timeout.tv_usec = 0;

    ret = recvfrom(sock, data, MAX_DATA_SIZE, 0, NULL, NULL);

    if (ret <= 0) {
        fprintf(stderr, "Error: recvfrom() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Ping response from %s:\n%s\n", hostname, data);

    close(sock);

    return 0;
}