//FormAI DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

void* handle_connection(void* arg) {
    char buffer[1024] = {0};
    int socket = *(int*)arg;
    int valread = read(socket, buffer, 1024);
    
    if (valread == 0) {
        printf("Client disconnected.\n");
    } else {
        printf("%s\n", buffer);
    
        char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Welcome to my simple web server!</h1></body></html>\n";
        write(socket, response, strlen(response));
    }
    
    close(socket);
    free(arg);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }
        
        printf("New client connected.\n");
        
        int* socket_ptr = malloc(sizeof(int));
        *socket_ptr = new_socket;
        
        pthread_t tid;
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, handle_connection, socket_ptr);
    }
    
    return 0;
}