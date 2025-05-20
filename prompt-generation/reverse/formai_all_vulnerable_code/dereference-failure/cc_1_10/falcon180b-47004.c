//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    int bytes;
    int timeout = 5;
    struct timeval tv;
    int res;

    if (argc!= 3) {
        printf("Usage:./ping <IP Address> <Port Number>\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    res = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (res < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        bytes = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes <= 0) {
            printf("Server not responding\n");
            break;
        }

        printf("Response received: %s", buffer);
        fflush(stdout);

        memset(buffer, 0, sizeof(buffer));
        strcpy(buffer, "PING");
        send(sock, buffer, strlen(buffer), 0);

        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        res = setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
        if (res < 0) {
            printf("Error setting receive timeout\n");
            exit(1);
        }

        res = setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));
        if (res < 0) {
            printf("Error setting send timeout\n");
            exit(1);
        }

        res = recv(sock, buffer, sizeof(buffer), 0);
        if (res <= 0) {
            printf("Server not responding\n");
            break;
        }

        printf("Response received: %s", buffer);
        fflush(stdout);

        usleep(500000);
    }

    close(sock);
    return 0;
}