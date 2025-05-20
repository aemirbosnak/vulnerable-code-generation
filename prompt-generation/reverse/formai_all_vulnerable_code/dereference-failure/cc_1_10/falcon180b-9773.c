//Falcon-180B DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    int new_socket;
    char buffer[BUFFER_SIZE];
    char *message = "Welcome to the chat server!\n";

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, addrlen) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %s\n", argv[1]);

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen);
        if (new_socket == -1) {
            perror("accept");
            exit(1);
        }

        send(new_socket, message, strlen(message), 0);
        close(new_socket);
    }

    return 0;
}