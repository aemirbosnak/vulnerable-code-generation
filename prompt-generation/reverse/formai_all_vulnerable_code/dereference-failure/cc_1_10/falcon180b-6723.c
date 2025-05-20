//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct hostent *server;
    char buffer[MAX_RESPONSE_LENGTH];
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];

    if (argc!= 6) {
        printf("Usage:./pop3_client <server_address> <port_number> <username> <password>\n");
        return 1;
    }

    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    portno = atoi(argv[2]);

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)server->h_addr, sizeof(struct sockaddr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    memset(buffer, 0, MAX_RESPONSE_LENGTH);
    recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);

    printf("Server response: %s\n", buffer);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    memset(buffer, 0, MAX_RESPONSE_LENGTH);
    recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);

    printf("Server response: %s\n", buffer);

    sprintf(command, "STAT\r\n");
    send(sockfd, command, strlen(command), 0);

    memset(buffer, 0, MAX_RESPONSE_LENGTH);
    recv(sockfd, buffer, MAX_RESPONSE_LENGTH, 0);

    printf("Server response: %s\n", buffer);

    close(sockfd);

    return 0;
}