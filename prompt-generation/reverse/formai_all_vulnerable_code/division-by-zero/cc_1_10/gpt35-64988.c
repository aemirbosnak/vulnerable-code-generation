//FormAI DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void xor_encrypt(char *key, char *data, int data_length){
    for(int i = 0; i < data_length; i++){
        data[i] ^= key[i % strlen(key)];
    }
}

int main(){
    int server_sockfd, client_sockfd, server_port, client_port, client_addr_len, recv_length;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE], key[BUFFER_SIZE];
    
    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sockfd == -1){
        printf("Failed to create socket\n");
        exit(-1);
    }
    
    // Bind the server socket to an address
    server_port = 8080;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);
    if(bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1){
        printf("Failed to bind socket to address\n");
        exit(-1);
    }
    
    // Start listening for connections
    if(listen(server_sockfd, 1) == -1){
        printf("Failed to start listening for connections\n");
        exit(-1);
    }
    
    printf("Listening on port %d...\n", server_port);
    
    // Wait for a client to connect
    client_addr_len = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if(client_sockfd == -1){
        printf("Failed to accept incoming connection\n");
        exit(-1);
    }
    
    // Receive the encryption key from the client
    recv_length = recv(client_sockfd, key, BUFFER_SIZE, 0);
    if(recv_length == -1){
        printf("Failed to receive encryption key\n");
        exit(-1);
    }
    
    printf("Received key: %s\n", key);
    
    // Receive the data to be encrypted from the client
    recv_length = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
    if(recv_length == -1){
        printf("Failed to receive data\n");
        exit(-1);
    }
    
    printf("Received data: %s\n", buffer);
    
    // Encrypt the data using the key
    xor_encrypt(key, buffer, strlen(buffer));
    
    printf("Encrypted data: %s\n", buffer);
    
    // Send the encrypted data back to the client
    if(send(client_sockfd, buffer, strlen(buffer), 0) == -1){
        printf("Failed to send encrypted data back to client\n");
        exit(-1);
    }
    
    // Close the socket and exit
    close(client_sockfd);
    close(server_sockfd);
    
    return 0;
}