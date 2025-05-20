//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if(argc!= 3) {
        printf("Usage:./proxy <server_ip> <server_port>\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if(connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    addrlen = sizeof(client_addr);
    while(TRUE) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if(client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(TRUE) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if(bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            send(server_socket, buffer, bytes_received, 0);

            if(memcmp(buffer, "GET ", 4) == 0) {
                printf("GET request detected\n");
            } else if(memcmp(buffer, "POST ", 5) == 0) {
                printf("POST request detected\n");
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}