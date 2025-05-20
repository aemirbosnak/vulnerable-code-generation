//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
/* 
SMTP client program in C
This program sends a simple email via SMTP server.

Please enter your own authentication details below.

To run this program, save it as smtp_client.c and run the following two commands:
gcc smtp_client.c -o smtp_client
./smtp_client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 25
#define MAX_BUFFER 1024

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];
    int n;

    /* Replace the following with your own authentication details */
    const char* username = "your_email_username";
    const char* password = "your_email_password";
    const char* from = "your_email_address";
    const char* to = "recipient_email_address";
    const char* subject = "Test Email";
    const char* message = "This is a test email. Hope you receive it.";

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get the IP address from the hostname */
    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    /* Set up the server address */
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    /* Connect to the server */
    if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Read the welcome message from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the HELO message */
    sprintf(buffer, "HELO %s\r\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the AUTH LOGIN message */
    sprintf(buffer, "AUTH LOGIN\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the username */
    sprintf(buffer, "%s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the password */
    sprintf(buffer, "%s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the MAIL FROM message */
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the RCPT TO message */
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the DATA message */
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the email body */
    sprintf(buffer, "Subject: %s\r\n%s\r\n.\r\n", subject, message);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Send the QUIT message */
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Read the response from the server */
    bzero(buffer, MAX_BUFFER);
    n = read(sockfd, buffer, MAX_BUFFER-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Close the socket */
    close(sockfd);

    return 0;
}