//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Failed to create socket. Error: %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    // Configure server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to connect to server. Error: %d (%s)\n", errno, strerror(errno));
        return 1;
    }

    // Authenticate with server
    printf("Username: ");
    char username[BUFFER_SIZE];
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Password: ");
    char password[BUFFER_SIZE];
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0;

    char auth_message[BUFFER_SIZE];
    sprintf(auth_message, "USER %s\r\n", username);
    send(sockfd, auth_message, strlen(auth_message), 0);

    char response[BUFFER_SIZE];
    recv(sockfd, response, BUFFER_SIZE, 0);

    sprintf(auth_message, "PASS %s\r\n", password);
    send(sockfd, auth_message, strlen(auth_message), 0);

    recv(sockfd, response, BUFFER_SIZE, 0);

    // Command loop
    char command[BUFFER_SIZE];
    while(1) {
        printf("> ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;

        send(sockfd, command, strlen(command), 0);
        recv(sockfd, response, BUFFER_SIZE, 0);

        printf("%s", response);
    }

    // Close socket
    close(sockfd);

    return 0;
}