//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        perror("Usage: ./smtp_client <ip_address> <port_number> <recipient_email_address>\n");
        exit(EXIT_FAILURE);
    }
    
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    // Creating Socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        perror("Error in creating socket...\n");
        exit(EXIT_FAILURE);
    }
    printf("Client Socket Created Successfully!\n");
    
    // Setting Server Details
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    
    // Connect to Server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection Failed...\n");
        exit(EXIT_FAILURE);
    }
    printf("Connected to SMTP Server successfully!\n");

    // Read Welcome Message from the Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    // Sending HELO Command
    sprintf(buffer, "HELO localhost\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from the Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    memset(buffer, 0, MAX_BUFFER_SIZE);
    
    // Sending MAIL FROM Command
    sprintf(buffer, "MAIL FROM: <sender_email_address>\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Sending RCPT TO Command
    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[3]);
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from the Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Sending DATA Command
    sprintf(buffer, "DATA\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from the Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Sending Message Body
    sprintf(buffer, "Subject: SMTP Client Example\r\n\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    sprintf(buffer, "This is an example message sent from the SMTP Client program.\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Sending End of Message Indicator
    sprintf(buffer, "\r\n.\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);
    
    // Sending QUIT Command
    sprintf(buffer, "QUIT\r\n");
    write(client_socket, buffer, strlen(buffer));
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read Response from Server
    read(client_socket, buffer, MAX_BUFFER_SIZE);
    printf("%s\n", buffer);

    // Closing Socket Connection
    close(client_socket);
    printf("Connection Closed!\n");

    return 0;
}