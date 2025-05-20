//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define IMAP_PORT 143
#define IMAP_FLAG_LOGIN "LOGIN"
#define IMAP_FLAG_AUTH "AUTH"
#define IMAP_FLAG_LS "LS"
#define IMAP_FLAG_SELECT "SELECT"
#define IMAP_FLAG_FETCH "FETCH"

struct imap_connection {
    int sockfd;
    char *hostname;
    int port;
};

struct imap_message {
    int uid;
    char *flags;
    char *body;
};

struct imap_connection *imap_connect(char *hostname, int port) {
    struct imap_connection *conn = malloc(sizeof(struct imap_connection));
    if (!conn) {
        return NULL;
    }

    conn->hostname = strdup(hostname);
    if (!conn->hostname) {
        free(conn);
        return NULL;
    }

    conn->port = port;

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(conn->port);
    server_addr.sin_addr.s_addr = inet_addr(conn->hostname);

    conn->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn->sockfd == -1) {
        free(conn->hostname);
        free(conn);
        return NULL;
    }

    if (connect(conn->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        close(conn->sockfd);
        free(conn->hostname);
        free(conn);
        return NULL;
    }

    return conn;
}

int imap_send_command(struct imap_connection *conn, char *command) {
    int len = strlen(command);
    if (send(conn->sockfd, command, len, 0) != len) {
        return -1;
    }

    return 0;
}

char *imap_receive_response(struct imap_connection *conn) {
    char *response = NULL;
    int size = 0;
    int n = 0;

    while ((n = recv(conn->sockfd, response + size, 1024, 0)) > 0) {
        size += n;
        response = realloc(response, size + 1);
        if (!response) {
            return NULL;
        }
    }

    if (n == -1) {
        free(response);
        return NULL;
    }

    response[size] = '\0';
    return response;
}

int imap_login(struct imap_connection *conn, char *username, char *password) {
    char command[1024];
    snprintf(command, sizeof(command), "%s %s %s\r\n", IMAP_FLAG_LOGIN, username, password);

    if (imap_send_command(conn, command) == -1) {
        return -1;
    }

    char *response = imap_receive_response(conn);
    if (!response) {
        return -1;
    }

    if (strncmp(response, "+OK", 3) != 0) {
        free(response);
        return -1;
    }

    free(response);
    return 0;
}

int imap_select_mailbox(struct imap_connection *conn, char *mailbox) {
    char command[1024];
    snprintf(command, sizeof(command), "%s %s\r\n", IMAP_FLAG_SELECT, mailbox);

    if (imap_send_command(conn, command) == -1) {
        return -1;
    }

    char *response = imap_receive_response(conn);
    if (!response) {
        return -1;
    }

    if (strncmp(response, "+OK", 3) != 0) {
        free(response);
        return -1;
    }

    free(response);
    return 0;
}

struct imap_message *imap_fetch_message(struct imap_connection *conn, int uid) {
    char command[1024];
    snprintf(command, sizeof(command), "%s %d (FLAGS BODY.PEEK[])\r\n", IMAP_FLAG_FETCH, uid);

    if (imap_send_command(conn, command) == -1) {
        return NULL;
    }

    char *response = imap_receive_response(conn);
    if (!response) {
        return NULL;
    }

    struct imap_message *message = malloc(sizeof(struct imap_message));
    if (!message) {
        free(response);
        return NULL;
    }

    char *flags = NULL;
    char *body = NULL;
    int size = 0;

    while (strncmp(response + size, "+OK", 3) != 0) {
        size += strlen(response + size) + 1;
    }

    flags = strdup(response + size);
    if (!flags) {
        free(response);
        free(message);
        return NULL;
    }

    size += strlen(flags) + 1;

    while ((strncmp(response + size, "BODY[", 5) != 0) && (strncmp(response + size, "--", 2) != 0)) {
        size += strlen(response + size) + 1;
    }

    body = strdup(response + size);
    if (!body) {
        free(response);
        free(flags);
        free(message);
        return NULL;
    }

    message->uid = uid;
    message->flags = flags;
    message->body = body;

    free(response);

    return message;
}

void imap_close(struct imap_connection *conn) {
    close(conn->sockfd);
    free(conn->hostname);
    free(conn);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return -1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    struct imap_connection *conn = imap_connect(hostname, port);
    if (!conn) {
        printf("Error connecting to IMAP server: %s\n", strerror(errno));
        return -1;
    }

    if (imap_login(conn, username, password) == -1) {
        printf("Error logging in to IMAP server: %s\n", strerror(errno));
        imap_close(conn);
        return -1;
    }

    if (imap_select_mailbox(conn, "INBOX") == -1) {
        printf("Error selecting mailbox: %s\n", strerror(errno));
        imap_close(conn);
        return -1;
    }

    struct imap_message *message = imap_fetch_message(conn, 1);
    if (!message) {
        printf("Error fetching message: %s\n", strerror(errno));
        imap_close(conn);
        return -1;
    }

    printf("UID: %d\n", message->uid);
    printf("Flags: %s\n", message->flags);
    printf("Body: %s\n", message->body);

    imap_close(conn);

    free(message->flags);
    free(message->body);
    free(message);

    return 0;
}