//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_REQ_LEN 1024
#define MAX_RES_LEN 32768

int create_listen_socket(int port) {
    int listen_fd;
    struct sockaddr_in server_addr;

    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error opening socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (const struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding to port");
        exit(1);
    }

    if (listen(listen_fd, 10) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    return listen_fd;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <listen_port>\n", argv[0]);
        exit(0);
    }

    int listen_fd = create_listen_socket(atoi(argv[1]));

    char request[MAX_REQ_LEN];
    char response[MAX_RES_LEN];
    char * read_buffer = malloc(sizeof(char) * MAX_RES_LEN); 
    int client_fd, bytes_read, server_fd;

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    while (1) {
        if ((client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Error accepting client connection");
            continue;
        }

        memset(request, 0, sizeof(request));
        if ((bytes_read = read(client_fd, request, sizeof(request))) < 0) {
            perror("Error reading client request");
            continue;
        }

        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Error opening server socket");
            continue;
        }

        struct hostent *server = gethostbyname(request);
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

        if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            close(server_fd);
            continue;
        }

        if (write(server_fd, request, strlen(request)) < 0) {
            perror("Error writing to server");
            close(server_fd);
            continue;
        }

        memset(response, 0, sizeof(response));
        while ((bytes_read = read(server_fd, read_buffer, sizeof(read_buffer)))) {
            if (bytes_read < 0) {
                perror("Error reading from server");
                close(server_fd);
                break;
            }

            if (write(client_fd, read_buffer, bytes_read) < 0) {
                perror("Error writing to client");
                close(server_fd);
                break;
            }

            strcat(response, read_buffer);
        }

        close(client_fd);
        close(server_fd);

        printf("%s\n", response); // log the response
    }

    return 0;
}