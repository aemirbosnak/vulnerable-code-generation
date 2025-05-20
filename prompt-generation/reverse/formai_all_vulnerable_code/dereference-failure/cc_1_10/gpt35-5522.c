//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

void send_mail(char* server_address,int server_port, char* sender_address, char* recipient_address, char* message){

    //Creating a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0){
        perror("Error creating socket");
        exit(1);
    }

    //Getting IP address of SMTP server
    struct hostent *he = gethostbyname(server_address);
    if(he == NULL){
        perror("Error resolving SMTP server address");
        exit(1);
    }

    //Configuration of network structure
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr = *((struct in_addr*) he->h_addr);

    //Connecting to the SMTP server
    if(connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0){
        perror("Error connecting to SMTP server");
        close(sock);
        exit(1);
    }

    char buffer[1024];
    int bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';

    printf("%s", buffer);

    //Sending HELO command to SMTP server
    sprintf(buffer, "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Sending MAIL FROM command to SMTP server
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender_address);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Sending RCPT TO command to SMTP server
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient_address);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Sending DATA command to SMTP server
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Sending message to SMTP server
    sprintf(buffer, "%s\r\n.\r\n", message);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Sending QUIT command to SMTP server
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, 1024, 0);
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    //Closing socket connection
    close(sock);
}

int main(){

    char* server_address = "smtp.gmail.com"; //SMTP server address
    int server_port = 587; //SMTP server port number
    char* sender_address = "your_email@gmail.com"; //Sender email address
    char* recipient_address = "recipient_email@example.com"; //Recipient email address
    char* message = "Subject: SMTP Client Example\n\nThis is an example email sent from an SMTP client.\n"; //Email message

    send_mail(server_address, server_port, sender_address, recipient_address, message);

    return 0;
}