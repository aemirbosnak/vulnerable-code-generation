//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void handle_client(int client_socket) {
    char buffer[BUFF_SIZE];
    bzero(buffer, BUFF_SIZE);

    int size = read(client_socket, buffer, BUFF_SIZE);
    if (size < 0) {
        error("Error reading from socket");
    }

    printf("Request: %s\n", buffer);

    // Detect and prevent directory traversal attacks
    if (strstr(buffer, "..") != NULL) {
        char *msg = "HTTP/1.0 403 Forbidden\r\n\r\n";
        write(client_socket, msg, strlen(msg));
        error("Error: directory traversal attack detected");
    }

    // Serve index.html by default
    char *filename = strtok(buffer, " ");
    filename = strtok(NULL, " ");
    if (strcmp(filename, "/") == 0) {
        filename = "/index.html";
    }

    // Open the file to return
    FILE *fp = fopen(&filename[1], "r");
    if (fp == NULL) {
        char *msg = "HTTP/1.0 404 Not Found\r\n\r\nFile not found";
        write(client_socket, msg, strlen(msg));
        error("Error: file not found");
    }

    char response[BUFF_SIZE*10];
    sprintf(response, "HTTP/1.0 200 OK\r\n\r\n");
    char line[BUFF_SIZE];
    while (fgets(line, BUFF_SIZE, fp)) {
        strcat(response, line);
    }

    fclose(fp);

    write(client_socket, response, strlen(response));
    printf("Response: %s\n", response);
}

int main(int argc , char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int server_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    struct sockaddr_in server_address, client_address;
    bzero((char *) &server_address, sizeof(server_address));
    int port = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    listen(server_socket, 5);
    printf("Server started on port %d...\n", port);

    while (1) {
        socklen_t client_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_length);
        if (client_socket < 0) {
            error("Error accepting client connection");
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_address.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Connection accepted from %s:%d\n", client_ip, ntohs(client_address.sin_port));

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}