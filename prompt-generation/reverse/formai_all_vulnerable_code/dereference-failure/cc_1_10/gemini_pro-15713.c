//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 993

struct imap_client {
    int sockfd;
    char *host;
    int port;
    char *username;
    char *password;
};

static int imap_client_connect(struct imap_client *client)
{
    struct sockaddr_in addr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    addr.sin_addr.s_addr = inet_addr(client->host);

    if (connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    return 0;
}

static int imap_client_auth(struct imap_client *client)
{
    char buf[1024];

    snprintf(buf, sizeof(buf), "A001 AUTHENTICATE LOGIN\r\n");
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    snprintf(buf, sizeof(buf), "%s\r\n", client->username);
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    snprintf(buf, sizeof(buf), "%s\r\n", client->password);
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

static int imap_client_select(struct imap_client *client, const char *mailbox)
{
    char buf[1024];

    snprintf(buf, sizeof(buf), "A002 SELECT %s\r\n", mailbox);
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

static int imap_client_fetch(struct imap_client *client, const char *msg_id)
{
    char buf[1024];

    snprintf(buf, sizeof(buf), "A003 FETCH %s BODY[TEXT]\r\n", msg_id);
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

static int imap_client_logout(struct imap_client *client)
{
    char buf[1024];

    snprintf(buf, sizeof(buf), "A004 LOGOUT\r\n");
    if (write(client->sockfd, buf, strlen(buf)) == -1) {
        perror("write");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) == -1) {
        perror("read");
        return -1;
    }

    return 0;
}

static void imap_client_free(struct imap_client *client)
{
    close(client->sockfd);
    free(client->host);
    free(client->username);
    free(client->password);
    free(client);
}

int main(int argc, char **argv)
{
    struct imap_client client;
    int ret;

    if (argc != 6) {
        fprintf(stderr, "Usage: %s <host> <port> <username> <password> <mailbox>\n", argv[0]);
        return -1;
    }

    client.host = strdup(argv[1]);
    client.port = atoi(argv[2]);
    client.username = strdup(argv[3]);
    client.password = strdup(argv[4]);

    ret = imap_client_connect(&client);
    if (ret != 0) {
        fprintf(stderr, "imap_client_connect failed: %d\n", ret);
        return -1;
    }

    ret = imap_client_auth(&client);
    if (ret != 0) {
        fprintf(stderr, "imap_client_auth failed: %d\n", ret);
        return -1;
    }

    ret = imap_client_select(&client, argv[5]);
    if (ret != 0) {
        fprintf(stderr, "imap_client_select failed: %d\n", ret);
        return -1;
    }

    ret = imap_client_fetch(&client, "1");
    if (ret != 0) {
        fprintf(stderr, "imap_client_fetch failed: %d\n", ret);
        return -1;
    }

    ret = imap_client_logout(&client);
    if (ret != 0) {
        fprintf(stderr, "imap_client_logout failed: %d\n", ret);
        return -1;
    }

    imap_client_free(&client);

    return 0;
}