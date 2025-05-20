//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 1024
#define DOCUMENT_ROOT "./www"

char *get_file_type(char *filename) {
    char *dot = strrchr(filename, '.');
    if (dot == NULL) {
        return "unknown";
    }
    return dot + 1;
}

void send_response(int client_socket, int status_code, char *status_message, char *content_type, char *content) {
    char response[4096];
    snprintf(response, sizeof(response), "HTTP/1.1 %d %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s",
            status_code, status_message, content_type, strlen(content), content);
    send(client_socket, response, strlen(response), 0);
}

void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, sizeof(request));
    recv(client_socket, request, MAX_REQUEST_SIZE, 0);

    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");

    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        send_response(client_socket, 404, "Not Found", "text/html", "<h1>404 Not Found</h1>");
        return;
    }

    char *content_type = get_file_type(path);
    char content[1024];
    fread(content, 1, sizeof(content), file);
    fclose(file);

    send_response(client_socket, 200, "OK", content_type, content);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        printf("Client connected\n");
        handle_request(client_socket);
        close(client_socket);
    }

    return 0;
}