//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define BUFFER_SIZE 8192

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <destination>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char *destination = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, destination, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to %s:%d\n", destination, port);

    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            fprintf(stderr, "Disconnected\n");
            break;
        } else if (bytes_received == -1) {
            fprintf(stderr, "recv() failed: %s\n", strerror(errno));
            return 1;
        }

        printf("Received %d bytes: %s\n", bytes_received, buffer);

        send(sock, buffer, bytes_received, 0);
    }

    close(sock);
    return 0;
}