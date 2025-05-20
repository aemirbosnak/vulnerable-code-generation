//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#define MAX_BUF_SIZE 1024

struct email {
    char *from;
    char *to;
    char *subject;
    char *body;
};

struct email *email_new(const char *from, const char *to, const char *subject, const char *body) {
    struct email *email = malloc(sizeof(struct email));
    if (!email) {
        return NULL;
    }

    email->from = strdup(from);
    email->to = strdup(to);
    email->subject = strdup(subject);
    email->body = strdup(body);

    return email;
}

void email_free(struct email *email) {
    if (!email) {
        return;
    }

    free(email->from);
    free(email->to);
    free(email->subject);
    free(email->body);
    free(email);
}

int email_send(struct email *email, const char *hostname, const int port) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buf[MAX_BUF_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "HELO %s\r\n", hostname);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "MAIL FROM: %s\r\n", email->from);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "RCPT TO: %s\r\n", email->to);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "DATA\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "From: %s\r\n", email->from);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "To: %s\r\n", email->to);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "Subject: %s\r\n", email->subject);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "\r\n%s\r\n", email->body);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), ".\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        return -1;
    }

    close(sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s hostname port from to subject body\n", argv[0]);
        return 1;
    }

    const char *hostname = argv[1];
    const int port = atoi(argv[2]);
    const char *from = argv[3];
    const char *to = argv[4];
    const char *subject = argv[5];

    char *body = NULL;
    size_t body_len = 0;
    while (getline(&body, &body_len, stdin) != -1) {
        body[strcspn(body, "\n")] = '\0';
    }

    struct email *email = email_new(from, to, subject, body);
    if (!email) {
        fprintf(stderr, "Failed to create email\n");
        return 1;
    }

    int rc = email_send(email, hostname, port);
    if (rc < 0) {
        fprintf(stderr, "Failed to send email: %d\n", rc);
        return 1;
    }

    email_free(email);

    return 0;
}