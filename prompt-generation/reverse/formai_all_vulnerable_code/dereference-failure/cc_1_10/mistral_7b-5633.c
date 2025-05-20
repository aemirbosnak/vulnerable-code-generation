//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define MAX_LINE 256
#define USER_AGENT "Simple POP3 Client (C)"

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_LINE];
    char *username = "user@example.com";
    char *password = "password";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("ERROR opening socket");

    server = gethostbyname("example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        die("gethostbyname");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(server->h_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR connecting");

    // greet server
    send(sockfd, USER_AGENT, strlen(USER_AGENT), 0);
    bzero(buffer, MAX_LINE);
    recv(sockfd, buffer, MAX_LINE, 0);
    printf("+OK %s\n", buffer);

    // login
    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    bzero(buffer, MAX_LINE);
    recv(sockfd, buffer, MAX_LINE, 0);
    printf("%s", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    bzero(buffer, MAX_LINE);
    recv(sockfd, buffer, MAX_LINE, 0);
    printf("%s", buffer);

    // list emails
    send(sockfd, "LIST\r\n", 5, 0);
    int i = 1;
    while (1) {
        bzero(buffer, MAX_LINE);
        int n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n > 0) {
            printf("%d: %s\n", i++, buffer);
        } else {
            break;
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}