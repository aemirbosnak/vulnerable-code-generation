//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "imap.example.com"
#define PORT 993
#define BUFFER_SIZE 1024

// Function prototypes
void error(const char *msg);
int open_connection(const char *hostname, int port);
void imap_connect(int sockfd, const char *username, const char *password);
void imap_logout(int sockfd);
void imap_select_mailbox(int sockfd);
void imap_list_messages(int sockfd);
void imap_read_message(int sockfd, int msg_num);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *username = argv[1];
    char *password = argv[2];

    int sockfd = open_connection(SERVER, PORT);
    imap_connect(sockfd, username, password);
    imap_select_mailbox(sockfd);
    imap_list_messages(sockfd);
    imap_logout(sockfd);

    close(sockfd);
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int open_connection(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(hostname);
    
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    return sockfd;
}

void imap_connect(int sockfd, const char *username, const char *password) {
    char buffer[BUFFER_SIZE];

    snprintf(buffer, sizeof(buffer), "A001 LOGIN %s %s\r\n", username, password);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Response: %s", buffer);
}

void imap_logout(int sockfd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A002 LOGOUT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Response: %s", buffer);
}

void imap_select_mailbox(int sockfd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A003 SELECT INBOX\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Response: %s", buffer);
}

void imap_list_messages(int sockfd) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "A004 SEARCH ALL\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Response: %s\n", buffer);

    // Assuming messages are numbered and present in the buffer
    // For simplicity, we'll parse them as integers
    char *message = strtok(buffer, " ");
    while (message != NULL) {
        if (isdigit(message[0])) {
            int msg_num = atoi(message);
            imap_read_message(sockfd, msg_num);
        }
        message = strtok(NULL, " ");
    }
}

void imap_read_message(int sockfd, int msg_num) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, sizeof(buffer), "A005 FETCH %d BODY[TEXT]\r\n", msg_num);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer) - 1);
    printf("Message %d: %s\n", msg_num, buffer);
}