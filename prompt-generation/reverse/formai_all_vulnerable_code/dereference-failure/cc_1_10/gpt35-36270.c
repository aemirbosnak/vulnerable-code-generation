//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, connect_result;
    struct sockaddr_in server_address;
    char receive_buffer[BUF_SIZE];
    char command_buffer[BUF_SIZE];
    char* username;
    char* password;
    char* imap_server;
    char* imap_port;
    
    printf("Welcome to the IMAP Client!\n");
    printf("Please enter your username:\n");
    fgets(username, BUF_SIZE, stdin);
    strtok(username, "\n");
    
    printf("Please enter your password:\n");
    fgets(password, BUF_SIZE, stdin);
    strtok(password, "\n");
    
    printf("Please enter the IMAP server:\n");
    fgets(imap_server, BUF_SIZE, stdin);
    strtok(imap_server, "\n");
    
    printf("Please enter the IMAP port:\n");
    fgets(imap_port, BUF_SIZE, stdin);
    strtok(imap_port, "\n");
    
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1) {
        printf("Error creating socket!\n");
        return -1;
    }
    
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(imap_port));
    
    connect_result = inet_pton(AF_INET, imap_server, &server_address.sin_addr);
    if(connect_result <= 0) {
        printf("Error connecting to server!\n");
        return -1;
    }
    
    connect_result = connect(sock_fd, (struct sockaddr*)&server_address, sizeof(struct sockaddr_in));
    if(connect_result == -1) {
        printf("Error connecting to server!\n");
        return -1;
    }
    
    printf("Connection established!\n");
    printf("Logging in...\n");
    sprintf(command_buffer, "LOGIN %s %s\r\n", username, password);
    write(sock_fd, command_buffer, strlen(command_buffer));
    read(sock_fd, receive_buffer, BUF_SIZE);
    
    if(strncmp(receive_buffer, "+OK", 3) != 0) {
        printf("Error logging in!\n");
        return -1;
    }
    
    printf("Logged in!\n");
    printf("Fetching messages...\n");
    sprintf(command_buffer, "SELECT INBOX\r\n");
    write(sock_fd, command_buffer, strlen(command_buffer));
    read(sock_fd, receive_buffer, BUF_SIZE);
    
    if(strncmp(receive_buffer, "+OK", 3) != 0) {
        printf("Error selecting mailbox!\n");
        return -1;
    }
    
    printf("Mailbox selected!\n");
    sprintf(command_buffer, "FETCH 1:* BODY[HEADER]\r\n");
    write(sock_fd, command_buffer, strlen(command_buffer));
    read(sock_fd, receive_buffer, BUF_SIZE);
    
    printf("Messages:\n\n");
    printf("%s\n\n", receive_buffer);
    
    printf("Logging out...\n");
    sprintf(command_buffer, "LOGOUT\r\n");
    write(sock_fd, command_buffer, strlen(command_buffer));
    read(sock_fd, receive_buffer, BUF_SIZE);
    
    if(strncmp(receive_buffer, "+OK", 3) != 0) {
        printf("Error logging out!\n");
        return -1;
    }
    
    printf("Logged out!\n");
    printf("Closing connection...\n");
    close(sock_fd);
    
    printf("Goodbye!\n");
    return 0;
}