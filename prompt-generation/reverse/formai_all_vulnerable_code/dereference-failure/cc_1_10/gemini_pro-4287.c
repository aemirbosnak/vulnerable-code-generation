//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define DEFAULT_POP3_PORT 110

typedef struct {
    int sockfd;
    char *hostname;
    short port;
    char *username;
    char *password;
} pop3_client;

int pop3_connect(pop3_client *client) {
    struct sockaddr_in server_addr;
    struct hostent *host_entry;

    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    if ((host_entry = gethostbyname(client->hostname)) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *) host_entry->h_addr_list[0]);
    server_addr.sin_port = htons(client->port);

    if (connect(client->sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    return 0;
}

int pop3_authenticate(pop3_client *client) {
    char buf[1024];
    char cmd[1024];

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    snprintf(cmd, sizeof(cmd), "USER %s\r\n", client->username);
    if (send(client->sockfd, cmd, strlen(cmd), 0) <= 0) {
        perror("send");
        return -1;
    }

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", client->password);
    if (send(client->sockfd, cmd, strlen(cmd), 0) <= 0) {
        perror("send");
        return -1;
    }

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    return 0;
}

int pop3_get_message_count(pop3_client *client) {
    char buf[1024];
    char cmd[1024];

    snprintf(cmd, sizeof(cmd), "STAT\r\n");
    if (send(client->sockfd, cmd, strlen(cmd), 0) <= 0) {
        perror("send");
        return -1;
    }

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    return atoi(buf);
}

int pop3_get_message(pop3_client *client, int message_number) {
    char buf[1024];
    char cmd[1024];

    snprintf(cmd, sizeof(cmd), "RETR %d\r\n", message_number);
    if (send(client->sockfd, cmd, strlen(cmd), 0) <= 0) {
        perror("send");
        return -1;
    }

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    printf("%s\n", buf);

    return 0;
}

int pop3_close(pop3_client *client) {
    char buf[1024];
    char cmd[1024];

    snprintf(cmd, sizeof(cmd), "QUIT\r\n");
    if (send(client->sockfd, cmd, strlen(cmd), 0) <= 0) {
        perror("send");
        return -1;
    }

    if (recv(client->sockfd, buf, sizeof(buf), 0) <= 0) {
        perror("recv");
        return -1;
    }

    close(client->sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    pop3_client client;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return -1;
    }

    client.hostname = argv[1];
    client.port = atoi(argv[2]);
    client.username = argv[3];
    client.password = argv[4];

    if (pop3_connect(&client) < 0) {
        return -1;
    }

    if (pop3_authenticate(&client) < 0) {
        return -1;
    }

    int message_count = pop3_get_message_count(&client);
    if (message_count < 0) {
        return -1;
    }

    for (int i = 1; i <= message_count; i++) {
        if (pop3_get_message(&client, i) < 0) {
            return -1;
        }
    }

    if (pop3_close(&client) < 0) {
        return -1;
    }

    return 0;
}