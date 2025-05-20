//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 2048

int main(int argc, char* argv[]) {
    int proxy_port, dst_port, proxy_fd, dst_fd, client_fd, nfds;
    char *proxy_host, *dst_host;
    char buf[MAX_BUF_SIZE], url[MAX_BUF_SIZE], *req, *p, *p1, *p2;
    fd_set set;

    if (argc != 4) { 
        fprintf(stderr, "Usage: proxy <proxy_host> <proxy_port> <dst_host:dst_port>");
        exit(1);
    }

    proxy_host = argv[1];
    proxy_port = atoi(argv[2]);

    dst_host = strtok(argv[3], ":");
    dst_port = atoi(strtok(NULL, ""));

    if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;         
    proxy_addr.sin_port = htons(proxy_port);
    proxy_addr.sin_addr.s_addr = inet_addr(proxy_host);
    memset(proxy_addr.sin_zero, '\0', sizeof(proxy_addr.sin_zero));

    if (connect(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", proxy_host, proxy_port);

    sprintf(url, "http://%s:%d", dst_host, dst_port);

    req = (char*) malloc(strlen(url) + 50);
    sprintf(req, "GET %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.1; WOW64; rv:25.0) Gecko/20100101 Firefox/25.0\r\n\r\n", url, dst_host);

    if (send(proxy_fd, req, strlen(req), 0) == -1) {
        perror("send");
        exit(1);
    }

    free(req);

    printf("Request sent:\n%s\n", req);

    memset(buf, 0, MAX_BUF_SIZE);
    int bytes_received;

    while ((bytes_received = recv(proxy_fd, buf, MAX_BUF_SIZE, 0)) > 0) {
        // replace compression header with identity
        char *p = strstr(buf, "Content-Encoding: gzip");
        if (p != NULL) {
            char *p1 = strstr(buf, "\r\n\r\n") + 4;
            char *p2 = strstr(p1, "\r\n");
            char *p3 = strstr(p1, "gzip");
            int i = 0;
            while (p != NULL) {
                memcpy(p, "identity", strlen("identity"));
                p = strstr(p+1, "Content-Encoding: gzip");
                i++;
            }
            printf("%d compression headers replaced\n", i);
        }

        if (dst_fd <= 0) {
            printf("Connecting to %s:%d\n", dst_host, dst_port);

            if ((dst_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
            }

            struct sockaddr_in dst_addr;
            dst_addr.sin_family = AF_INET;         
            dst_addr.sin_port = htons(dst_port);
            dst_addr.sin_addr.s_addr = inet_addr(dst_host);
            memset(dst_addr.sin_zero, '\0', sizeof(dst_addr.sin_zero));

            if (connect(dst_fd, (struct sockaddr *) &dst_addr, sizeof(struct sockaddr_in)) == -1) {
                perror("connect");
                exit(1);
            }

            printf("Connected to %s:%d\n", dst_host, dst_port);

            // non-blocking proxy_fd
            fcntl(proxy_fd, F_SETFL, O_NONBLOCK);

            // add both sockets to the set 
            FD_ZERO(&set);
            FD_SET(proxy_fd, &set);
            FD_SET(dst_fd, &set);

            nfds = proxy_fd > dst_fd ? proxy_fd + 1 : dst_fd + 1;

            // keep forwarding data between the sockets
            while (select(nfds, &set, NULL, NULL, NULL)) {
                if (FD_ISSET(proxy_fd, &set)) {
                    int len = recv(proxy_fd, buf, MAX_BUF_SIZE - 1, 0);
                    if (len == -1) {
                        perror("recv");
                        exit(1);
                    } else if (len == 0) {
                        break;
                    }
                    buf[len] = '\0';

                    printf("[Proxy --> Destination]:\n%s\n\n", buf);

                    if (send(dst_fd, buf, len, 0) == -1) {
                        perror("send");
                        exit(1);
                    }
                }

                if (FD_ISSET(dst_fd, &set)) {
                    int len = recv(dst_fd, buf, MAX_BUF_SIZE - 1, 0);
                    if (len == -1) {
                        perror("recv");
                        exit(1);
                    } else if (len == 0) {
                        break;
                    }
                    buf[len] = '\0';

                    printf("[Proxy <-- Destination]:\n%s\n\n", buf);

                    if (send(proxy_fd, buf, len, 0) == -1) {
                        perror("send");
                        exit(1);
                    }
                }
            }
        }

        printf("[Proxy <-- Server]:\n%s\n\n", buf);

        if (send(client_fd, buf, bytes_received, 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }

    close(proxy_fd);
    close(dst_fd);

    return 0;
}