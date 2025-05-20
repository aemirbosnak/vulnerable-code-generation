//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define DEFAULT_PORT 110
#define MAX_LINE 1024

static int get_line(int sock, char *buf, int size) {
    int i = 0;
    char c;
    while ((i < size - 1) && (c = getchar()) != '\n')
        buf[i++] = c;
    buf[i] = '\0';
    return i;
}

static void pop3_login(int sock, const char *username, const char *password) {
    char buf[MAX_LINE];
    int n;
    fprintf(stderr, "USER %s\n", username);
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);
    if (strncmp(buf, "+OK", 3) != 0) return;

    fprintf(stderr, "PASS %s\n", password);
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);
}

static void pop3_list(int sock) {
    char buf[MAX_LINE];
    int n;

    fprintf(stderr, "LIST\n");
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);

    while ((n = get_line(sock, buf, MAX_LINE)) > 0) {
        fprintf(stdout, "%s\n", buf);
        if (strncmp(buf, ".", 1) == 0) break;
    }
}

static void pop3_retr(int sock, int msg_num) {
    char buf[MAX_LINE];
    int n;

    fprintf(stderr, "RETR %d\n", msg_num);
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);

    if (strncmp(buf, "+OK", 3) != 0) return;

    while ((n = get_line(sock, buf, MAX_LINE)) > 0) {
        fprintf(stdout, "%s\n", buf);
        if (strncmp(buf, ".", 1) == 0) break;
    }
}

static void pop3_dele(int sock, int msg_num) {
    char buf[MAX_LINE];
    int n;

    fprintf(stderr, "DELE %d\n", msg_num);
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);
}

static void pop3_quit(int sock) {
    char buf[MAX_LINE];
    int n;
    fprintf(stderr, "QUIT\n");
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) return;
    fprintf(stderr, "%s\n", buf);
}

int main(int argc, char **argv) {
    int sock, port;
    struct sockaddr_in server_addr;
    char *server_name, *username, *password;
    int msg_num;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password> [<port>] [<msg_num>]\n", argv[0]);
        exit(1);
    }

    server_name = argv[1];
    username = argv[2];
    password = argv[3];

    if (argc > 4) port = atoi(argv[4]);
    else port = DEFAULT_PORT;

    if (argc > 5) msg_num = atoi(argv[5]);
    else msg_num = -1;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_name, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buf[MAX_LINE];
    int n;
    if ((n = get_line(sock, buf, MAX_LINE)) <= 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }
    fprintf(stderr, "%s\n", buf);

    pop3_login(sock, username, password);
    pop3_list(sock);
    if (msg_num >= 0) {
        pop3_retr(sock, msg_num);
        pop3_dele(sock, msg_num);
    }
    pop3_quit(sock);

    close(sock);
    exit(0);
}