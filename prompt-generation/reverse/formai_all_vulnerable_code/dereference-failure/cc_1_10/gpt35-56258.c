//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[MAXSIZE], filename[MAXSIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(21);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }
    
    // Receive banner message from server
    memset(buffer, 0, MAXSIZE);
    if (recv(sockfd, buffer, MAXSIZE, 0) < 0) {
        error("Error receiving banner message");
    }
    printf("%s", buffer); 
    
    // Send username
    memset(buffer, 0, MAXSIZE);
    printf("Username: ");
    fgets(buffer, MAXSIZE, stdin);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending username");
    }
    
    // Receive password prompt from server
    memset(buffer, 0, MAXSIZE);
    if (recv(sockfd, buffer, MAXSIZE, 0) < 0) {
        error("Error receiving password prompt");
    }
    
    // Send password
    memset(buffer, 0, MAXSIZE);
    printf("Password: ");
    fgets(buffer, MAXSIZE, stdin);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending password");
    }
    
    // Receive login message from server
    memset(buffer, 0, MAXSIZE);
    if (recv(sockfd, buffer, MAXSIZE, 0) < 0) {
        error("Error receiving login message");
    }
    printf("%s", buffer);
    
    // Send ASCII mode command
    if (send(sockfd, "TYPE A\r\n", strlen("TYPE A\r\n"), 0) < 0) {
        error("Error sending ASCII mode command");
    }
    
    // Receive command prompt from server
    memset(buffer, 0, MAXSIZE);
    if (recv(sockfd, buffer, MAXSIZE, 0) < 0) {
        error("Error receiving command prompt");
    }
    
    // Send PASV command
    if (send(sockfd, "PASV\r\n", strlen("PASV\r\n"), 0) < 0) {
        error("Error sending PASV command");
    }
    
    // Receive PASV response from server
    memset(buffer, 0, MAXSIZE);
    if (recv(sockfd, buffer, MAXSIZE, 0) < 0) {
        error("Error receiving PASV response");
    }
    
    // Parse PASV response to get port number
    int port_number;
    char *token;
    token = strtok(buffer, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    token = strtok(NULL, ",");
    port_number = atoi(token) * 256;
    token = strtok(NULL, ",");
    port_number += atoi(token);
    
    // Connect to data port
    int data_sockfd;
    struct sockaddr_in data_addr;
    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0) {
        error("Error opening data socket");
    }
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(argv[1]);
    data_addr.sin_port = htons(port_number);
    if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        error("Error connecting to data port");
    }
    
    // Send RETR command
    memset(buffer, 0, MAXSIZE);
    printf("Enter filename: ");
    fgets(filename, MAXSIZE, stdin);
    sprintf(buffer, "RETR %s", strtok(filename, "\n"));
    strcat(buffer, "\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        error("Error sending RETR command");
    }
    
    // Receive file data
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        error("Error creating file");
    }
    while ((n = recv(data_sockfd, buffer, MAXSIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, file);
    }
    if (n < 0) {
        error("Error receiving file data");
    }
    fclose(file);
    
    // Close sockets
    close(sockfd);
    close(data_sockfd);
    
    return 0;
}