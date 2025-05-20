//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_HTTP_HEADER_LENGTH 1024
#define MAX_RESPONSE_LENGTH 2048

int main(int argc, char *argv[]) {
    char* host = "www.google.com";
    char* path = "/";
    int port = 80;

    struct hostent *server;
    struct sockaddr_in server_addr;

    char request[MAX_HTTP_HEADER_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    memset(request, 0, MAX_HTTP_HEADER_LENGTH);
    memset(response, 0, MAX_RESPONSE_LENGTH);

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Failed to create socket\n");
        return 1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Failed to find host\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr*)server->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to connect\n");
        return 1;
    }

    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:62.0) Gecko/20100101 Firefox/62.0\r\n\r\n", path, host);

    send(client_socket, request, strlen(request), 0);

    int response_length = recv(client_socket, response, MAX_RESPONSE_LENGTH, 0);

    printf("HTTP response:\n\n%d bytes received\n\n%s", response_length, response);

    close(client_socket);

    return 0;
}