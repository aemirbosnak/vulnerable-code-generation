//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 1024

/* This function sends a command to the POP3 server and prints the response */
void sendCommand(int sockfd, const char *cmd) {
    char response[MAX_SIZE];
    memset(response, 0, MAX_SIZE);
    write(sockfd, cmd, strlen(cmd));
    read(sockfd, response, MAX_SIZE);
    printf("%s", response);
}

int main(int argc, char *argv[]) {

    /* Validate command line arguments */
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    /* Create socket */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    /* Get IP address of server */
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    /* Set up socket address */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2])) ;

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    /* Read greeting from server */
    char greeting[MAX_SIZE];
    memset(greeting, 0, MAX_SIZE);
    read(sockfd, greeting, MAX_SIZE);
    printf("%s", greeting);

    /* Send user name */
    char user[MAX_SIZE];
    printf("Username: ");
    fgets(user, MAX_SIZE, stdin);
    char *pos;
    if ((pos=strchr(user, '\n')) != NULL) {
        *pos = '\0';
    }
    char cmd[MAX_SIZE];
    sprintf(cmd, "USER %s\r\n", user);
    sendCommand(sockfd, cmd);

    /* Send password */
    char password[MAX_SIZE];
    printf("Password: ");
    fgets(password, MAX_SIZE, stdin);
    if ((pos=strchr(password, '\n')) != NULL) {
        *pos = '\0';
    }
    sprintf(cmd, "PASS %s\r\n", password);
    sendCommand(sockfd, cmd);

    /* Get number of messages */
    sendCommand(sockfd, "STAT\r\n");

    /* Retrieve list of messages */
    sendCommand(sockfd, "LIST\r\n");

    /* Quit */
    sendCommand(sockfd, "QUIT\r\n");

    /* Close socket */
    close(sockfd);

    return 0;
}