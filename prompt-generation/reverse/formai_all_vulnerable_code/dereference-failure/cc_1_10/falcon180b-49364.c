//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PORT 25
#define SERVER "smtp.gmail.com"
#define USERNAME "your_email_address"
#define PASSWORD "your_password"

int main() {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Authenticate with server
    char username[100] = USERNAME;
    char password[100] = PASSWORD;
    char auth_string[200];
    sprintf(auth_string, "AUTH LOGIN\r\n");
    send(sock, auth_string, strlen(auth_string), 0);
    sprintf(auth_string, "%s\r\n", username);
    send(sock, auth_string, strlen(auth_string), 0);
    sprintf(auth_string, "%s\r\n", password);
    send(sock, auth_string, strlen(auth_string), 0);

    // Send email
    char from[100] = USERNAME;
    char to[100] = "recipient_email_address";
    char subject[100] = "Test email";
    char message_body[500] = "This is a test email sent using SMTP client in C.";
    char message[1000];
    sprintf(message, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", from, to, subject, message_body);
    send(sock, message, strlen(message), 0);

    // Close connection
    close(sock);

    return 0;
}