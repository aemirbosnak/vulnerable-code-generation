//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port, opt = 1;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting socket option\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    for (port = atoi(argv[2]); port <= MAX; port++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
    return 0;
}