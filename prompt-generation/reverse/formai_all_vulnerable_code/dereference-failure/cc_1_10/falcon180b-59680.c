//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, retval, opt = TRUE;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    char message[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage:./server <port number>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    retval = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error binding socket!\n");
        exit(1);
    }

    retval = listen(server_socket, BACKLOG);
    if (retval == -1) {
        printf("Error listening on socket!\n");
        exit(1);
    }

    while (opt) {
        memset(message, 0, BUFFER_SIZE);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection!\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            retval = recv(client_socket, message, BUFFER_SIZE, 0);
            if (retval <= 0) {
                printf("Client disconnected!\n");
                break;
            }

            printf("Received message: %s\n", message);

            retval = send(client_socket, message, strlen(message), 0);
            if (retval == -1) {
                printf("Error sending message!\n");
                exit(1);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}