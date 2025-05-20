//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 10240

int main(int argc, char *argv[])
{
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server;
    char username[50];
    char password[50];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int n;

    printf("Enter POP3 server hostname: ");
    scanf("%s", argv[1]);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(argv[1]);

    if (host == NULL)
    {
        printf("Error resolving hostname\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(110);
    server.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);

    if (n <= 0)
    {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);

    if (n <= 0)
    {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s", response);

    close(sockfd);

    return 0;
}