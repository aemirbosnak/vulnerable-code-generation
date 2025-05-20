//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_USERNAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_BUFFER_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUFFER_LENGTH];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // check if command line arguments are correct
    if (argc != 2) {
        fprintf(stderr, "Usage: %s server_name\n", argv[0]);
        exit(1);
    }

    // get server info
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: could not create socket\n");
        exit(1);
    }

    // set server address struct
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: could not connect to server\n");
        exit(1);
    } else {
        printf("Connected to POP3 server %s...\n", argv[1]);
    }

    // receive server greeting
    memset(buffer, '\0', sizeof(buffer));
    n = read(sockfd, buffer, MAX_BUFFER_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "ERROR: could not read from socket\n");
        exit(1);
    } else {
        printf("%s\n", buffer);
    }

    // send user command
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH];
    printf("Username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    write(sockfd, buffer, strlen(buffer));

    // receive server response to user command
    memset(buffer, '\0', sizeof(buffer));
    read(sockfd, buffer, MAX_BUFFER_LENGTH - 1);
    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "ERROR: invalid username\n");
        exit(1);
    }

    // send password command
    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    write(sockfd, buffer, strlen(buffer));

    // receive server response to password command
    memset(buffer, '\0', sizeof(buffer));
    read(sockfd, buffer, MAX_BUFFER_LENGTH - 1);
    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "ERROR: invalid password\n");
        exit(1);
    }

    // send list command
    printf("Fetching mail list...\n");
    write(sockfd, "LIST\r\n", strlen("LIST\r\n"));

    // receive server response to list command
    memset(buffer, '\0', sizeof(buffer));
    read(sockfd, buffer, MAX_BUFFER_LENGTH - 1);
    if (strstr(buffer, "+OK") == NULL) {
        fprintf(stderr, "ERROR: could not fetch mail list\n");
        exit(1);
    } else {
        printf("%s", buffer);
    }

    // send quit command
    printf("Logging out and disconnecting from server...\n");
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    close(sockfd);

    return 0;
}