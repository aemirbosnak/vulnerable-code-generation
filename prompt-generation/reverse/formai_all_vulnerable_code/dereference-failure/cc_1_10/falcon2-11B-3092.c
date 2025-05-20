//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    int server_ip = inet_addr(argv[1]);
    int server_port = atoi(argv[2]);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = server_ip;

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to server!\n");

    char request[100];
    memset(request, 0, sizeof(request));
    printf("Enter the HTTP request:\n");
    fgets(request, sizeof(request), stdin);

    int request_len = strlen(request);
    char response[100];
    memset(response, 0, sizeof(response));
    ssize_t bytes_received = send(server_socket, request, request_len, 0);
    if (bytes_received < 0) {
        perror("send");
        return 1;
    }
    printf("Sent request to server.\n");

    ssize_t bytes_received_response = recv(server_socket, response, sizeof(response), 0);
    if (bytes_received_response < 0) {
        perror("recv");
        return 1;
    }
    printf("Received response from server:\n%s", response);

    return 0;
}