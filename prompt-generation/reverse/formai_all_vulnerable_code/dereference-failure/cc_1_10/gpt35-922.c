//FormAI DATASET v1.0 Category: Simple Web Server ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define MAX_REQUEST_SIZE 2048
#define WEB_ROOT "./webroot"
#define NOT_FOUND_PAGE "404.html"

void handle_client(int client_fd, struct sockaddr_in client_addr);
void respond_to_client(int client_fd, char* request, char* response);

int main(int argc, char** argv) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int port = argc > 1 ? atoi(argv[1]) : DEFAULT_PORT;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket() failed");
        exit(1);
    }

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen() failed");
        exit(1);
    }

    printf("Server started on port %d.\n", port);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept() failed");
            continue;
        }

        handle_client(client_fd, client_addr);

        close(client_fd);
    }

    close(server_fd);

    return 0;
}

void handle_client(int client_fd, struct sockaddr_in client_addr) {
    char request[MAX_REQUEST_SIZE], response[MAX_REQUEST_SIZE];
    int request_len = recv(client_fd, request, sizeof(request), 0);
    if (request_len < 0) {
        perror("recv() failed");
        exit(1);
    }

    request[request_len] = '\0';

    printf("Request received from %s:%d:\n%s\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), request);

    respond_to_client(client_fd, request, response);
}

void respond_to_client(int client_fd, char* request, char* response) {
    char method[MAX_REQUEST_SIZE], path[MAX_REQUEST_SIZE], version[MAX_REQUEST_SIZE];
    sscanf(request, "%s %s %s", method, path, version);

    if (strcmp(method, "GET") != 0) {
        perror("Only GET requests are supported.");
        exit(1);
    }

    strcat(path, "index.html");

    char* file_path = calloc(strlen(WEB_ROOT) + strlen(path) + 1, sizeof(char));
    strcat(file_path, WEB_ROOT);
    strcat(file_path, path);

    int fd = open(file_path, O_RDONLY);
    if (fd < 0) {
        printf("File not found: %s\n", path);

        char* not_found_path = calloc(strlen(WEB_ROOT) + strlen(NOT_FOUND_PAGE) + 1, sizeof(char));
        strcat(not_found_path, WEB_ROOT);
        strcat(not_found_path, "/");
        strcat(not_found_path, NOT_FOUND_PAGE);

        fd = open(not_found_path, O_RDONLY);
        if (fd < 0) {
            perror("404.html not found.");
            exit(1);
        }
    }

    int bytes_read;
    while ((bytes_read = read(fd, response, sizeof(response))) > 0) {
        if (send(client_fd, response, bytes_read, 0) < 0) {
            perror("send() failed");
            exit(1);
        }
    }

    close(fd);
}