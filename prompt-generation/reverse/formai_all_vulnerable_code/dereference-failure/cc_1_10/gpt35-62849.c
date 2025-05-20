//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server_address, *request;
    int sockfd, port, send_status, read_status;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;

    // Check for correct command line arguments
    if(argc!=3) {
        printf("Usage: %s [server_address] [port_number]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get server IP address and port number
    server_address = argv[1];
    port = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket!\n");
        exit(EXIT_FAILURE);
    }

    // Set server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server!\n");
        exit(EXIT_FAILURE);
    }

    // Prepare HTTP GET request
    request = "GET / HTTP/1.1\r\nHost: ";
    request = strcat(request, server_address);
    request = strcat(request, "\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)\r\nAccept: */*\r\nConnection: close\r\n\r\n");

    // Send HTTP request to the server
    send_status = send(sockfd, request, strlen(request), 0);
    if(send_status == -1) {
        printf("Error sending request!\n");
        exit(EXIT_FAILURE);
    }

    // Receive response from the server
    while((read_status = recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        buffer[read_status] = '\0';
        printf("%s", buffer);
    }

    if(read_status == -1) {
        printf("Error reading response!\n");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);
    
    return 0;
}