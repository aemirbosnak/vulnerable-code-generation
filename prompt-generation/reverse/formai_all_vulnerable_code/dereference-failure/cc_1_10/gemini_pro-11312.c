//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 1024

typedef struct {
    int fd;
    struct sockaddr_in addr;
} connection_t;

typedef struct {
    char *username;
    char *password;
} credentials_t;

typedef struct {
    connection_t conn;
    credentials_t creds;
} client_t;

bool client_init(client_t *client, const char *host, const char *port, const char *username, const char *password) {
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("gethostbyname");
        return false;
    }

    client->conn.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->conn.fd < 0) {
        perror("socket");
        return false;
    }

    client->conn.addr.sin_family = AF_INET;
    client->conn.addr.sin_port = htons(atoi(port));
    memcpy(&client->conn.addr.sin_addr, host_entry->h_addr_list[0], host_entry->h_length);

    client->creds.username = strdup(username);
    client->creds.password = strdup(password);

    return true;
}

bool client_connect(client_t *client) {
    if (connect(client->conn.fd, (struct sockaddr *)&client->conn.addr, sizeof(client->conn.addr)) < 0) {
        perror("connect");
        return false;
    }

    return true;
}

bool client_login(client_t *client) {
    char message[MAX_MESSAGE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "LOGIN %s %s", client->creds.username, client->creds.password);

    if (send(client->conn.fd, message, strlen(message), 0) < 0) {
        perror("send");
        return false;
    }

    if (recv(client->conn.fd, message, MAX_MESSAGE_SIZE, 0) < 0) {
        perror("recv");
        return false;
    }

    if (strcmp(message, "OK") != 0) {
        printf("Login failed: %s\n", message);
        return false;
    }

    return true;
}

bool client_send_email(client_t *client, const char *to, const char *subject, const char *body) {
    char message[MAX_MESSAGE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "SEND %s %s %s", to, subject, body);

    if (send(client->conn.fd, message, strlen(message), 0) < 0) {
        perror("send");
        return false;
    }

    if (recv(client->conn.fd, message, MAX_MESSAGE_SIZE, 0) < 0) {
        perror("recv");
        return false;
    }

    if (strcmp(message, "OK") != 0) {
        printf("Sending email failed: %s\n", message);
        return false;
    }

    return true;
}

void client_close(client_t *client) {
    close(client->conn.fd);
    free(client->creds.username);
    free(client->creds.password);
}

int main(int argc, char **argv) {
    if (argc < 6) {
        printf("Usage: %s <host> <port> <username> <password> <to> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    client_t client;
    if (!client_init(&client, argv[1], argv[2], argv[3], argv[4])) {
        return EXIT_FAILURE;
    }

    if (!client_connect(&client)) {
        client_close(&client);
        return EXIT_FAILURE;
    }

    if (!client_login(&client)) {
        client_close(&client);
        return EXIT_FAILURE;
    }

    if (!client_send_email(&client, argv[5], argv[6], argv[7])) {
        client_close(&client);
        return EXIT_FAILURE;
    }

    client_close(&client);
    return EXIT_SUCCESS;
}