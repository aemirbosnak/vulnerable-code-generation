//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define MAX_MSG_LENGTH 1024

// Function for sending email
void send_email(int sock, char *from, char *to, char *subject, char *body) {
    char buffer[MAX_MSG_LENGTH];
    int total_bytes = 0;
    
    // Send HELO command
    sprintf(buffer, "HELO example.com\r\n");
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send message header
    sprintf(buffer, "FROM: %s\r\n", from);
    total_bytes += send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "TO: %s\r\n", to);
    total_bytes += send(sock, buffer, strlen(buffer), 0);
    sprintf(buffer, "SUBJECT: %s\r\n", subject);
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send message body
    sprintf(buffer, "%s\r\n.\r\n", body);
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    total_bytes += send(sock, buffer, strlen(buffer), 0);

    printf("Total bytes sent: %d\n", total_bytes);
}

// Thread function for sending emails
void *send_email_thread(void *arg) {
    int sock;
    char *server_ip = (char*)arg;
    struct sockaddr_in server_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        pthread_exit(NULL);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(25);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        pthread_exit(NULL);
    }

    // Send email
    send_email(sock, "me@example.com", "you@example.com", "Test Email", "Hello World!");

    // Close socket
    close(sock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int i, num_threads;
    pthread_t *threads;

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server_ip> <num_threads>\n", argv[0]);
        exit(1);
    }
    char *server_ip = argv[1];
    num_threads = atoi(argv[2]);

    // Create array of thread IDs
    threads = (pthread_t*)malloc(sizeof(pthread_t) * num_threads);
    if (threads == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Start threads
    for (i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, send_email_thread, (void*)server_ip) != 0) {
            perror("Error creating thread");
            exit(1);
        }
    }

    // Wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory
    free(threads);

    return 0;
}