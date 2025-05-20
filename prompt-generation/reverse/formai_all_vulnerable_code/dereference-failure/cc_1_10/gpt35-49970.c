//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in server;
    bool is_connected;
} HTTPClient;

bool connect_to_server(HTTPClient *client, char *host, int port) {
    if (client->is_connected) return true;
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("Error: host not found");
        return false;
    }
    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock < 0) {
        perror("Error: cannot create socket");
        return false;
    }
    memset(&client->server, 0, sizeof(client->server));
    client->server.sin_family = AF_INET;
    memcpy(&client->server.sin_addr.s_addr, server->h_addr, server->h_length);
    client->server.sin_port = htons(port);
    if (connect(client->sock, (struct sockaddr *)&client->server, sizeof(client->server)) < 0) {
        perror("Error: cannot connect to server");
        return false;
    }
    client->is_connected = true;
    return true;
}

void disconnect_from_server(HTTPClient *client) {
    if (client->is_connected) {
        close(client->sock);
        client->is_connected = false;
    }
}

bool send_request(HTTPClient *client, char *request) {
    if (!client->is_connected) {
        perror("Error: not connected to server");
        return false;
    }
    int len = strlen(request);
    if (write(client->sock, request, len) != len) {
        perror("Error: failed to send request");
        return false;
    }
    return true;
}

bool receive_response(HTTPClient *client, char *response, int response_len) {
    if (!client->is_connected) {
        perror("Error: not connected to server");
        return false;
    }
    int total_bytes = 0, bytes_read = 0;
    memset(response, 0, response_len);
    while ((bytes_read = read(client->sock, response + total_bytes, response_len - total_bytes - 1)) > 0) {
        total_bytes += bytes_read;
        if (total_bytes >= response_len - 1) break;
    }
    if (bytes_read < 0) {
        perror("Error: failed to receive response");
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    HTTPClient client = {0};
    if (!connect_to_server(&client, "example.com", 80)) exit(EXIT_FAILURE);
    char request[256] = {0}, response[BUFFER_SIZE] = {0};
    sprintf(request, "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n");
    if (!send_request(&client, request)) exit(EXIT_FAILURE);
    if (!receive_response(&client, response, BUFFER_SIZE)) exit(EXIT_FAILURE);
    printf("Received response:\n%s\n", response);
    disconnect_from_server(&client);
    return 0;
}