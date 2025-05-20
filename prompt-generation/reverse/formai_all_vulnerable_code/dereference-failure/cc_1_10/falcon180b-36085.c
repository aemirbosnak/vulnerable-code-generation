//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int bytes_sent, bytes_recv;
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    if ((inet_pton(AF_INET, argv[1], &server_addr.sin_addr)) <= 0) {
        printf("Invalid server address\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);

        if (send(socket_fd, send_buffer, strlen(send_buffer), 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }

        memset(recv_buffer, 0, BUFFER_SIZE);
        bytes_recv = recv(socket_fd, recv_buffer, BUFFER_SIZE, 0);

        if (bytes_recv <= 0) {
            printf("Error receiving message\n");
            exit(1);
        }

        printf("Received message: %s", recv_buffer);
    }

    close(socket_fd);
    return 0;
}