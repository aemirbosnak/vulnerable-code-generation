//FormAI DATASET v1.0 Category: Email Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 2048
#define PORT 587

int main(){

 char *server_addr = "<server_address> ";
 char *servername = "<server_name>";
 char *username = "<username>";
 char *password = "<password>";
 char *recipient = "<recipient_email>";
 char *subject = "<email_subject>";
 char *message = "<email_message>";

 int sockfd, connection;
 struct sockaddr_in server_address;
 struct hostent *server;

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if(sockfd < 0){
    perror("Error opening Socket");
    return 1;
 }

 server = gethostbyname(servername);
 if(server == NULL){
    perror("Error, no such host");
    return 1;
 }

 bzero((char *) &server_address, sizeof(server_address));
 server_address.sin_family = AF_INET;
 bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);

 server_address.sin_port = htons(PORT);

 connection = connect(sockfd, (const struct sockaddr *) &server_address, sizeof(server_address));
 if(connection < 0){
    perror("Error connecting to server");
    return 1;
 }

 char buffer[MAX];
 bzero(buffer, MAX);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "EHLO ");
 strcat(buffer, server_addr);
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "AUTH LOGIN\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, username);
 strcat(buffer, "\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, password);
 strcat(buffer, "\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "MAIL FROM: ");
 strcat(buffer, username);
 strcat(buffer, "\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "RCPT TO: ");
 strcat(buffer, recipient);
 strcat(buffer, "\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "DATA\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "Subject: ");
 strcat(buffer, subject);
 strcat(buffer, "\r\n");
 strcat(buffer, message);
 strcat(buffer, "\r\n.\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 bzero(buffer, MAX);
 strcat(buffer, "QUIT\r\n");
 send(sockfd, buffer, strlen(buffer), 0);
 recv(sockfd, buffer, MAX-1, 0);
 printf("%s\n", buffer);

 close(sockfd);

 return 0;

}