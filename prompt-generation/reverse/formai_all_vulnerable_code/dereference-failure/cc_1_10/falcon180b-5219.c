//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_SIZE 1024

int server_socket;
int client_socket;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char request[MAX_REQUEST_SIZE];

    memset(request, 0, MAX_REQUEST_SIZE);
    recv(client_socket, request, MAX_REQUEST_SIZE, 0);

    if (strcmp(request, "GET / HTTP/1.1") == 0) {
        send(client_socket, response, strlen(response), 0);
    } else {
        char response[strlen(request) + 100];
        sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>");
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
    free(arg);
    pthread_exit(0);
}

int main() {
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    memset(&server_addr, 0, addrlen);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *) &server_addr, addrlen) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen)) == -1) {
            perror("accept");
            exit(1);
        }

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket)!= 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    return 0;
}