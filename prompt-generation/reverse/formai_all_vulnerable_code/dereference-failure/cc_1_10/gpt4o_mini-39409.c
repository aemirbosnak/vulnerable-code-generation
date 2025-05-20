//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define IMAP_PORT 993
#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int create_socket(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        error("Error: No such host");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)host->h_addr, host->h_length);
    server_addr.sin_port = htons(IMAP_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Response: %s", buffer);
}

void login(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", username, password);
    send_command(sockfd, command);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" *");
}

void fetch_email(int sockfd, const char *mailbox, int email_id) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]", email_id);
    send_command(sockfd, command);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = create_socket(hostname);

    send_command(sockfd, "* OK IMAP4 ready");
    login(sockfd, username, password);
    list_mailboxes(sockfd);

    // Fetch email from the first mailbox
    fetch_email(sockfd, "INBOX", 1);

    close(sockfd);
    return 0;
}