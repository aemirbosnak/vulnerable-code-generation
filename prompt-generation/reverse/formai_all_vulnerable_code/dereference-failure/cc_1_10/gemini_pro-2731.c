//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

// Define the FTP commands
#define USER "USER"
#define PASS "PASS"
#define LIST "LIST"
#define RETR "RETR"
#define STOR "STOR"
#define QUIT "QUIT"

// Function to send a command to the FTP server
void send_command(int sockfd, char *command) {
    // Send the command to the server
    send(sockfd, command, strlen(command), 0);
    
    // Receive the response from the server
    char response[256];
    recv(sockfd, response, 256, 0);
    
    // Print the response to the console
    printf("%s\n", response);
}

// Function to receive a file from the FTP server
void receive_file(int sockfd, char *filename) {
    // Open the file for writing
    FILE *fp = fopen(filename, "wb");
    
    // Receive the file from the server
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(sockfd, buffer, 1024, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }
    
    // Close the file
    fclose(fp);
}

// Function to send a file to the FTP server
void send_file(int sockfd, char *filename) {
    // Open the file for reading
    FILE *fp = fopen(filename, "rb");
    
    // Send the file to the server
    char buffer[1024];
    int bytes_sent;
    while ((bytes_sent = fread(buffer, 1, 1024, fp)) > 0) {
        send(sockfd, buffer, bytes_sent, 0);
    }
    
    // Close the file
    fclose(fp);
}

int main(int argc, char **argv) {
    // Check if the user has provided enough arguments
    if (argc < 4) {
        printf("Usage: %s <hostname> <port> <command>\n", argv[0]);
        return 1;
    }
    
    // Get the hostname, port, and command from the user
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];
    
    // Create a socket for connecting to the FTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Connect to the FTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    // Send the USER command to the server
    send_command(sockfd, USER);
    
    // Send the PASS command to the server
    send_command(sockfd, PASS);
    
    // Send the command to the server
    send_command(sockfd, command);
    
    // If the command is LIST, receive the list of files from the server
    if (strcmp(command, LIST) == 0) {
        receive_file(sockfd, "list.txt");
    }
    
    // If the command is RETR, receive the file from the server
    else if (strcmp(command, RETR) == 0) {
        // Get the filename from the user
        char filename[256];
        printf("Enter the name of the file to receive: ");
        scanf("%s", filename);
        
        // Receive the file from the server
        receive_file(sockfd, filename);
    }
    
    // If the command is STOR, send the file to the server
    else if (strcmp(command, STOR) == 0) {
        // Get the filename from the user
        char filename[256];
        printf("Enter the name of the file to send: ");
        scanf("%s", filename);
        
        // Send the file to the server
        send_file(sockfd, filename);
    }
    
    // Send the QUIT command to the server
    send_command(sockfd, QUIT);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}