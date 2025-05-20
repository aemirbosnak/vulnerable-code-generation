//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>

#define PORT 993
#define MAX_STRING 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[MAX_STRING];
    char *imap_cmd = "LOGIN \"user\" \"password\"";
    char *imap_cmd_select_inbox = "SELECT INBOX";
    char *imap_cmd_search_inbox = "SEARCH \"ALL\"";
    char *imap_cmd_fetch_first_message = "FETCH 1:0 BODY[HEADER.FIELDS (SUBJECT)]";

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s imap_server_host imap_user\n", argv[0]);
        exit(1);
    }

    portno = PORT;
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        error("ERROR connecting");
    }

    n = write(sockfd, imap_cmd, strlen(imap_cmd));
    if (n < 0) {
        error("ERROR writing login command");
    }

    n = read(sockfd, buffer, MAX_STRING);
    if (n < 0) {
        error("ERROR reading login response");
    }

    printf("%s\n", buffer);

    n = write(sockfd, imap_cmd_select_inbox, strlen(imap_cmd_select_inbox));
    if (n < 0) {
        error("ERROR writing select command");
    }

    n = read(sockfd, buffer, MAX_STRING);
    if (n < 0) {
        error("ERROR reading select response");
    }

    printf("%s\n", buffer);

    n = write(sockfd, imap_cmd_search_inbox, strlen(imap_cmd_search_inbox));
    if (n < 0) {
        error("ERROR writing search command");
    }

    n = read(sockfd, buffer, MAX_STRING);
    if (n < 0) {
        error("ERROR reading search response");
    }

    printf("%s\n", buffer);

    n = write(sockfd, imap_cmd_fetch_first_message, strlen(imap_cmd_fetch_first_message));
    if (n < 0) {
        error("ERROR writing fetch command");
    }

    n = read(sockfd, buffer, MAX_STRING);
    if (n < 0) {
        error("ERROR reading fetch response");
    }

    printf("%s\n", buffer);

    return 0;
}