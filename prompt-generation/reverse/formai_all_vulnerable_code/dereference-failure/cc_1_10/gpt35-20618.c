//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>

int main()
{
    //creating a socket for SMTP client
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    //setting SMTP server address       
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(25);
    serveraddr.sin_addr.s_addr = inet_addr("smtp.gmail.com");
    //connecting to SMTP server
    connect(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr));
    char buffer[1024]; //buffer to store read/write data
    int n;
    n=read(sockfd, buffer, sizeof(buffer)); //reading server response
    printf("\n%s", buffer);

    //setting login credentials
    char fromMail[] = "sender@gmail.com";
    char username[] = "sender@gmail.com";
    char password[] = "password123";

    //authenticating login credentials
    char auth[1024];
    sprintf(auth, "AUTH LOGIN %s %s", username, password);
    write(sockfd, auth, strlen(auth));
    n=read(sockfd, buffer, sizeof(buffer)); //reading server response
    printf("\n%s", buffer);

    //setting sender's email address
    char mailFrom[1024];
    sprintf(mailFrom, "MAIL FROM: %s", fromMail);
    write(sockfd, mailFrom, strlen(mailFrom));
    n=read(sockfd, buffer, sizeof(buffer)); //reading server response
    printf("\n%s", buffer);

    //setting recipient's email address
    char toMail[1024];
    sprintf(toMail, "RCPT TO: receiver@gmail.com");
    write(sockfd, toMail, strlen(toMail));
    n=read(sockfd, buffer, sizeof(buffer)); //reading server response
    printf("\n%s", buffer);

    //setting subject of mail
    char sub[] = "Subject: SMTP Client Program\n\n";
    write(sockfd, sub, strlen(sub));

    //setting body of mail
    char msg[] = "hello,\nThis is a test mail from SMTP client program\n";
    write(sockfd, msg, strlen(msg));

    //closing the connection
    close(sockfd);
    return 0;
}