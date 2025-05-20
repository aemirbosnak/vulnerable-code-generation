//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define USER "username"
#define PASS "password"
#define HOST "pop.gmail.com"
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *host_info;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;
    char *cmd;
    char *token;
    char username[64];
    char password[64];
    char response[64];
    int status;
    FILE *fp;
    char filename[64];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    host_info = gethostbyname(HOST);
    if (host_info == NULL) {
        printf("Error: Could not resolve server address\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(cmd, "USER %s\r\n", USER);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUF_SIZE, 0);

    token = strtok(buffer, " ");
    if (strcmp(token, "+OK")!= 0) {
        printf("Error: Invalid response from server\n");
        exit(1);
    }

    sprintf(cmd, "PASS %s\r\n", PASS);
    send(sockfd, cmd, strlen(cmd), 0);
    recv(sockfd, buffer, BUF_SIZE, 0);

    token = strtok(buffer, " ");
    if (strcmp(token, "+OK")!= 0) {
        printf("Error: Invalid response from server\n");
        exit(1);
    }

    do {
        sprintf(cmd, "LIST\r\n");
        send(sockfd, cmd, strlen(cmd), 0);
        recv(sockfd, buffer, BUF_SIZE, 0);

        token = strtok(buffer, "\r\n");
        while (token!= NULL) {
            if (strlen(token) > 1) {
                if (token[strlen(token) - 1] == '\r') {
                    token[strlen(token) - 1] = '\0';
                }
            }
            fprintf(stdout, "%s", token);
            token = strtok(NULL, "\r\n");
        }

    } while (strcmp(token, ".\r\n")!= 0);

    close(sockfd);
    exit(0);
}