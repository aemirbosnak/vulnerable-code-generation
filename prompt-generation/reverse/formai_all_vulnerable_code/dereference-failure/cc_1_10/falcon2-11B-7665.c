//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server_port>\n", argv[0]);
        exit(1);
    }
    
    int server_port = atoi(argv[1]);
    
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);
    
    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }
    
    if (listen(listen_fd, 5) < 0) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }
    
    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (client_fd < 0) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }
        
        char buffer[256];
        int n = read(client_fd, buffer, sizeof(buffer));
        if (n < 0) {
            fprintf(stderr, "Error reading from client\n");
            exit(1);
        }
        
        printf("Received: %s\n", buffer);
        
        char response[256];
        sprintf(response, "Hello, %s!", buffer);
        if (write(client_fd, response, strlen(response)) < 0) {
            fprintf(stderr, "Error writing to client\n");
            exit(1);
        }
        
        if (close(client_fd) < 0) {
            fprintf(stderr, "Error closing client\n");
            exit(1);
        }
    }
    
    return 0;
}