//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int client_socket;
    char *address = "smtp.gmail.com";
    char *mail_from = "sender_email@gmail.com";
    char *rcpt_to = "receiver_email@gmail.com";
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    struct hostent *host_info;

    if(argc != 3)
    {
        printf("Usage: %s username password\n",argv[0]);
        exit(1);
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    host_info = gethostbyname(address);

    memset(&server_address,0,sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(587);
    server_address.sin_addr = *((struct in_addr *) host_info->h_addr);

    connect(client_socket, (struct sockaddr *) &server_address, 
          sizeof(server_address));

    // Receive welcome message
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("%s",buffer);

    // Send HELO command
    sprintf(buffer,"HELO %s\r\n",address);
    send(client_socket,buffer,strlen(buffer),0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send AUTH LOGIN command
    sprintf(buffer,"AUTH LOGIN\r\n");
    send(client_socket,buffer,strlen(buffer),0);
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send username
    char* username = argv[1];
    char* password = argv[2];
    char encoded_username[BUFFER_SIZE];
    char encoded_password[BUFFER_SIZE];
    memset(encoded_username, 0, sizeof(encoded_username));
    memset(encoded_password, 0, sizeof(encoded_password));
    sprintf(encoded_username,"%s",username);
    sprintf(encoded_password,"%s",password);
    strcpy(buffer,encoded_username);
    strcat(buffer,"\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send password
    strcpy(buffer,encoded_password);
    strcat(buffer,"\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send MAIL FROM command
    sprintf(buffer,"MAIL FROM:<%s>\r\n",mail_from);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send RCPT TO command
    sprintf(buffer,"RCPT TO:<%s>\r\n",rcpt_to);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send DATA command
    sprintf(buffer,"DATA\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send email body
    sprintf(buffer,"From: <%s>\r\nTo: <%s>\r\nSubject: SMTP Test\r\n\r\nThis is a test email sent from a SMTP client program.\r\n\r\n.\r\n",mail_from,rcpt_to);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    // Send QUIT command
    sprintf(buffer,"QUIT\r\n");
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, sizeof(buffer));
    recv(client_socket, buffer, BUFFER_SIZE, 0);// Response from server
    printf("%s",buffer);

    close(client_socket);

    return 0;
}