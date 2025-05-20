//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define MAX_THREADS 5

pthread_mutex_t lock;

typedef struct {
    char *recipient;
    char *subject;
    char *body;
} Email;

void *send_email(void *arg) {
    Email *email = (Email *)arg;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    // Server setup
    struct hostent *host = gethostbyname(SERVER);
    if (host == NULL) {
        perror("Failed to get host");
        close(sockfd);
        pthread_exit(NULL);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        pthread_exit(NULL);
    }

    // SMTP conversation
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    send(sockfd, "EHLO localhost\r\n", 17, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Authentication
    // Note: This is just a simple example, replace with actual authentication flow
    send(sockfd, "AUTH LOGIN\r\n", 13, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send email
    send(sockfd, "MAIL FROM:<you@example.com>\r\n", 31, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    send(sockfd, "RCPT TO:<", 10, 0);
    send(sockfd, email->recipient, strlen(email->recipient), 0);
    send(sockfd, ">\r\n", 4, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    send(sockfd, "DATA\r\n", 7, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Email content
    send(sockfd, "Subject: ", 9, 0);
    send(sockfd, email->subject, strlen(email->subject), 0);
    send(sockfd, "\r\n\r\n", 4, 0);
    send(sockfd, email->body, strlen(email->body), 0);
    send(sockfd, "\r\n.\r\n", 5, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Close connection
    send(sockfd, "QUIT\r\n", 7, 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    close(sockfd);
    free(email);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Example use case with a few emails
    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(&lock);
        Email *email = malloc(sizeof(Email));
        email->recipient = "recipient@example.com"; // change as necessary
        email->subject = "Test Subject";
        email->body = "This is a test email body.";
        pthread_create(&threads[thread_count++], NULL, send_email, (void *)email);
        pthread_mutex_unlock(&lock);
    }

    // Wait for all threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&lock);
    return 0;
}