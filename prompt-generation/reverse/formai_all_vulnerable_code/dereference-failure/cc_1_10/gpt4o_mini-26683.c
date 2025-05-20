//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 587
#define SERVER "smtp.example.com"
#define BUFFER_SIZE 1024

typedef struct {
    char *email;
    char *subject;
    char *body;
} Email;

void *send_email(void *arg) {
    Email *email = (Email *)arg;
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    // Define the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sock);
        return NULL;
    }

    // Send EHLO
    send(sock, "EHLO localhost\r\n", 17, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Send MAIL FROM
    char mail_from[BUFFER_SIZE];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", email->email);
    send(sock, mail_from, strlen(mail_from), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Send RCPT TO
    char rcpt_to[BUFFER_SIZE];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", email->email);
    send(sock, rcpt_to, strlen(rcpt_to), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Send DATA
    send(sock, "DATA\r\n", 7, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Send the email content
    char data[BUFFER_SIZE];
    sprintf(data, "Subject: %s\r\n\r\n%s\r\n.\r\n", email->subject, email->body);
    send(sock, data, strlen(data), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Close the connection
    send(sock, "QUIT\r\n", 7, 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    close(sock);
    free(email);
    pthread_exit(NULL);
}

void queue_email(const char *email, const char *subject, const char *body) {
    pthread_t thread;
    Email *new_email = malloc(sizeof(Email));
    new_email->email = strdup(email);
    new_email->subject = strdup(subject);
    new_email->body = strdup(body);

    // Create a new thread to send the email
    if (pthread_create(&thread, NULL, send_email, (void *)new_email) != 0) {
        perror("Failed to create thread");
        free(new_email->email);
        free(new_email->subject);
        free(new_email->body);
        free(new_email);
    }

    pthread_detach(thread);
}

int main() {
    const char *recipient = "recipient@example.com";
    const char *subject = "Hello World!";
    const char *body = "This is a test email sent asynchronously.";

    printf("Queueing an email...\n");
    queue_email(recipient, subject, body);

    // Simulating other work while email is being sent
    for (int i = 0; i < 5; i++) {
        printf("Doing other work (%d)\n", i + 1);
        sleep(1);
    }

    printf("Email queued. Check your email!\n");
    return 0;
}