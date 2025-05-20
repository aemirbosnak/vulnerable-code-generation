//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

struct imap_client {
    int sockfd;
    char *hostname;
    int port;
    char *username;
    char *password;
};

struct imap_client *imap_client_new(char *hostname, int port, char *username, char *password)
{
    struct imap_client *client = malloc(sizeof(*client));
    if (!client) {
        perror("malloc");
        return NULL;
    }

    client->sockfd = -1;
    client->hostname = hostname;
    client->port = port;
    client->username = username;
    client->password = password;

    return client;
}

void imap_client_free(struct imap_client *client)
{
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client);
}

int imap_client_connect(struct imap_client *client)
{
    struct sockaddr_in server_addr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    server_addr.sin_addr.s_addr = inet_addr(client->hostname);

    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    return 0;
}

int imap_client_login(struct imap_client *client)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A0 CAPABILITY\r\n");
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
        buf[n] = '\0';
        if (strstr(buf, "IMAP4rev1")) {
            break;
        }
    }

    if (n == -1) {
        perror("recv");
        return -1;
    }

    snprintf(buf, sizeof(buf), "A1 LOGIN %s %s\r\n", client->username, client->password);
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
        buf[n] = '\0';
        if (strstr(buf, "OK LOGIN completed")) {
            break;
        }
    }

    if (n == -1) {
        perror("recv");
        return -1;
    }

    return 0;
}

int imap_client_list_mailboxes(struct imap_client *client)
{
    char buf[1024];
    int n;

    snprintf(buf, sizeof(buf), "A2 LIST \"\" *\r\n");
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
        buf[n] = '\0';
        printf("%s\n", buf);
    }

    if (n == -1) {
        perror("recv");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv)
{
    struct imap_client *client;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    client = imap_client_new(argv[1], atoi(argv[2]), argv[3], argv[4]);
    if (!client) {
        return EXIT_FAILURE;
    }

    if (imap_client_connect(client) == -1) {
        imap_client_free(client);
        return EXIT_FAILURE;
    }

    if (imap_client_login(client) == -1) {
        imap_client_free(client);
        return EXIT_FAILURE;
    }

    if (imap_client_list_mailboxes(client) == -1) {
        imap_client_free(client);
        return EXIT_FAILURE;
    }

    imap_client_free(client);

    return EXIT_SUCCESS;
}