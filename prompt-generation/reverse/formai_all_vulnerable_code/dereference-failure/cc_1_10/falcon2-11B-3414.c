//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

#define MAXLINE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in address;
    socklen_t addrlen;
} tcp_connection;

tcp_connection* connect_tcp(const char* host, int port) {
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(host);

    tcp_connection* connection = malloc(sizeof(tcp_connection));
    connection->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (connection->sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    if (connect(connection->sockfd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return connection;
}

void handle_client(tcp_connection* connection) {
    char buffer[MAXLINE];
    char request[MAXLINE];

    while (true) {
        printf("Waiting for client request...\n");
        fflush(stdout);
        memset(buffer, 0, sizeof(buffer));
        ssize_t nread = recv(connection->sockfd, buffer, sizeof(buffer), 0);
        if (nread <= 0) {
            break;
        }

        if (strcmp(buffer, "GET / HTTP/1.1\r\n\r\n") == 0) {
            printf("Received GET request\n");
            fflush(stdout);
            strcpy(request, buffer);
            memset(buffer, 0, sizeof(buffer));

            if (nread = recv(connection->sockfd, buffer, sizeof(buffer), 0) <= 0) {
                break;
            }

            printf("Received response from server: %s\n", buffer);
            fflush(stdout);
        }
    }

    printf("Disconnecting client...\n");
    fflush(stdout);
    close(connection->sockfd);
    free(connection);
}

int main(int argc, char* argv[]) {
    int port = 8080;
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    tcp_connection* connection = connect_tcp("127.0.0.1", port);
    if (connection == NULL) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, connection);

    pthread_join(thread, NULL);

    return 0;
}