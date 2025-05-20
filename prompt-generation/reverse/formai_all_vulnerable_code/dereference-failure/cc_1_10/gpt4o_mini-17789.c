//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    char *sender;
    char *subject;
    char *body;
} Email;

void print_email(Email email) {
    printf("From: %s\n", email.sender);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
}

int connect_to_pop3_server(const char *hostname) {
    struct hostent *host;
    struct sockaddr_in server_addr;
    int sockfd;

    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Unable to get host address");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Unable to connect to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
}

char *receive_response(int sockfd) {
    static char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    if (n < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }

    buffer[n] = '\0';
    return buffer;
}

void authenticate(int sockfd, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s", username);
    send_command(sockfd, command);
    printf("Server: %s", receive_response(sockfd));

    snprintf(command, sizeof(command), "PASS %s", password);
    send_command(sockfd, command);
    printf("Server: %s", receive_response(sockfd));
}

void retrieve_emails(int sockfd) {
    const int max_emails = MAX_EMAILS;
    char command[BUFFER_SIZE];

    send_command(sockfd, "LIST");
    printf("Server: %s", receive_response(sockfd));

    for (int i = 1; i <= max_emails; i++) {
        snprintf(command, sizeof(command), "RETR %d", i);
        send_command(sockfd, command);
        char *response = receive_response(sockfd);
        if (strncmp(response, "+OK", 3) != 0) {
            break; // No more emails
        }
        
        Email email;
        email.body = strdup(response + 4); // Assuming body starts after the "+OK "
        
        char *line = strtok(email.body, "\n");
        email.sender = strdup(line ? line : "unknown");
        line = strtok(NULL, "\n");
        email.subject = strdup(line ? line : "No Subject");

        print_email(email);

        free(email.body);
        free(email.sender);
        free(email.subject);
    }

    send_command(sockfd, "QUIT");
    printf("Server: %s", receive_response(sockfd));
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sockfd = connect_to_pop3_server(hostname);
    printf("Connected to POP3 server.\n");

    char *response = receive_response(sockfd);
    printf("Server: %s", response);

    if (strncmp(response, "+OK", 3) != 0) {
        fprintf(stderr, "Failed to connect to POP3 server.\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    authenticate(sockfd, username, password);
    retrieve_emails(sockfd);

    close(sockfd);
    return 0;
}