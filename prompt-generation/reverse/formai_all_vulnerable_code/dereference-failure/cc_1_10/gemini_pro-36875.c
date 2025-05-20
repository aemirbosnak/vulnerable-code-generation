//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLEN 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *hp;
    struct sockaddr_in addr;
    char buf[MAXLEN];
    char *msg = "HELO localhost\r\nMAIL FROM: <sender@example.com>\r\nRCPT TO: <recipient@example.com>\r\nDATA\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\nQUIT\r\n";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s\n", strerror(errno));
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, hp->h_addr_list[0], hp->h_length);
    addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    while (fgets(buf, MAXLEN, stdin) != NULL) {
        if (strcmp(buf, "QUIT\r\n") == 0) {
            break;
        }
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            fprintf(stderr, "send() failed: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        exit(1);
    }

    while (recv(sockfd, buf, MAXLEN, 0) > 0) {
        printf("%s", buf);
    }

    close(sockfd);

    return 0;
}