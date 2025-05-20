//FormAI DATASET v1.0 Category: Socket programming ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h> // for socket(), bind(), listen() and accept()
#include<arpa/inet.h> // for inet_addr()
#include<string.h> // for memset()

#define MAX_CLIENTS 10

int main(int argc, char *argv[]){
    
    int client_sock[MAX_CLIENTS], server_sock, client_socket, recv_size, opt = 1;
    struct sockaddr_in server, client;
    char message[100];
    char *ip_address = "127.0.0.1"; // localhost
    int port_num = 8888;
    int max_clients = MAX_CLIENTS;
    
    // Create Socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock == -1){
        printf("Error: Could not create socket!\n");
    }
    printf("Server socket created successfully!\n");
    
    // Set socket option to reuse the address
    if(setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0 ) {
        printf("Error: Unable to set socket option!\n");
    }
    printf("Socket option set successfully!\n");
    
    // Set server socket values
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_port = htons(port_num);
    
    // Bind the socket to the specified IP and port
    if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        printf("Error: Unable to bind to socket!\n");
    }
    printf("Binding completed...\n");
    
    //Listen for incoming connections
    if(listen(server_sock, max_clients) < 0){
        printf("Error: Unable to listen on specified port!\n");
    }
    printf("Now listening to incoming connections...\n");
    
    // Accept incoming client connections
    for(int i=0; i<max_clients; i++){
        int c = sizeof(struct sockaddr_in);
        client_socket = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&c);
        if(client_sock < 0){
            printf("Error: Could not accept connection!\n");
        }
        client_sock[i] = client_socket;
        printf("Client %d connection accepted!\n", i+1);
    }
    
    // Receive incoming messages from clients
    while(1){
        for(int i=0; i<max_clients; i++){
            memset(message, 0, sizeof(message)); // Clear the message buffer
            if(recv_size = recv(client_sock[i], message, sizeof(message), 0) > 0){
                printf("Received message from client %d: %s\n", i+1, message);
                for(int j=0; j<max_clients; j++){
                    if(i != j){ // Do not send message to the same client that sent the message
                        send(client_sock[j], message, strlen(message), 0);   
                    }
                }
            }
        }
    }

    // Close the sockets
    for(int i=0; i<max_clients; i++){
        close(client_sock[i]);
    }
    close(server_sock);
    
    return 0;
}