//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143
#define IMAP_OK "OK"
#define IMAP_BAD "BAD"
#define IMAP_NO "NO"
#define CRLF "\r\n"

typedef struct {
    int sockfd;
    char *host;
    int port;
} IMAPClient;

IMAPClient *imap_client_new(char *host, int port) {
    IMAPClient *client = malloc(sizeof(IMAPClient));
    if (client == NULL) {
        return NULL;
    }

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        free(client);
        return NULL;
    }

    client->host = strdup(host);
    client->port = port;

    return client;
}

void imap_client_free(IMAPClient *client) {
    close(client->sockfd);
    free(client->host);
    free(client);
}

int imap_client_connect(IMAPClient *client) {
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    addr.sin_addr.s_addr = inet_addr(client->host);

    return connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr));
}

char *imap_client_send_command(IMAPClient *client, char *command) {
    char *response = NULL;
    ssize_t length;

    length = send(client->sockfd, command, strlen(command), 0);
    if (length < 0) {
        return NULL;
    }

    length = recv(client->sockfd, response, 4096, 0);
    if (length < 0) {
        return NULL;
    }

    response[length] = '\0';

    return response;
}

int main(int argc, char **argv) {
    IMAPClient *client;
    char *response;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return EXIT_FAILURE;
    }

    client = imap_client_new(argv[1], atoi(argv[2]));
    if (client == NULL) {
        fprintf(stderr, "Failed to create IMAP client\n");
        return EXIT_FAILURE;
    }

    if (imap_client_connect(client) < 0) {
        fprintf(stderr, "Failed to connect to IMAP server\n");
        imap_client_free(client);
        return EXIT_FAILURE;
    }

    response = imap_client_send_command(client, "CAPABILITY" CRLF);
    if (response == NULL) {
        fprintf(stderr, "Failed to send CAPABILITY command\n");
        imap_client_free(client);
        return EXIT_FAILURE;
    }

    printf("IMAP server capabilities:\n%s", response);

    imap_client_free(client);

    return EXIT_SUCCESS;
}