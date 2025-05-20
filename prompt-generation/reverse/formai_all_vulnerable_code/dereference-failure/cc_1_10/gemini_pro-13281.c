//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>

#define RESPONSE_BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[RESPONSE_BUFSIZE];

    if (recv(sockfd, buf, RESPONSE_BUFSIZE, 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    char username[100];

    printf("Username: ");
    scanf("%s", username);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    if (recv(sockfd, buf, RESPONSE_BUFSIZE, 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    char password[100];

    printf("Password: ");
    scanf("%s", password);

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    if (recv(sockfd, buf, RESPONSE_BUFSIZE, 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buf);

    char command[100];

    while (true)
    {
        printf("Command: ");
        scanf("%s", command);

        send(sockfd, command, strlen(command), 0);
        send(sockfd, "\r\n", strlen("\r\n"), 0);

        if (recv(sockfd, buf, RESPONSE_BUFSIZE, 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        printf("%s", buf);
    }

    close(sockfd);

    return 0;
}