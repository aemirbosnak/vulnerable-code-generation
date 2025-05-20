//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/time.h>

#define PORT 25
#define BUFSIZE 1024

void sendmail(char *recipient, char *message) {
    char *msg = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: SMTP Client Test\r\n\r\n";
    strcat(msg, message);

    char buf[BUFSIZE];
    int sockfd;
    struct hostent *server;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, hostname not found\n");
        exit(1);
    }

    bzero((char *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    write(sockfd, msg, strlen(msg));
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s recipient message\n", argv[0]);
        exit(1);
    }

    sendmail(argv[1], argv[2]);
    return 0;
}