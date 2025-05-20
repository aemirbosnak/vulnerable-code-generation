//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc , char *argv[]) 
{
    int sockfd, portNum, smtpCode;
    char buffer[1024];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    if (argc < 3) {
        printf("Usage: %s hostname portNum\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    portNum = atoi(argv[2]);
    
    //Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(EXIT_FAILURE);
    }
    
    //Configure the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portNum);
    
    //Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    //Receive server greeting
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send hello message to server
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send mail from message
    sprintf(buffer, "MAIL FROM:<john.doe@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send rcpt to message
    sprintf(buffer, "RCPT TO:<jane.doe@yahoo.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send data message
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send email message
    sprintf(buffer, "From: John Doe <john.doe@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "To: Jane Doe <jane.doe@yahoo.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "Subject: Sending email using SMTP Client\r\n\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    sprintf(buffer, "Hello Jane,\n\nI'm sending this email using SMTP Client.\n\nBest regards,\nJohn.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Send quit message
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    //Close socket
    close(sockfd);
    
    return 0;
}