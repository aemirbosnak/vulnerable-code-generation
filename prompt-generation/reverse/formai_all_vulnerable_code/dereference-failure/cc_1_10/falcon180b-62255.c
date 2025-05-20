//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    int opt = 1;

    if (argc!= 3) {
        printf("Usage:./client <IP Address> <Port Number>\n");
        exit(0);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Error creating socket\n");
        exit(0);
    }

    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(0);
    }

    char buffer[1024];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);

        send(socket_fd, buffer, strlen(buffer), 0);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        int bytes_received = recv(socket_fd, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            printf("Error receiving data from server\n");
            exit(0);
        }

        printf("Received from server: %s", buffer);
    }

    close(socket_fd);

    return 0;
}