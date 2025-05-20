//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

typedef struct {
    char *host;
    int port;
    char *username;
    char *password;
} IMAP_CONFIG;

typedef struct {
    int fd;
    char *buffer;
} IMAP_CLIENT;

IMAP_CLIENT *imap_client_create(IMAP_CONFIG *config) {
    IMAP_CLIENT *client = malloc(sizeof(IMAP_CLIENT));
    if (client == NULL) {
        return NULL;
    }

    client->fd = -1;
    client->buffer = NULL;

    client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->fd < 0) {
        free(client);
        return NULL;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config->port);
    server_addr.sin_addr.s_addr = inet_addr(config->host);

    if (connect(client->fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        close(client->fd);
        free(client);
        return NULL;
    }

    client->buffer = malloc(MAX_SIZE);
    if (client->buffer == NULL) {
        close(client->fd);
        free(client);
        return NULL;
    }

    return client;
}

void imap_client_destroy(IMAP_CLIENT *client) {
    if (client == NULL) {
        return;
    }

    if (client->fd >= 0) {
        close(client->fd);
    }

    if (client->buffer != NULL) {
        free(client->buffer);
    }

    free(client);
}

int imap_client_send(IMAP_CLIENT *client, char *command) {
    if (client == NULL || command == NULL) {
        return -1;
    }

    int len = strlen(command);
    if (send(client->fd, command, len, 0) != len) {
        return -1;
    }

    return 0;
}

int imap_client_recv(IMAP_CLIENT *client) {
    if (client == NULL) {
        return -1;
    }

    int len = recv(client->fd, client->buffer, MAX_SIZE, 0);
    if (len < 0) {
        return -1;
    }

    client->buffer[len] = '\0';

    return len;
}

int imap_client_login(IMAP_CLIENT *client, IMAP_CONFIG *config) {
    if (client == NULL || config == NULL) {
        return -1;
    }

    if (imap_client_send(client, "LOGIN") < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    if (imap_client_send(client, config->username) < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    if (imap_client_send(client, config->password) < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    return 0;
}

int imap_client_select(IMAP_CLIENT *client, char *mailbox) {
    if (client == NULL || mailbox == NULL) {
        return -1;
    }

    if (imap_client_send(client, "SELECT") < 0) {
        return -1;
    }

    if (imap_client_send(client, mailbox) < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    return 0;
}

int imap_client_search(IMAP_CLIENT *client, char *query) {
    if (client == NULL || query == NULL) {
        return -1;
    }

    if (imap_client_send(client, "SEARCH") < 0) {
        return -1;
    }

    if (imap_client_send(client, query) < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    return 0;
}

int imap_client_fetch(IMAP_CLIENT *client, char *uid, char *part) {
    if (client == NULL || uid == NULL || part == NULL) {
        return -1;
    }

    if (imap_client_send(client, "FETCH") < 0) {
        return -1;
    }

    if (imap_client_send(client, uid) < 0) {
        return -1;
    }

    if (imap_client_send(client, "BODY") < 0) {
        return -1;
    }

    if (imap_client_send(client, part) < 0) {
        return -1;
    }

    if (imap_client_recv(client) < 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    IMAP_CONFIG config = {
        .host = argv[1],
        .port = atoi(argv[2]),
        .username = argv[3],
        .password = argv[4]
    };

    IMAP_CLIENT *client = imap_client_create(&config);
    if (client == NULL) {
        printf("Failed to create IMAP client\n");
        return 1;
    }

    if (imap_client_login(client, &config) < 0) {
        printf("Failed to login to IMAP server\n");
        imap_client_destroy(client);
        return 1;
    }

    if (imap_client_select(client, "Inbox") < 0) {
        printf("Failed to select Inbox folder\n");
        imap_client_destroy(client);
        return 1;
    }

    if (imap_client_search(client, "UNSEEN") < 0) {
        printf("Failed to search for unseen emails\n");
        imap_client_destroy(client);
        return 1;
    }

    char *uid = strtok(client->buffer, " ");
    while (uid != NULL) {
        if (imap_client_fetch(client, uid, "TEXT") < 0) {
            printf("Failed to fetch email text\n");
            imap_client_destroy(client);
            return 1;
        }

        printf("%s\n", client->buffer);

        uid = strtok(NULL, " ");
    }

    imap_client_destroy(client);

    return 0;
}