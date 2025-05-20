//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024

typedef struct {
    char *hostname;
    int port;
    char *username;
    char *password;
} IMAPConfig;

void parse_input(IMAPConfig *config) {
    printf("Enter IMAP Server Hostname: ");
    config->hostname = malloc(100);
    fgets(config->hostname, 100, stdin);
    config->hostname[strcspn(config->hostname, "\n")] = 0;  // Remove newline character

    printf("Enter IMAP Username: ");
    config->username = malloc(100);
    fgets(config->username, 100, stdin);
    config->username[strcspn(config->username, "\n")] = 0;  // Remove newline character

    printf("Enter IMAP Password: ");
    config->password = malloc(100);
    fgets(config->password, 100, stdin);
    config->password[strcspn(config->password, "\n")] = 0;  // Remove newline character
}

int connect_to_imap(IMAPConfig *config) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Cannot open socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config->port);
    inet_pton(AF_INET, config->hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) break; // Exit on error or connection close
        printf("%s", buffer);
    }
}

void login(int sockfd, IMAPConfig *config) {
    char command[256];
    snprintf(command, sizeof(command), "A001 LOGIN %s %s", config->username, config->password);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void list_mailboxes(int sockfd) {
    send_command(sockfd, "A002 LIST \"\" \"*\"");
    receive_response(sockfd);
}

void fetch_email(int sockfd, int email_number) {
    char command[256];
    snprintf(command, sizeof(command), "A003 FETCH %d BODY[]", email_number);
    send_command(sockfd, command);
    receive_response(sockfd);
}

void cleanup(IMAPConfig *config) {
    free(config->hostname);
    free(config->username);
    free(config->password);
}

int main() {
    IMAPConfig config;
    config.port = IMAP_PORT;

    parse_input(&config);
    int sockfd = connect_to_imap(&config);
    
    if (sockfd >= 0) {
        receive_response(sockfd); // Read server greeting
        login(sockfd, &config);
        list_mailboxes(sockfd);
        
        int email_number;
        printf("Enter email number to fetch: ");
        scanf("%d", &email_number);
        fetch_email(sockfd, email_number);

        close(sockfd);
    }

    cleanup(&config);
    return 0;
}