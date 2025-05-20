//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080

void* client_handler(void* arg) {
    int client_sock = *(int*)arg;
    char buf[1024];
    printf("Client connected: %s\n", inet_ntoa(((struct sockaddr_in*)arg)->sin_addr));
    while (1) {
        bzero(buf, sizeof(buf));
        ssize_t n = recv(client_sock, buf, sizeof(buf), 0);
        if (n == 0) {
            break;
        }
        printf("Client: %s\n", buf);
        ssize_t m = send(client_sock, buf, n, 0);
        if (m == 0) {
            break;
        }
        printf("Server: %s\n", buf);
    }
    printf("Client disconnected: %s\n", inet_ntoa(((struct sockaddr_in*)arg)->sin_addr));
    close(client_sock);
    pthread_exit(NULL);
}

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int optval = 1;
    socklen_t clilen = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    portno = PORT;

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int newsockfd;
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(EXIT_FAILURE);
        }

        pthread_t thread;
        pthread_create(&thread, NULL, client_handler, (void *) &newsockfd);
        pthread_detach(thread);
    }

    close(sockfd);
    return 0;
}