//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char *msg = "From: nobody@nowhere.com\r\nTo: nobody@nowhere.com\r\nSubject: Test Message\r\n\r\nHello World!\r\n.\r\n";
    struct hostent *server;
    char *hostname = "smtp.gmail.com";
    int port = 465;

    if (argc!= 2) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    printf("Connected to %s on port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    numbytes = write(sockfd, msg, strlen(msg));
    if (numbytes < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    printf("Message sent\n");

    close(sockfd);
    return 0;
}