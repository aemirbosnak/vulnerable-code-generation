//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int server_fd, new_connection_fd, chars_read;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        printf("Failed to listen on socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d\n", SERVER_IP, atoi(argv[1]));

    while (1) {
        new_connection_fd = accept(server_fd, (struct sockaddr *)&client_addr, &chars_read);
        if (new_connection_fd < 0) {
            printf("Failed to accept new connection\n");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            chars_read = read(new_connection_fd, buffer, MAX_BUFFER_SIZE);
            if (chars_read < 0) {
                printf("Failed to read from socket\n");
                exit(EXIT_FAILURE);
            }

            printf("%s", buffer);
            write(new_connection_fd, buffer, chars_read);
        }
    }

    close(server_fd);
    return 0;
}