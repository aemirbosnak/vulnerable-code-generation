//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_BUF_SIZE 1024

typedef struct {
    int sockfd;
    char *host;
    char *user;
    char *pass;
} pop3_client_t;

int pop3_client_init(pop3_client_t *client, char *host, char *user, char *pass) {
    int ret;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    ret = inet_pton(AF_INET, host, &server_addr.sin_addr);
    if (ret != 1) {
        return -1;
    }

    ret = connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        return -1;
    }

    client->host = host;
    client->user = user;
    client->pass = pass;

    return 0;
}

int pop3_client_login(pop3_client_t *client) {
    int ret;
    char buf[MAX_BUF_SIZE];

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    snprintf(buf, MAX_BUF_SIZE, "USER %s\r\n", client->user);
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    snprintf(buf, MAX_BUF_SIZE, "PASS %s\r\n", client->pass);
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    return 0;
}

int pop3_client_list(pop3_client_t *client) {
    int ret;
    char buf[MAX_BUF_SIZE];

    snprintf(buf, MAX_BUF_SIZE, "LIST\r\n");
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    printf("%s", buf);

    return 0;
}

int pop3_client_retr(pop3_client_t *client, int msg_num) {
    int ret;
    char buf[MAX_BUF_SIZE];

    snprintf(buf, MAX_BUF_SIZE, "RETR %d\r\n", msg_num);
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    printf("%s", buf);

    return 0;
}

int pop3_client_dele(pop3_client_t *client, int msg_num) {
    int ret;
    char buf[MAX_BUF_SIZE];

    snprintf(buf, MAX_BUF_SIZE, "DELE %d\r\n", msg_num);
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    return 0;
}

int pop3_client_quit(pop3_client_t *client) {
    int ret;
    char buf[MAX_BUF_SIZE];

    snprintf(buf, MAX_BUF_SIZE, "QUIT\r\n");
    ret = send(client->sockfd, buf, strlen(buf), 0);
    if (ret < 0) {
        return -1;
    }

    ret = recv(client->sockfd, buf, MAX_BUF_SIZE, 0);
    if (ret < 0) {
        return -1;
    }

    close(client->sockfd);

    return 0;
}

int main(int argc, char **argv) {
    int ret;
    char *host, *user, *pass;
    pop3_client_t client;

    if (argc != 4) {
        printf("Usage: %s host user pass\n", argv[0]);
        return EXIT_FAILURE;
    }

    host = argv[1];
    user = argv[2];
    pass = argv[3];

    ret = pop3_client_init(&client, host, user, pass);
    if (ret < 0) {
        printf("Error initializing POP3 client: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    ret = pop3_client_login(&client);
    if (ret < 0) {
        printf("Error logging in to POP3 server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    ret = pop3_client_list(&client);
    if (ret < 0) {
        printf("Error listing POP3 messages: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    ret = pop3_client_retr(&client, 1);
    if (ret < 0) {
        printf("Error retrieving POP3 message: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    ret = pop3_client_dele(&client, 1);
    if (ret < 0) {
        printf("Error deleting POP3 message: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    ret = pop3_client_quit(&client);
    if (ret < 0) {
        printf("Error quitting POP3 session: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}