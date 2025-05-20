//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define MAX_EMAIL_LEN 50
#define MAX_BODY_LEN 2000

int main(int argc, char *argv[]) {

    if(argc!=4) {
        printf("Invalid arguments. Usage: ./smtpclient <server address> <port> <sender email>\n");
        exit(0);    
    }

    char* server_ip = argv[1];
    int port = atoi(argv[2]);
    char* sender_email = argv[3];
    char receiver_email[MAX_EMAIL_LEN];
    char subject[MAX_EMAIL_LEN];
    char body[MAX_BODY_LEN];

    printf("Enter receiver email : ");
    scanf("%s",receiver_email);

    printf("Enter subject : ");
    scanf("%s",subject);

    printf("Enter email body : ");
    scanf("%[^\n]s", body);

    char message[MAX_BODY_LEN+MAX_EMAIL_LEN+MAX_EMAIL_LEN+strlen(subject)+100];
    sprintf(message,"From: %s\nTo: %s\nSubject: %s\n%s",sender_email,receiver_email,subject,body);

    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: Opening socket.\n");
        exit(1);
    }

    server = gethostbyname(server_ip);
    if(server==NULL) {
        printf("Error: No such host found.\n");
        exit(2);
    }

    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr))<0) {
        printf("Error: Failed to connect to server.\n");
        exit(3);
    }

    char buffer[1024];

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"HELO %s\r\n", server_ip);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"MAIL FROM:<%s>\r\n", sender_email);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"RCPT TO:<%s>\r\n", receiver_email);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"%s\r\n", message);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer,"QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer)-1, 0);

    close(sockfd);

    return 0;
}