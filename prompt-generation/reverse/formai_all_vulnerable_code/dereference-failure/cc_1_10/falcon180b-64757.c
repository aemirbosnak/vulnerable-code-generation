//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIME_OUT 5

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char hostname[MAX_HOSTNAME];
    int hostnamelen, port;
    char data[MAX_DATA];
    int datalen;
    struct timeval timeout;
    fd_set readfds;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <port> <data>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);
    strcpy(data, argv[3]);

    hostnamelen = strlen(hostname);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    datalen = strlen(data);

    if (send(sock, data, datalen, 0) == -1) {
        printf("Error sending data\n");
        close(sock);
        return 1;
    }

    timeout.tv_sec = TIME_OUT;
    timeout.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    if (select(sock + 1, &readfds, NULL, NULL, &timeout) == -1) {
        printf("Error selecting socket\n");
        close(sock);
        return 1;
    }

    if (FD_ISSET(sock, &readfds)) {
        char buf[MAX_DATA];
        int buflen;

        buflen = recv(sock, buf, MAX_DATA, 0);

        if (buflen == -1) {
            printf("Error receiving data\n");
            close(sock);
            return 1;
        }

        buf[buflen] = '\0';

        printf("Received data: %s\n", buf);
    } else {
        printf("No data received\n");
    }

    close(sock);

    return 0;
}