//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        die("gethostbyname");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    portno = 25;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR connecting");

    // Greeting the server
    char helo[50] = "HELO user.example.com\r\n";
    write(sockfd, helo, strlen(helo));

    // Logging in
    char login[100] = "MAIL FROM:<user@example.com>\r\n";
    char password_cmd[50] = "RSET\r\n";
    char password[50] = "password\r\n";
    write(sockfd, login, strlen(login));
    write(sockfd, password_cmd, strlen(password_cmd));
    write(sockfd, password, strlen(password));

    // Sending email
    char rcpt[50] = "RCPT TO:<recipient@example.com>\r\n";
    char data_cmd[20] = "DATA\r\n";
    char subject[50] = "Subject: Test Email\r\n";
    char body[100] = "This is a test email from our new SMTP client!\r\n.\r\n";

    write(sockfd, rcpt, strlen(rcpt));

    write(sockfd, data_cmd, strlen(data_cmd));
    write(sockfd, subject, strlen(subject));
    write(sockfd, body, strlen(body));

    close(sockfd);

    return 0;
}