//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: irregular
// Whohoo! Here comes the FTP client I built!
// Let's start with the libraries.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Now let's define some constants.

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

// Define a function to handle FTP commands.

void execute_ftp_command(int sockfd, char *message)
{
    // Here's where we will handle all the FTP commands.
    
    // First we need to split the command and the arguments.
    
    char *command = strtok(message, " ");
    char *arg1 = strtok(NULL, " ");
    char *arg2 = strtok(NULL, " ");
    
    // Now let's check what command is being executed.
    
    if (strcmp(command, "ls") == 0)
    {
        // If the command is ls, we need to send the appropriate command to the server.
        
        send(sockfd, "LIST\n", strlen("LIST\n"), 0);
        
        // Receive the response from the server.
        
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }
    else if (strcmp(command, "get") == 0)
    {
        // If the command is get, we need to download the specified file from the server.
        
        char ftp_command[BUFFER_SIZE];
        sprintf(ftp_command, "RETR %s\n", arg1);
        send(sockfd, ftp_command, strlen(ftp_command), 0);
        
        // Open the file to write the downloaded content to.
        
        FILE *file = fopen(arg2, "w");
        
        // Receive the response from the server.
        
        char buffer[BUFFER_SIZE];
        int bytes_read;
        do
        {
            bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
            fwrite(buffer, 1, bytes_read, file);
        } while (bytes_read == BUFFER_SIZE);
        
        // Close the file.
        
        fclose(file);
        printf("Download complete!\n");
    }
    else
    {
        // If the command is not recognized, simply send it to the server and display the response.
        
        send(sockfd, message, strlen(message), 0);
        
        // Receive the response from the server.
        
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }
}

int main()
{
    // First we need to create a socket.
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    // Set up the address of the server we want to connect to.
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Connect to the server.
    
    int connect_result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_result == -1)
    {
        fprintf(stderr, "Error connecting to server!\n");
        exit(1);
    }
    
    // Now we can start sending and receiving messages.
    
    printf("Welcome to FTP Client!\n");
    char input[BUFFER_SIZE];
    while (1)
    {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strlen(input) - 1] = '\0';  // Remove the newline character.
        execute_ftp_command(sockfd, input);
    }
    
    // Close the socket and we're done!
    
    close(sockfd);
    return 0;
}