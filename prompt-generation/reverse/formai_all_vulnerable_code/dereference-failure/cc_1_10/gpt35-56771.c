//FormAI DATASET v1.0 Category: Firewall ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>
#include<netdb.h>
#include<pthread.h>

#define BUFFER_LEN 1024
#define ERROR -1

void *firewall(void* args);

int main(int argc, char const *argv[]) {

    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);
    pthread_t thread_id;

    if (argc != 2) {
        
        printf("Usage: %s <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
        
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == ERROR) {
        
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == ERROR) {
        
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 20) == ERROR) {
        
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Firewall activated\n");

    while (1) {

        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) == ERROR) {
            
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (pthread_create(&thread_id, NULL, &firewall, (void *)&client_fd) == ERROR) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *firewall(void* args) {
    
    char buffer[BUFFER_LEN] = {0};
    int client_fd = *(int *)args;

    read(client_fd , buffer, BUFFER_LEN);

    if (strstr(buffer, "password") != NULL) {
        printf("Attempt to access password detected, request denied.\n");
        close(client_fd);
    } else {
        printf("Packet allowed.\n");
        write(client_fd , "Message received", strlen("Message received") + 1);
        close(client_fd);
    }

    pthread_exit(NULL);
}