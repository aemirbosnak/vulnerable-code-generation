//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listen_socket;
    int client_socket;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);
    int port = 8080;

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_address, &addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        char *buffer = NULL;
        int length = 0;
        int nread;

        while ((nread = recv(client_socket, buffer + length, sizeof(buffer) - length, 0)) > 0) {
            length += nread;
            printf("Received %d bytes: %s\n", nread, buffer);

            buffer[length] = 0;
            if (strcmp(buffer, "quit") == 0) {
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
        printf("Client disconnected\n");
    }

    close(listen_socket);
    return 0;
}