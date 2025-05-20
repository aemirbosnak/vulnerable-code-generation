//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_NAME 256
#define MAX_SERVICE_NAME 256
#define MAX_DATAGRAM_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, n, ret, addrlen;
    char *host, *service;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char datagram[MAX_DATAGRAM_SIZE];
    char response[MAX_DATAGRAM_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    service = argv[2];

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Invalid host: %s\n", host);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(service));
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    addrlen = sizeof(server_addr);

    while (1) {
        fputs("Enter a message to send: ", stdout);
        fgets(datagram, MAX_DATAGRAM_SIZE, stdin);
        datagram[strcspn(datagram, "\n")] = '\0';

        ret = sendto(sock, datagram, strlen(datagram), 0, (struct sockaddr *)&server_addr, addrlen);
        if (ret == -1) {
            perror("sendto");
            exit(1);
        }

        ret = recvfrom(sock, response, MAX_DATAGRAM_SIZE, 0, (struct sockaddr *)&server_addr, &addrlen);
        if (ret == -1) {
            perror("recvfrom");
            exit(1);
        }

        fputs("Received response: ", stdout);
        fputs(response, stdout);
    }

    close(sock);
    exit(0);
}