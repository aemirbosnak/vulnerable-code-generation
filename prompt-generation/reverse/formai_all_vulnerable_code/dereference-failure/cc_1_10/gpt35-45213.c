//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 256

int main(int argc, char **argv) {
    int sockfd, numbytes;
    char buf[BUF_SIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;

    if (argc != 4) {
        fprintf(stderr,"usage: %s hostname username password\n", argv[0]);
        exit(1);
    }

    if ((he=gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(993);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    /* Login */
    sprintf(buf, ". login %s %s\n", argv[2], argv[3]);
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, '\0', BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE - 1, 0);
    buf[strcspn(buf, "\r\n")] = 0; // Remove trailing CRLF
    printf("%s\n", buf);

    /* List mailboxes */
    sprintf(buf, ". list \"\" *\n");
    send(sockfd, buf, strlen(buf), 0);
    memset(buf, '\0', BUF_SIZE);
    recv(sockfd, buf, BUF_SIZE - 1, 0);
    buf[strcspn(buf, "\r\n")] = 0; // Remove trailing CRLF
    printf("%s\n", buf);
    while ((numbytes = recv(sockfd, buf, BUF_SIZE - 1, 0)) > 0) {
        buf[numbytes] = '\0';
        printf("%s", buf);
    }

    /* Logout */
    sprintf(buf, ". logout\n");
    send(sockfd, buf, strlen(buf), 0);

    close(sockfd);

    return 0;
}