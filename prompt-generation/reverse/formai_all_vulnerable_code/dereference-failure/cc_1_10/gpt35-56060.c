//FormAI DATASET v1.0 Category: Networking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, conn_fd;
    struct sockaddr_in server_addr;
    char buf[MAX_BUF_SIZE];
    
    // creating socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(1);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    
    // binding socket to port
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }
    
    // listening for incoming connections
    if(listen(sock_fd, 1) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }
    
    printf("Server listening on port %d\n", atoi(argv[1]));
    
    // accepting incoming connections
    if((conn_fd = accept(sock_fd, (struct sockaddr *)NULL, NULL)) == -1) {
        perror("Failed to accept a connection");
        exit(1);
    }
    
    printf("Connection established with client\n");
    
    // receiving data from client
    while(1) {
        memset(buf, 0, sizeof(buf));
        if (recv(conn_fd, buf, MAX_BUF_SIZE, 0) == -1) {
            perror("Failed to receive data");
            exit(1);
        }
        
        if(strcmp(buf, "exit") == 0) {
            printf("Closing connection with client\n");
            break;
        }
        printf("Received data from client: %s\n", buf);
    }
    
    close(sock_fd);
    close(conn_fd);
    
    return 0;
}