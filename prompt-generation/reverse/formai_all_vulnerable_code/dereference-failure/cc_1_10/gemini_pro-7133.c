//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUF_SIZE 1024

struct client_info {
    int sockfd;
    struct sockaddr_in addr;
    pthread_t thread;
};

struct client_info clients[MAX_CLIENTS];
int client_count = 0;

void *client_handler(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buf[MAX_BUF_SIZE];
    int n;

    while ((n = read(client->sockfd, buf, MAX_BUF_SIZE)) > 0) {
        if (strncmp(buf, "GET", 3) == 0) {
            char *host = strstr(buf, "Host: ");
            if (host) {
                host += 6;
                char *end = strstr(host, "\r\n");
                if (end) {
                    *end = '\0';
                    struct hostent *he = gethostbyname(host);
                    if (he) {
                        struct sockaddr_in server_addr;
                        server_addr.sin_family = AF_INET;
                        server_addr.sin_port = htons(80);
                        server_addr.sin_addr = *(struct in_addr *)he->h_addr;

                        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
                        if (server_sockfd >= 0) {
                            if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) >= 0) {
                                write(server_sockfd, buf, n);
                                while ((n = read(server_sockfd, buf, MAX_BUF_SIZE)) > 0) {
                                    write(client->sockfd, buf, n);
                                }
                            }
                            close(server_sockfd);
                        }
                    }
                }
            }
        }
    }

    close(client->sockfd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in addr;

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)sizeof(addr));
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        if (client_count >= MAX_CLIENTS) {
            printf("Too many clients, closing connection\n");
            close(newsockfd);
            continue;
        }

        struct client_info *client = &clients[client_count++];
        client->sockfd = newsockfd;
        client->addr = addr;
        pthread_create(&client->thread, NULL, client_handler, (void *)client);
    }

    return 0;
}