//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <openssl/ssl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./imap_client <server_IP> <username> <password>\n");
        exit(EXIT_FAILURE);
    }

    char *server_IP = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    struct hostent *server = gethostbyname(server_IP);
    if (server == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(993);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Authenticate
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    char login_command[BUFFER_SIZE];
    sprintf(login_command, "a1 LOGIN %s %s\n", username, password);
    write(sockfd, login_command, strlen(login_command));

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Select inbox
    char select_command[BUFFER_SIZE];
    sprintf(select_command, "a2 SELECT INBOX\n");
    write(sockfd, select_command, strlen(select_command));

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // List messages
    char fetch_command[BUFFER_SIZE];
    sprintf(fetch_command, "a3 FETCH 1:* (BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\n");
    write(sockfd, fetch_command, strlen(fetch_command));

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    // Logout
    char logout_command[BUFFER_SIZE];
    sprintf(logout_command, "a4 LOGOUT\n");
    write(sockfd, logout_command, strlen(logout_command));

    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE);
    printf("%s", buffer);

    close(sockfd);
    exit(EXIT_SUCCESS);
}