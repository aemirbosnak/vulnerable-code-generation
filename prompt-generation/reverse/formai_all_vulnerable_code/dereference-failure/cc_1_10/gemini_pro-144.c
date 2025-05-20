//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    int server_sock;
    int client_sock;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int port;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    port = atoi(argv[1]);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(server_sock, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        while ((bytes_read = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
            // Handle the HTTP request here
            printf("%s\n", buffer);

            // Send the HTTP response here
            char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>\r\n";
            send(client_sock, response, strlen(response), 0);
        }

        close(client_sock);
    }

    close(server_sock);

    return EXIT_SUCCESS;
}