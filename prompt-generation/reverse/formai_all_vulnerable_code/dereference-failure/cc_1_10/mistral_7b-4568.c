//MISTRAL-7B DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_file(FILE *file, int client_socket) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    fseek(file, 0, SEEK_SET);
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    fclose(file);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char request[BUFFER_SIZE];
    char *path_end;
    FILE *file;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Simple web server listening on port %d\n", PORT);

    while (true) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        recv(client_socket, request, BUFFER_SIZE, 0);
        printf("Received request:\n%s\n", request);

        path_end = strrchr(request, '/');
        if (path_end != NULL) {
            *path_end = '\0';
            path_end++;
        }

        if (strcmp(path_end, "favicon.ico") != 0 && strcmp(path_end, "") == 0) {
            file = fopen("index.html", "rb");
            if (file != NULL) {
                send_file(file, client_socket);
                close(client_socket);
                fclose(file);
                continue;
            }
        }

        send(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n", 17, 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}