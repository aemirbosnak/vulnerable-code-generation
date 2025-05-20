//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>

#define PORT 80

struct client_data {
    int sockfd;
    struct sockaddr_in addr;
};

void* handle_client(void* arg) {
    struct client_data* data = (struct client_data*)arg;
    int sockfd = data->sockfd;

    char buf[1024];
    int n;

    // Read request
    n = read(sockfd, buf, sizeof(buf) - 1);
    if (n < 0) {
        perror("read");
        close(sockfd);
        free(data);
        pthread_exit(NULL);
    }
    buf[n] = '\0';

    // Parse request
    char* method = strtok(buf, " ");
    char* path = strtok(NULL, " ");
    char* version = strtok(NULL, "\r\n");

    // Check method
    if (strcmp(method, "GET") != 0) {
        // Only support GET method
        n = sprintf(buf, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
        write(sockfd, buf, n);
        close(sockfd);
        free(data);
        pthread_exit(NULL);
    }

    // Check path
    if (strcmp(path, "/") != 0) {
        // Only support root path
        n = sprintf(buf, "HTTP/1.1 404 Not Found\r\n\r\n");
        write(sockfd, buf, n);
        close(sockfd);
        free(data);
        pthread_exit(NULL);
    }

    // Check version
    if (strcmp(version, "HTTP/1.1") != 0) {
        // Only support HTTP/1.1
        n = sprintf(buf, "HTTP/1.1 400 Bad Request\r\n\r\n");
        write(sockfd, buf, n);
        close(sockfd);
        free(data);
        pthread_exit(NULL);
    }

    // Send response
    char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>";
    n = strlen(response);
    write(sockfd, response, n);

    // Close connection
    close(sockfd);

    // Free memory
    free(data);

    return NULL;
}

int main() {
    int listenfd, sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    // Create socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set socket options
    int reuseaddr = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

    // Bind socket
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(listenfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    // Handle connections in a multi-threaded way
    pthread_t tid;
    while (1) {
        len = sizeof(cliaddr);
        sockfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
        if (sockfd == -1) {
            if (errno == EINTR) {
                // Interrupted by signal, continue
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }

        // Create a new thread to handle the client
        struct client_data* data = malloc(sizeof(struct client_data));
        data->sockfd = sockfd;
        data->addr = cliaddr;
        pthread_create(&tid, NULL, handle_client, (void*)data);
        pthread_detach(tid);
    }

    // Close listen socket
    close(listenfd);

    return 0;
}