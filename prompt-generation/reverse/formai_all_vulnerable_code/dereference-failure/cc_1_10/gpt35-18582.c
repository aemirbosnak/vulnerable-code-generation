//FormAI DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(){
    int server_fd, new_socket, valread, file_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *file_name = malloc(BUFFER_SIZE);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while(1){
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0){
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Receive file name from client
        valread = read( new_socket , buffer, BUFFER_SIZE);
        sscanf(buffer, "%s", file_name);

        // Open requested file
        file_fd = open(file_name, O_RDONLY);
        if(file_fd < 0){
            // Return error message if file not found
            send(new_socket, "HTTP/1.1 404 NOT FOUND\n\n", 24, 0);
            send(new_socket, "File Not Found\n", 15, 0);
            close(new_socket);
            continue;
        }

        // Send file contents to client
        send(new_socket, "HTTP/1.1 200 OK\n\n", 17, 0);
        while((valread = read(file_fd, buffer, BUFFER_SIZE)) > 0){
            send(new_socket, buffer, valread, 0);
        }

        // Close file and socket
        close(file_fd);
        close(new_socket);
    }
    
    return 0;
}