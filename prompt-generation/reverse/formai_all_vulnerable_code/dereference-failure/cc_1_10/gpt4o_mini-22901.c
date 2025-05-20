//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdbool.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    char *username;
    char *password;
    char *hostname;
    int port;
} IMAPConfig;

typedef struct {
    char **emails;
    int count;
} EmailList;

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

IMAPConfig* create_config(const char *username, const char *password, const char *hostname, int port) {
    IMAPConfig *config = malloc(sizeof(IMAPConfig));
    config->username = strdup(username);
    config->password = strdup(password);
    config->hostname = strdup(hostname);
    config->port = port;
    return config;
}

void free_config(IMAPConfig *config) {
    free(config->username);
    free(config->password);
    free(config->hostname);
    free(config);
}

int connect_to_imap(IMAPConfig *config) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("Error creating socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config->port);
    if (inet_pton(AF_INET, config->hostname, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection failed");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
}

void login(int sockfd, IMAPConfig *config) {
    char response[BUFFER_SIZE];
    char login_command[BUFFER_SIZE];

    snprintf(login_command, sizeof(login_command), "a1 LOGIN %s %s", config->username, config->password);
    send_command(sockfd, login_command, response);
    printf("Login Response: %s\n", response);
}

EmailList* fetch_emails(int sockfd) {
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    EmailList *email_list = malloc(sizeof(EmailList));
    email_list->emails = malloc(MAX_EMAILS * sizeof(char*));
    email_list->count = 0;

    send_command(sockfd, "a2 SELECT INBOX", response);
    printf("Select INBOX Response: %s\n", response);

    send_command(sockfd, "a3 SEARCH ALL", response);
    printf("Search Response: %s\n", response);

    // Normally, we'd parse the response to extract email IDs, but for this example, let's simulate it.
    email_list->emails[email_list->count] = strdup("example@example.com");
    email_list->emails[++(email_list->count)] = strdup("test@test.com");

    return email_list;
}

void print_emails(EmailList *email_list) {
    printf("Fetched Emails:\n");
    for (int i = 0; i < email_list->count; i++) {
        printf("%d: %s\n", i + 1, email_list->emails[i]);
    }
}

void free_email_list(EmailList *email_list) {
    for (int i = 0; i < email_list->count; i++) {
        free(email_list->emails[i]);
    }
    free(email_list->emails);
    free(email_list);
}

int main() {
    IMAPConfig *config = create_config("user@example.com", "password", "imap.example.com", IMAP_PORT);
    int sockfd = connect_to_imap(config);
    
    login(sockfd, config);
    EmailList *email_list = fetch_emails(sockfd);
    print_emails(email_list);
    
    // Cleanup
    free_email_list(email_list);
    free_config(config);
    close(sockfd);
    
    return 0;
}