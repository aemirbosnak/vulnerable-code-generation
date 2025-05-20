//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    char subject[BUFFER_SIZE];
    char from[BUFFER_SIZE];
} Email;

void receive_email(int sock, Email *email) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    
    // Read email data from POP3 server
    while (recv(sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        if (strstr(buffer, "Subject:") != NULL) {
            sscanf(buffer, "%*[^:]: %[^\n]", email->subject);
        }
        if (strstr(buffer, "From:") != NULL) {
            sscanf(buffer, "%*[^:]: %[^\n]", email->from);
        }
        if (strstr(buffer, ".") != NULL) { // End of email body
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <POP3 server IP> <username:password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server_ip = argv[1];
    char *credentials = argv[2];
    char *username = strtok(credentials, ":");
    char *password = strtok(NULL, ":");

    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return EXIT_FAILURE;
    }

    // Receive POP3 server greeting
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Send USER command
    sprintf(buffer, "USER %s\r\n", username);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Send PASS command
    sprintf(buffer, "PASS %s\r\n", password);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Send LIST command
    send(sock, "LIST\r\n", 7, 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Let's receive up to MAX_EMAILS
    Email emails[MAX_EMAILS];
    int email_count = 0;

    for (int i = 1; i <= MAX_EMAILS; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        send(sock, buffer, strlen(buffer), 0);
        memset(buffer, 0, BUFFER_SIZE);
        
        // Receive the email
        receive_email(sock, &emails[email_count]);
        email_count++;

        // Print email information
        printf("Email %d:\n", i);
        printf("From: %s\n", emails[email_count - 1].from);
        printf("Subject: %s\n\n", emails[email_count - 1].subject);
        
        // Break if we hit the last email
        if (strstr(buffer, "OK") == NULL) {
            break;
        }
    }

    // Send QUIT command
    send(sock, "QUIT\r\n", 7, 0);
    close(sock);
    
    return EXIT_SUCCESS;
}