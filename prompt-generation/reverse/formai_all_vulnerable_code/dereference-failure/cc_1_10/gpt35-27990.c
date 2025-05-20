//FormAI DATASET v1.0 Category: Chat server ; Style: modular
// Header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<unistd.h>
#include<pthread.h>

// Constants
#define PORT 8080
#define MAX_CLIENTS 10

// Structures
typedef struct{
    int socket;
    struct sockaddr_in address;
}client_t;

// Function prototypes
void *connection_handler(void *client_socket_ptr);
void error(char *msg);

// Main function
int main(){
    int server_socket, client_socket, opt = 1, sock_size = sizeof(struct sockaddr_in);
    struct sockaddr_in address, *temp_address;
    pthread_t thread_id;
    client_t *client_list[MAX_CLIENTS];
    int client_count = 0;

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == 0){
        error("Failed to create socket");
    }

    // Setting socket options
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        error("Failed to set socket options");
    }

    // Assigning IP and port to socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding socket to the address and port
    if(bind(server_socket, (struct sockaddr *)&address, sock_size) < 0){
        error("Failed to bind socket");
    }

    // Listening for incoming connections
    if(listen(server_socket, 3) < 0){
        error("Failed to listen for connections");
    }

    // Accepting incoming connections
    while((client_socket = accept(server_socket, (struct sockaddr *)&temp_address, (socklen_t *)&sock_size))){
        // Creating a client structure and adding it to the client list
        client_t *client = malloc(sizeof(client_t));
        client->socket = client_socket;
        client->address = *temp_address;
        client_list[client_count] = client;
        client_count++;

        // Creating a thread to handle the client's connection
        if(pthread_create(&thread_id, NULL, connection_handler, (void *)&client_socket) < 0){
            error("Failed to create thread");
        }

        // Detaching the thread to free up resources
        pthread_detach(thread_id);
    }

    // Closing server socket
    close(server_socket);

    return 0;
}

// Function to handle incoming connections
void *connection_handler(void *client_socket_ptr){
    int client_socket = *(int *)client_socket_ptr;
    char buffer[1024] = {0};
    int read_status;

    // Infinite loop to receive messages from client
    while(1){
        read_status = read(client_socket, buffer, 1024);
        if(read_status == 0){
            // Client has disconnected
            break;
        }
        else if(read_status < 0){
            // Error in reading
            error("Error in reading from client");
        }

        // Printing received message
        printf("Message received from client: %s\n", buffer);

        // Echoing the message back to the client
        write(client_socket, buffer, strlen(buffer));
        memset(buffer, 0, 1024);
    }

    // Closing client socket
    close(client_socket);

    return NULL;
}

// Function to print error message and exit
void error(char *msg){
    perror(msg);
    exit(EXIT_FAILURE);
}