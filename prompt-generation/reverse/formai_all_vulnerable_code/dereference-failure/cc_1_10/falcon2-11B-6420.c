//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 10

void handleRequest(int socket, char* request) {
    printf("Received request: %s\n", request);
    char* response = "Hello, World!";
    send(socket, response, strlen(response), 0);
}

int main(int argc, char* argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int addrlen = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(1);
        }

        if (new_socket!= -1) {
            int i;
            for (i = 0; i < 1024; i++) {
                if (read(new_socket, buffer, sizeof(buffer)) < 0) {
                    perror("read failed");
                    exit(1);
                }

                handleRequest(new_socket, buffer);
                printf("Sent response\n");
            }

            close(new_socket);
        }
    }

    close(server_socket);
    return 0;
}