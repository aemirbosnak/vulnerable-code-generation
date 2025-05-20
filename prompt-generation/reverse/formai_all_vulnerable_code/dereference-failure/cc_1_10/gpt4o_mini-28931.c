//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int open_connection(const char *hostname, int port) {
    struct hostent *server;
    struct sockaddr_in server_addr;
    int sockfd;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command, char *response) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
    
    memset(response, 0, BUFFER_SIZE);
    read(sockfd, response, BUFFER_SIZE - 1);
}

void login(int sockfd, const char *username, const char *password) {
    char response[BUFFER_SIZE];

    // Get server ready
    send_command(sockfd, "", response);
    printf("%s", response);

    // Send USER command
    snprintf(response, BUFFER_SIZE, "USER %s", username);
    send_command(sockfd, response, response);
    printf("%s", response);

    // Send PASS command
    snprintf(response, BUFFER_SIZE, "PASS %s", password);
    send_command(sockfd, response, response);
    printf("%s", response);
}

void list_messages(int sockfd) {
    char response[BUFFER_SIZE];

    // Send LIST command
    send_command(sockfd, "LIST", response);
    printf("%s", response);
}

void retrieve_message(int sockfd, int message_num) {
    char response[BUFFER_SIZE];

    // Send RETR command for the specified message number
    snprintf(response, BUFFER_SIZE, "RETR %d", message_num);
    send_command(sockfd, response, response);
    printf("%s", response);
}

void delete_message(int sockfd, int message_num) {
    char response[BUFFER_SIZE];

    // Send DELE command to delete the specified message
    snprintf(response, BUFFER_SIZE, "DELE %d", message_num);
    send_command(sockfd, response, response);
    printf("%s", response);
}

void quit_connection(int sockfd) {
    char response[BUFFER_SIZE];

    // Send QUIT command
    send_command(sockfd, "QUIT", response);
    printf("%s", response);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = open_connection(hostname, POP3_PORT);
    if (sockfd < 0) {
        return 1;
    }

    login(sockfd, username, password);
    list_messages(sockfd);

    // Example of retrieving the first message
    retrieve_message(sockfd, 1);

    // Example of deleting the first message (if desired)
    // delete_message(sockfd, 1);

    quit_connection(sockfd);
    close(sockfd);

    return 0;
}