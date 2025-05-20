//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <ctype.h>

#define IMAP_PORT 143

typedef struct {
    int sockfd;
    char *hostname;
    char *username;
    char *password;
} imap_client_t;

imap_client_t *imap_client_create(char *hostname, char *username, char *password) {
    imap_client_t *client = malloc(sizeof(imap_client_t));
    if (client == NULL) {
        perror("malloc");
        return NULL;
    }

    client->sockfd = -1;
    client->hostname = strdup(hostname);
    client->username = strdup(username);
    client->password = strdup(password);

    return client;
}

void imap_client_destroy(imap_client_t *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client->hostname);
    free(client->username);
    free(client->password);
    free(client);
}

int imap_client_connect(imap_client_t *client) {
    struct hostent *host = gethostbyname(client->hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(IMAP_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        return -1;
    }

    if (connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(client->sockfd);
        client->sockfd = -1;
        return -1;
    }

    return 0;
}

int imap_client_login(imap_client_t *client) {
    char buf[1024];

    // Send LOGIN command
    snprintf(buf, sizeof(buf), "LOGIN %s %s\r\n", client->username, client->password);
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    // Read response
    if (recv(client->sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return -1;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "LOGIN failed: %s\n", buf);
        return -1;
    }

    return 0;
}

int imap_client_select(imap_client_t *client, char *mailbox) {
    char buf[1024];

    // Send SELECT command
    snprintf(buf, sizeof(buf), "SELECT %s\r\n", mailbox);
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    // Read response
    if (recv(client->sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return -1;
    }

    // Check response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "SELECT failed: %s\n", buf);
        return -1;
    }

    return 0;
}

int imap_client_fetch(imap_client_t *client, int msgid, char **body) {
    char buf[1024];

    // Send FETCH command
    snprintf(buf, sizeof(buf), "FETCH %d BODY[TEXT]\r\n", msgid);
    if (send(client->sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return -1;
    }

    // Read response
    int len = 0;
    char *ptr = NULL;
    while (1) {
        if (recv(client->sockfd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            return -1;
        }

        // Check for end of message
        if (strncmp(buf, "\r\n.\r\n", 5) == 0) {
            break;
        }

        // Grow buffer if necessary
        if (len + strlen(buf) + 1 > *body) {
            *body = realloc(*body, len + strlen(buf) + 1);
            if (*body == NULL) {
                perror("realloc");
                return -1;
            }
            ptr = *body + len;
        }

        // Copy data to buffer
        memcpy(ptr, buf, strlen(buf));
        len += strlen(buf);
        ptr += strlen(buf);
    }

    // Add null terminator
    *ptr = '\0';

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create IMAP client
    imap_client_t *client = imap_client_create(hostname, username, password);
    if (client == NULL) {
        return EXIT_FAILURE;
    }

    // Connect to IMAP server
    if (imap_client_connect(client) != 0) {
        imap_client_destroy(client);
        return EXIT_FAILURE;
    }

    // Login to IMAP server
    if (imap_client_login(client) != 0) {
        imap_client_destroy(client);
        return EXIT_FAILURE;
    }

    // Select INBOX mailbox
    if (imap_client_select(client, "INBOX") != 0) {
        imap_client_destroy(client);
        return EXIT_FAILURE;
    }

    // Fetch first email body
    char *body = NULL;
    if (imap_client_fetch(client, 1, &body) != 0) {
        imap_client_destroy(client);
        return EXIT_FAILURE;
    }

    // Print email body
    printf("%s", body);

    // Cleanup
    imap_client_destroy(client);
    free(body);

    return EXIT_SUCCESS;
}