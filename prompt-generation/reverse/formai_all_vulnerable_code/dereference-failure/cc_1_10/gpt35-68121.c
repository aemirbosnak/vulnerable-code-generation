//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096
#define ERR_EXIT(m) \
    do { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while (0)

int proxy(int connfd, char *host, int port);
int tcp_connect(const char *host, int port);
void sigchld_handler(int sig);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int listenfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    char buf[BUF_SIZE];
    socklen_t cliaddr_len;
    pid_t pid;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
        ERR_EXIT("socket");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
                   &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    if (bind(listenfd, (struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
        ERR_EXIT("bind");

    if (listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    signal(SIGCHLD, sigchld_handler);

    while (1) {
        cliaddr_len = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len)) < 0) {
            if (errno == EINTR)
                continue;
            ERR_EXIT("accept");
        }

        printf("Received connection from %s:%d\n",
                inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        if ((pid = fork()) == -1)
            ERR_EXIT("fork");
        else if (pid == 0) {
            close(listenfd);
            proxy(connfd, argv[1], 80);
            exit(EXIT_SUCCESS);
        }

        close(connfd);
    }

    return 0;
}

int proxy(int connfd, char *host, int port)
{
    char buf[BUF_SIZE], method[BUF_SIZE], path[BUF_SIZE], version[BUF_SIZE];
    int i, n, clientfd;
    struct sockaddr_in clientaddr;
    char hostname[100];
    fprintf(stdout, "===== HTTP Proxy Start =====\n");

    if ((n = read(connfd, buf, BUF_SIZE)) <= 0)
        ERR_EXIT("read");

    sscanf(buf, "%s %s %s", method, path, version);
    fprintf(stdout, "Received message: %s %s %s\n", method, path, version);

    if (strcasecmp(method, "GET")) {
        fprintf(stderr, "HTTP method is not supported.\n");
        return -1;
    }

    char *proxy_host = strtok(path, "/");
    char *proxy_path = strtok(NULL, "");

    if (proxy_path == NULL)
        proxy_path = "/";

    fprintf(stdout, "Proxy request for: %s%s\n", proxy_host, proxy_path);

    if ((clientfd = tcp_connect(proxy_host, port)) < 0)
        ERR_EXIT("tcp_connect");

    sprintf(buf, "GET /%s HTTP/1.0\r\n"
            "Host: %s\r\n"
            "User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36\r\n\r\n", proxy_path, proxy_host);

    write(clientfd, buf, strlen(buf));

    while ((n = read(clientfd, buf, BUF_SIZE)) > 0) {
        write(connfd, buf, n);
    }

    fprintf(stdout, "===== HTTP Proxy End =====\n");

    close(clientfd);
    return 0;
}

int tcp_connect(const char *host, int port)
{
    int sockfd, n;
    char portstr[10];
    struct addrinfo hints, *servinfo, *p;
    sprintf(portstr, "%d", port);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(host, portstr, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        return -1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1)
            continue;
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Connection failed.\n");
        return -1;
    }

    freeaddrinfo(servinfo);

    return sockfd;
}

void sigchld_handler(int sig)
{
    while (waitpid(-1, NULL, WNOHANG) > 0);
}