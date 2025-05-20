//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    int listen_sock, client_sock, port = 8080;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage:./proxy <port>\n");
        exit(1);
    }

    port = atoi(argv[1]);

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_sock, 5) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for connection...\n");
        socklen_t addr_size = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size);

        if (client_sock == -1) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        char buffer[1024];
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);

            if (bytes_received <= 0) {
                fprintf(stderr, "Error receiving data\n");
                exit(1);
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            send(client_sock, buffer, strlen(buffer), 0);
        }

        close(client_sock);
    }

    close(listen_sock);
    return 0;
}