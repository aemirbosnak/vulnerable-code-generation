//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct pop3_user_info {
    char username[256];
    char password[256];
} pop3_user_info;

typedef struct pop3_client_info {
    char hostname[256];
    int port;
    int socket_fd;
    int connected;
    pop3_user_info user_info;
} pop3_client_info;

void pop3_client_connect(pop3_client_info* client) {
    struct addrinfo hints, *servinfo, *p;
    int rv, rc;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rc = getaddrinfo(client->hostname, NULL, &hints, &servinfo))!= 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for(p = servinfo; p!= NULL; p = p->ai_next) {
        if ((client->socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(client->socket_fd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(client->socket_fd);
            client->socket_fd = -1;
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to POP3 server\n");
        exit(EXIT_FAILURE);
    }

    if (connect(client->socket_fd, p->ai_addr, p->ai_addrlen) == -1) {
        perror("connect");
        close(client->socket_fd);
        client->socket_fd = -1;
    }

    client->connected = 1;
}

void pop3_client_disconnect(pop3_client_info* client) {
    if (client->connected) {
        close(client->socket_fd);
        client->connected = 0;
    }
}

void pop3_client_login(pop3_client_info* client) {
    char cmd[256];
    char response[1024];

    memset(cmd, 0, sizeof(cmd));
    memset(response, 0, sizeof(response));

    sprintf(cmd, "USER %s\r\n", client->user_info.username);
    write(client->socket_fd, cmd, strlen(cmd));

    if (read(client->socket_fd, response, sizeof(response)) == 0) {
        fprintf(stderr, "Read error\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Login failed\n");
        exit(EXIT_FAILURE);
    }

    memset(cmd, 0, sizeof(cmd));
    memset(response, 0, sizeof(response));

    sprintf(cmd, "PASS %s\r\n", client->user_info.password);
    write(client->socket_fd, cmd, strlen(cmd));

    if (read(client->socket_fd, response, sizeof(response)) == 0) {
        fprintf(stderr, "Read error\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(response, "+OK") == NULL) {
        fprintf(stderr, "Login failed\n");
        exit(EXIT_FAILURE);
    }

    client->connected = 1;
}

void pop3_client_get_messages(pop3_client_info* client) {
    char cmd[256];
    char response[1024];

    memset(cmd, 0, sizeof(cmd));
    memset(response, 0, sizeof(response));

    sprintf(cmd, "LIST\r\n");
    write(client->socket_fd, cmd, strlen(cmd));

    if (read(client->socket_fd, response, sizeof(response)) == 0) {
        fprintf(stderr, "Read error\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(response, "OK") == NULL) {
        fprintf(stderr, "Command not found\n");
        exit(EXIT_FAILURE);
    }
}

void pop3_client_quit(pop3_client_info* client) {
    char cmd[256];
    char response[1024];

    memset(cmd, 0, sizeof(cmd));
    memset(response, 0, sizeof(response));

    sprintf(cmd, "QUIT\r\n");
    write(client->socket_fd, cmd, strlen(cmd));

    if (read(client->socket_fd, response, sizeof(response)) == 0) {
        fprintf(stderr, "Read error\n");
        exit(EXIT_FAILURE);
    }

    if (strstr(response, "BYE") == NULL) {
        fprintf(stderr, "Command not found\n");
        exit(EXIT_FAILURE);
    }

    pop3_client_disconnect(client);
}

int main(int argc, char** argv) {
    pop3_client_info client;
    pthread_t thread;

    if (argc < 2) {
        fprintf(stderr, "Usage: pop3_client <hostname>\n");
        exit(EXIT_FAILURE);
    }

    memset(&client, 0, sizeof(client));
    strncpy(client.hostname, argv[1], sizeof(client.hostname));
    client.port = 110;

    if ((client.socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(client.socket_fd, (struct sockaddr*)&client.user_info.username, sizeof(client.user_info.username)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    pop3_client_connect(&client);

    pop3_client_login(&client);

    pop3_client_get_messages(&client);

    pop3_client_quit(&client);

    pop3_client_disconnect(&client);

    return 0;
}