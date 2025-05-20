//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port, n;
    struct sockaddr_in address;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not find local host name\n");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr = *((struct in_addr *)server->h_addr);

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(server_socket, 5);

    while (1) {
        client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("ERROR on accepting");
            exit(1);
        }

        printf("Client connected: %d\n", client_socket);
        n = read(client_socket, NULL, 0);
        if (n == 0) {
            close(client_socket);
            continue;
        }

        write(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>", n);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}