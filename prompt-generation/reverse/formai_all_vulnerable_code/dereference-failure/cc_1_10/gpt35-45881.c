//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define PORT 8080 
#define MAXBUFLEN 8192 

void handle_client_request(int proxy_sock, 
                           struct sockaddr_in client_addr, 
                           char* request, int request_size) 
{ 
    // Extract the client IP address and port number 
    char client_ip[INET_ADDRSTRLEN]; 
    inet_ntop(AF_INET, &(client_addr.sin_addr), 
              client_ip, INET_ADDRSTRLEN); 
    int client_port = ntohs(client_addr.sin_port); 

    // Create a new socket to handle the client request 
    int server_sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (server_sock < 0) { 
        fprintf(stderr, "Failed to create socket for server.\n"); 
        exit(1); 
    } 

    // Connect to the server 
    struct sockaddr_in server_addr; 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_port = htons(80); 
    if (inet_pton(AF_INET, "172.217.164.174", 
                  &(server_addr.sin_addr)) <= 0) { 
        fprintf(stderr, "Invalid server address.\n"); 
        exit(1); 
    } 
    if (connect(server_sock, (struct sockaddr*)&server_addr, 
                sizeof(server_addr)) < 0) { 
        fprintf(stderr, "Failed to connect to server.\n"); 
        exit(1); 
    } 

    // Forward the client request to the server 
    if (send(server_sock, request, request_size, 0) < 0) { 
        fprintf(stderr, "Failed to forward client request to server.\n"); 
        exit(1); 
    } 

    // Receive the response from the server 
    char* response = (char*)malloc(MAXBUFLEN); 
    int total_recv = 0; 
    int recv_size; 
    char buf[MAXBUFLEN]; 
    while ((recv_size = recv(server_sock, buf, MAXBUFLEN, 0)) > 0) { 
        if (total_recv + recv_size > MAXBUFLEN) { 
            fprintf(stderr, "Response too big.\n"); 
            free(response); 
            exit(1); 
        } 
        memcpy(response + total_recv, buf, recv_size); 
        total_recv += recv_size; 
    } 
    if (recv_size < 0) { 
        fprintf(stderr, "Failed to receive server response.\n"); 
        free(response); 
        exit(1); 
    } 

    // Forward the server response to the client 
    if (send(proxy_sock, response, total_recv, 0) < 0) { 
        fprintf(stderr, "Failed to forward server response to client.\n"); 
        free(response); 
        exit(1); 
    } 

    // Clean up 
    free(response); 
    close(server_sock); 
} 

int main() 
{ 
    // Create the proxy socket 
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (proxy_sock < 0) { 
        fprintf(stderr, "Failed to create proxy socket.\n"); 
        exit(1); 
    } 

    // Bind the proxy socket to the port 
    struct sockaddr_in proxy_addr; 
    proxy_addr.sin_family = AF_INET; 
    proxy_addr.sin_port = htons(PORT); 
    proxy_addr.sin_addr.s_addr = INADDR_ANY; 
    memset(proxy_addr.sin_zero, '\0', sizeof(proxy_addr.sin_zero)); 
    if (bind(proxy_sock, (struct sockaddr*)&proxy_addr, 
             sizeof(proxy_addr)) < 0) { 
        fprintf(stderr, "Failed to bind proxy socket to port %d.\n", PORT); 
        exit(1); 
    } 

    // Listen for incoming client connections 
    if (listen(proxy_sock, 10) < 0) { 
        fprintf(stderr, "Failed to listen for incoming client connections.\n"); 
        exit(1); 
    } 

    printf("Waiting for client connections on port %d...\n", PORT); 

    while (1) { 
        // Accept an incoming client connection 
        struct sockaddr_in client_addr; 
        int client_sock; 
        socklen_t client_addr_len = sizeof(client_addr); 
        if ((client_sock = accept(proxy_sock, (struct sockaddr*)(&client_addr), 
                                  &client_addr_len)) < 0) { 
            fprintf(stderr, "Failed to accept incoming client connection.\n"); 
            exit(1); 
        } 

        printf("Received client connection from %s:%d.\n", 
               inet_ntoa(client_addr.sin_addr), client_addr.sin_port); 

        // Receive the client request 
        char* request = (char*)malloc(MAXBUFLEN); 
        int total_recv = 0; 
        int recv_size; 
        char buf[MAXBUFLEN]; 
        while ((recv_size = recv(client_sock, buf, MAXBUFLEN, 0)) > 0) { 
            if (total_recv + recv_size > MAXBUFLEN) { 
                fprintf(stderr, "Request too big.\n"); 
                free(request); 
                exit(1); 
            } 
            memcpy(request + total_recv, buf, recv_size); 
            total_recv += recv_size; 
            if (strstr(request, "\r\n\r\n")) { 
                break; 
            } 
        } 
        if (recv_size < 0) { 
            fprintf(stderr, "Failed to receive client request.\n"); 
            free(request); 
            exit(1); 
        } 

        printf("Received client request:\n%s\n", request); 

        // Handle the client request 
        handle_client_request(client_sock, client_addr, request, total_recv); 

        // Clean up 
        free(request); 
        close(client_sock); 
    } 

    // Should never get here 
    return 0; 
}