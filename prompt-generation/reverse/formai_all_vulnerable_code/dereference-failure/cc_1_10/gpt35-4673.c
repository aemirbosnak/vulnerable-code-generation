//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define CRLF "\r\n"
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int i;
    int sd;
    struct hostent *he;
    struct sockaddr_in dest;
    char buf[BUF_SIZE+1];

    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((he=gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Couldn't resolve host %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(143);
    memcpy(&(dest.sin_addr), he->h_addr_list[0], he->h_length);

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sd, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "a login %s %s" CRLF, argv[2], argv[3]);
    send(sd, buf, strlen(buf), 0);
    recv(sd, buf, BUF_SIZE, 0);
    buf[strlen(buf)-2] = 0; // remove CRLF
    printf("%s\n", buf);

    sprintf(buf, "a select inbox" CRLF);
    send(sd, buf, strlen(buf), 0);
    recv(sd, buf, BUF_SIZE, 0);
    buf[strlen(buf)-2] = 0; // remove CRLF
    printf("%s\n", buf);

    sprintf(buf, "a fetch 1 body[header]" CRLF);
    send(sd, buf, strlen(buf), 0);
    memset(buf, 0, sizeof(buf));
    recv(sd, buf, BUF_SIZE, 0);
    buf[strlen(buf)-2] = 0; // remove CRLF
    printf("%s\n", buf);

    sprintf(buf, "a logout" CRLF);
    send(sd, buf, strlen(buf), 0);
    recv(sd, buf, BUF_SIZE, 0);
    buf[strlen(buf)-2] = 0; // remove CRLF
    printf("%s\n", buf);

    close(sd);
    
    return 0;
}