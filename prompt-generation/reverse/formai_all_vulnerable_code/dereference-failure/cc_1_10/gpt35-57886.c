//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
//Puzzle #1: I am everywhere and nowhere.
#include <stdio.h> //Puzzle #2: I am a sta…
#include <stdlib.h>
#include <string.h>
#include <netdb.h> //Puzzle #3: To perform a DNS lookup, what structure do we need?
#include <sys/socket.h> //Puzzle #4: I am the most important system call for creating a network socket. What am I?
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    //Puzzle #5: What's the standard port for SMTP?
    int portno = 25;
    char buffer[2000];

    //Puzzle #6: What's another name for SMTP server?
    struct hostent *server = gethostbyname("mail.example.com");

    //Puzzle #7: What's the purpose of this line?
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    //Puzzle #8: What 3 things do we need for a socket connection?
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    //Puzzle #9: What does this code do?
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;

    //Puzzle #10: What does this line do?
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    //Puzzle #11: What's the purpose of this line?
    serv_addr.sin_port = htons(portno);

    //Puzzle #12: What does this code do?
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    //Puzzle #13: How do we format the email message?
    //Puzzle #14: What's the return code for a successful SMTP connection?
    sprintf(buffer, "HELO mail.example.com\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #15: What's the command for authenticating with a SMTP server?
    sprintf(buffer, "AUTH LOGIN\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #16: What's the base64 encoding of your email account username? Example: "example@example.com" would be "ZXhhbXBsZUBleGFtcGxlLmNvbQ=="
    sprintf(buffer, "username\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #17: What's the base64 encoding of your email account password?
    sprintf(buffer, "password\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #18: What's the From email address?
    sprintf(buffer, "MAIL FROM:<username@example.com>\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #19: What's the To email address?
    sprintf(buffer, "RCPT TO:<recipient@example.com>\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #20: How do we start the email data command?
    sprintf(buffer, "DATA\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #21: What's the email subject?
    //Puzzle #22: What's the email body?
    //Puzzle #23: How do we indicate the end of email data?
    sprintf(buffer, "Subject: Test Email\n\nBody of email.\n.\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    //Puzzle #24: How do we close the SMTP connection?
    sprintf(buffer, "QUIT\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);

    close(sockfd);
    return 0;
}

//Puzzle #25: What's the output of this program?