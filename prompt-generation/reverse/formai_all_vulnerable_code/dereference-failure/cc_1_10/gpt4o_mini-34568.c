//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    int id;
    int size;
} Email;

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void get_email_stats(int socket, Email emails[], int *email_count) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    // Retrieve the number of emails
    strcpy(command, "STAT\r\n");
    send(socket, command, strlen(command), 0);
    recv(socket, buffer, BUFFER_SIZE, 0);
    
    // Parse the response for total emails
    int total_emails = 0, total_bytes = 0;
    sscanf(buffer, "+OK %d %d", &total_emails, &total_bytes);
    printf("Total Emails: %d, Total Size: %d bytes\n", total_emails, total_bytes);

    *email_count = total_emails;

    // Retrieve sizes of each email
    for (int i = 1; i <= total_emails && i <= MAX_EMAILS; i++) {
        sprintf(command, "LIST %d\r\n", i);
        send(socket, command, strlen(command), 0);
        recv(socket, buffer, BUFFER_SIZE, 0);
        
        int email_id, email_size;
        sscanf(buffer, "+OK %d %d", &email_id, &email_size);
        
        emails[i-1].id = email_id;
        emails[i-1].size = email_size;
    }
}

void display_email_stats(Email emails[], int email_count) {
    printf("\nEmail Details:\n");
    printf("ID\tSize\n");
    printf("------------------------\n");
    for (int i = 0; i < email_count; i++) {
        printf("%d\t%d bytes\n", emails[i].id, emails[i].size);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    
    struct sockaddr_in server_addr;
    int sockfd;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Setup server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    // Initialize email details
    Email emails[MAX_EMAILS];
    int email_count;

    // Receive the welcome message
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server: %s", buffer);

    // Send USER command
    char username[BUFFER_SIZE];
    printf("Enter username: ");
    fgets(username, BUFFER_SIZE, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline character
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    // Send PASS command
    char password[BUFFER_SIZE];
    printf("Enter password: ");
    fgets(password, BUFFER_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline character
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    // Retrieve email statistics
    get_email_stats(sockfd, emails, &email_count);

    // Display email statistics
    display_email_stats(emails, email_count);

    // Send QUIT command
    send(sockfd, "QUIT\r\n", 7, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}