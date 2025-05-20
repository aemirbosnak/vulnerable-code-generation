//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
/*
This program is an example of building an SMTP client using C programming language.
The program takes in the sender email address, recipient email address, subject and message body from the user through command line arguments and sends the email using SMTP protocol.

The program uses the following libraries:
1. <stdio.h> - for input/output functions
2. <string.h> - for string manipulation functions
3. <sys/socket.h> - for socket creation and interaction
4. <netinet/in.h> - for defining the socket addresses
5. <arpa/inet.h> - for converting IP addresses to binary format

To use the program, the user must have access to an SMTP server address and port number that allows email sending.

Author: [Your Name]
Date: [Date]

*/

#include <stdio.h> 
#include <string.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{
    int client_sock, resp_code;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], from_addr[BUFFER_SIZE], to_addr[BUFFER_SIZE], 
         subject[BUFFER_SIZE], message[BUFFER_SIZE];
    
    // Check if all required arguments are provided by the user
    if (argc != 5) {
        printf("Usage: %s <SMTP server> <SMTP port> <sender email> <recipient email>\n", argv[0]);
        return -1;
    }
    
    // Get user input values
    strcpy(from_addr, argv[3]);
    strcpy(to_addr, argv[4]);

    // Get email subject and message body from user input through standard input
    printf("Enter email subject: ");
    fgets(subject, BUFFER_SIZE, stdin);
    printf("Enter email message body: ");
    fgets(message, BUFFER_SIZE, stdin);
    
    // Create socket
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        printf("Error creating socket.\n");
        return -1;
    }

    // Set server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to the server.\n");
        return -1;
    }

    // Receive server response message on connection
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from_addr);
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to_addr);
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send email details
    sprintf(buffer, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n", 
            from_addr, to_addr, subject, message);
    send(client_sock, buffer, strlen(buffer), 0);

    // Send end of message indicator
    sprintf(buffer, ".\r\n");
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);

    // Send QUIT command and close the connection
    sprintf(buffer, "QUIT\r\n");
    send(client_sock, buffer, strlen(buffer), 0);
    recv(client_sock, buffer, BUFFER_SIZE, 0);
    close(client_sock);

    printf("Email sent successfully.\n");

    return 0;
}