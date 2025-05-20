//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

struct mail_message {
    char *from;
    char *to;
    char *subject;
    char *body;
};

int create_socket(struct sockaddr_in *addr) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    addr->sin_family = AF_INET;
    addr->sin_port = htons(SMTP_PORT);
    addr->sin_addr.s_addr = inet_addr("127.0.0.1");

    return sockfd;
}

int connect_to_server(int sockfd, struct sockaddr_in *addr) {
    if (connect(sockfd, (struct sockaddr *)addr, sizeof(struct sockaddr)) < 0) {
        perror("connect");
        return -1;
    }

    return 0;
}

int send_command(int sockfd, char *command) {
    int len = strlen(command);
    if (send(sockfd, command, len, 0) < len) {
        perror("send");
        return -1;
    }

    return 0;
}

int receive_response(int sockfd, char *buffer, int len) {
    int n = recv(sockfd, buffer, len, 0);
    if (n < 0) {
        perror("recv");
        return -1;
    }

    buffer[n] = '\0';

    return n;
}

int send_mail(int sockfd, struct mail_message *message) {
    char buffer[1024];

    // Send the HELO command
    if (send_command(sockfd, "HELO smtp.example.com\r\n") < 0) {
        return -1;
    }

    // Receive the response
    if (receive_response(sockfd, buffer, sizeof(buffer)) < 0) {
        return -1;
    }

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: %s\r\n", message->from);
    if (send_command(sockfd, buffer) < 0) {
        return -1;
    }

    // Receive the response
    if (receive_response(sockfd, buffer, sizeof(buffer)) < 0) {
        return -1;
    }

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: %s\r\n", message->to);
    if (send_command(sockfd, buffer) < 0) {
        return -1;
    }

    // Receive the response
    if (receive_response(sockfd, buffer, sizeof(buffer)) < 0) {
        return -1;
    }

    // Send the DATA command
    if (send_command(sockfd, "DATA\r\n") < 0) {
        return -1;
    }

    // Receive the response
    if (receive_response(sockfd, buffer, sizeof(buffer)) < 0) {
        return -1;
    }

    // Send the message body
    snprintf(buffer, sizeof(buffer), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n",
             message->from, message->to, message->subject, message->body);
    if (send_command(sockfd, buffer) < 0) {
        return -1;
    }

    // Send the QUIT command
    if (send_command(sockfd, "QUIT\r\n") < 0) {
        return -1;
    }

    // Receive the response
    if (receive_response(sockfd, buffer, sizeof(buffer)) < 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in addr;

    if (argc < 5) {
        printf("Usage: %s from to subject body\n", argv[0]);
        return -1;
    }

    sockfd = create_socket(&addr);
    if (sockfd < 0) {
        return -1;
    }

    if (connect_to_server(sockfd, &addr) < 0) {
        return -1;
    }

    struct mail_message message;
    message.from = argv[1];
    message.to = argv[2];
    message.subject = argv[3];
    message.body = argv[4];

    if (send_mail(sockfd, &message) < 0) {
        return -1;
    }

    close(sockfd);

    return 0;
}