//FormAI DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
/* This is a chat client and server application written in C language
 *
 * Author: [Your Name]
 * Date: [Date]
 *
 * Description:
 * This program connects multiple chat clients to the chat server using TCP/IP socket programming.
 * Chat clients can communicate with each other through the chat server
 * Each client sends and receives messages over the network in real-time
 */

// Importing necessary libraries 
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

// Maximum buffer size for messages
#define MAX_MSG_SIZE 1024 

// Function to receive incoming messages from the client
void receive_message(int socket, char* buffer) {
    ssize_t message_size = recv(socket, buffer, MAX_MSG_SIZE, 0);
    if (message_size == 0) { // If the message is empty, disconnect the client.
        printf("Empty message received. Client disconnected.\n");
        close(socket);
        exit(1);
    } else if (message_size < 0) { // If the message is negative, report an error.
        perror("receive error");
        exit(1);
    } else { // If the message is valid, print the message received.
        buffer[message_size] = '\0'; // Add null termination to the end of the message
        printf("MESSAGE RECEIVED: %s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    char server_message[MAX_MSG_SIZE] = "Hello, you are now connected to the chat server.\n";
    char client_message[MAX_MSG_SIZE];

    // Creating server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket creation"); // If server socket creation fails, report an error.
        exit(1);
    }

    // Defining server address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Binding server to specified IP address and port.
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind error");
        exit(1);
    }

    // Set the server to listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen error");
        exit(1);
    }

    while (1) { // Run the server program indefinitely
        printf("Waiting for incoming connections...\n");
        // Create a new socket with a new client connection if a client connects to the server.
        new_socket = accept(server_socket, NULL, NULL);
        if (new_socket == -1) {
            perror("accept error");
            exit(1);
        }

        // Send a welcome message to the new client when connected to the server.
        send(new_socket, server_message, strlen(server_message), 0);
        printf("Welcome message sent to client.\n");

        // Loop until a client disconnects from the server
        while(1) {
            // Receive message from the client
            receive_message(new_socket, client_message);
            
            // If message is "exit", the client wants to disconnect
            if(strcmp(client_message, "exit") == 0) {
                printf("Client wants to disconnect, goodbye! \n");
                close(new_socket); //Close individual client socket
                break; //Break the listening loop to wait for new connections
            }
          
            //Send received message to other clients 
            for(int i = 4 ; i < 15 ; i++)
            {
            	if(i != new_socket)
            	{
            		send(i, client_message, strlen(client_message), 0);
            	}
            }

            // Clear the buffer after use
            memset(client_message, 0, sizeof(client_message));
        }
    }

    // Close the server socket
    printf("Server program terminated. \n");
    close(server_socket);
    return 0;
}