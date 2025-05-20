//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock, i, opt = TRUE, status;
    struct sockaddr_in serv_addr;
    char buffer[MAX];
    fd_set readfds;
    struct timeval timeout;

    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    while (opt) {
        status = select(sock + 1, &readfds, NULL, NULL, &timeout);
        if (status == -1) {
            printf("Error in select()\n");
            exit(1);
        } else if (FD_ISSET(sock, &readfds)) {
            memset(buffer, '0', sizeof(buffer));
            if (recv(sock, buffer, MAX, 0) == -1) {
                printf("Error in recv()\n");
                exit(1);
            }
            printf("Received: %s\n", buffer);
        } else {
            printf("No response from server\n");
            opt = FALSE;
        }
    }

    close(sock);
    exit(0);
}