//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 1024
#define MAXSIZE 5242880
#define SMTP_PORT 25

char *readFile(char *filename) {
    FILE *file_pointer = fopen(filename, "r");
    char *buffer = malloc(MAXSIZE);
    char *ptr = buffer;
    if (file_pointer == NULL) {
        printf("Error in opening file \"%s\".\n", filename);
    } else {
        while (!feof(file_pointer)) {
            ptr += fread(ptr, 1, MAXSIZE, file_pointer);
        }
        fclose(file_pointer);
    }
    return buffer;
}

void sendCommand(int sockfd, const char *command) {
    printf("%s", command);
    send(sockfd, command, strlen(command), 0);
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc != 3) {
        printf("Usage: %s [hostname] [port number]\n", argv[0]);
        exit(1);
    }
    char *hostname = argv[1];
    int portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("ERROR: no such host\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy(server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[MAXLINE], username[MAXLINE], password[MAXLINE], recipient[MAXLINE], from[MAXLINE], subject[MAXLINE], *body;
    int len;

    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter sender email address: ");
    scanf("%s", from);
    printf("Enter email subject: ");
    scanf(" %[^\n]", subject);

    printf("Enter email body (filename or raw text):\n");
    body = (char *)malloc(MAXSIZE);
    char *input = (char *)malloc(MAXLINE);
    scanf("%s", input);
    if (strstr(input, ".txt") == NULL) {
        strcpy(body, input);
    } else {
        body = readFile(input);
    }

    len = sprintf(buffer, "AUTH LOGIN\r\n");
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "%s\r\n", username);
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "%s\r\n", password);
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "DATA\r\n");
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "Subject:%s\r\nFrom:<%s>\r\nTo:<%s>\r\n\r\n%s\r\n.\r\n", subject, from, recipient, body);
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    len = sprintf(buffer, "QUIT\r\n");
    sendCommand(sockfd, buffer);
    recv(sockfd, buffer, MAXLINE, 0);
    bzero(buffer, MAXLINE);

    close(sockfd);
    return 0;
}