//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define PORT 993

int main() {
    char username[50];
    char password[50];
    char email_addr[50];
    char command[256];
    char response[1024];
    char host[50];
    char mailbox[50];
    char out_buf[1024];
    char *p;
    int sock_fd;
    struct sockaddr_in server;
    struct hostent *hp;

    printf("Enter your email address: ");
    fgets(email_addr, 50, stdin);
    printf("Enter your username: ");
    fgets(username, 50, stdin);
    printf("Enter your password: ");
    fgets(password, 50, stdin);

    // remove newline characters from input strings
    if ((p=strchr(username, '\n')) != NULL) *p = '\0';
    if ((p=strchr(password, '\n')) != NULL) *p = '\0';
    if ((p=strchr(email_addr, '\n')) != NULL) *p = '\0';

    // get hostname from email address
    sscanf(email_addr, "%*[^@]@%s", host);

    // connect to mail server using IMAP protocol
    if ((hp = gethostbyname(host)) == NULL) {
        printf("Unknown host %s\n", host);
        exit(1);
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset((char *)&server, 0, sizeof(struct sockaddr_in));
    memcpy(&(server.sin_addr.s_addr), hp->h_addr, hp->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(sock_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("Error connecting to server\n");
        close(sock_fd);
        exit(1);
    }

    printf("Connected to server %s\n", host);

    // authenticate user
    sprintf(command, "a001 LOGIN %s %s\n", username, password);
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, response, sizeof(response), 0);
    printf("%s\n", response);

    // select mailbox
    sprintf(command, "a002 SELECT INBOX\n");
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, response, sizeof(response), 0);
    printf("%s\n", response);

    // fetch first 10 messages
    sprintf(command, "a003 FETCH 1:10 BODY[HEADER.FIELDS (FROM DATE SUBJECT)]\n");
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, response, sizeof(response), 0);
    printf("%s\n", response);

    // logout and close connection
    sprintf(command, "a004 LOGOUT\n");
    send(sock_fd, command, strlen(command), 0);
    recv(sock_fd, response, sizeof(response), 0);
    printf("%s\n", response);

    close(sock_fd);

    return 0;
}