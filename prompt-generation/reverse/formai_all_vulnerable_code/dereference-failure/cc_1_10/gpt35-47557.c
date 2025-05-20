//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define HOSTNAME "pop.example.com"
#define PORT 110

int main(int argc, char *argv[]) {
    char buffer[1024], username[40], password[40], command[100];
    int sockfd, n;

    struct hostent* server;
    struct sockaddr_in serv_addr;

    printf("Welcome to POP3 Client!\n\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(HOSTNAME);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));

    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(command, "USER %s\r\n", username);
    write(sockfd, command, strlen(command));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    write(sockfd, command, strlen(command));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(command, "STAT\r\n");
    write(sockfd, command, strlen(command));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    sprintf(command, "QUIT\r\n");
    write(sockfd, command, strlen(command));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s\n", buffer);

    close(sockfd);

    printf("\nPOP3 Client has finished running. Have a great day!\n");

    return 0;
}