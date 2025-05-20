//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SIZE 1024
#define MAX_MAILBOX 50

char *mailbox[MAX_MAILBOX];
int mailbox_count = 0;

void list_mailboxes(int sockfd) {
    char buf[MAX_SIZE] = {0};
    char response[MAX_SIZE] = {0};
    sprintf(buf, "%s\r\n", "LIST \"\" *");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, response, MAX_SIZE, 0);
    char *tok = strtok(response, "\r\n");
    while (tok) {
        if (strstr(tok, "LIST")) {
            mailbox[mailbox_count++] = strdup(tok);
        }
        tok = strtok(NULL, "\r\n");
    }
    printf("Mailboxes:\n");
    for (int i = 0; i < mailbox_count; ++i) {
        printf("%s\n", mailbox[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host '%s'\n", argv[1]);
        exit(1);
    }
    int port = atoi(argv[2]);
    struct sockaddr_in serv_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: could not create socket");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: could not connect to server");
        exit(1);
    }
    char buf[MAX_SIZE] = {0};
    char response[MAX_SIZE] = {0};
    recv(sockfd, response, MAX_SIZE, 0);
    printf("%s\n", response);
    sprintf(buf, "%s\r\n", "LOGIN username password");
    send(sockfd, buf, strlen(buf), 0);
    recv(sockfd, response, MAX_SIZE, 0);
    printf("%s\n", response);
    list_mailboxes(sockfd);
    close(sockfd);
    return 0;
}