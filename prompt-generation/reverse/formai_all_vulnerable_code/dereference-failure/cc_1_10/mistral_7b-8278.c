//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

struct smtp_message {
    char from[100];
    char to[100];
    char subject[100];
    char body[500];
};

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <from_email> <to_email> <subject> <message>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sockfd, portno;
    char buffer[BUFFER_SIZE];
    struct smtp_message msg;

    // Initialize message
    strcpy(msg.from, argv[1]);
    strcpy(msg.to, argv[2]);
    strcpy(msg.subject, argv[3]);
    strcpy(msg.body, argv[4]);

    // Prepare the SMTP header
    char header[1024];
    sprintf(header, "HELO %s\r\n"
                    "MAIL FROM: <%s>\r\n"
                    "RCPT TO: <%s>\r\n"
                    "DATA\r\n", "RuinedWorldSurvivors.com", msg.from, msg.to);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to SMTP server");
        close(sockfd);
        return 1;
    }

    // Send the SMTP greeting
    write(sockfd, "ECHO: Hi, we're the Ruined World Survivors, please let us send an email.\r\n", strlen("ECHO: Hi, we're the Ruined World Survivors, please let us send an email.\r\n"));

    // Send the HELO command
    write(sockfd, "HELO RuinedWorldSurvivors.com\r\n", strlen("HELO RuinedWorldSurvivors.com\r\n"));

    // Send the SMTP header
    write(sockfd, header, strlen(header));

    // Send the email data
    sprintf(buffer, "FROM: <%s>\r\n", msg.from);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "TO: <%s>\r\n", msg.to);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "SUBJECT: %s\r\n", msg.subject);
    write(sockfd, buffer, strlen(buffer));
    sprintf(buffer, "\r\n%s\r\n.\r\n", msg.body);
    write(sockfd, buffer, strlen(buffer));

    // Send the QUIT command
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));

    close(sockfd);
    return 0;
}