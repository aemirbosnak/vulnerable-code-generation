//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <unistd.h> 
#include <errno.h> 
#include <pthread.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <ctype.h> 

#define BUFFER_SIZE 1024 
#define DEFAULT_PORT 8080 
#define THREAD_POOL_SIZE 10 

void handle_request(int); 
void *worker_thread(void *); 

int main(int argc, char *argv[]) {

    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 

    int opt = 1; 
    int addrlen = sizeof(address); 

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Allow multiple connections to the same server
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("Setsockopt failed"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(DEFAULT_PORT); 

    // Bind server socket to a port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("Bind failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) { 
        perror("Listen failed"); 
        exit(EXIT_FAILURE); 
    }

    // Create thread pool
    pthread_t thread_pool[THREAD_POOL_SIZE]; 
    int i; 
    for (i = 0; i < THREAD_POOL_SIZE; i++) { 
        pthread_create(&thread_pool[i], NULL, worker_thread, NULL); 
    } 

    // Main server loop
    while (true) { 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) { 
            perror("Accept failed");  
            exit(EXIT_FAILURE); 
        } 

        printf("Connection accepted from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port)); 

        // Add socket to worker queue
        int *client_socket = malloc(sizeof(int)); 
        *client_socket = new_socket; 
        pthread_t worker_thread_id; 
        pthread_create(&worker_thread_id, NULL, worker_thread, (void *)client_socket); 
    } 

    return 0; 
} 

void *worker_thread(void *arg) { 
    // Get socket file descriptor
    int client_socket = *((int *)arg); 
    free(arg); 

    handle_request(client_socket); 

    // Close socket file descriptor
    close(client_socket); 

    return NULL; 
} 

void handle_request(int client_socket) { 
    char buffer[BUFFER_SIZE] = {0}; 
    int valread = read(client_socket, buffer, BUFFER_SIZE); 
    printf("Received message: %s\n", buffer); 

    // Send response
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello world!"; 
    int response_len = strlen(response); 
    int sent_bytes = send(client_socket, response, response_len, 0); 

    printf("Sent %d bytes\n", sent_bytes); 
}