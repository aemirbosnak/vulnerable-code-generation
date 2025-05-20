//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#define BUFSIZE 1024

typedef struct {
    int sockfd;
    char *username;
    pthread_t tid;
} client_info;

void *client_thread(void *arg) {
    client_info *info = (client_info *)arg;
    char buf[BUFSIZE];
    int n;

    while (1) {
        memset(buf, 0, BUFSIZE);
        n = read(info->sockfd, buf, BUFSIZE);
        if (n < 0) {
            perror("read");
            break;
        } else if (n == 0) {
            printf("Connection closed by server.\n");
            break;
        }

        printf("%s", buf);
    }

    close(info->sockfd);
    free(info->username);
    free(info);
    return NULL;
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *hostname, *username;
    char buf[BUFSIZE];
    int n, i;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    portno = atoi(argv[2]);
    username = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    n = write(sockfd, username, strlen(username));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    client_info *info = malloc(sizeof(client_info));
    info->sockfd = sockfd;
    info->username = strdup(username);

    pthread_create(&info->tid, NULL, client_thread, (void *)info);

    while (1) {
        memset(buf, 0, BUFSIZE);
        fgets(buf, BUFSIZE, stdin);
        n = strlen(buf);

        if (strncmp(buf, "/quit", 5) == 0) {
            break;
        }

        n = write(sockfd, buf, n);
        if (n < 0) {
            perror("write");
            break;
        }
    }

    pthread_join(info->tid, NULL);

    close(sockfd);
    return 0;
}