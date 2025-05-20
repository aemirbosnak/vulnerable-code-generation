//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFF_SIZE];
    int addrlen;
    int opt = TRUE;

    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if(bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if(listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while(TRUE) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);

        if(client_socket == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(TRUE) {
            memset(buffer, 0, BUFF_SIZE);

            int bytes_received = recv(client_socket, buffer, BUFF_SIZE, 0);

            if(bytes_received <= 0) {
                if(errno!= EAGAIN) {
                    printf("Client disconnected\n");
                    close(client_socket);
                    break;
                }
            }

            send(client_socket, buffer, bytes_received, 0);
        }
    }

    close(listen_socket);

    return 0;
}