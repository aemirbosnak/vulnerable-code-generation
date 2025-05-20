//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

typedef struct {
    int sockfd;
    char *host;
    int port;
} email_client;

email_client *email_client_create(const char *host, int port) {
    email_client *client = malloc(sizeof(email_client));
    if (!client) {
        perror("malloc");
        return NULL;
    }

    client->sockfd = -1;
    client->host = strdup(host);
    client->port = port;

    return client;
}

void email_client_destroy(email_client *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client->host);
    free(client);
}

int email_client_connect(email_client *client) {
    struct sockaddr_in servaddr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(client->host);
    servaddr.sin_port = htons(client->port);

    if (connect(client->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return -1;
    }

    return 0;
}

int email_client_send_command(email_client *client, const char *command) {
    int len = strlen(command);

    if (write(client->sockfd, command, len) != len) {
        perror("write");
        return -1;
    }

    return 0;
}

int email_client_recv_response(email_client *client, char *buf, size_t bufsize) {
    int len = read(client->sockfd, buf, bufsize - 1);
    if (len == -1) {
        perror("read");
        return -1;
    }

    buf[len] = '\0';

    return len;
}

int email_client_send_email(email_client *client, const char *from, const char *to, const char *subject, const char *body) {
    char buf[BUFSIZE];

    snprintf(buf, BUFSIZE, "MAIL FROM: <%s>\r\n", from);
    if (email_client_send_command(client, buf) == -1) {
        return -1;
    }

    snprintf(buf, BUFSIZE, "RCPT TO: <%s>\r\n", to);
    if (email_client_send_command(client, buf) == -1) {
        return -1;
    }

    if (email_client_send_command(client, "DATA\r\n") == -1) {
        return -1;
    }

    snprintf(buf, BUFSIZE, "Subject: %s\r\n", subject);
    if (email_client_send_command(client, buf) == -1) {
        return -1;
    }

    if (email_client_send_command(client, body) == -1) {
        return -1;
    }

    if (email_client_send_command(client, "\r\n.\r\n") == -1) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    email_client *client;
    char buf[BUFSIZE];
    int len;

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <host> <port> <from> <to> [subject] [body]\n", argv[0]);
        return 1;
    }

    client = email_client_create(argv[1], atoi(argv[2]));
    if (!client) {
        return 1;
    }

    if (email_client_connect(client) == -1) {
        email_client_destroy(client);
        return 1;
    }

    len = email_client_recv_response(client, buf, BUFSIZE);
    if (len == -1) {
        email_client_destroy(client);
        return 1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected response from server: %s\n", buf);
        email_client_destroy(client);
        return 1;
    }

    if (email_client_send_email(client, argv[3], argv[4], argv[5], argv[6]) == -1) {
        email_client_destroy(client);
        return 1;
    }

    len = email_client_recv_response(client, buf, BUFSIZE);
    if (len == -1) {
        email_client_destroy(client);
        return 1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected response from server: %s\n", buf);
        email_client_destroy(client);
        return 1;
    }

    email_client_destroy(client);

    return 0;
}