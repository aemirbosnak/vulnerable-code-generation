//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 587
#define BUFFER_SIZE 1024

// Function declarations
void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body);
void log_time(const char *message);
void clear_buffer(char *buffer, int size);

// Main function
int main() {
    char smtp_server[100], from[100], to[100], subject[100], body[BUFFER_SIZE];

    log_time("Starting Email Client");
    
    printf("Enter SMTP Server: ");
    fgets(smtp_server, sizeof(smtp_server), stdin);
    smtp_server[strcspn(smtp_server, "\n")] = 0; // Remove newline

    printf("Enter From Email: ");
    fgets(from, sizeof(from), stdin);
    from[strcspn(from, "\n")] = 0; // Remove newline

    printf("Enter To Email: ");
    fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = 0; // Remove newline

    printf("Enter Subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline

    printf("Enter Body of Email:\n");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline
   
    send_email(smtp_server, from, to, subject, body);
    log_time("Email sent successfully!");

    return 0;
}

// Function to send email
void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Clear buffer
    clear_buffer(buffer, BUFFER_SIZE);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the SMTP server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // SMTP Handshake
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    
    // HELO command
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // MAIL FROM
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // RCPT TO
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // DATA command
    send(sock, "DATA\r\n", 6, 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Email headers and body
    snprintf(buffer, sizeof(buffer), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // QUIT command
    send(sock, "QUIT\r\n", 7, 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Close socket
    close(sock);
}

// Log timestamp for debugging
void log_time(const char *message) {
    time_t t;
    time(&t);
    char* time_str = ctime(&t);
    time_str[strcspn(time_str, "\n")] = 0; // Remove newline
    printf("[%s] %s\n", time_str, message);
}

// Clear buffer function
void clear_buffer(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
}