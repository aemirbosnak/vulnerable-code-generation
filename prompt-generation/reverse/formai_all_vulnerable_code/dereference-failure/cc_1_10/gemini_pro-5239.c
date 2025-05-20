//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_BUF_SIZE 1024
#define MAX_CONNECTIONS 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char buf[MAX_BUF_SIZE];
} connection_t;

void *handle_connection(void *arg) {
    connection_t *conn = (connection_t *)arg;
    int nbytes;
    while((nbytes = read(conn->sockfd, conn->buf, MAX_BUF_SIZE - 1)) > 0) {
        conn->buf[nbytes] = '\0';
        printf("Received:\n%s", conn->buf);

        // Parse the HTTP request and send it to the destination server
        char *host = strtok(conn->buf, " ");
        char *path = strtok(NULL, " ");
        host = host + strlen("GET http://");
        *strchr(host, '/') = '\0';

        struct hostent *he = gethostbyname(host);
        if (!he) {
            printf("Error: could not resolve hostname '%s'\n", host);
            close(conn->sockfd);
            pthread_exit(NULL);
        }

        struct sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(80);
        dest_addr.sin_addr = *((struct in_addr *)he->h_addr);

        int dest_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (dest_sockfd < 0) {
            printf("Error: could not create socket\n");
            close(conn->sockfd);
            pthread_exit(NULL);
        }

        if (connect(dest_sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
            printf("Error: could not connect to destination server\n");
            close(conn->sockfd);
            close(dest_sockfd);
            pthread_exit(NULL);
        }

        write(dest_sockfd, conn->buf, nbytes);

        // Read the response from the destination server and send it back to the client
        char buf[MAX_BUF_SIZE];
        while((nbytes = read(dest_sockfd, buf, MAX_BUF_SIZE - 1)) > 0) {
            buf[nbytes] = '\0';
            write(conn->sockfd, buf, nbytes);
        }

        close(dest_sockfd);
    }

    close(conn->sockfd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error: could not bind socket to port %d\n", port);
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        printf("Error: could not listen on socket\n");
        close(sockfd);
        return 1;
    }

    printf("Listening on port %d\n", port);

    while(1) {
        connection_t conn;
        socklen_t addrlen = sizeof(conn.addr);
        conn.sockfd = accept(sockfd, (struct sockaddr *)&conn.addr, &addrlen);
        if (conn.sockfd < 0) {
            printf("Error: could not accept connection\n");
            continue;
        }

        pthread_t thread;
        pthread_create(&thread, NULL, handle_connection, &conn);
        pthread_detach(thread);
    }

    close(sockfd);
    return 0;
}