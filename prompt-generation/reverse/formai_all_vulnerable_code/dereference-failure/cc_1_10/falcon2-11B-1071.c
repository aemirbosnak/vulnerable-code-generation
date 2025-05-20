//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char from[100], to[100], message[1000];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <smtp_server> <from> <to>\n", argv[0]);
        return 1;
    }

    from[0] = to[0] = '\0';
    bzero(message, 1000);

    // set from, to and message
    strcpy(from, argv[2]);
    strcpy(to, argv[3]);
    strcpy(message, "Hello, this is a test message.");

    portno = 25; // default port for SMTP

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket failed\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    send(sockfd, message, strlen(message), 0);
    printf("Message sent\n");

    close(sockfd);
    return 0;
}