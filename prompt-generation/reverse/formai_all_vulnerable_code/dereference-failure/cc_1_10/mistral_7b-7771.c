//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SURREAL_PORT 8080

typedef struct {
    int sock;
    char host[256];
    char path[1024];
} surreal_http_client;

surreal_http_client *create_client() {
    surreal_http_client *client = malloc(sizeof(surreal_http_client));
    client->sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(client->host, 0, sizeof(client->host));
    memset(client->path, 0, sizeof(client->path));
    return client;
}

void surreal_connect(surreal_http_client *client, char *host, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    connect(client->sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
}

void send_request(surreal_http_client *client, char *method, char *path) {
    char request[1024];
    sprintf(request, "%s %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Surreal HTTP Client/1.0\r\nAccept: */*\r\nConnection: close\r\n\r\n", method, path, client->host);
    write(client->sock, request, strlen(request));
}

void recv_response(surreal_http_client *client, char *buffer, int size) {
    ssize_t bytes_received;
    while (size > 0) {
        bytes_received = recv(client->sock, buffer, size, 0);
        if (bytes_received <= 0) {
            break;
        }
        memcpy(buffer + size, buffer, bytes_received);
        size += bytes_received;
        buffer -= bytes_received;
    }
}

void destroy_client(surreal_http_client *client) {
    close(client->sock);
    free(client);
}

int main(int argc, char *argv[]) {
    surreal_http_client *client = create_client();
    if (client == NULL) {
        perror("Could not allocate memory for client.");
        return 1;
    }

    strcpy(client->host, "www.example.com");
    strcpy(client->path, "/surreal");

    surreal_connect(client, client->host, SURREAL_PORT);

    send_request(client, "GET", client->path);

    char buffer[4096];
    int size = sizeof(buffer);

    recv_response(client, buffer, size);

    printf("Received response:\n%s\n", buffer);

    destroy_client(client);

    return 0;
}