//Falcon-180B DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define ALLOWED_IP "192.168.1.1"

char allowed_ip[20];
int allowed_port;
char request_buffer[BUFFER_SIZE];

void process_request(int client_socket) {
    char *request = strtok(request_buffer, " ");
    if (request == NULL) {
        return;
    }
    if (strcmp(request, "GET")!= 0) {
        send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n", 60, 0);
        close(client_socket);
        return;
    }
    request = strtok(NULL, " ");
    if (request == NULL) {
        return;
    }
    if (strcmp(request, "/") == 0) {
        send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 0\r\n\r\n", 60, 0);
    } else {
        send(client_socket, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: 0\r\n\r\n", 60, 0);
    }
    close(client_socket);
}

void main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addr_len;
    char *ip;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        ip = inet_ntoa(client_addr.sin_addr);
        if (strcmp(ip, ALLOWED_IP)!= 0) {
            send(client_socket, "HTTP/1.1 403 Forbidden\r\nContent-Type: text/html\r\nContent-Length: 0\r\n\r\n", 60, 0);
            close(client_socket);
            continue;
        }

        memset(request_buffer, 0, BUFFER_SIZE);
        recv(client_socket, request_buffer, BUFFER_SIZE, 0);
        process_request(client_socket);
    }
}