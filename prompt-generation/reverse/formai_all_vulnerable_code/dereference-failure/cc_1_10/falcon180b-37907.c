//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int n;

    if (argc < 5) {
        printf("Usage:./program <IP Address> <Port Number> <Username> <Password>\n");
        exit(0);
    }

    strcpy(server_addr.sin_zero, "");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    printf("Connecting to server...\n");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");
    printf("Sending login information...\n");

    char *username = argv[3];
    char *password = argv[4];
    char *login_info = (char *)malloc(strlen(username) + strlen(password) + 10);
    sprintf(login_info, "USER %s\r\n", username);
    send(sockfd, login_info, strlen(login_info), 0);
    free(login_info);

    n = recv(sockfd, buffer, BUF_SIZE, 0);
    if (n < 0) {
        printf("Error receiving response from server\n");
        exit(0);
    }

    printf("Response from server: %s\n", buffer);

    char *response = strtok(buffer, "\r\n");
    while (response!= NULL) {
        if (strcasecmp(response, "235") == 0) {
            printf("Login successful\n");
            break;
        } else {
            printf("Invalid login information\n");
            exit(0);
        }
        response = strtok(NULL, "\r\n");
    }

    free(buffer);
    close(sockfd);

    return 0;
}