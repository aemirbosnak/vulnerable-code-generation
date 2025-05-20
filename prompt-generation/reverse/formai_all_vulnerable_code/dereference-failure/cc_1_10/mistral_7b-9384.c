//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

typedef struct {
    char command;
    char args[5][10];
} smtp_cmd;

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    portno = SERVER_PORT;
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr,
         server->h_length);
    serveraddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s\n", inet_ntoa(serveraddr.sin_addr));

    smtp_cmd commands[] = {
        {'E', "HELO ephemeral.example.com"},
        {'M', "MAIL FROM:<ephemeral@example.com>"},
        {'R', "RCPT TO:<recipient@example.com>"},
        {'D', "DATA"},
        {'Q', "\r\n.\r\nQUIT"}
    };

    for (int i = 0; i < 5; i++) {
        write(sockfd, &commands[i].command, sizeof(commands[i].command));
        if (commands[i].command == 'M') {
            write(sockfd, &commands[i].args[0], strlen(commands[i].args[0]));
            write(sockfd, &commands[i].args[1], strlen(commands[i].args[1]));
        } else {
            write(sockfd, commands[i].args, sizeof(commands[i].args));
        }
        char response[100];
        n = recv(sockfd, response, sizeof(response), 0);
        if (n > 0) {
            printf("Received response: %s\n", response);
        }
    }

    close(sockfd);
    return 0;
}