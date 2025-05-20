//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include<stdio.h> // for standard input/output functions
#include<sys/socket.h> // for socket functions
#include<arpa/inet.h> // for inet functions
#include<string.h> // for string functions
#include<stdlib.h> // for exit function

#define BUFFER_SIZE 1024 // define buffer size

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int client_socket, port_number, n;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    
    // check for command line arguments
    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    
    // create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
        error("ERROR opening socket");
    
    // clear server_address buffer
    memset(&server_address, '\0', sizeof(server_address));
    
    // set server_address properties
    port_number = atoi(argv[2]);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_number);
    
    // convert IP address from ASCII to binary form
    if(inet_pton(AF_INET, argv[1], &server_address.sin_addr)<=0)
    {
        error("ERROR invalid address or address not supported");
    }
    
    // connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        error("ERROR connecting");
    
    // receive greeting message from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send EHLO message to server
    strcpy(message, "EHLO clientSMTP\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send MAIL FROM message to server
    strcpy(message, "MAIL FROM:<sender@example.com>\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send RCPT TO message to server
    strcpy(message, "RCPT TO:<recipient@example.com>\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send DATA message to server
    strcpy(message, "DATA\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send email message to server
    strcpy(message, "Subject: SMTP Test\r\n");
    strcat(message, "From: Sender <sender@example.com>\r\n");
    strcat(message, "To: Recipient <recipient@example.com>\r\n");
    strcat(message, "This is a test email message.\r\n");
    strcat(message, ".\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // send QUIT message to server
    strcpy(message, "QUIT\r\n");
    n = send(client_socket, message, strlen(message), 0);
    if (n < 0)
        error("ERROR writing to socket");
    
    // receive response from server
    memset(buffer, '\0', BUFFER_SIZE);
    n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);
    
    // close socket
    close(client_socket);
    
    return 0;
}