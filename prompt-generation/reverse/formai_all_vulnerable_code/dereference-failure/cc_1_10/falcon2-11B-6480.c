//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>
#include <arpa/nameser.h>
#include <string.h>
#include <pthread.h>

#define SERVER_PORT "143"
#define SERVER_ADDR "imap.gmail.com"
#define MAX_BUFFER_SIZE 1024
#define MESSAGE_SIZE_LIMIT 1000

typedef struct {
    char username[50];
    char password[50];
    char mail_folder[50];
} mail_config;

int connect_to_imap_server(mail_config *config) {
    int sockfd, rc;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(SERVER_ADDR);

    if (server == NULL) {
        perror("Error, hostname could not be resolved");
        return -1;
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(atoi(SERVER_PORT));

    rc = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (rc == -1) {
        perror("Error connecting");
        return -1;
    }

    printf("Connected to IMAP server\n");
    return sockfd;
}

int login_to_imap_server(mail_config *config, int sockfd) {
    char command[100];
    char response[MAX_BUFFER_SIZE];

    sprintf(command, "LOGIN %s %s\r\n", config->username, config->password);
    write(sockfd, command, strlen(command));

    read(sockfd, response, MAX_BUFFER_SIZE);
    printf("Login response: %s\n", response);

    return 0;
}

int logout_from_imap_server(mail_config *config, int sockfd) {
    char command[100];
    char response[MAX_BUFFER_SIZE];

    sprintf(command, "LOGOUT\r\n");
    write(sockfd, command, strlen(command));

    read(sockfd, response, MAX_BUFFER_SIZE);
    printf("Logout response: %s\n", response);

    return 0;
}

int get_message_ids(mail_config *config, int sockfd) {
    char command[100];
    char response[MAX_BUFFER_SIZE];

    sprintf(command, "LIST \"%s\"\r\n", config->mail_folder);
    write(sockfd, command, strlen(command));

    read(sockfd, response, MAX_BUFFER_SIZE);
    printf("Message ID list response: %s\n", response);

    return 0;
}

int get_message_content(mail_config *config, int sockfd, int message_id) {
    char command[100];
    char response[MAX_BUFFER_SIZE];

    sprintf(command, "FETCH %d (RFC822)\r\n", message_id);
    write(sockfd, command, strlen(command));

    read(sockfd, response, MAX_BUFFER_SIZE);
    printf("Message content response: %s\n", response);

    return 0;
}

int main() {
    mail_config config;
    int sockfd, rc;

    strcpy(config.username, "your_username");
    strcpy(config.password, "your_password");
    strcpy(config.mail_folder, "inbox");

    sockfd = connect_to_imap_server(&config);

    if (sockfd == -1) {
        perror("Error connecting to IMAP server");
        exit(1);
    }

    rc = login_to_imap_server(&config, sockfd);

    if (rc == -1) {
        perror("Error logging in to IMAP server");
        exit(1);
    }

    rc = get_message_ids(&config, sockfd);

    if (rc == -1) {
        perror("Error getting message IDs");
        exit(1);
    }

    rc = get_message_content(&config, sockfd, 1);

    if (rc == -1) {
        perror("Error getting message content");
        exit(1);
    }

    rc = logout_from_imap_server(&config, sockfd);

    if (rc == -1) {
        perror("Error logging out from IMAP server");
        exit(1);
    }

    close(sockfd);

    return 0;
}