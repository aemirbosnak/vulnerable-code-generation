//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {    
    if (argc != 3) {
        printf("Usage: %s <server ip> <server port>\n", argv[0]);
        exit(-1);
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    
    printf("Welcome to our joyful FTP client! Let's get started!\n");
    
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Failed to create a socket!\n");
        exit(-1);
    }
    
    // Connect to the server
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error: Failed to connect to the server!\n");
        exit(-1);
    }
    
    printf("Connected to the server at %s:%d!\n", server_ip, server_port);
    
    // Authenticate with the server (you can replace these with your own username and password)
    char *username = "joe";
    char *password = "12345";
    char auth_buffer[BUFFER_SIZE];
    sprintf(auth_buffer, "USER %s\r\n", username);
    send(client_socket, auth_buffer, strlen(auth_buffer), 0);
    recv(client_socket, auth_buffer, BUFFER_SIZE, 0); // receive server response
    memset(auth_buffer, 0, BUFFER_SIZE);
    sprintf(auth_buffer, "PASS %s\r\n", password);
    send(client_socket, auth_buffer, strlen(auth_buffer), 0);
    recv(client_socket, auth_buffer, BUFFER_SIZE, 0); // receive server response

    printf("Authentication successful!\n");
    
    // Send a command to the server to retrieve a file (you can replace the filename with your own)
    char *filename = "example.txt";
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "RETR %s\r\n", filename);
    send(client_socket, buffer, strlen(buffer), 0);
    recv(client_socket, buffer, BUFFER_SIZE, 0); // receive server response
    
    if (strncmp(buffer, "550", 3) == 0) {
        printf("Error: File %s not found on the server!\n", filename);
        exit(-1);
    }
    
    // Create a file to store the data
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Failed to create file %s!\n", filename);
        exit(-1);
    }
    
    // Receive the data from the server and write it to the file
    int bytes_received = 0;
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
        memset(buffer, 0, BUFFER_SIZE);
    }
    
    fclose(file);
    printf("File %s retrieved successfully!\n", filename);
    
    // Close the connection and socket
    close(client_socket);
    printf("Disconnected from the server!\n");
    
    return 0;
}