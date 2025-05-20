//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

typedef struct {
    char* hostname;
    int port;
    char* username;
    char* password;
} IMAP_client;

IMAP_client* imap_client_init(char* hostname, int port, char* username, char* password) {
    IMAP_client* client = malloc(sizeof(IMAP_client));
    client->hostname = strdup(hostname);
    client->port = port;
    client->username = strdup(username);
    client->password = strdup(password);
    return client;
}

void imap_client_destroy(IMAP_client* client) {
    free(client->hostname);
    free(client->username);
    free(client->password);
    free(client);
}

void imap_client_connect(IMAP_client* client) {
    struct hostent* host = gethostbyname(client->hostname);
    if (host == NULL) {
        printf("Error: %s not found\n", client->hostname);
        exit(1);
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(client->port);
    address.sin_addr = *((struct in_addr*) host->h_addr);
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: socket creation failed\n");
        exit(1);
    }
    if (connect(sock, (struct sockaddr*) &address, sizeof(address)) < 0) {
        printf("Error: connection failed\n");
        exit(1);
    }
    char buf[BUF_SIZE];
    ssize_t n = read(sock, buf, BUF_SIZE);
    if (n <= 0) {
        printf("Error: read failed\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);
    snprintf(buf, BUF_SIZE, "LOGIN %s %s\r\n", client->username, client->password);
    if (write(sock, buf, strlen(buf)) < 0) {
        printf("Error: write failed\n");
        exit(1);
    }
    n = read(sock, buf, BUF_SIZE);
    if (n <= 0) {
        printf("Error: read failed\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);
    close(sock);
}

int main() {
    IMAP_client* client = imap_client_init("imap.gmail.com", 993, "example@gmail.com", "password");
    imap_client_connect(client);
    imap_client_destroy(client);
    return 0;
}