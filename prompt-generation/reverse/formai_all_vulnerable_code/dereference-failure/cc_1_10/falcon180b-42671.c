//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    if (send(sock, argv[3], strlen(argv[3]), 0) == -1) {
        printf("Error sending username\n");
        return 1;
    }

    while (1) {
        memset(buf, 0, BUF_SIZE);
        n = recv(sock, buf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            return 1;
        }

        printf("Received data: %s", buf);
    }

    return 0;
}