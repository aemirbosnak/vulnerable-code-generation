//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;

    // Create the socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        error("Error creating socket");
    }

    // Set server address and port number
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(21);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to FTP server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        error("Error connecting to server");
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Read welcome message from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Send username to server
    char username[] = "USER anonymous\r\n";
    if (send(client_socket, username, strlen(username), 0) < 0) {
        error("Error sending message to server");
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Read response from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Send password to server
    char password[] = "PASS anonymous\r\n";
    if (send(client_socket, password, strlen(password), 0) < 0) {
        error("Error sending message to server");
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Read response from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Set transfer mode to binary
    char type[] = "TYPE I\r\n";
    if (send(client_socket, type, strlen(type), 0) < 0) {
        error("Error sending message to server");
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Read response from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Open data connection to server
    char pasv[] = "PASV\r\n";
    if (send(client_socket, pasv, strlen(pasv), 0) < 0) {
        error("Error sending message to server");
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Read response from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Parse response to get port number for data connection
    int port;
    char* p = strtok(buffer, ",");
    p = strtok(NULL, ",");
    p = strtok(NULL, ",");
    p = strtok(NULL, ",");
    int a = atoi(p);
    p = strtok(NULL, ",");
    int b = atoi(p);
    port = a*256 + b;

    // Create address for data connection
    struct sockaddr_in data_address;
    data_address.sin_family = AF_INET;
    data_address.sin_port = htons(port);
    data_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Create data socket
    int data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket < 0) {
        error("Error creating socket");
    }

    // Connect to data connection
    if (connect(data_socket, (struct sockaddr*)&data_address, sizeof(data_address)) < 0) {
        error("Error connecting to server");
    }

    // Send command to list files on FTP server
    char list[] = "LIST\r\n";
    if (send(client_socket, list, strlen(list), 0) < 0) {
        error("Error sending message to server");
    }

    memset(buffer, 0, BUFFER_SIZE);

    // Read response from server
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s\n", buffer);

    // Read and print list of files
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(data_socket, buffer, BUFFER_SIZE, 0) < 0) {
        error("Error reading message from server");
    }
    printf("%s", buffer);

    // Close data socket and connection
    close(data_socket);
    printf("Data connection closed\n");

    // Close control socket and connection
    close(client_socket);
    printf("Control connection closed\n");

    return 0;
}