//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define SERVER "smtp.gmail.com"
#define PORT 587
#define USER "your_username"
#define PASS "your_password"

int main()
{
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char send_buffer[1024], recv_buffer[1024];
    int send_len, recv_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // Authenticate
    char auth_buffer[100];
    sprintf(auth_buffer, "AUTH LOGIN\r\n");
    send(sockfd, auth_buffer, strlen(auth_buffer), 0);

    char username_buffer[100];
    sprintf(username_buffer, "%s\r\n", USER);
    send(sockfd, username_buffer, strlen(username_buffer), 0);

    char password_buffer[100];
    sprintf(password_buffer, "%s\r\n", PASS);
    send(sockfd, password_buffer, strlen(password_buffer), 0);

    // Send email
    char from_buffer[100];
    sprintf(from_buffer, "From: %s\r\n", USER);
    send(sockfd, from_buffer, strlen(from_buffer), 0);

    char to_buffer[100];
    sprintf(to_buffer, "To: recipient@example.com\r\n");
    send(sockfd, to_buffer, strlen(to_buffer), 0);

    char subject_buffer[100];
    sprintf(subject_buffer, "Subject: Test Email\r\n");
    send(sockfd, subject_buffer, strlen(subject_buffer), 0);

    char message_buffer[100];
    sprintf(message_buffer, "This is a test email.\r\n");
    send(sockfd, message_buffer, strlen(message_buffer), 0);

    // Close connection
    close(sockfd);

    return 0;
}