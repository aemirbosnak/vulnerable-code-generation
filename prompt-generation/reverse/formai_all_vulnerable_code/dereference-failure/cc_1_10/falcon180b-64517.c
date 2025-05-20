//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char **argv) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int port;
    int result;
    int opt = 1;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <data>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);
    strcpy(data, argv[3]);

    if ((host = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        return 1;
    }

    if (host->h_addrtype!= AF_INET) {
        fprintf(stderr, "Host is not an IPv4 address\n");
        return 1;
    }

    memcpy(&server.sin_addr, host->h_addr, host->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    if (send(sock, data, strlen(data), 0) == -1) {
        perror("send");
        return 1;
    }

    if (recv(sock, data, MAX_DATA, 0) == -1) {
        perror("recv");
        return 1;
    }

    printf("Received data: %s\n", data);

    close(sock);

    return 0;
}