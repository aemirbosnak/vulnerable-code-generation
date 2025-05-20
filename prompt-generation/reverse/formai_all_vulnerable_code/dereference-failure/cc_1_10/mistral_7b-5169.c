//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 4096

int main(int argc, char const *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <message>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host as %s\n", argv[1]);
        exit(1);
    }

    portno = SERVER_PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char helo_msg[] = "HELO localhost\r\n";
    send(sockfd, helo_msg, strlen(helo_msg), 0);

    char mail_from_msg[1024];
    sprintf(mail_from_msg, "MAIL FROM: <%s>\r\n", argv[2]);
    send(sockfd, mail_from_msg, strlen(mail_from_msg), 0);

    char rcpt_to_msg[] = "RCPT TO: <test@example.com>\r\n";
    send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0);

    char data_msg[] = "DATA\r\n";
    send(sockfd, data_msg, strlen(data_msg), 0);

    char subject[] = "Test Email\r\n";
    send(sockfd, subject, strlen(subject), 0);

    char message[] = "This is a test email.\r\n.\r\n";
    send(sockfd, message, strlen(message), 0);

    char quit_msg[] = "QUIT\r\n";
    send(sockfd, quit_msg, strlen(quit_msg), 0);

    close(sockfd);
    return 0;
}