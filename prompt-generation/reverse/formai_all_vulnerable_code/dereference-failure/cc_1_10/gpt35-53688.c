//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_SIZE 2048

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: ./httpc get <URL> <parameters?> OR ./httpc post <URL> <data>");
    }

    char *method = argv[1];
    char *url = argv[2];
    char *parameters = argv[3];

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        printf("Error: Could not create socket.");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP server port
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status == -1) {
        printf("Error: Could not connect to server.");
        exit(1);
    }

    char request[MAX_SIZE];
    char response[MAX_SIZE];

    memset(request, 0, sizeof(request));
    memset(response, 0, sizeof(response));

    if (strcmp(method, "get") == 0) {
        sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", url, url);
    } else if (strcmp(method, "post") == 0) {
        sprintf(request, "POST /%s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s", 
                url, url, strlen(parameters), parameters);
    } else {
        printf("Error: Invalid HTTP method.");
        exit(1);
    }

    if (send(client_socket, request, strlen(request), 0) == -1) {
        printf("Error: Could not send request to server.");
        exit(1);
    }

    if (recv(client_socket, response, MAX_SIZE, 0) == -1) {
        printf("Error: Could not receive response from server.");
        exit(1);
    }

    printf("Response:\n%s", response);

    close(client_socket);

    return 0;
}