//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 110

int main() {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    const char *username = "your_username";
    const char *password = "your_password";
    const char *hostname = "pop.gmail.com";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char auth_command[100];
    sprintf(auth_command, "USER %s\r\n", username);
    send(sockfd, auth_command, strlen(auth_command), 0);

    char auth_response[100];
    n = recv(sockfd, auth_response, sizeof(auth_response), 0);
    if (n <= 0) {
        printf("Error receiving authentication response\n");
        exit(1);
    }
    printf("Authentication response: %s\n", auth_response);

    sprintf(auth_command, "PASS %s\r\n", password);
    send(sockfd, auth_command, strlen(auth_command), 0);

    n = recv(sockfd, auth_response, sizeof(auth_response), 0);
    if (n <= 0) {
        printf("Error receiving authentication response\n");
        exit(1);
    }
    printf("Authentication response: %s\n", auth_response);

    char list_command[100];
    sprintf(list_command, "LIST\r\n");
    send(sockfd, list_command, strlen(list_command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving message list\n");
        exit(1);
    }
    printf("Message list:\n%s", buffer);

    close(sockfd);
    return 0;
}