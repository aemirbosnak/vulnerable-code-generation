//Falcon2-11B DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define HOSTNAME "127.0.0.1"
#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    char filename[BUFFER_SIZE];
    FILE *file = fopen(argv[1], "rb");

    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int socketfd, client_fd, n;
    struct sockaddr_in serv_addr, cli_addr;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if (socketfd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(HOSTNAME);
    serv_addr.sin_port = htons(PORT);

    if (bind(socketfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind");
        return 1;
    }

    listen(socketfd, 5);

    while (1) {
        client_fd = accept(socketfd, (struct sockaddr *)&cli_addr, &n);

        if (client_fd < 0) {
            perror("Failed to accept connection");
            continue;
        }

        char *qr_code = (char *)malloc(sizeof(buffer));

        if (!qr_code) {
            perror("Failed to allocate memory");
            close(client_fd);
            continue;
        }

        read(client_fd, buffer, BUFFER_SIZE);
        sprintf(qr_code, "%s", buffer);

        printf("QR Code: %s\n", qr_code);
        free(qr_code);
        close(client_fd);
    }

    return 0;
}