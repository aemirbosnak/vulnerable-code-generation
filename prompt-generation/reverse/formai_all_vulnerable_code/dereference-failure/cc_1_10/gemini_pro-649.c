//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SMTP_PORT 25

int main() {
    // Let's gather our trusty tools!
    int sockfd, len;
    struct sockaddr_in servaddr;
    char *server = "mail.example.com";
    char *sender = "you@example.com";
    char *recipients[] = {"friend1@example.com", "friend2@example.com"};
    char *subject = "Greetings, earthlings!";
    char *body = "Twas brillig, and the slithy toves...";
    char buf[1024];

    // Let's connect our spaceship to the SMTP server!
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Uh-oh, our spaceship didn't launch! :(");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
        perror("Oops, we can't find the SMTP server! :(");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Blast off failed! Couldn't connect to the SMTP server! :(");
        return 1;
    }

    // Let's introduce ourselves to the SMTP server!
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);
    sprintf(buf, "HELO earth\r\n");
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    // Time to send the mail!
    sprintf(buf, "MAIL FROM: %s\r\n", sender);
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    for (int i = 0; i < sizeof(recipients) / sizeof(char *); i++) {
        sprintf(buf, "RCPT TO: %s\r\n", recipients[i]);
        write(sockfd, buf, strlen(buf));
        len = read(sockfd, buf, sizeof(buf));
        printf("Server: %s", buf);
    }

    sprintf(buf, "DATA\r\n");
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    sprintf(buf, "Subject: %s\r\n\r\n", subject);
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    sprintf(buf, "%s\r\n.\r\n", body);
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    // Mission accomplished! Let's say goodbye!
    sprintf(buf, "QUIT\r\n");
    write(sockfd, buf, strlen(buf));
    len = read(sockfd, buf, sizeof(buf));
    printf("Server: %s", buf);

    close(sockfd);
    return 0;
}