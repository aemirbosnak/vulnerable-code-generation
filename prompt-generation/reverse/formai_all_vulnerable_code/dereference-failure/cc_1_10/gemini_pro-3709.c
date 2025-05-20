//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

typedef struct
{
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

Email *create_email(char *from, char *to, char *subject, char *body)
{
    Email *email = malloc(sizeof(Email));
    email->from = strdup(from);
    email->to = strdup(to);
    email->subject = strdup(subject);
    email->body = strdup(body);
    return email;
}

void delete_email(Email *email)
{
    free(email->from);
    free(email->to);
    free(email->subject);
    free(email->body);
    free(email);
}

int send_email(Email *email)
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_MSG_SIZE];

    portno = 25;
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        fprintf(stderr, "ERROR: no such host\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "ERROR: opening socket\n");
        return -1;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR: connecting\n");
        return -1;
    }

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "HELO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "MAIL FROM: <");
    strcat(buffer, email->from);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "RCPT TO: <");
    strcat(buffer, email->to);
    strcat(buffer, ">\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "From: ");
    strcat(buffer, email->from);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "To: ");
    strcat(buffer, email->to);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "Subject: ");
    strcat(buffer, email->subject);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "\r\n");
    strcat(buffer, email->body);
    strcat(buffer, "\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    bzero(buffer, MAX_MSG_SIZE);
    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, MAX_MSG_SIZE);
    recv(sockfd, buffer, MAX_MSG_SIZE, 0);

    close(sockfd);

    return 0;
}

int main(int argc, char **argv)
{
    Email *email;

    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s from to subject body\n", argv[0]);
        return 1;
    }

    email = create_email(argv[1], argv[2], argv[3], argv[4]);
    send_email(email);
    delete_email(email);

    return 0;
}