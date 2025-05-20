//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>  
#include <stdlib.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <errno.h>  
#include <string.h>  
#include <unistd.h>   
#include <time.h>  
  
#define PORT 27015  
#define MAX_CONNECTIONS 10  
#define BUFFER_SIZE 1024  
  
int main(int argc, char **argv) {  
    int sock, status, connfd, t = 1;  
    struct sockaddr_in sin, client_addr;  
    char buffer[BUFFER_SIZE];  
    fd_set socket_set;  
    struct timeval timeout;  
    int bytes_received, client_len = sizeof(client_addr);  
  
    // Create socket  
    sock = socket(AF_INET, SOCK_STREAM, 0);  
  
    // Set reuse address option  
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &t, sizeof(int));  
  
    sin.sin_family = AF_INET;  
    sin.sin_addr.s_addr = INADDR_ANY;  
    sin.sin_port = htons(PORT);  
  
    // Bind socket to port and address  
    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) != 0) {  
        printf("Error while binding to port %d: %s\n", PORT, strerror(errno));  
        return -1;  
    }  
  
    // Set socket to listen state  
    if (listen(sock, MAX_CONNECTIONS) != 0) {  
        printf("Error while attempting to listen for connections: %s\n", strerror(errno));  
        return -1;  
    }  
  
    printf("Wireless Network Scanner listening on port %d...\n", PORT);  
  
    while (1) {  
        FD_ZERO(&socket_set); // clear socket set  
        FD_SET(sock, &socket_set); // add socket to set  
  
        // Set timeout for select  
        timeout.tv_sec = 5; // seconds  
        timeout.tv_usec = 0; // microseconds  
  
        status = select(sock + 1, &socket_set, NULL, NULL, &timeout); // blocking call  
  
        if (status < 0) {  
            printf("Error while waiting for client connection: %s\n", strerror(errno));  
            return -1;  
        } else if (status == 0) {  
            printf("Wireless Network Scanner waiting for client...\n");  
        } else if (FD_ISSET(sock, &socket_set)) {  
            // Accept client connection  
            connfd = accept(sock, (struct sockaddr*)&client_addr, &client_len);  
            if (connfd < 0) {  
                printf("Error while attempting to accept client connection: %s\n", strerror(errno));  
                return -1;  
            }  
  
            // Read client data  
            bytes_received = recv(connfd, buffer, BUFFER_SIZE, 0);  
            if (bytes_received < 0) {  
                printf("Error while attempting to read client data: %s\n", strerror(errno));  
                return -1;  
            }  
            buffer[bytes_received] = '\0'; // null-terminate string  
            printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));  
            printf("Client data: %s\n", buffer);  
            close(connfd);  
        }  
    }  
}