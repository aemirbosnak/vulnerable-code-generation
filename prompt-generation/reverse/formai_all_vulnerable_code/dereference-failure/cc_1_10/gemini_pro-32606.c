//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

/* Initialise the POP3 client */
int pop3_init(const char *host, int port) {
    int fd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        return -1;
    }
    server = gethostbyname(host);
    if (server == NULL) {
        return -1;
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        close(fd);
        return -1;
    }
    return fd;
}

/* Execute a command on the POP3 server */
int pop3_cmd(int fd, const char *cmd, char *resp, size_t resp_len) {
    int n;
    char buf[1024];

    if (send(fd, cmd, strlen(cmd), 0) < 0) {
        return -1;
    }

    n = recv(fd, buf, sizeof(buf), 0);
    if (n < 0) {
        return -1;
    }

    buf[n] = 0;
    snprintf(resp, resp_len, "%s", buf);
    return 0;
}

/* Retrieve a message from the POP3 server */
int pop3_retr(int fd, int msg_num, char *msg, size_t msg_len) {
    int n;
    char buf[1024];

    snprintf(buf, sizeof(buf), "RETR %d\r\n", msg_num);

    if (send(fd, buf, strlen(buf), 0) < 0) {
        return -1;
    }

    n = recv(fd, msg, msg_len, 0);
    if (n < 0) {
        return -1;
    }

    msg[n] = 0;
    return 0;
}

/* Delete a message from the POP3 server */
int pop3_dele(int fd, int msg_num) {
    char buf[1024];

    snprintf(buf, sizeof(buf), "DELE %d\r\n", msg_num);

    if (send(fd, buf, strlen(buf), 0) < 0) {
        return -1;
    }

    return 0;
}

/* Quit the POP3 session */
int pop3_quit(int fd) {
    int n;
    char buf[1024];

    if (send(fd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        return -1;
    }

    n = recv(fd, buf, sizeof(buf), 0);
    if (n < 0) {
        return -1;
    }

    close(fd);
    return 0;
}

int main(int argc, char **argv) {
    int fd;
    char resp[1024];
    char msg[10240];

    fd = pop3_init("pop.example.com", 110);
    if (fd < 0) {
        fprintf(stderr, "Error initialising POP3 client: %s\n", strerror(errno));
        return 1;
    }

    if (pop3_cmd(fd, "USER me@example.com\r\n", resp, sizeof(resp)) < 0) {
        fprintf(stderr, "Error sending USER command: %s\n", strerror(errno));
        return 1;
    }

    if (pop3_cmd(fd, "PASS my_password\r\n", resp, sizeof(resp)) < 0) {
        fprintf(stderr, "Error sending PASS command: %s\n", strerror(errno));
        return 1;
    }

    if (pop3_cmd(fd, "STAT\r\n", resp, sizeof(resp)) < 0) {
        fprintf(stderr, "Error sending STAT command: %s\n", strerror(errno));
        return 1;
    }

    printf("There are %s messages on the server.\n", resp);

    if (pop3_retr(fd, 1, msg, sizeof(msg)) < 0) {
        fprintf(stderr, "Error retrieving message: %s\n", strerror(errno));
        return 1;
    }

    printf("%s", msg);

    if (pop3_dele(fd, 1) < 0) {
        fprintf(stderr, "Error deleting message: %s\n", strerror(errno));
        return 1;
    }

    if (pop3_quit(fd) < 0) {
        fprintf(stderr, "Error quitting POP3 session: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}