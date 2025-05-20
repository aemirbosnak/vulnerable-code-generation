//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>     
#include <stdlib.h>    
#include <unistd.h>    
#include <string.h>    
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netdb.h>      
 
#define MAX 1000
 
void send_mail(int sockfd, char* content, char* from, char* rcpt){
    char buffer[MAX] = {0};
    int numbytes;
     
    // Send helo message (Introducing the client to the server)
    char* helomsg = "HELO this is a test message\n";
    send(sockfd, helomsg, strlen(helomsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
     
    sleep(1);
     
    // Send mail from message
    char* frommsg = (char *) malloc(1 + strlen(from) + strlen("MAIL FROM:< >\n"));
    strcpy(frommsg, "MAIL FROM:<");
    strcat(frommsg, from);
    strcat(frommsg, ">\n");
    send(sockfd, frommsg, strlen(frommsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
     
    sleep(1);
     
    // Send rcpt to message
    char* tomsg = (char *) malloc(1 + strlen(rcpt) + strlen("RCPT TO:< >\n"));
    strcpy(tomsg, "RCPT TO:<");
    strcat(tomsg, rcpt);
    strcat(tomsg, ">\n");
    send(sockfd, tomsg, strlen(tomsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
     
    sleep(1);
     
    // Send data message
    char* datamsg = "DATA\n";
    send(sockfd, datamsg, strlen(datamsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
     
    sleep(1);
     
    // Send message content
    send(sockfd, content, strlen(content), 0);
     
    // Send message end
    char* endmsg = "\r\n.\r\n";
    send(sockfd, endmsg, strlen(endmsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
     
    sleep(1);
     
    // Send quit message
    char* quitmsg = "QUIT\n";
    send(sockfd, quitmsg, strlen(quitmsg), 0);
    numbytes = recv(sockfd, buffer, MAX-1, 0);
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);
 
    close(sockfd);
}  

int main(int argc, char *argv[])
{
    if(argc != 5){
        printf("Usage: ./smtp_client <SMTP Server IP Address> <SMTP Port> <From Address> <To Address>\n");
        return -1;
    }
 
    char *server_ip = argv[1];
    int port = atoi(argv[2]);
    char* from = argv[3];
    char* to = argv[4];
     
    printf("SMTP Server IP Address : %s\n", server_ip);
    printf("Port : %d\n", port);
    printf("From : %s\n", from);
    printf("To : %s\n\n", to);
         
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *he;
     
    if ((he = gethostbyname(server_ip)) == NULL){
        perror("gethostbyname");
        return -1;
    }
 
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket error");
        return -1;
    }
 
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
     
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        perror("connect error");
        return -1;
    }
 
    char* content = "Subject: Test Email\nFrom: Example <user@example.com>\nTo: Example <user@example.com>\nThis is a test email sent from an SMTP client written in C.\n.";
  
    send_mail(sockfd, content, from, to);
     
    return 0;
}