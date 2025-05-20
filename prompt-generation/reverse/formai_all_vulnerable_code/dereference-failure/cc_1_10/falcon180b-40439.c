//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 2048

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(struct sockaddr_in);

    if (argc!= 3) {
        printf("Usage:./proxy <server_ip> <server_port>\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(server_socket, (struct sockaddr*)&server_addr, addrlen) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addrlen)) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    printf("Error receiving data\n");
                }

                close(client_socket);
                break;
            }

            int bytes_sent = send(server_socket, buffer, bytes_received, 0);

            if (bytes_sent <= 0) {
                printf("Error sending data to server\n");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}