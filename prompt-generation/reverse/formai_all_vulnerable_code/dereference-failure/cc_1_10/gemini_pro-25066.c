//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
// Dennis Ritchie-inspired C client-server application

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

// Client
void client(int sockfd)
{
    char sendbuf[MAX_MSG_SIZE];
    char recvbuf[MAX_MSG_SIZE];
    
    while (1) {
        // Read message from stdin
        printf("> ");
        fgets(sendbuf, MAX_MSG_SIZE, stdin);
        
        // Send message to server
        if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
            perror("send");
            exit(1);
        }
        
        // Receive message from server
        if (recv(sockfd, recvbuf, MAX_MSG_SIZE, 0) == -1) {
            perror("recv");
            exit(1);
        }
        
        // Print received message
        printf("< %s", recvbuf);
    }
}

// Server
void server(int sockfd)
{
    int client_sock[MAX_CLIENTS];
    int client_len[MAX_CLIENTS];
    int max_fd;
    fd_set read_fds;
    
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sock[i] = -1;
        client_len[i] = 0;
    }
    
    while (1) {
        // Initialize read file descriptor set
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);
        max_fd = sockfd;
        
        // Add client sockets to read file descriptor set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sock[i] != -1) {
                FD_SET(client_sock[i], &read_fds);
                if (client_sock[i] > max_fd) {
                    max_fd = client_sock[i];
                }
            }
        }
        
        // Select on read file descriptor set
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(1);
        }
        
        // Handle new client connection
        if (FD_ISSET(sockfd, &read_fds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);
            
            int new_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
            if (new_sockfd == -1) {
                perror("accept");
                exit(1);
            }
            
            // Find empty slot for client socket
            int empty_slot = -1;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sock[i] == -1) {
                    empty_slot = i;
                    break;
                }
            }
            
            if (empty_slot == -1) {
                // No empty slot available
                close(new_sockfd);
                continue;
            }
            
            // Add client socket to array
            client_sock[empty_slot] = new_sockfd;
            client_len[empty_slot] = client_addr_len;
        }
        
        // Handle client messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sock[i] != -1 && FD_ISSET(client_sock[i], &read_fds)) {
                char recvbuf[MAX_MSG_SIZE];
                
                // Receive message from client
                if (recv(client_sock[i], recvbuf, MAX_MSG_SIZE, 0) == -1) {
                    perror("recv");
                    exit(1);
                }
                
                // Send message to client
                if (send(client_sock[i], recvbuf, strlen(recvbuf), 0) == -1) {
                    perror("send");
                    exit(1);
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <role>\n", argv[0]);
        exit(1);
    }
    
    int port = atoi(argv[1]);
    char *role = argv[2];
    
    if (strcmp(role, "client") == 0) {
        // Client
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }
        
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        
        if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            exit(1);
        }
        
        client(sockfd);
    } else if (strcmp(role, "server") == 0) {
        // Server
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }
        
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        
        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            perror("bind");
            exit(1);
        }
        
        if (listen(sockfd, MAX_CLIENTS) == -1) {
            perror("listen");
            exit(1);
        }
        
        server(sockfd);
    } else {
        fprintf(stderr, "Invalid role: %s\n", role);
        exit(1);
    }
    
    return 0;
}