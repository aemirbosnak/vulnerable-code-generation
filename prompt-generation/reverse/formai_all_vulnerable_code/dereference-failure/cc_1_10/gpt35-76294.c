//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_LEN 1024

// A struct to hold email details
typedef struct {
    char *to;
    char *from;
    char *subject;
    char *body;
} Email;

// Function to send an email
void send_email(Email *email)
{
    int client_socket, connection_status;
    struct sockaddr_in server_address;
    char message[MAX_LEN], server_reply[MAX_LEN];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set server details
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(25);
    inet_pton(AF_INET, "localhost", &server_address.sin_addr);

    // Connect to the server
    connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connection_status < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send HELO message
    sprintf(message, "HELO localhost\r\n");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM: <%s>\r\n", email->from);
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send RCPT TO message
    sprintf(message, "RCPT TO: <%s>\r\n", email->to);
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send DATA message
    sprintf(message, "DATA\r\n");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send email message
    sprintf(message, "To: <%s>\r\nFrom: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", email->to, email->from, email->subject, email->body);
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(client_socket, server_reply, MAX_LEN, 0) < 0) {
        perror("Error receiving message from server");
        exit(EXIT_FAILURE);
    }

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    if (send(client_socket, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(client_socket);
}

// Function to create a new email with given details
Email *create_email(char *to, char *from, char *subject, char *body)
{
    Email *new_email = (Email*) malloc(sizeof(Email));
    new_email->to = strdup(to);
    new_email->from = strdup(from);
    new_email->subject = strdup(subject);
    new_email->body = strdup(body);
    return new_email;
}

// Function to free memory allocated for an email
void free_email(Email *email)
{
    free(email->to);
    free(email->from);
    free(email->subject);
    free(email->body);
    free(email);
}

// Function to be executed by each thread
void *send_email_thread(void *thread_args)
{
    Email *email = (Email*) thread_args;
    send_email(email);
    free_email(email);
    pthread_exit(NULL);
}

int main()
{
    // Create list of emails to send
    Email *email1 = create_email("recipient1@example.com", "sender@example.com", "Test Email 1", "This is a test email.");
    Email *email2 = create_email("recipient2@example.com", "sender@example.com", "Test Email 2", "This is another test email.");
    Email *email3 = create_email("recipient3@example.com", "sender@example.com", "Test Email 3", "This is yet another test email.");

    // Create array of emails and threads
    Email *emails[3] = {email1, email2, email3};
    pthread_t threads[3];

    // Start each thread
    for (int i = 0; i < 3; i++) {
        int thread_status = pthread_create(&threads[i], NULL, send_email_thread, (void*) emails[i]);
        if (thread_status != 0) {
            perror("Error creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for each thread to finish
    for (int i = 0; i < 3; i++) {
        int thread_status = pthread_join(threads[i], NULL);
        if (thread_status != 0) {
            perror("Error joining thread");
            exit(EXIT_FAILURE);
        }
    }

    printf("All emails sent successfully!\n");

    return 0;
}