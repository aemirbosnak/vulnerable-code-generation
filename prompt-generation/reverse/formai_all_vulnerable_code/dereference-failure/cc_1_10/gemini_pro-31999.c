//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <arpa/inet.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define POP3_PORT 110

static bool is_valid_user(const char *user) {
    return strlen(user) <= 64 && strchr(user, '@') != NULL;
}

static bool is_valid_pass(const char *pass) {
    return strlen(pass) <= 64;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server-ip> <user> <pass>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    const char *user = argv[2];
    const char *pass = argv[3];

    if (!is_valid_user(user)) {
        fprintf(stderr, "Invalid user: %s\n", user);
        return EXIT_FAILURE;
    }

    if (!is_valid_pass(pass)) {
        fprintf(stderr, "Invalid pass: %s\n", pass);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    int n = 0;
    while ((n = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "USER %s\r\n", user);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    n = 0;
    while ((n = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    n = 0;
    while ((n = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    n = 0;
    while ((n = read(sockfd, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}