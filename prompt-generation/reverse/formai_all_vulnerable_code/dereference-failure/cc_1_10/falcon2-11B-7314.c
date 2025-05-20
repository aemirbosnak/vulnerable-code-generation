//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define MAX_MSG_LEN 100

int main(int argc, char *argv[])
{
    int server_fd, new_socket, conn_fd;
    int yes = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[MAX_MSG_LEN];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(server_fd, MAX_CLIENTS);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
        if (new_socket < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("New client connected\n");
        conn_fd = dup(new_socket);
        while (1) {
            printf("Enter message:\n");
            fgets(buffer, MAX_MSG_LEN, stdin);
            printf("Sending message: %s\n", buffer);
            send(conn_fd, buffer, strlen(buffer), 0);
            if (strcmp(buffer, "exit") == 0) {
                printf("Client disconnected\n");
                close(conn_fd);
                break;
            }
        }
    }

    close(server_fd);
    return 0;
}