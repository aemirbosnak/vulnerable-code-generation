//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

typedef struct {
    int sockfd;
    char *host;
    int port;
} SMTP_CLIENT;

SMTP_CLIENT *smtp_client_new(char *host, int port) {
    SMTP_CLIENT *client = malloc(sizeof(SMTP_CLIENT));
    if (client == NULL) {
        return NULL;
    }

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        free(client);
        return NULL;
    }

    client->host = strdup(host);
    if (client->host == NULL) {
        close(client->sockfd);
        free(client);
        return NULL;
    }

    client->port = port;

    return client;
}

int smtp_client_connect(SMTP_CLIENT *client) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(client->port);
    server_addr.sin_addr.s_addr = inet_addr(client->host);

    int ret = connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_hello(SMTP_CLIENT *client) {
    char hello[1024];
    snprintf(hello, sizeof(hello), "HELO %s\r\n", client->host);

    int ret = send(client->sockfd, hello, strlen(hello), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_mail_from(SMTP_CLIENT *client, char *sender) {
    char mail_from[1024];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", sender);

    int ret = send(client->sockfd, mail_from, strlen(mail_from), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_rcpt_to(SMTP_CLIENT *client, char *recipient) {
    char rcpt_to[1024];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", recipient);

    int ret = send(client->sockfd, rcpt_to, strlen(rcpt_to), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_data(SMTP_CLIENT *client) {
    char data[1024];
    snprintf(data, sizeof(data), "DATA\r\n");

    int ret = send(client->sockfd, data, strlen(data), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_message(SMTP_CLIENT *client, char *message) {
    char message_end[1024];
    snprintf(message_end, sizeof(message_end), "\r\n.\r\n");

    int ret = send(client->sockfd, message, strlen(message), 0);
    if (ret == -1) {
        return -1;
    }

    ret = send(client->sockfd, message_end, strlen(message_end), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

int smtp_client_send_quit(SMTP_CLIENT *client) {
    char quit[1024];
    snprintf(quit, sizeof(quit), "QUIT\r\n");

    int ret = send(client->sockfd, quit, strlen(quit), 0);
    if (ret == -1) {
        return -1;
    }

    return 0;
}

void smtp_client_free(SMTP_CLIENT *client) {
    if (client == NULL) {
        return;
    }

    if (client->sockfd != -1) {
        close(client->sockfd);
    }

    if (client->host != NULL) {
        free(client->host);
    }

    free(client);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <host> <port> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    SMTP_CLIENT *client = smtp_client_new(argv[1], atoi(argv[2]));
    if (client == NULL) {
        fprintf(stderr, "Failed to create SMTP client\n");
        return 1;
    }

    if (smtp_client_connect(client) != 0) {
        fprintf(stderr, "Failed to connect to SMTP server\n");
        smtp_client_free(client);
        return 1;
    }

    if (smtp_client_send_hello(client) != 0) {
        fprintf(stderr, "Failed to send HELO command\n");
        smtp_client_free(client);
        return 1;
    }

    if (smtp_client_send_mail_from(client, argv[3]) != 0) {
        fprintf(stderr, "Failed to send MAIL FROM command\n");
        smtp_client_free(client);
        return 1;
    }

    if (smtp_client_send_rcpt_to(client, argv[4]) != 0) {
        fprintf(stderr, "Failed to send RCPT TO command\n");
        smtp_client_free(client);
        return 1;
    }

    if (smtp_client_send_data(client) != 0) {
        fprintf(stderr, "Failed to send DATA command\n");
        smtp_client_free(client);
        return 1;
    }

    char message[1024];
    snprintf(message, sizeof(message), "Subject: Test Email\n\nThis is a test email sent from a C program.\n");

    if (smtp_client_send_message(client, message) != 0) {
        fprintf(stderr, "Failed to send message\n");
        smtp_client_free(client);
        return 1;
    }

    if (smtp_client_send_quit(client) != 0) {
        fprintf(stderr, "Failed to send QUIT command\n");
        smtp_client_free(client);
        return 1;
    }

    smtp_client_free(client);

    return 0;
}