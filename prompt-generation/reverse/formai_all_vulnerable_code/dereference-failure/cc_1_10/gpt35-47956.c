//FormAI DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

void *connection_handler(void *);
pthread_mutex_t lock;

int main(int argc, char *argv[])
{
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    
    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        puts("Bind failed");
        return 1;
    }
    
    puts("Bind done");
    
    // Listen
    listen(socket_desc, 3);
    
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c)))
    {
        puts("Connection accepted");
        
        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = client_sock;
        
        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) < 0)
        {
            perror("Could not create thread");
            return 1;
        }
        
        puts("Handler assigned");
    }
    
    if (client_sock < 0)
    {
        perror("Accept failed");
        return 1;
    }
    
    return 0;
}

void *connection_handler(void *socket_desc)
{
    int sock = *(int *)socket_desc, read_size;
    char *message, client_message[2000];
    
    // Send welcome message to client
    message = "Connected to chat server. Type 'exit' to quit\n";
    write(sock, message, strlen(message));
    
    // Receive messages from client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0)
    {
        // Terminate message with null character
        client_message[read_size] = '\0';
        
        // Check if client wants to exit program
        if (strcmp(client_message, "exit") == 0)
        {
            message = "Goodbye from chat server\n";
            write(sock, message, strlen(message));
            
            // Release socket and exit thread
            close(sock);
            break;
        }
        
        // Add mutex lock to prevent parallel write access to stdout
        pthread_mutex_lock(&lock);
        
        // Print received message to stdout
        printf("Received message from client #%i: %s\n", sock, client_message);
        
        // Unlock mutex
        pthread_mutex_unlock(&lock);
    }
    
    if (read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("Recv failed");
    }
    
    // Free allocated memory and return
    free(socket_desc);
    
    return 0;
}