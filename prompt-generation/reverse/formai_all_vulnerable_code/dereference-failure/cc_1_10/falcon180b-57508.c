//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 10240

int main(int argc, char *argv[]) {
    char hostname[256];
    char username[256];
    char password[256];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        if (send(sockfd, command, strlen(command), 0) == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(response, 0, MAX_RESPONSE_LENGTH);

        if (recv(sockfd, response, MAX_RESPONSE_LENGTH, 0) == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s\n", response);
    }

    close(sockfd);

    return 0;
}