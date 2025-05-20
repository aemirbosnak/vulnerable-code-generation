//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[4096];
    int port = 80;
    char *ip = "192.168.1.1";

    if (argc > 1) {
        ip = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s:%d\n", ip, port);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, 4096, 0);

        if (n < 0) {
            printf("Recv failed: %s\n", strerror(errno));
            exit(1);
        }

        if (n == 0) {
            printf("Disconnected\n");
            break;
        }

        printf("Received %d bytes: %s\n", n, buffer);
    }

    close(sockfd);
    return 0;
}