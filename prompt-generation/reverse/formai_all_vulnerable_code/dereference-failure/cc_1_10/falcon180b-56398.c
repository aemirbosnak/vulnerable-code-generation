//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

char *request_method = "GET";
char *request_path = "/";
char *request_version = "HTTP/1.1";

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char *response;
    int response_len;
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        response = (char *)malloc(BUFFER_SIZE);
        response_len = sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen(response));

        send(client_socket, response, response_len, 0);
        close(client_socket);
        free(response);
    }

    close(server_socket);
    return 0;
}