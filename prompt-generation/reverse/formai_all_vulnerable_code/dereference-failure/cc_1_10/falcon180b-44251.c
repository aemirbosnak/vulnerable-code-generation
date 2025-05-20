//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define DOCUMENT_ROOT "./www"

char *get_content_type(char *filename) {
    char *extension = strrchr(filename, '.');
    if (extension == NULL) {
        return "application/octet-stream";
    } else {
        return "text/html";
    }
}

void send_response(int client_socket, int status_code, char *status_message, char *content_type, char *content) {
    char response[4096];
    sprintf(response, "HTTP/1.1 %d %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s", status_code, status_message, content_type, strlen(content), content);
    send(client_socket, response, strlen(response), 0);
}

void handle_request(int client_socket) {
    char request[MAX_REQUEST_SIZE];
    recv(client_socket, request, MAX_REQUEST_SIZE, 0);

    char *method, *filename;
    char *request_line = strtok(request, "\r\n");
    sscanf(request_line, "%s %s HTTP/1.1", method, filename);

    char path[1024];
    snprintf(path, sizeof(path), "%s%s", DOCUMENT_ROOT, filename);
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        send_response(client_socket, 404, "Not Found", "text/html", "<h1>404 Not Found</h1>");
    } else {
        char content[1024*10];
        fread(content, 1, sizeof(content), file);
        fclose(file);

        char *content_type = get_content_type(filename);
        send_response(client_socket, 200, "OK", content_type, content);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        handle_request(client_socket);
        close(client_socket);
    }

    return 0;
}