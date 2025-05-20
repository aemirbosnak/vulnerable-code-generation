//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define IMAP_PORT 143

typedef struct {
    int sockfd;
    char *hostname;
    int port;
    char *username;
    char *password;
} IMAPClient;

IMAPClient *imap_client_new(char *hostname, int port, char *username, char *password) {
    IMAPClient *client = malloc(sizeof(IMAPClient));
    client->sockfd = -1;
    client->hostname = hostname;
    client->port = port;
    client->username = username;
    client->password = password;
    return client;
}

void imap_client_free(IMAPClient *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }
    free(client);
}

int imap_client_connect(IMAPClient *client) {
    struct hostent *host;
    struct sockaddr_in addr;

    host = gethostbyname(client->hostname);
    if (host == NULL) {
        return -1;
    }
    
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        return -1;
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(client->port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    
    if (connect(client->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return -1;
    }
    
    return 0;
}

int imap_client_login(IMAPClient *client) {
    char buf[1024];
    int len;
    
    len = snprintf(buf, sizeof(buf), "LOGIN %s %s\r\n", client->username, client->password);
    if (send(client->sockfd, buf, len, 0) == -1) {
        return -1;
    }
    
    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len == -1) {
        return -1;
    }
    
    buf[len] = '\0';
    if (strncmp(buf, "+OK LOGIN completed", 19) != 0) {
        return -1;
    }
    
    return 0;
}

int imap_client_select(IMAPClient *client, char *mailbox) {
    char buf[1024];
    int len;
    
    len = snprintf(buf, sizeof(buf), "SELECT %s\r\n", mailbox);
    if (send(client->sockfd, buf, len, 0) == -1) {
        return -1;
    }
    
    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len == -1) {
        return -1;
    }
    
    buf[len] = '\0';
    if (strncmp(buf, "+OK ", 4) != 0) {
        return -1;
    }
    
    return 0;
}

int imap_client_fetch(IMAPClient *client, char *uid) {
    char buf[1024];
    int len;
    
    len = snprintf(buf, sizeof(buf), "FETCH %s (BODY)\r\n", uid);
    if (send(client->sockfd, buf, len, 0) == -1) {
        return -1;
    }
    
    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len == -1) {
        return -1;
    }
    
    buf[len] = '\0';
    if (strncmp(buf, "+OK FETCH completed", 19) != 0) {
        return -1;
    }
    
    return 0;
}

int main(int argc, char **argv) {
    IMAPClient *client;
    char *hostname;
    int port;
    char *username;
    char *password;
    char *mailbox;
    char *uid;
    char buf[1024];
    int len;
    
    if (argc != 6) {
        fprintf(stderr, "Usage: %s hostname port username password mailbox uid\n", argv[0]);
        return 1;
    }
    
    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    mailbox = argv[5];
    uid = argv[6];
    
    client = imap_client_new(hostname, port, username, password);
    if (client == NULL) {
        fprintf(stderr, "Failed to create IMAP client\n");
        return 1;
    }
    
    if (imap_client_connect(client) != 0) {
        fprintf(stderr, "Failed to connect to IMAP server\n");
        imap_client_free(client);
        return 1;
    }
    
    if (imap_client_login(client) != 0) {
        fprintf(stderr, "Failed to login to IMAP server\n");
        imap_client_free(client);
        return 1;
    }
    
    if (imap_client_select(client, mailbox) != 0) {
        fprintf(stderr, "Failed to select mailbox\n");
        imap_client_free(client);
        return 1;
    }
    
    if (imap_client_fetch(client, uid) != 0) {
        fprintf(stderr, "Failed to fetch message\n");
        imap_client_free(client);
        return 1;
    }
    
    len = recv(client->sockfd, buf, sizeof(buf), 0);
    if (len == -1) {
        fprintf(stderr, "Failed to receive message\n");
        imap_client_free(client);
        return 1;
    }
    
    buf[len] = '\0';
    printf("%s", buf);
    
    imap_client_free(client);
    
    return 0;
}