//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host: %s\n", argv[1]);
        exit(1);
    }

    portno = htons(PORT);

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        printf("Waiting for connection...\n");
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE];
        n = read(client_socket, buffer, BUFFER_SIZE);
        if (n <= 0) {
            printf("Connection closed by client.\n");
            close(client_socket);
            continue;
        }

        printf("Received %d bytes: %s\n", n, buffer);
        write(client_socket, "Hello, World!", 12);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}