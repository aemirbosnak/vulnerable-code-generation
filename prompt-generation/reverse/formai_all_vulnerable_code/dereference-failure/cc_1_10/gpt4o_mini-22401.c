//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <fcntl.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 1024

typedef struct {
    char *hostname;
    char *username;
    char *password;
} imap_credentials_t;

void *imap_connect(void *arg);
void send_command(int sockfd, const char *cmd);
void receive_response(int sockfd);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    imap_credentials_t *credentials = malloc(sizeof(imap_credentials_t));
    credentials->hostname = argv[1];
    credentials->username = argv[2];
    credentials->password = argv[3];

    pthread_t imap_thread;
    if (pthread_create(&imap_thread, NULL, imap_connect, (void *)credentials) != 0) {
        fprintf(stderr, "Error creating thread: %s\n", strerror(errno));
        free(credentials);
        return 1;
    }

    pthread_join(imap_thread, NULL);
    free(credentials);
    return 0;
}

void *imap_connect(void *arg) {
    imap_credentials_t *creds = (imap_credentials_t *)arg;
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, creds->hostname, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported: %s\n", strerror(errno));
        close(sockfd);
        return NULL;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        close(sockfd);
        return NULL;
    }

    receive_response(sockfd);
    
    // Login to the IMAP server
    char login_command[BUFFER_SIZE];
    snprintf(login_command, sizeof(login_command), "A001 LOGIN %s %s\r\n", creds->username, creds->password);
    send_command(sockfd, login_command);
    receive_response(sockfd);
    
    // Select INBOX
    send_command(sockfd, "A002 SELECT INBOX\r\n");
    receive_response(sockfd);

    close(sockfd);
    return NULL;
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
        fprintf(stderr, "Error sending command: %s\n", strerror(errno));
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "Error reading response: %s\n", strerror(errno));
        return;
    }

    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}