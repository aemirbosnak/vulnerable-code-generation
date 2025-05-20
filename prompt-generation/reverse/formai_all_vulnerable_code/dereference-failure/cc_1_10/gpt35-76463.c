//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 65535
#define MAX_URL_LENGTH 2048
#define PORT 8080

// This function converts a URL string into a hostname and a path
int url_to_hostname_and_path(char *url, char **hostname, char **path) {
    char *beginning = strstr(url, "://");
    if (beginning == NULL) {
        fprintf(stderr, "Error: Invalid URL format\n");
        return -1;
    }
    beginning += 3;
    char *end = strstr(beginning, "/");
    if (end == NULL) {
        *hostname = strdup(beginning);
        *path = strdup("/");
    } else {
        *hostname = strndup(beginning, end - beginning);
        *path = strdup(end);
    }
    return 0;
}

// This function receives data from the client and forwards it to the server
void *client_to_server(void *args) {
    int client_socket = *(int *)args;
    char buffer[MAX_BUFFER_SIZE], url[MAX_URL_LENGTH];
    bzero(buffer, MAX_BUFFER_SIZE);
    recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    sscanf(buffer, "GET %s HTTP/1.1", url);
    printf("Requested URL: %s\n", url);
    char *hostname, *path;
    url_to_hostname_and_path(url, &hostname, &path);
    printf("Hostname: %s\n", hostname);
    printf("Path: %s\n", path);
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    struct in_addr addr;
    inet_aton(hostname, &addr);
    server_address.sin_addr = addr;
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Error: Failed to create server socket\n");
        return NULL;
    }
    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        return NULL;
    }
    send(server_socket, buffer, strlen(buffer), 0);
    while (1) {
        bzero(buffer, MAX_BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            fprintf(stderr, "Error: Failed to receive data from client\n");
            return NULL;
        }
        if (bytes_received == 0) {
            // End of client input
            break;
        }
        send(server_socket, buffer, bytes_received, 0);
    }
    close(server_socket);
    free(hostname);
    free(path);
    return NULL;
}

int main(int argc, char **argv) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Error: Failed to create server socket\n");
        return 1;
    }
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Failed to bind server socket\n");
        return 1;
    }
    if (listen(server_socket, 10) < 0) {
        fprintf(stderr, "Error: Failed to listen on server socket\n");
        return 1;
    }
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            fprintf(stderr, "Error: Failed to accept client connection\n");
            continue;
        }
        pthread_t thread;
        int *socket_ptr = malloc(sizeof(int));
        *socket_ptr = client_socket;
        if (pthread_create(&thread, NULL, client_to_server, (void *)socket_ptr) < 0) {
            fprintf(stderr, "Error: Failed to create thread\n");
            continue;
        }
    }
    return 0;
}