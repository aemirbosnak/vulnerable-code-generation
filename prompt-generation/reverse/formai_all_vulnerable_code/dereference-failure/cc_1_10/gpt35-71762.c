//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;
    char *message, buffer[MAXSIZE];
    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    
    //Enter IP and port number
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    
    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }
    
    printf("Connected to server %s:%s\n", argv[1], argv[2]);
    
    //Receive greeting message from the server
    if (recv(socket_desc, buffer, MAXSIZE, 0) < 0) {
        perror("Failed to receive greeting message");
        return 1;
    }
    
    printf("Server: %s", buffer);
    
    //Send username
    printf("Enter username: ");
    scanf("%s", message);
    send(socket_desc, message, strlen(message), 0);
    
    //Receive password prompt
    if (recv(socket_desc, buffer, MAXSIZE, 0) < 0) {
        perror("Failed to receive password prompt");
        return 1;
    }
    
    printf("Server: %s", buffer);
    
    //Send password
    printf("Enter password: ");
    scanf("%s", message);
    send(socket_desc, message, strlen(message), 0);
    
    //Receive login status
    if (recv(socket_desc, buffer, MAXSIZE, 0) < 0) {
        perror("Failed to receive login status");
        return 1;
    }
    
    printf("Server: %s", buffer);
    
    //Send command
    printf("Enter command: ");
    scanf("%s", message);
    send(socket_desc, message, strlen(message), 0);
    
    //Receive command output
    if (recv(socket_desc, buffer, MAXSIZE, 0) < 0) {
        perror("Failed to receive command output");
        return 1;
    }
    
    printf("Server: %s", buffer);
    
    close(socket_desc);
    
    return 0;
}