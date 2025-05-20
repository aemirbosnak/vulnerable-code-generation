//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024

void clear_buffer(char *buffer) {
    memset(buffer, 0, BUFFER_SIZE);
}

void display_welcome_message() {
    printf("Welcome to the Enthusiastic C Email Client!\n");
    printf("=============================================\n");
    printf("Connect with your friends and family effortlessly.\n");
    printf("Let's get started with sending some e-mails!\n\n");
}

int create_socket(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    int sock;

    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Cannot resolve hostname: %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    
    return sock;
}

void send_email(int socket, const char* from, const char* to, const char* subject, const char* body) {
    char buffer[BUFFER_SIZE];
    
    snprintf(buffer, BUFFER_SIZE, "HELO client\nMAIL FROM: <%s>\nRCPT TO: <%s>\nDATA\nSubject: %s\n\n%s\n.\nQUIT\n", 
            from, to, subject, body);

    send(socket, buffer, strlen(buffer), 0);
    clear_buffer(buffer);
    recv(socket, buffer, BUFFER_SIZE - 1, 0);
    printf("Server response: %s\n", buffer);
}

void compose_email(char *from, char *to, char *subject, char *body) {
    printf("Enter 'from' address: ");
    fgets(from, 100, stdin);
    strtok(from, "\n"); // Remove newline character
    
    printf("Enter 'to' address: ");
    fgets(to, 100, stdin);
    strtok(to, "\n"); // Remove newline character
    
    printf("Enter subject: ");
    fgets(subject, 100, stdin);
    strtok(subject, "\n"); // Remove newline character
    
    printf("Enter email body:\n");
    fgets(body, BUFFER_SIZE, stdin);
    strtok(body, "\n"); // Remove newline character
}

int main() {
    display_welcome_message();

    char from[100];
    char to[100];
    char subject[100];
    char body[BUFFER_SIZE];

    compose_email(from, to, subject, body);

    // Create the socket and connect to SMTP server
    int socket = create_socket("smtp.example.com", 587); // Replace with real SMTP server
    
    // Send Email
    send_email(socket, from, to, subject, body);

    // Clean up and close the socket
    close(socket);
    
    printf("Email sent successfully! ✈️\n");
    return 0;
}