//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF 1024 // maximum buffer size
#define IMAP_PORT 143 // IMAP port number

int main(int argc, char *argv[]) {
    // declarations
    int sock;
    char buffer[MAX_BUF];
    struct sockaddr_in server_addr;
    struct hostent *server;
    char username[MAX_BUF];
    char password[MAX_BUF];
    char command[MAX_BUF];

    // check arguments
    if (argc < 2) {
        printf("Usage: %s server_address\n", argv[0]);
        exit(1);
    }

    // get server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: cannot create socket\n");
        exit(1);
    }

    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    // connect to server
    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: cannot connect to server\n");
        exit(1);
    }

    // read server greeting
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // login
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    sprintf(command, "LOGIN %s %s\r\n", username, password);
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // list mailboxes
    sprintf(command, "LIST \"\" *\r\n");
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // select mailbox
    printf("Mailbox: ");
    scanf("%s", command);
    sprintf(command, "SELECT %s\r\n", command);
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // fetch messages
    sprintf(command, "FETCH 1:* BODY[HEADER.FIELDS (FROM SUBJECT)]\r\n");
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // logout
    sprintf(command, "LOGOUT\r\n");
    send(sock, command, strlen(command), 0);
    memset(buffer, 0, MAX_BUF);
    recv(sock, buffer, MAX_BUF, 0);
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}