//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int socket_fd, status, connect_fd, port;
    struct sockaddr_in server_address;
    char buffer[1024];
    int bytes_read;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
        exit(1);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to IMAP server!\n");

    while (1) {
        bytes_read = read(socket_fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            if (bytes_read == 0) {
                fprintf(stderr, "Connection closed by server\n");
                exit(1);
            } else {
                fprintf(stderr, "Error reading from socket: %s\n", strerror(errno));
                exit(1);
            }
        }
        printf("%s", buffer);
    }

    return 0;
}