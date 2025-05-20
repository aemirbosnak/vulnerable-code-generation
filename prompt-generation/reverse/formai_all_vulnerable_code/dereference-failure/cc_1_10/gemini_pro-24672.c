//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

typedef struct {
    int sockfd;
    char *host;
    int port;
    char *username;
    char *password;
} IMAPClient;

IMAPClient *imap_client_init(char *host, int port, char *username, char *password) {
    IMAPClient *client = malloc(sizeof(IMAPClient));
    client->sockfd = -1;
    client->host = host;
    client->port = port;
    client->username = username;
    client->password = password;
    return client;
}

int imap_client_connect(IMAPClient *client) {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        return -1;
    }

    server = gethostbyname(client->host);
    if (server == NULL) {
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(client->port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(client->sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return -1;
    }

    return 0;
}

int imap_client_login(IMAPClient *client) {
    char buf[1024];
    int len;

    len = sprintf(buf, "A001 LOGIN %s %s\r\n", client->username, client->password);
    if (send(client->sockfd, buf, len, 0) < 0) {
        return -1;
    }

    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        return -1;
    }

    if (strncmp(buf, "+OK LOGIN completed", 18) != 0) {
        return -1;
    }

    return 0;
}

int imap_client_select(IMAPClient *client, char *mailbox) {
    char buf[1024];
    int len;

    len = sprintf(buf, "A002 SELECT %s\r\n", mailbox);
    if (send(client->sockfd, buf, len, 0) < 0) {
        return -1;
    }

    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        return -1;
    }

    if (strncmp(buf, "+OK [READ-ONLY] ", 16) != 0) {
        return -1;
    }

    return 0;
}

int imap_client_fetch(IMAPClient *client, int msg_num, char *part) {
    char buf[1024];
    int len;

    len = sprintf(buf, "A003 FETCH %d (BODY.PEEK[%s])\r\n", msg_num, part);
    if (send(client->sockfd, buf, len, 0) < 0) {
        return -1;
    }

    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        return -1;
    }

    if (strncmp(buf, "+OK FETCH completed", 18) != 0) {
        return -1;
    }

    return 0;
}

int imap_client_logout(IMAPClient *client) {
    char buf[1024];
    int len;

    len = sprintf(buf, "A004 LOGOUT\r\n");
    if (send(client->sockfd, buf, len, 0) < 0) {
        return -1;
    }

    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len < 0) {
        return -1;
    }

    if (strncmp(buf, "+OK LOGOUT completed", 20) != 0) {
        return -1;
    }

    return 0;
}

int imap_client_close(IMAPClient *client) {
    close(client->sockfd);
    free(client);
    return 0;
}

int main(int argc, char **argv) {
    IMAPClient *client;
    int ret;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s host port username password\n", argv[0]);
        return -1;
    }

    client = imap_client_init(argv[1], atoi(argv[2]), argv[3], argv[4]);
    ret = imap_client_connect(client);
    if (ret < 0) {
        fprintf(stderr, "imap_client_connect() failed\n");
        return -1;
    }

    ret = imap_client_login(client);
    if (ret < 0) {
        fprintf(stderr, "imap_client_login() failed\n");
        return -1;
    }

    ret = imap_client_select(client, "INBOX");
    if (ret < 0) {
        fprintf(stderr, "imap_client_select() failed\n");
        return -1;
    }

    ret = imap_client_fetch(client, 1, "HEADER");
    if (ret < 0) {
        fprintf(stderr, "imap_client_fetch() failed\n");
        return -1;
    }

    ret = imap_client_logout(client);
    if (ret < 0) {
        fprintf(stderr, "imap_client_logout() failed\n");
        return -1;
    }

    ret = imap_client_close(client);
    if (ret < 0) {
        fprintf(stderr, "imap_client_close() failed\n");
        return -1;
    }

    return 0;
}