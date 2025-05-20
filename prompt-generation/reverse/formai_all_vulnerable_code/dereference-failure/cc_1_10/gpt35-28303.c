//FormAI DATASET v1.0 Category: Socket programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

// Define the socket port number
#define PORT 8080

void *
connection_handler(void *socket_desc) 
{
    // Get the socket descriptor
    int client_sock = *(int *)socket_desc;
    int read_size;
    char client_message[2000];
     
    // Send initial message to the client
    char *message = "Hello! Welcome to the server!\n";
    write(client_sock, message, strlen(message));
         
    // Receive a message from client
    while ((read_size = recv(client_sock , client_message , 2000 , 0)) > 0) {
        // Check if client wants to quit
        if (strcmp(client_message, "quit\n") == 0) {
            // Close the socket to the client
            close(client_sock);
            puts("Client disconnected");
            break;
        }
        // Send the message back to client
        write(client_sock , client_message , strlen(client_message));
        memset(client_message, 0, strlen(client_message));  // Reset the buffer
    }
         
    if (read_size == 0) {
        puts("Client disconnected");
    } else if (read_size == -1) {
        perror("recv failed");
    }
         
    // Free up the socket descriptor memory
    free(socket_desc);
         
    return NULL;
}

int
main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
     
    // Create the socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
     
    // Reset the server and client memory
    memset(&server, 0, sizeof(server));
    memset(&client, 0, sizeof(client));
     
    // Prepare the server sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
     
    // Bind the socket to the IP address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    puts("Bind done");
     
    // Listen for incoming connections
    listen(socket_desc, 3);
     
    // Accept incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        puts("Connection accepted");
         
        // Spawn a new thread to handle incoming connection
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
         
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) < 0) {
            perror("Could not create thread");
            return 1;
        }
         
        // Join the thread
        pthread_join(sniffer_thread, NULL);
    }
     
    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }
     
    return 0;
}