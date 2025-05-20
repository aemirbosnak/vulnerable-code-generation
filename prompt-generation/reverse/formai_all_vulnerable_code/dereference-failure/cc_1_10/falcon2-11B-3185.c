//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int server_port = 8080;

typedef struct {
    char *data;
    int length;
} Request;

Request *create_request(char *data, int length) {
    Request *request = (Request *) malloc(sizeof(Request));
    request->data = data;
    request->length = length;
    return request;
}

void *serve_request(void *request) {
    Request *r = (Request *) request;
    printf("Received request: %s\n", r->data);
    free(r);
    return NULL;
}

void *handle_client(void *client) {
    int client_fd = *((int *) client);
    char buffer[1024];
    int n;

    while (1) {
        n = recv(client_fd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("Error receiving data");
            break;
        }
        Request *r = create_request(buffer, n);
        pthread_t thread;
        pthread_create(&thread, NULL, serve_request, (void *) r);
        pthread_join(thread, NULL);
    }

    close(client_fd);
    return NULL;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    int addrlen = sizeof(client_address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(server_port);

    bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    listen(server_fd, 5);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *) &client_address, (socklen_t *) &addrlen);
        if (client_fd == -1) {
            perror("Error accepting connection");
            exit(1);
        }
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *) &client_fd);
        pthread_join(thread, NULL);
    }

    close(server_fd);
    return 0;
}