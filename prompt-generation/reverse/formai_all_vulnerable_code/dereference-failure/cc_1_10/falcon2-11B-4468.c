//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define MAX_MSG_LEN 256

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    
    int sockfd, new_socket;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);
    int opt = 1;
    int yes = 1;
    
    char buffer[MAX_MSG_LEN];
    char message[MAX_MSG_LEN];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }
    
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Failed to bind socket\n");
        return 1;
    }
    
    if (listen(sockfd, 5) < 0) {
        printf("Error: Failed to listen\n");
        return 1;
    }
    
    while (1) {
        new_socket = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &addrlen);
        
        if (new_socket < 0) {
            printf("Error: Failed to accept connection\n");
            return 1;
        }
        
        printf("Connected to client with address: %s\n", inet_ntoa(cli_addr.sin_addr));
        
        while (read(new_socket, buffer, MAX_MSG_LEN) > 0) {
            strcpy(message, buffer);
            write(new_socket, message, strlen(message));
            printf("Received message: %s\n", message);
        }
        
        close(new_socket);
    }
    
    return 0;
}