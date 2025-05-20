//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

// Function declarations
void *handle_response(int sockfd);
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body);
int connect_to_smtp(const char *server, int port);
void send_command(int sockfd, const char *cmd, char *response);
void trim_newline(char *str);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <smtp_server> <from_email> <to_email> <subject>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *subject = argv[4];

    char body[BUFFER_SIZE];
    printf("Enter your message body (end with a single line with '.' only):\n");
    int idx = 0;
    char line[BUFFER_SIZE];
    
    while (fgets(line, sizeof(line), stdin) && strcmp(line, ".\n") != 0) {
        strcpy(&body[idx], line);
        idx += strlen(line);
    }
    body[idx] = '\0'; // Null terminate the body

    int sockfd = connect_to_smtp(smtp_server, SMTP_PORT);
    if (sockfd == -1) {
        perror("Could not connect to SMTP server");
        return EXIT_FAILURE;
    }

    // Create a thread to handle server responses
    pthread_t response_thread;
    pthread_create(&response_thread, NULL, handle_response, (void *)(intptr_t)sockfd);

    // Send email
    send_email(sockfd, from_email, to_email, subject, body);

    pthread_join(response_thread, NULL);
    close(sockfd);
    return EXIT_SUCCESS;
}

int connect_to_smtp(const char *server, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        return -1;
    }

    return sockfd;
}

void *handle_response(int sockfd) {
    char response[BUFFER_SIZE];
    while (1) {
        memset(response, 0, sizeof(response));
        read(sockfd, response, sizeof(response) - 1);
        printf("Response: %s", response);
        if (strstr(response, "421") || strstr(response, "500")) {
            break; // Terminate on error responses
        }
    }
    return NULL;
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char response[BUFFER_SIZE];

    send_command(sockfd, "EHLO localhost\r\n", response);
    send_command(sockfd, "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, "DATA\r\n", response);

    char data[BUFFER_SIZE * 2];
    snprintf(data, sizeof(data), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, data, response);
    printf("Email sent successfully!\n");
}

void send_command(int sockfd, const char *cmd, char *response) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), cmd, ""); // Formatting the command
    write(sockfd, buffer, strlen(buffer));
    // Keep the response handling minimal by calling in loop
    read(sockfd, response, sizeof(response) - 1);
    trim_newline(response);
}

void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}