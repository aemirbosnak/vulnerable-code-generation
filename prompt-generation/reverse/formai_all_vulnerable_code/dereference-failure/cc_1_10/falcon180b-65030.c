//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char hostname[50];
    int port;
    char buf[BUFF_SIZE];
    int n;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *login_data = malloc(50 + strlen(username) + strlen(password));
    sprintf(login_data, "LOGIN %s %s\r\n", username, password);

    send(sockfd, login_data, strlen(login_data), 0);

    char *response = malloc(BUFF_SIZE);
    n = recv(sockfd, response, BUFF_SIZE, 0);

    if (n < 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    response[n] = '\0';

    printf("Login response: %s\n", response);

    char *cmd = "LIST \"\" \"*\"\r\n";
    send(sockfd, cmd, strlen(cmd), 0);

    n = recv(sockfd, response, BUFF_SIZE, 0);

    if (n < 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    response[n] = '\0';

    printf("List response: %s\n", response);

    close(sockfd);

    return 0;
}