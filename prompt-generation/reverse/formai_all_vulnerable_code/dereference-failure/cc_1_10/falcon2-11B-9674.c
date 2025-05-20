//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_socket, client_socket, n;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];
    char *message = "Welcome to my TCP/IP server!\n";
    
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }
    
    if (listen(server_socket, 3) == -1) {
        perror("listen");
        exit(1);
    }
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&n);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }
        
        if (read(client_socket, buffer, sizeof(buffer)) == -1) {
            perror("read");
            exit(1);
        }
        
        write(client_socket, message, strlen(message));
        
        close(client_socket);
    }
    
    return 0;
}