//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <signal.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    
    if (bytes_received == -1) {
        perror("Error receiving client request.\n");
        return;
    }
    
    /* Extract the host name and port number from the request headers */
    char* host = strstr(buffer, "Host: ") + 6;
    char* port = strstr(host, ":");
    
    if (port == NULL) {
        port = "80";
        host[strcspn(host, "\r\n")] = '\0'; /* Remove end of line characters */
    } else {
        *port = '\0';
        port++;
    }
    
    /* Establish a connection to the destination server */
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent* server = gethostbyname(host);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(port));
    server_address.sin_addr = *(struct in_addr*)server->h_addr;
    
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to the server.\n");
        return;
    }
    
    /* Forward the client request to the destination server */
    if (send(server_socket, buffer, bytes_received, 0) == -1) {
        perror("Error sending request to the server.\n");
        return;
    }
    
    /* Receive response from the server and forward it to the client */
    int total_bytes = 0;
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            perror("Error sending response to the client.\n");
            return;
        }
        
        total_bytes += bytes_received;
    }
    
    close(server_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PROXY_PORT);
    
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding to port.\n");
        return 1;
    }
    
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening for connections.\n");
        return 1;
    }
    
    printf("Proxy server started on port %d.\n", PROXY_PORT);
    
    while (1) {
        struct sockaddr_in client_address;
        unsigned int client_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_size);
        
        if (client_socket == -1) {
            perror("Error accepting connection.\n");
            return 1;
        }
        
        /* Fork a new process to handle the client request */
        if (fork() == 0) {
            close(server_socket);
            handle_request(client_socket);
            close(client_socket);
            return 0;
        } else {
            close(client_socket);
        }
    }
    
    return 0;
}