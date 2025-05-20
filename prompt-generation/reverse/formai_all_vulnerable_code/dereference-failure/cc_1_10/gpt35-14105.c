//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<netdb.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/select.h>

#define PORT 50000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int sock_fd, conn_fd; 
    struct sockaddr_in server_addr; 
    struct timeval tv; 
    char *request = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"; 
    char buffer[BUFFER_SIZE]; 

    // Initialize socket 
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(sock_fd == -1) {
        printf("Socket creation failed: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE);
    }

    // Set socket options
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    memset(&server_addr, 0, sizeof(server_addr)); 
  
    // Assign IP, PORT 
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = inet_addr("172.217.166.78"); 
    server_addr.sin_port = htons( PORT ); 
  
    // Connect the client socket to server socket 
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { 
        printf("Connection failed: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    // Send the request to server
    if (send(sock_fd, request, strlen(request), 0) < 0) { 
        printf("Send failed: %s\n", strerror(errno)); 
        exit(EXIT_FAILURE); 
    }

    // Receive data from server
    int total_bytes = 0; 
    int read_bytes;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sock_fd, &read_fds);
    while(select(sock_fd + 1, &read_fds, NULL, NULL, &tv)) {
        read_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);
        if(read_bytes < 0) {
            printf("Receive failed: %s\n", strerror(errno)); 
            exit(EXIT_FAILURE);
        }
        if(read_bytes == 0) {
            break;
        }
        buffer[read_bytes] = '\0';
        total_bytes += read_bytes;
    }

    // Close socket and print results
    close(sock_fd);
    printf("Total bytes received: %d\n", total_bytes);

    return 0;
}