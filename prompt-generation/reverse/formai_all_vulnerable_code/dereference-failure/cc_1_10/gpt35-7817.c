//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *addr_res;
    int client_socket, server_port, return_code;
    char server_name[100], server_path[100], request[BUFFER_SIZE], response[BUFFER_SIZE];
    memset(&hints, 0, sizeof(hints)); 

    if(argc != 3) {
        printf("Usage: %s [Server Name] [Server Port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    strcpy(server_name, argv[1]);
    server_port = atoi(argv[2]);
    if(server_port < 0 || server_port > 65535) {
        printf("Invalid server port number. Use between 1-65535.\n");
        exit(EXIT_FAILURE);
    }
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Failed to create client socket.\n");
        exit(EXIT_FAILURE);
    }
    hints.ai_family = AF_INET; 
    hints.ai_socktype = SOCK_STREAM;
    return_code = getaddrinfo(server_name, "http", &hints, &addr_res);
    if(return_code != 0) { 
        printf("Failed to resolve server address.\n");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    memcpy(&(server_address.sin_addr), &((struct sockaddr_in *)addr_res->ai_addr)->sin_addr, sizeof(struct in_addr));
    server_address.sin_port = htons(server_port);
    server_address.sin_family = AF_INET;
    return_code = connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if(return_code != 0) { 
        printf("Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\nConnection: close\r\n\r\n", server_name);
    return_code = send(client_socket, request, strlen(request), 0);
    if (return_code < 0) {
        printf("Failed to send request to server.\n");
        exit(EXIT_FAILURE);
    }
    memset(&response, 0, BUFFER_SIZE);
    return_code = recv(client_socket, response, BUFFER_SIZE, 0);
    if (return_code < 0) {
        printf("Failed to receive response from server.\n");
        exit(EXIT_FAILURE);
    }
    printf("Response from server:\n\n%s\n", response);
    close(client_socket);
    return 0;
}