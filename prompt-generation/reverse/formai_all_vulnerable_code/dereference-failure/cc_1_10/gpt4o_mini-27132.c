//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

typedef struct {
    const char *server;
    const char *from;
    const char *to;
    const char *subject;
    const char *body;
} email_t;

void *send_email(void *arg) {
    email_t *email = (email_t *)arg;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Connect to SMTP server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(email->server);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        pthread_exit(NULL);
    }

    // Receive server greeting
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send EHLO
    sprintf(buffer, "EHLO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Start TLS
    sprintf(buffer, "STARTTLS\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Here you would typically set up TLS and handle it accordingly
    // For simplicity, we will skip that part

    // Send MAIL FROM
    sprintf(buffer, "MAIL FROM:<%s>\r\n", email->from);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send RCPT TO
    sprintf(buffer, "RCPT TO:<%s>\r\n", email->to);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send DATA
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send email body
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", email->subject, email->body);
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    // Send QUIT
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Server: %s", buffer);

    close(sock);
    free(email);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <smtp_server> <from> <to> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    email_t *email = malloc(sizeof(email_t));
    email->server = argv[1];
    email->from = argv[2];
    email->to = argv[3];
    email->subject = argv[4];
    email->body = argv[5];

    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, send_email, (void *)email) != 0) {
        perror("Failed to create the thread");
        free(email);
        return EXIT_FAILURE;
    }

    pthread_detach(thread_id);
    printf("Email is being sent...\n");

    // Do other things while waiting for the email to send
    while (1) {
        printf("Main thread is still running...\n");
        sleep(5);
    }

    return EXIT_SUCCESS;
}