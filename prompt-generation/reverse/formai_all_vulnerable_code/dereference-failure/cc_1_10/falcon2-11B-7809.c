//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void sendEmail(const char* from, const char* to, const char* subject, const char* body) {
    // Connect to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Create a socket address structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(25);
    server.sin_addr.s_addr = inet_addr("smtp.example.com");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the email
    sendmail(sockfd, from, to, subject, body);

    // Close the socket
    close(sockfd);
}

int sendmail(int sockfd, const char* from, const char* to, const char* subject, const char* body) {
    char msg[4096];
    snprintf(msg, sizeof(msg), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", from, to, subject, body);

    // Send the email headers
    write(sockfd, msg, strlen(msg));

    // Send the email body
    write(sockfd, body, strlen(body));

    // Send the end of the email
    write(sockfd, "\r\n.\r\n", 5);

    // Close the socket
    close(sockfd);
}

int main(int argc, char** argv) {
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s from to subject body\n", argv[0]);
        exit(1);
    }

    sendEmail(argv[1], argv[2], argv[3], argv[4]);

    return 0;
}