//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21
#define MAX_BUF_SIZE 1024

typedef struct {
    int sockfd;
    char *host;
    int port;
    char *user;
    char *pass;
} ftp_client_config_t;

void ftp_client_connect(ftp_client_config_t *config) {
    struct sockaddr_in servaddr;

    config->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (config->sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent *hostinfo = gethostbyname(config->host);
    if (hostinfo == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(config->port);
    memcpy(&servaddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

    if (connect(config->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }
}

void ftp_client_login(ftp_client_config_t *config) {
    char buf[MAX_BUF_SIZE];

    // Send USER command
    snprintf(buf, MAX_BUF_SIZE, "USER %s\r\n", config->user);
    write(config->sockfd, buf, strlen(buf));
    read(config->sockfd, buf, MAX_BUF_SIZE);
    if (strncmp(buf, "331", 3) != 0) {
        fprintf(stderr, "Error: USER command failed\n");
        exit(1);
    }

    // Send PASS command
    snprintf(buf, MAX_BUF_SIZE, "PASS %s\r\n", config->pass);
    write(config->sockfd, buf, strlen(buf));
    read(config->sockfd, buf, MAX_BUF_SIZE);
    if (strncmp(buf, "230", 3) != 0) {
        fprintf(stderr, "Error: PASS command failed\n");
        exit(1);
    }
}

void ftp_client_list(ftp_client_config_t *config) {
    char buf[MAX_BUF_SIZE];

    // Send LIST command
    write(config->sockfd, "LIST\r\n", strlen("LIST\r\n"));
    while (read(config->sockfd, buf, MAX_BUF_SIZE) > 0) {
        printf("%s", buf);
    }
}

void ftp_client_disconnect(ftp_client_config_t *config) {
    close(config->sockfd);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <host> <port> <user> <pass>\n", argv[0]);
        exit(1);
    }

    ftp_client_config_t config;
    config.host = argv[1];
    config.port = atoi(argv[2]);
    config.user = argv[3];
    config.pass = argv[4];

    ftp_client_connect(&config);
    ftp_client_login(&config);
    ftp_client_list(&config);
    ftp_client_disconnect(&config);

    return 0;
}