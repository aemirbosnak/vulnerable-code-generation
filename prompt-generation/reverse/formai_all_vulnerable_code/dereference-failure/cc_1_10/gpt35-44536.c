//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>

#define CRLF "\r\n"

int main(int argc, char *argv[]) {
    int sock, port;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc < 3) {
        printf("usage: %s servername portnumber\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[2]);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("ERROR creating a socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    bzero(buffer, sizeof(buffer));

    // Login command
    sprintf(buffer, "%s LOGIN %s %s" CRLF, "a001", "username", "password");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    bzero(buffer, sizeof(buffer));

    // Select mailbox command
    sprintf(buffer, "%s SELECT %s" CRLF, "a002", "INBOX");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    bzero(buffer, sizeof(buffer));

    // Fetch command
    sprintf(buffer, "%s FETCH 1 BODY[TEXT]" CRLF, "a003");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    bzero(buffer, sizeof(buffer));

    close(sock);
    return 0;
}