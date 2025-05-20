//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
  
#define SMTP_PORT 25 
  
int main(int argc, char const *argv[]) 
{ 
    int sock = 0;
    struct sockaddr_in server_address; 
    char message[1024] = {0}; 
    char server_response[4096] = {0};

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    // Set server details
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(SMTP_PORT); 
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 

    // Receive greeting message from server
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 

    printf("%s", server_response); 

    // Send HELO command to server
    sprintf(message, "HELO %s\r\n", argv[1]);
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    // Send MAIL FROM command to server
    sprintf(message, "MAIL FROM:<%s>\r\n", argv[2]);
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    // Send RCPT TO command to server
    sprintf(message, "RCPT TO:<%s>\r\n", argv[3]);
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    // Send DATA command to server
    sprintf(message, "DATA\r\n");
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    // Send email content to server
    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", argv[2], argv[3], argv[4], argv[5]);
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    // Send quit command to server 
    sprintf(message, "QUIT\r\n"); 
    send(sock, message, strlen(message), 0); 
    if (recv(sock, server_response, 4096, 0) < 0) 
    { 
        printf("\nReceive failed\n"); 
        return -1; 
    } 
    printf("%s", server_response); 

    close(sock); 
    return 0; 
}