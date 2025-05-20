//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 4096
#define PORT 8080
#define HOST_FILE "/etc/hosts"

char* create_silly_response(char* request) {
    if (strstr(request, "google.com") != NULL) {
        return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello Google! I am your biggest fan!</h1></body></html>";
    } else {
        return "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<html><body><h1>Oops! Requested resource not found</h1></body></html>";
    }
}

void forward_request(int client_fd, struct sockaddr_in server_addr, char* request) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Could not create server socket");
        exit(1);
    }

    if (connect(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    send(server_fd, request, strlen(request), 0);

    char buf[BUF_SIZE];
    int num_bytes;
    while ((num_bytes = recv(server_fd, buf, BUF_SIZE, 0)) > 0) {
        send(client_fd, buf, num_bytes, 0);
    }

    close(server_fd);
}

void handle_silly_request(int client_fd, char* request) {
    char* response = create_silly_response(request);
    send(client_fd, response, strlen(response), 0);
}

int main() {
    int server_fd, client_fd, num_bytes;
    char buf[BUF_SIZE];
    struct sockaddr_in server_addr, client_addr;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Could not create server socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Could not bind to port");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Could not listen on port");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        unsigned int client_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_len);
        if (client_fd < 0) {
            perror("Could not accept client connection");
            continue;
        }

        memset(buf, 0, BUF_SIZE);
        if ((num_bytes = recv(client_fd, buf, BUF_SIZE, 0)) <= 0) {
            close(client_fd);
            continue;
        }

        printf("Received request: %s\n", buf);

        if (strstr(buf, "GET") != NULL) {
            handle_silly_request(client_fd, buf);
        } else {
            struct hostent* host_info = gethostbyname("www.google.com");
            if (host_info == NULL) {
                perror("Could not get host info");
                close(client_fd);
                continue;
            }

            struct in_addr addr;
            memcpy(&addr, host_info->h_addr_list[0], sizeof(struct in_addr));

            server_addr.sin_addr.s_addr = addr.s_addr;
            forward_request(client_fd, server_addr, buf);
        }

        close(client_fd);
    }

    return 0;
}