//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <sys/socket.h>
#include <netinet/in.h>

static bool imap_login(int sockfd, const char *username, const char *password)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A1 LOGIN %s %s\r\n", username, password);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return false;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        return false;
    }
    buf[n] = '\0';

    if (strncmp(buf, "+OK LOGIN completed", 18) != 0) {
        fprintf(stderr, "IMAP login failed: %s\n", buf);
        return false;
    }

    return true;
}

static bool imap_select(int sockfd, const char *mailbox)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A1 SELECT %s\r\n", mailbox);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return false;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        return false;
    }
    buf[n] = '\0';

    if (strncmp(buf, "+OK [READ-ONLY] ", 17) != 0) {
        fprintf(stderr, "IMAP select failed: %s\n", buf);
        return false;
    }

    return true;
}

static bool imap_fetch(int sockfd, const char *msg_id, const char *part)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A1 FETCH %s (BODY[%s])\r\n", msg_id, part);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return false;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        return false;
    }
    buf[n] = '\0';

    if (strncmp(buf, "+OK FETCH completed", 19) != 0) {
        fprintf(stderr, "IMAP fetch failed: %s\n", buf);
        return false;
    }

    return true;
}

static bool imap_logout(int sockfd)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A1 LOGOUT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return false;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n < 0) {
        perror("recv");
        return false;
    }
    buf[n] = '\0';

    if (strncmp(buf, "+OK LOGOUT completed", 21) != 0) {
        fprintf(stderr, "IMAP logout failed: %s\n", buf);
        return false;
    }

    return true;
}

static void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s <server> <port> <username> <password> <mailbox> <msg_id> <part>\n", progname);
    fprintf(stderr, "  <server>   The IMAP server hostname or IP address.\n");
    fprintf(stderr, "  <port>     The IMAP server port number.\n");
    fprintf(stderr, "  <username> The IMAP username.\n");
    fprintf(stderr, "  <password> The IMAP password.\n");
    fprintf(stderr, "  <mailbox>   The IMAP mailbox to select.\n");
    fprintf(stderr, "  <msg_id>    The IMAP message ID to fetch.\n");
    fprintf(stderr, "  <part>      The IMAP message part to fetch (e.g., BODY[TEXT]).\n");
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in server_addr;

    if (argc != 8) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    if (!imap_login(sockfd, argv[3], argv[4])) {
        return EXIT_FAILURE;
    }

    if (!imap_select(sockfd, argv[5])) {
        return EXIT_FAILURE;
    }

    if (!imap_fetch(sockfd, argv[6], argv[7])) {
        return EXIT_FAILURE;
    }

    if (!imap_logout(sockfd)) {
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}