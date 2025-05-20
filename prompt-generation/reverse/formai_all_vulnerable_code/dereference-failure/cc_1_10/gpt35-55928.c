//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int send_mail(char *smtp_server, char *from, char *to, char *subject, char *message) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];

    // Create socket for SMTP server connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR creating socket");
        return -1;
    }

    // Get SMTP server details using DNS resolution
    server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return -1;
    }

    // Initialize socket address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25); // SMTP port

    // Connect to SMTP server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    // Receive initial message from SMTP server
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send HELO message to SMTP server
    char hello_message[MAX_BUFFER];
    sprintf(hello_message, "HELO %s\r\n", smtp_server);
    n = write(sockfd,hello_message,strlen(hello_message));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to HELO message
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send MAIL FROM command
    char mail_from[MAX_BUFFER];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", from);
    n = write(sockfd,mail_from,strlen(mail_from));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to MAIL FROM command
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send RCPT TO command
    char rcpt_to[MAX_BUFFER];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", to);
    n = write(sockfd,rcpt_to,strlen(rcpt_to));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to RCPT TO command
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send DATA command
    char data_command[MAX_BUFFER];
    sprintf(data_command, "DATA\r\n");
    n = write(sockfd,data_command,strlen(data_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to DATA command
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send email headers and body
    char email[MAX_BUFFER];
    sprintf(email, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, message);
    n = write(sockfd,email,strlen(email));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to email message
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Send QUIT command
    char quit_command[MAX_BUFFER];
    sprintf(quit_command, "QUIT\r\n");
    n = write(sockfd,quit_command,strlen(quit_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive response to QUIT command
    bzero(buffer,MAX_BUFFER);
    n = read(sockfd,buffer,MAX_BUFFER);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }
    printf("%s",buffer);

    // Close socket connection
    close(sockfd);

    return 0;
}

int main() {
    char smtp_server[] = "smtp.gmail.com";
    char from[] = "sender@gmail.com";
    char to[] = "recipient@gmail.com";
    char subject[] = "Test email from SMTP client";
    char message[] = "Hello!\nThis is a test email from a SMTP client program.\n\nBest regards,\nSMTP Bot";
    int result = send_mail(smtp_server, from, to, subject, message);
    if (result == 0) {
        printf("Email successfully sent!\n");
    }
    return result;
}