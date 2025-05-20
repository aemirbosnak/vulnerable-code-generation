//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

void handle_connection(int conn_fd){
    printf("Connection established.\n");
    char buffer[BUFFER_SIZE];
    int bytes_read;
    while((bytes_read = read(conn_fd, buffer, BUFFER_SIZE-1))) {
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);
        if(strstr(buffer, "rm") || strstr(buffer, "sudo")) {
            printf("Intrusion detected: %s\n", buffer);
            exit(EXIT_FAILURE);
        }
        write(conn_fd, buffer, strlen(buffer));
    }
    printf("Connection closed.\n");
    close(conn_fd);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);
    if(port < 1024 || port > 65535) {
        printf("Invalid port number.\n");
        return EXIT_FAILURE;
    }
    printf("Starting server on port %d.\n", port);
    struct sockaddr_in server_address, client_address;
    int server_fd, client_fd;
    socklen_t client_address_size = sizeof(client_address);
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket.\n");
        return EXIT_FAILURE;
    }
    if(bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket.\n");
        return EXIT_FAILURE;
    }
    if(listen(server_fd, SOMAXCONN) < 0) {
        printf("Failed to listen on socket.\n");
        return EXIT_FAILURE;
    }
    while(1) {
        if((client_fd = accept(server_fd, (struct sockaddr *) &client_address, &client_address_size)) < 0) {
            printf("Failed to accept connection.\n");
            continue;
        }
        handle_connection(client_fd);
    }
    return EXIT_SUCCESS;
}