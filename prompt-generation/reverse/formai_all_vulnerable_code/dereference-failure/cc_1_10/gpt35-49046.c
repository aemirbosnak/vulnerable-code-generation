//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // variables to hold server information
    char host[100], port[10];
    printf("Enter server host: ");
    scanf("%s", host);
    printf("Enter server port: ");
    scanf("%s", port);

    // variables to hold user information
    char sender_email[100], recipient_email[100], subject[100], message[BUFFER_SIZE], username[50], password[50]; 
    printf("Enter your email address: ");
    scanf("%s", sender_email);
    printf("Enter recipient email address: ");
    scanf("%s", recipient_email);
    printf("Enter subject: ");
    scanf("%s", subject);
    printf("Enter message: ");
    fgets(message, BUFFER_SIZE, stdin);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // get host by name
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Error finding server\n");
        return 1;
    }

    // set server address information
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // read welcome message
    char response[BUFFER_SIZE];
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send HELO message
    char helo_message[BUFFER_SIZE];
    sprintf(helo_message, "HELO %s\n", host);
    write(sockfd, helo_message, strlen(helo_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send LOGIN message
    char login_message[BUFFER_SIZE];
    sprintf(login_message, "LOGIN %s %s\n", username, password);
    write(sockfd, login_message, strlen(login_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send MAIL FROM message
    char mail_from_message[BUFFER_SIZE];
    sprintf(mail_from_message, "MAIL FROM:<%s>\n", sender_email);
    write(sockfd, mail_from_message, strlen(mail_from_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send RCPT TO message
    char rcpt_to_message[BUFFER_SIZE];
    sprintf(rcpt_to_message, "RCPT TO:<%s>\n", recipient_email);
    write(sockfd, rcpt_to_message, strlen(rcpt_to_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send DATA message
    char data_message[BUFFER_SIZE];
    sprintf(data_message, "DATA\n");
    write(sockfd, data_message, strlen(data_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send email message
    char email_message[BUFFER_SIZE];
    sprintf(email_message, "From: <%s>\nTo: <%s>\nSubject: %s\n%s\n.\n", sender_email, recipient_email, subject, message);
    write(sockfd, email_message, strlen(email_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // send QUIT message
    char quit_message[BUFFER_SIZE];
    sprintf(quit_message, "QUIT\n");
    write(sockfd, quit_message, strlen(quit_message));
    read(sockfd, response, BUFFER_SIZE);
    printf("%s\n", response);

    // close socket
    close(sockfd);

    return 0;
}