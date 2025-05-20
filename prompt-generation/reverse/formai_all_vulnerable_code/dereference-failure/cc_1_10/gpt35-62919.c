//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [server IP] [port]\n", argv[0]);
        exit(1);
    }
    
    const char *server_ip = argv[1];
    int port = atoi(argv[2]);
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(port);
    
    // create a TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }
    
    // connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(1);
    }
    
    // prepare the HTTP request message
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", server_ip);
    
    // send the message to the server
    write(socket_fd, buffer, strlen(buffer));
    
    // receive and print the response from the server
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = read(socket_fd, buffer, BUFFER_SIZE);
    while (bytes_received > 0) {
        printf("%s", buffer);
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = read(socket_fd, buffer, BUFFER_SIZE);
    }
    
    // close the socket
    close(socket_fd);
    
    return 0;
}