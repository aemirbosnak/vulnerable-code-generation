//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 25

struct smtp_client {
    int sockfd;
    char *host;
    int port;
};

struct smtp_client *smtp_client_create(char *host, int port) {
    struct smtp_client *client = malloc(sizeof(struct smtp_client));
    if (client == NULL) {
        return NULL;
    }

    client->sockfd = -1;
    client->host = strdup(host);
    client->port = port;

    return client;
}

int smtp_client_connect(struct smtp_client *client) {
    struct sockaddr_in addr;
    struct hostent *host_info;

    host_info = gethostbyname(client->host);
    if (host_info == NULL) {
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    addr.sin_addr = *(struct in_addr *)host_info->h_addr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        return -1;
    }

    if (connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(client->sockfd);
        client->sockfd = -1;
        return -1;
    }

    return 0;
}

int smtp_client_send(struct smtp_client *client, char *data) {
    int len = strlen(data);
    if (send(client->sockfd, data, len, 0) != len) {
        return -1;
    }
    return 0;
}

int smtp_client_recv(struct smtp_client *client, char *buf, int len) {
    int n = recv(client->sockfd, buf, len, 0);
    if (n <= 0) {
        return -1;
    }
    buf[n] = '\0';
    return n;
}

int smtp_client_close(struct smtp_client *client) {
    close(client->sockfd);
    client->sockfd = -1;
    free(client->host);
    free(client);
    return 0;
}

int main(int argc, char *argv[]) {
    struct smtp_client *client;
    char buf[1024];

    if (argc != 4) {
        printf("Usage: %s host port message\n", argv[0]);
        return 1;
    }

    client = smtp_client_create(argv[1], atoi(argv[2]));
    if (client == NULL) {
        printf("Error: Could not create SMTP client\n");
        return 1;
    }

    if (smtp_client_connect(client) != 0) {
        printf("Error: Could not connect to SMTP server\n");
        smtp_client_close(client);
        return 1;
    }

    printf("connected to %s:%d\n", client->host, client->port);

    smtp_client_send(client, "HELO world\n");
    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_send(client, "MAIL FROM: <test@example.com>\n");
    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_send(client, "RCPT TO: <test@example.com>\n");
    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_send(client, "DATA\n");
    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_send(client, "To: test@example.com\n");
    smtp_client_send(client, "From: test@example.com\n");
    smtp_client_send(client, "Subject: Test message\n");
    smtp_client_send(client, "\n");
    smtp_client_send(client, "This is a test message.\n");
    smtp_client_send(client, ".\n");

    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_send(client, "QUIT\n");
    smtp_client_recv(client, buf, sizeof(buf));
    printf("%s", buf);

    smtp_client_close(client);
    return 0;
}