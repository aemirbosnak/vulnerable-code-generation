//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in dest;
    char *ip, *port;
    int opt = 1;
    int timeout = 5;
    int max_attempts = 3;
    int attempts = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    ip = argv[1];
    port = argv[2];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    dest.sin_family = AF_INET;
    dest.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &dest.sin_addr);

    ret = connect(sock, (struct sockaddr *)&dest, sizeof(dest));
    if (ret == -1) {
        printf("Error connecting to %s:%s\n", ip, port);
        close(sock);
        return 1;
    }

    printf("Connected to %s:%s\n", ip, port);

    while (attempts < max_attempts) {
        ret = send(sock, "PING", strlen("PING"), 0);
        if (ret == -1) {
            printf("Error sending PING message\n");
            close(sock);
            return 1;
        }

        ret = recv(sock, &dest, sizeof(dest), 0);
        if (ret == -1) {
            printf("Error receiving response\n");
            close(sock);
            return 1;
        }

        if (dest.sin_family == AF_INET && dest.sin_port == htons(atoi(port))) {
            printf("PING response received from %s:%s\n", inet_ntoa(dest.sin_addr), ntohs(dest.sin_port));
            break;
        } else {
            printf("Invalid response received\n");
        }

        attempts++;
        sleep(timeout);
    }

    if (attempts == max_attempts) {
        printf("No response received\n");
    }

    close(sock);
    return 0;
}