//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PORT 25 //SMTP port number

int main(int argc, char *argv[]) {
    struct sockaddr_in serv_addr; //server address struct
    struct hostent *server;
    char buffer[1024]; //buffer for messages
    int sockfd, n;

    if (argc < 2) {
        fprintf(stderr, "Error: Please provide server name");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0); //socket creation
    if (sockfd < 0) {
        fprintf(stderr, "Error: Socket creation failed");
        exit(1);
    }

    server = gethostbyname(argv[1]); //get server by name
    if (server == NULL) {
        fprintf(stderr, "Error: Server not found");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr)); //clear server address
    serv_addr.sin_family = AF_INET; //set address family to internet

    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length); //copy server address
    serv_addr.sin_port = htons(PORT); //set port number

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { //connect to server
        fprintf(stderr, "Error: Connection failed");
        exit(1);
    }

    //connection successful. Send message
    printf("Connected to server. Sending message...\n");

    //Send hello message
    sprintf(buffer, "EHLO client.domain.com\r\n"); //EHLO identifies client and requests extended status codes
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send MAIL FROM
    sprintf(buffer, "MAIL FROM:<sender@domain.com>\r\n"); //specify sender's email address
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send RCPT TO
    sprintf(buffer, "RCPT TO:<receiver@domain.com>\r\n"); //specify recipient's email address
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send DATA
    sprintf(buffer, "DATA\r\n"); //beginning of email message
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send message body
    sprintf(buffer, "From: sender@domain.com\r\nTo: receiver@domain.com\r\nSubject: SMTP Client Test\r\n\r\nThis is a test email message.\r\n"); //actual message
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send message termination sequence
    sprintf(buffer, "\r\n.\r\n"); //indicates end of message
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    //Send QUIT message
    sprintf(buffer, "QUIT\r\n"); //end session
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(sockfd); //close socket

    return 0;
}