//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 4096
 
char* HTTP_200 = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
char* HTTP_404 = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n";
 
const char* WEB_ROOT = "/var/www/html/";
 
void handle_request(int client_socket) {
    char request_buffer[MAX_REQUEST_SIZE];
    recv(client_socket, request_buffer, MAX_REQUEST_SIZE - 1, 0);
     
    char* request_path = strtok(request_buffer, " ");
    request_path = strtok(NULL, " ");
     
    char file_path[strlen(WEB_ROOT) + strlen(request_path)];
    strcpy(file_path, WEB_ROOT);
    strcat(file_path, request_path);
     
    FILE* file = fopen(file_path, "r");
     
    if (file == NULL) {
        send(client_socket, HTTP_404, strlen(HTTP_404), 0);
        return;
    }
     
    send(client_socket, HTTP_200, strlen(HTTP_200), 0);
     
    char file_buffer[MAX_REQUEST_SIZE];
    int bytes_read = fread(file_buffer, 1, MAX_REQUEST_SIZE - 1, file);
     
    while(bytes_read > 0) {
        send(client_socket, file_buffer, bytes_read, 0);
        bytes_read = fread(file_buffer, 1, MAX_REQUEST_SIZE - 1, file);
    }
     
    fclose(file);
}
 
int main(int argc, char *argv[]) {
    int server_socket, client_socket, address_length;
    struct sockaddr_in server_address, client_address;
     
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
     
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
     
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
     
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen to socket");
        exit(EXIT_FAILURE);
    }
     
    printf("Multivariable Web Server running on port 8080\n");
     
    while(1) {
        address_length = sizeof(struct sockaddr_in);
         
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &address_length);
         
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            exit(EXIT_FAILURE);
        }
         
        handle_request(client_socket);
         
        close(client_socket);
    }
     
    return 0;
}