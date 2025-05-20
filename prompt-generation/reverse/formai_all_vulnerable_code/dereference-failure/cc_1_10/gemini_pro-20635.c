//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 21

typedef struct ftp_client {
    int sockfd;
    char *host;
    int port;
    char *username;
    char *password;
} ftp_client;

ftp_client *ftp_client_new(char *host, int port, char *username, char *password) {
    ftp_client *client = malloc(sizeof(ftp_client));
    if (client == NULL) {
        return NULL;
    }

    client->sockfd = -1;
    client->host = strdup(host);
    client->port = port;
    client->username = strdup(username);
    client->password = strdup(password);

    return client;
}

int ftp_client_connect(ftp_client *client) {
    struct sockaddr_in serv_addr;

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(client->port);
    serv_addr.sin_addr.s_addr = inet_addr(client->host);

    if (connect(client->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        return -1;
    }

    return 0;
}

int ftp_client_login(ftp_client *client) {
    char buf[1024];
    int n;

    n = read(client->sockfd, buf, sizeof(buf) - 1);
    if (n < 0) {
        return -1;
    }

    buf[n] = '\0';

    if (strncmp(buf, "220 ", 4) != 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "USER %s\r\n", client->username);
    n = write(client->sockfd, buf, strlen(buf));
    if (n < 0) {
        return -1;
    }

    n = read(client->sockfd, buf, sizeof(buf) - 1);
    if (n < 0) {
        return -1;
    }

    buf[n] = '\0';

    if (strncmp(buf, "331 ", 4) != 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "PASS %s\r\n", client->password);
    n = write(client->sockfd, buf, strlen(buf));
    if (n < 0) {
        return -1;
    }

    n = read(client->sockfd, buf, sizeof(buf) - 1);
    if (n < 0) {
        return -1;
    }

    buf[n] = '\0';

    if (strncmp(buf, "230 ", 4) != 0) {
        return -1;
    }

    return 0;
}

int ftp_client_close(ftp_client *client) {
    if (client->sockfd != -1) {
        close(client->sockfd);
    }

    free(client->host);
    free(client->username);
    free(client->password);
    free(client);

    return 0;
}

int main(int argc, char **argv) {
    ftp_client *client;
    int n;
    char buf[1024];

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    client = ftp_client_new(argv[1], atoi(argv[2]), argv[3], argv[4]);
    if (client == NULL) {
        fprintf(stderr, "Error: could not create FTP client.\n");
        return 1;
    }

    if (ftp_client_connect(client) < 0) {
        fprintf(stderr, "Error: could not connect to FTP server.\n");
        return 1;
    }

    if (ftp_client_login(client) < 0) {
        fprintf(stderr, "Error: could not login to FTP server.\n");
        return 1;
    }

    while (1) {
        printf("> ");
        fflush(stdout);

        n = read(0, buf, sizeof(buf) - 1);
        if (n < 0) {
            break;
        }

        buf[n] = '\0';

        if (strncmp(buf, "quit", 4) == 0) {
            break;
        }

        n = write(client->sockfd, buf, strlen(buf));
        if (n < 0) {
            break;
        }

        n = read(client->sockfd, buf, sizeof(buf) - 1);
        if (n < 0) {
            break;
        }

        buf[n] = '\0';

        printf("%s", buf);
    }

    ftp_client_close(client);

    return 0;
}