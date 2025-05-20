//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

#define BUFF_SIZE 1024

//Global variables to be used for termination of the server when desired
int server_socket;
int client_socket;

//Signal handler function for termination
void handle_termination(int sig){
    printf("\nShutting down server...\n");
    close(server_socket);
    close(client_socket);
    exit(0);
}

int main(int argc, char* argv[]){
    
    signal(SIGINT, handle_termination); //Setting up signal handler for termination
    
    if(argc < 2){
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }
    
    int port = atoi(argv[1]);
    
    //Creating the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        printf("Error: Could not create server socket.\n");
        return 1;
    }
    
    //Setting up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    //Binding the server socket to the server address
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        printf("Error: Could not bind server socket.\n");
        close(server_socket);
        return 1;
    }
    
    //Listening for incoming clients
    if(listen(server_socket, 1) == -1){
        printf("Error: Could not listen for incoming clients.\n");
        close(server_socket);
        return 1;
    }
    
    printf("Server running on port %d\n", port);
    
    //Accepting incoming clients
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
    
    if(client_socket == -1){
        printf("Error: Could not accept incoming client.\n");
        close(server_socket);
        return 1;
    }
    
    //Initiating communication with client
    char buffer[BUFF_SIZE];
    
    while(1){
        
        //Receiving message from client
        if(recv(client_socket, buffer, BUFF_SIZE, 0) == -1){
            printf("Error: Could not receive message from client.\n");
            close(client_socket);
            close(server_socket);
            return 1;
        }
        
        printf("Received message from client: %s\n", buffer);
        
        //Sending acknowledgement to client
        char ack_msg[] = "Your message has been received.";
        if(send(client_socket, ack_msg, strlen(ack_msg), 0) == -1){
            printf("Error: Could not send acknowledgement to client.\n");
            close(client_socket);
            close(server_socket);
            return 1;
        }
        
        printf("Sent acknowledgement to client.\n");
        
    }
    
    return 0;
}