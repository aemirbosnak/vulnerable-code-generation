//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Define the POP3 port number
#define POP3_PORT 110

// Define the size of the read buffer
#define BUFFER_SIZE 4096

// Define the response codes from the server
#define OK_RESPONSE "+OK"
#define ERR_RESPONSE "-ERR"

// Define an error function for socket errors
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Define a function to read a response from the server
char *read_response(int sockfd) {
    char *response = malloc(BUFFER_SIZE);
    bzero(response, BUFFER_SIZE);
    read(sockfd, response, BUFFER_SIZE - 1);
    return response;
}

// Define a function to send a command to the server and return the response
char *send_command(int sockfd, char *command) {
    // Send the command
    write(sockfd, command, strlen(command));
    
    // Read the response
    char *response = read_response(sockfd);
    
    // Check for errors
    if (strstr(response, ERR_RESPONSE) != NULL) {
        printf("ERROR: %s", response);
        exit(1);
    }
    
    return response;
}

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 3) {
        printf("USAGE: %s server_address username\n", argv[0]);
        exit(1);
    }
    
    // Get the address of the server
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("ERROR: Could not find server address");
    }
    
    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR: Could not open socket");
    }
    
    // Set up the server address struct
    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
          (char *) &server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(POP3_PORT);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("ERROR: Could not connect to server");
    }
    
    // Authenticate with the server
    send_command(sockfd, "USER ");
    send_command(sockfd, "PASS ");
    
    // Retrieve the number of messages and their sizes
    char *response = send_command(sockfd, "STAT\n");
    int num_messages;
    int total_size;
    sscanf(response, "+OK %d %d", &num_messages, &total_size);
    free(response);
    
    // Print out the number of messages and their sizes
    printf("There are %d messages with a total size of %d bytes\n", num_messages, total_size);
    
    // Loop through the messages and retrieve their contents
    for (int i = 1; i <= num_messages; i++) {
        // Get the size of the message
        char size_command[BUFFER_SIZE];
        sprintf(size_command, "LIST %d\n", i);
        response = send_command(sockfd, size_command);
        int size;
        sscanf(response, "+OK %d %*d", &size);
        free(response);
        
        // Retrieve the message
        char message_command[BUFFER_SIZE];
        sprintf(message_command, "RETR %d\n", i);
        response = send_command(sockfd, message_command);
        printf("Message %d (%d bytes):\n%s\n", i, size, response);
        free(response);
    }
    
    // Delete all of the messages
    for (int i = 1; i <= num_messages; i++) {
        char delete_command[BUFFER_SIZE];
        sprintf(delete_command, "DELE %d\n", i);
        send_command(sockfd, delete_command);
    }
    
    // Close the connection
    send_command(sockfd, "QUIT\n");
    close(sockfd);
    
    return 0;
}