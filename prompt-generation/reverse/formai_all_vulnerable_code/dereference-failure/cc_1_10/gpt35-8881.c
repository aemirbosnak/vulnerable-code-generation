//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

/* function to create a socket for given server and port */
int create_socket(char *server, int port) {
    struct hostent *he;
    struct sockaddr_in addr;

    he = gethostbyname(server);
    if (he == NULL) {
        perror("gethostbyname");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(addr.sin_zero), '\0', 8);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        return -1;
    }

    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
        perror("connect");
        return -1;
    }

    return sockfd;
}

/* function to handle HTTP request and response */
void handle_request(int clientfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    /* read HTTP request from client */
    if(read(clientfd, buffer, BUFFER_SIZE) < 0) {
        perror("read");
        return;
    }

    /* parse host and port from HTTP request */
    char *host = NULL;
    int port = 80;

    char *temp = strtok(buffer, " ");
    while(temp) {
        if(strstr(temp, "http://")) {
            host = temp + strlen("http://");
        }
        else if(strstr(temp, "Host:")) {
            host = strtok(NULL, "\r\n");
        }
        else if(strstr(temp, "Accept:")) {
            break;
        }

        temp = strtok(NULL, " ");
    }

    if(host) {
        char *temp_host = strtok(host, ":");
        char *temp_port = strtok(NULL, ":");
        if(temp_port) {
            port = atoi(temp_port);
        }

        /* create a socket to forward the HTTP request */
        int serverfd = create_socket(temp_host, port);
        if(serverfd >= 0) {
            /* forward HTTP request to server */
            if(write(serverfd, buffer, strlen(buffer)) < 0) {
                perror("write");
                close(serverfd);
                return;
            }

            /* read HTTP response from server */
            memset(buffer, 0, BUFFER_SIZE);
            while(read(serverfd, buffer, BUFFER_SIZE) > 0) {
                /* send HTTP response back to client */
                if(write(clientfd, buffer, strlen(buffer)) < 0) {
                    perror("write");
                    break;
                }

                memset(buffer, 0, BUFFER_SIZE);
            }

            close(serverfd);
        }
    }

    close(clientfd);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("usage: %s <port>\n", argv[0]);
        return 0;
    }

    int port = atoi(argv[1]);

    /* create a socket to listen for incoming HTTP requests */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        return 0;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(addr.sin_zero), '\0', 8);

    if(bind(sockfd, (struct sockaddr *)&addr, sizeof(struct sockaddr)) < 0) {
        perror("bind");
        return 0;
    }

    if(listen(sockfd, 10) < 0) {
        perror("listen");
        return 0;
    }

    /* accept incoming HTTP requests and handle them */
    while(1) {
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);
        int clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if(clientfd < 0) {
            perror("accept");
            continue;
        }

        pid_t pid = fork();
        if(pid < 0) {
            perror("fork");
            close(clientfd);
            continue;
        }
        else if(pid == 0) {
            close(sockfd);
            handle_request(clientfd);
            exit(0);
        }
        else {
            close(clientfd);
        }
    }

    return 0;
}