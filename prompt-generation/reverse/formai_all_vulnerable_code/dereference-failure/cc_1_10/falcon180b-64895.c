//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER "127.0.0.1"
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    char *auth_string = NULL;
    auth_string = calloc(strlen(username) + strlen(password) + 2, sizeof(char));
    strcat(auth_string, username);
    strcat(auth_string, "\0");
    strcat(auth_string, password);

    send(sockfd, auth_string, strlen(auth_string), 0);
    free(auth_string);

    char *response = NULL;
    response = calloc(BUFFER_SIZE, sizeof(char));
    n = recv(sockfd, response, BUFFER_SIZE, 0);

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}