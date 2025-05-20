//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_LENGTH 1024

void displayError(char* errorMessage) {
    fprintf(stderr, "%s: %s\n", errorMessage, strerror(errno));
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s server_address port_number\n", argv[0]);
        exit(1);
    }
    
    char* server_address = argv[1];
    int port_number = atoi(argv[2]);
    
    //Create a socket for TCP connection
    int tcp_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (tcp_socket == -1) {
        displayError("Socket creation failed");
    }
    
    //Configure connection
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port_number);
    if (inet_pton(AF_INET, server_address, &server.sin_addr) <= 0) {
        displayError("Invalid address/ Address not supported");
    }
    
    //Connect to server
    if (connect(tcp_socket, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        displayError("Connection failed");
    }
    
    char recvBuffer[MAX_LENGTH] = {0};
    int readSize = 0;
    
    //Receive server greeting
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("Server greeting receive failed");
    }
    printf("%s", recvBuffer);
    
    //Send username
    char* username = "USER example@gmail.com\r\n";
    if (send(tcp_socket, username, strlen(username), 0) < 0)
    {
        displayError("Username send failed");
    }
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("Username confirmation receive failed");
    }
    printf("%s", recvBuffer);
    
    //Send password
    char* password = "PASS mypassword\r\n";
    if (send(tcp_socket, password, strlen(password), 0) < 0)
    {
        displayError("Password send failed");
    }
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("Password confirmation receive failed");
    }
    printf("%s", recvBuffer);
    
    //List emails
    char* list = "LIST\r\n";
    if (send(tcp_socket, list, strlen(list), 0) < 0)
    {
        displayError("List command send failed");
    }
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("List receive failed");
    }
    printf("%s", recvBuffer);
    
    //Retrieve email
    char* retrieve = "RETR 1\r\n";
    if (send(tcp_socket, retrieve, strlen(retrieve), 0) < 0)
    {
        displayError("Retrieve command send failed");
    }
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("Retrieve email receive failed");
    }
    printf("%s", recvBuffer);
    
    //Quit
    char* quit = "QUIT\r\n";
    if (send(tcp_socket, quit, strlen(quit), 0) < 0)
    {
        displayError("Quit command send failed");
    }
    readSize = recv(tcp_socket, recvBuffer, MAX_LENGTH, 0);
    if (readSize < 0)
    {
        displayError("Quit confirmation receive failed");
    }
    printf("%s", recvBuffer);
    
    //Close socket
    close(tcp_socket);
    
    return 0;
}