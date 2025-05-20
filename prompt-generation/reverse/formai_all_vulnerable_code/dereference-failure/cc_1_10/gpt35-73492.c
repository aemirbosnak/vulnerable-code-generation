//FormAI DATASET v1.0 Category: Networking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 50
#define PORT 8080

int sockfd, client_fd[MAX_CLIENTS];
struct sockaddr_in server_addr, client_addr;
socklen_t addr_len = sizeof(struct sockaddr_in);
pthread_t threads[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char message[1024];
    memset(message, 0, sizeof(message));
    
    while (true) {
        int len = recv(client_socket, message, sizeof(message), 0);
        
        if (len == 0) {
            printf("Client %d disconnected.\n", client_socket);
            break;
        }
        message[len] = '\0';
        printf("Client %d sent: %s\n", client_socket, message);
        
        for (int i = 0; i < client_count; i++) {
            if (client_fd[i] != client_socket) {
                send(client_fd[i], message, strlen(message), 0);
            }
        }
    }
    
    for (int i = 0; i < client_count; i++) {
        if (client_fd[i] == client_socket) {
            client_fd[i] = -1;
            break;
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        printf("Failed to create socket. Error code: %d\n", errno);
        exit(errno);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    int bind_result = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    if (bind_result < 0) {
        printf("Failed to bind socket. Error code: %d\n", errno);
        exit(errno);
    }
    
    int listen_result = listen(sockfd, MAX_CLIENTS);
    if (listen_result < 0) {
        printf("Failed to listen on socket. Error code: %d\n", errno);
        exit(errno);
    }
    
    printf("Server listening on port %d...\n", PORT);
    
    while (true) {
        int cfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
        if (cfd < 0) {
            printf("Failed to accept incoming connection. Error code: %d\n", errno);
            continue;
        }
        
        bool max_clients_reached = (client_count == MAX_CLIENTS);
        if (!max_clients_reached) {
            client_fd[client_count] = cfd;
            client_count++;
            pthread_create(&threads[client_count], NULL, handle_client, &cfd);
            
            printf("New client connected! IP: %s, count: %d.\n", inet_ntoa(client_addr.sin_addr), client_count);
        }
        else {
            printf("Maximum clients reached. Connection rejected.\n");
            close(cfd);
        }
    }
    
    return 0;
}